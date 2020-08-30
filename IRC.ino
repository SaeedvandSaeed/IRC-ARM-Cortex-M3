#include <Wire.h>            // I2C communication lib
#include <MapleFreeRTOS.h>   // MapleFree Real-Time Operating System lib 
#include "EEPROM.h"          // eeprom lib

//Global Deffenition 
#define DEG2RAD (0.0174532925199432957)
#define RAD2DEG (57.295779513082320876)
#define DEG2DXL (11.377777776666666668)

//Global Deffenition of low and high byte of integer registers
#define _LOBYTE(w)   ((unsigned char)(((unsigned long)(w)) & 0xff))        //get low byte (8 first bits) from one 16 bit value
#define _HIBYTE(w)   ((unsigned char)((((unsigned long)(w)) >> 8) & 0xff)) //get high byte (8'th to 16'th bits) from 16 bit value
#define NUM_OF_DXL (18)                                                    //white led on board

#define External_Button (20)                                               //define  External Button for starting the robot
#define External_LED (19)                                                  //define  External LED

double Angle[NUM_OF_DXL];

//Writing value to motors
byte D_TORQUE_ENABLE[NUM_OF_DXL];
byte D_STATUS_LED[NUM_OF_DXL];
byte D_KD_GAIN[NUM_OF_DXL];   
byte D_KI_GAIN[NUM_OF_DXL];
byte D_KP_GAIN[NUM_OF_DXL];
int  D_GOAL_POSITION[NUM_OF_DXL];
int  D_MOVING_SPEED[NUM_OF_DXL];

//---------------------------------
int Change_State=0;             // If state of movement of the robot change it helps to fixing the currect behaviour of robot- walking currecting
int changed=0;                  // Helper variable for previous variable
byte walking_state=0;           // (0= No Action, 1= In Place Walking, 2= Forward Walking)
byte walking_speed=0;           // (1 to 5 is for walking Speed in which, its converting to 1/10 in -Vx)
byte Rotate_Direction=0;        // (0= No Turning, 1= Turn to Left, 2= Turn to Right)
byte Rotate_Speed=0;            // (1 to 5, its for turning speed, its converting to 1/10 in -Vt)
byte Kicking_instructions=0;    // (0= No Kicking, 1 Kick left, 2= Kick Right)
byte Side_Walk_Instructions=0;  // (0= No Action, 1 Go to Left, 2= Go to Right)
byte Other_Instructions=0;      // This is Reserve data For run Another instructions 
//---------------------------------
Dynamixel DXL(1);               // Dynamixel on Serial1(USART1)
HardwareTimer Timer(1);         // Hardware timer for RTC

unsigned short int  RTC_Sec=0, RTC_Min=0;

float X=0.0f, Y=0.0f, Z=0.0f;  //absolute orientation calculated from kalman filter in Degree

signed short DXLWTaskCNT=0 , DXLWTaskHz=0;    //IMU task internal frequency value
signed short DXLRTaskCNT=0 , DXLRTaskHz=0;    //IMU task internal frequency value
signed short SIMUTaskCNT=0 , SIMUTaskHz=0;    //Sensor IMU task internal frequency val
signed short MCNTTaskCNT=0 , MCNTTaskHz=0;    //IMU task internal frequency value
signed short ROBOTaskCNT=0 , ROBOTaskHz=0;    //IMU task internal frequency value
signed short REGUTaskCNT=0 , REGUTaskHz=0;    //IMU task internal frequency value

//----------------------------------------------------These are Related to Walking of the robot---------------------------------------------------
double Motion_Resolution=2;          //min=0.1 max=10; motion resolution of steps (it means that more smooth motion if resolution is lower (1,2,3,5,10 is possible for this))
double Double_Support_Sleep=0.25;    //double foot in ground time sleep
double Single_Support_Sleep=0.0;     //one foot time sleep when other foot is in air
double Step_Height=0.90;  //Cheak Public and MCNT too     //min=0.01  max=1.0   the steps height of each leg
double Gait_Frequency=0.985; //97    //gait runs frequency depended to the motion resolution value max=1.0

double Side_Roll_Perecent=0.15;      //how much legs in each gait should be turn around roll axis (Each Foot Rool) 
double Side_Y_Percent=0;      /*-*/  //howmuch legs in each gait should be go to up or down, its in count of another leg, Negetive is for opening the legs, (Each hip + feet roll)
double Side_Yaw_Percent=0;           //howmuch each legs become open(charly chaplin) in every gait

double X_offset=-5;//4;//8;              //offset of move torso to forward or backward - Negative for Front side
double Y_offset=0;          /*-*/    //35 offset of move torso to sidevard (Positive is for how many legs are become open in walking state)
double Z_offset=35; //35             //sitting the robot in z axis
double Yaw_offset=0;                 //ofset of robot turn around yaw axis, Radian
double Roll_offset=0;                //ofset of robot turn around roll axis, Radian
double Pitch_offset=-0.0;            //ofset of robot turn around pitch axis, Radian
  
double Vx=0.0;                       //velocity of X (forward) direction from PC
double Vy=0.0;                       //velocity of Y (sideward) direction
double Vt=0.0;                       //velocity of T (rotate) speed

double Vx_Backup=0.0;
double Vy_Backup=0.0;
double Vt_Backup=0.0;

int start_to_show=0;
//------------------------------------------------------These are for robot balancing thorgh IMU---------------------------------------------------
double Kp_X_Correction=0.1;
double Kp_X_Correction_hand=1.5;//1.3;
double Kp_Pitch_Correction=0.015;//0.005
double Kp_Roll_Correction=0.01;//0.005

int turning_time=0;
//----------------------------------------------------------------Initialize system-----------------------------------------------------------------
void setup()
{
  pinMode(External_Button, INPUT_PULLDOWN); // For External Button
  pinMode(External_LED, OUTPUT);            // For External LED
  digitalWrite(External_LED, HIGH);
  
  RTC_Setup_Timer(1000000);                 // Initialize RTC for 1 mili secound  
  SerialUSB.begin();                        // Config serialUSB port
  SerialUSB.attachInterrupt(usbInterrupt);
  Wire.begin(1,0);                          // Initialize i2c comunication port (sda and scl)
  DXL.begin(3);                             // Initialize Dynamixel defult bus (1000000bps)
  pinMode(BOARD_LED_PIN, OUTPUT);
  pinMode(BOARD_BUTTON_PIN, INPUT_PULLDOWN);
  //RTOS system config
  xTaskCreate( vDXLWTask       ,( signed char * ) "DXLW"  ,configMINIMAL_STACK_SIZE, NULL, 2, NULL ); //Init Real Time Clock task for calculate internal frequency of tasks
  //xTaskCreate( vDXLRTask       ,( signed char * ) "DXLR"  ,configMINIMAL_STACK_SIZE, NULL, 1, NULL ); 
  xTaskCreate( vSIMUTask       ,( signed char * ) "SIMU"  ,configMINIMAL_STACK_SIZE, NULL, 1, NULL ); //Init IMU task for read and run fusion alghorithm
  xTaskCreate( vMCNTTask       ,( signed char * ) "MCNT"  ,configMINIMAL_STACK_SIZE, NULL, 1, NULL ); //Init Real Time Clock task for calculate internal frequency of tasks
  xTaskCreate( vROBOTask       ,( signed char * ) "MCNT"  ,configMINIMAL_STACK_SIZE, NULL, 1, NULL ); //Init Real Time Clock task for calculate internal frequency of tasks 
  
  vTaskStartScheduler();      //Start schaduler of task, this function from RTOS lib and defult system if pipe line system
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
//main loop for micro, but it's not used. the RTOS task is running
void loop()
{
   //action in task
}

