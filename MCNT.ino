//motors IDs
#define Left_Ebow          (2-1)
#define Left_Arm_Roll      (4-1)
#define Left_Arm_Pitch     (6-1)

#define Right_Ebow         (1-1)
#define Right_Arm_Roll     (3-1)
#define Right_Arm_Pitch    (5-1)

#define Left_Hip_Yaw       (8-1)
#define Left_Hip_Roll      (10-1)
#define Left_Hip_Pitch     (12-1)
#define Left_Knee          (14-1)
#define Left_Foot_Pitch    (16-1)  
#define Left_Foot_Roll     (18-1) 

#define Right_Hip_Yaw      (7-1)
#define Right_Hip_Roll     (9-1)
#define Right_Hip_Pitch    (11-1)
#define Right_Knee         (13-1)
#define Right_Foot_Pitch   (15-1)
#define Right_Foot_Roll    (17-1)
//--------------------------------------------------------------------------------------------
//Length of legs
#define Lower_Leg_len  357 
#define Upper_Leg_len  327
#define leg_length  (Lower_Leg_len + Upper_Leg_len)
//--------------------------------------------------------------------------------------------
//joints offset for inverse kinematic
#define Left_Leg_Hip_Pitch_Offset  0        // positive is for go though forward
#define Left_Leg_Knee_Offset 0.75           // positive is for seat
#define Left_Leg_Foot_Pitch_Offset 0.00     // negative is for go though forward

#define Right_Leg_Hip_Pitch_Offset -0       // negative is for go though forward
#define Right_Leg_Knee_Offset -0.75         // negative is for seat
#define Right_Leg_Foot_Pitch_Offset -0.00   // positive is for go though forward

#define Left_Leg_X_Offset 27                // positive is for leg to come forward
#define Left_Leg_Y_Offset 0.00766           // positive is for leg open to side
#define Left_Leg_Z_Offset -1                // positive is for leg up (-49 is for stand state)
#define Left_Leg_Roll_Offset -0.02          // positive go up the interior side of leg
#define Left_Leg_Pitch_Offset -0.03         // positive is for front side of foot down
#define Left_Leg_Yaw_Offset 0.030           // positive is going to outside

#define Right_Leg_X_Offset 0
#define Right_Leg_Y_Offset 0.00566   //28          // positive is for leg open to side
#define Right_Leg_Z_Offset 1                // positive is for leg up(-49 is for stand state)
#define Right_Leg_Roll_Offset -0.01         // negative go up the interior side of leg
#define Right_Leg_Pitch_Offset 0.05         // -0.02  positive is for front side of foot down
#define Right_Leg_Yaw_Offset  0             // positive is going to outside

#define Motion_Kick_Left 1
#define Motion_Kik_Right 2
//---------------------------------------------------------------------------------------------
double L_X=0;
double L_Y=0;
double L_Z=0;
double L_Roll=0;
double L_Pitch=0;
double L_Yaw=0;

double R_X=0;
double R_Y=0;
double R_Z=0;
double R_Roll=0;                            // Foot interiour side open, Positive is for interior side down
double R_Pitch=0;
double R_Yaw=0;                             // Legs open in yaw side, positive is for leg open

double Left_Leg_Roll_turning=0;             // this is for how much each roll should be turn turn to interior side in left foot (0-1)
double Right_Leg_Roll_turning=0;            // this is for how much each roll should be turn turn to interior side in right foot (0-1)
//----------------------------------------------------------------------------------------------

// Motion Control Task (runs under more than 200Hz)
void vMCNTTask( void *pvParameters )
{
  //------------------------------------
  portTickType xLastWakeTime;
  const portTickType xFrequency = 10; //loop frequency Reg_Control_Motion_Frequency
  xLastWakeTime = xTaskGetTickCount ();
  vTaskDelay(1000);
  //------------------------------------
  // X_offset=8;
  // Step_Height=0.90;
  Vx=-0.0;                     //velocity of X (forward) direction from PC (min -1 to max 1), negative is for go stright a head (-0.5 forward, X_offset=20)
  Vy=-0.0;                     //velocity of Y (sideward) direction  // (negative is for walk to left)
  Vt=0.0;                      //velocity of T (rotate) speed (per radian) positive is for turn to left (0.1 L, -0.1 R)
   
  //Initial Values for Hand Joints
  Angle[Left_Ebow]=40*DEG2RAD;        // positive is for elbow hand go to front side 
  Angle[Left_Arm_Roll]=-2.5*DEG2RAD;  // negative is for left open to side
  Angle[Left_Arm_Pitch]=0*DEG2RAD;    // negative is for go forward
  
  Angle[Right_Ebow]=-40*DEG2RAD;      // negative is for elbow hand go to front side 
  Angle[Right_Arm_Roll]=2.5*DEG2RAD;  // positive is for left open to side
  Angle[Right_Arm_Pitch]=0*DEG2RAD;   // posetive is for go forward

  //vTaskDelay(2000);
  L_X=0;         // negativie is for leg back
  L_Y=0;         // positive is for leg open
  L_Z=Z_offset;
  L_Roll=0;      // positive is for interior side up
  L_Pitch=0;     // positive is for front side of foot down
  L_Yaw=0;

  R_X=0;
  R_Y=-0;       // positive is for leg open
  R_Z=Z_offset;
  R_Roll=0;
  R_Pitch=0;    // negative is for front side of foot up
  R_Yaw=0;
   
  ik(0.04); //call inverse kinematic for 
  vTaskDelay(1000);
   

  digitalWrite(External_LED, LOW);  // for Turning External LED Off by Starting the robot (+5v) is going to LED
  delay(10);
  
  //wait for button pressed to start motion
 // while(!digitalRead(BOARD_BUTTON_PIN))
  while(!digitalRead(External_Button))  // for Starting the robot through External button by Negative(-5v) from push button
  {
    //Push Recovery in the Stand State
    // Stand_Push_Recovery();
  }
     
   digitalWrite(External_LED, HIGH);  
   digitalWrite(BOARD_LED_PIN, LOW);
   vTaskDelay(500);
   
   start_to_show=1;
   
   //Kick_Left(0.02);
  // Kick_Right(0.02);
  // while(1); 

   //SerialUSB.println("\nMain Motion Controller Started...");
   
//-------------------------------------This loop is for walking of the robot with omnini Directional Algorithm------------------------------
    for(;;)
    {      
       if(Kicking_instructions==1) 
       { 
         // here should write something to get steady state for kick
         togglePin(BOARD_LED_PIN);
         Kick_Left(0.02);
         Change_State=1; //Fixing_body_position_between_movements
         togglePin(BOARD_LED_PIN);
       }
       else if(Kicking_instructions==2) 
       { 
         togglePin(BOARD_LED_PIN);
         Kick_Right(0.02);
         Change_State=1;  //Fixing_body_position_between_movements
         togglePin(BOARD_LED_PIN);
       }
      
      if ((Vx!=0)||(Vy!=0)||(Vt!=0)||Change_State==1) // if there are some instructions to execute
      {        
       turning_time++; 
       //---------------Kick------------------
       if(Change_State==1) // For Walk in place after kick
       {
           Vx=0.33;                    
           Vy=0.0;                     
           Vt=0.0; 
           X_offset=-5;
           Step_Height=0.70;
          
           togglePin(External_LED);
       }
       /*
       else if(changed==1)
       {
           Vx=Vx_Backup; // For return current instructions the robot movement       
           Vy=Vy_Backup;        
           Vt=Vt_Backup;  
           
           changed=0;
       }*/
       
       /*
       if(turning_time>=5)//12
       {
           Vx=-0.0001; //0.9       
           Vy=0.0; //0.5       
           Vt=0.0;  
       }
       if(turning_time>=6)//12
       {
         Kick_Right(0.02);
         while(1); 
         
           Vx=-0.5; //0.9       //velocity of X (forward) direction from PC (min -1 to max 1) //negative is for walk to forward
           Vy=0.0; //0.5       //velocity of Y (sideward) direction  // negative is for walk to right
           Vt=0.0;    
       }
     */
       /*
       if(turning_time>=25)//12
       {
           Vx=-0.0; //0.9       //velocity of X (forward) direction from PC (min -1 to max 1) //negative is for walk to forward
           Vy=0.0; //0.5       //velocity of Y (sideward) direction  // negative is for walk to right
           Vt=0.1;    
       }
          if(turning_time>=30)//12
       {
           Vx=-0.0001; //0.9       //velocity of X (forward) direction from PC (min -1 to max 1) //negative is for walk to forward
           Vy=0.0; //0.5       //velocity of Y (sideward) direction  // negative is for walk to right
           Vt=0.0;    
       }
       if(turning_time>=32)//12
       {
         Kick_Right(0.02);
         while(1);    
       }
*/
       double wave_range=360;  // for determine the value of wave range for walk
       if(Change_State==1) // For Walk in place after kick with just Right leg for one time
       {
         wave_range=180;
       }
       for(double t=0;t<=wave_range;t+=Motion_Resolution)
        {
         //for stablization correction
        
       //  X_offset=Kp_X_Correction*X; 
       //  Pitch_offset=Kp_Pitch_Correction*(-sin(X));  
       //  Roll_offset=Kp_Roll_Correction*(-sin(Y)); 
         
         Angle[Left_Arm_Pitch]=(Kp_Pitch_Correction*(-(X)))*Kp_X_Correction_hand;
         Angle[Right_Arm_Pitch]=(Kp_Pitch_Correction*((X)))*Kp_X_Correction_hand;
          
          //For Hands Balancing By GY80
          if(Y>=2.5*DEG2RAD) // for filtering the hands coming interior in y axis
          {   
         //   Angle[Left_Arm_Roll]=Kp_Roll_Correction*(-(Y))*2.5;  
          }        
          if(Y<=2.5*DEG2RAD) // for filtering the hands coming interior in y axis
          {  
         //   Angle[Right_Arm_Roll]=Kp_Roll_Correction*(-(Y))*2.5;
          }
         
          MCNTTaskCNT++;
          
          L_X=0;
          L_Y=0;
          L_Z=Z_offset;
          L_Roll=0;
          L_Pitch=0;
          L_Yaw=0;
  
          R_X=0;
          R_Y=0;
          R_Z=Z_offset;
          R_Roll=0;
          R_Pitch=0;
          R_Yaw=0;

          if ((t==180)||(t==360)) //double support time  
          {
            vTaskDelay(Double_Support_Sleep*1000);             
          }  
          if ((t==90)||(t==270))  //single support time
          {  
            vTaskDelay(Single_Support_Sleep*1000);     
          }  
          
          L_Z=(t>=180) ?    (Z_offset+(sin((t-180)*DEG_TO_RAD)*RAD_TO_DEG)*Step_Height) : 
                            (Z_offset);   //z axis trajectory for left legs
          if(Vy>0)          // for avoidance of coming the Left leg to intorior side (Because of Mechanical restrictions, Value 60). and there are some equ for become leg open all the time
            L_Y=(t<=180) ?  (Y_offset+(sin((t-180)*DEG_TO_RAD)*RAD_TO_DEG)*Step_Height*(Side_Y_Percent)) :
                            (Y_offset+((cos((t-180)*DEG_TO_RAD)*RAD_TO_DEG)*(Vy)))+((Vy*60))  + ((sin((t-180)*DEG_TO_RAD)*RAD_TO_DEG)*Step_Height*(Side_Y_Percent+1))*1.5; 
          else                 
            L_Y=(t<=180) ?  (Y_offset+(sin((t-180)*DEG_TO_RAD)*RAD_TO_DEG)*Step_Height*(Side_Y_Percent)) :
                            (Y_offset+((cos((t-180)*DEG_TO_RAD)*RAD_TO_DEG)*(Vy)))-((Vy*60)) + ((sin((t-180)*DEG_TO_RAD)*RAD_TO_DEG)*Step_Height*(Side_Y_Percent+1))*1.5;
                            
          L_Roll=(t<=180) ? (Roll_offset+(sin((t-180)*DEG_TO_RAD))*Step_Height*Side_Roll_Perecent) : 
                            (Roll_offset);                               
          L_X=-(X_offset+(cos((t-180)*DEG_TO_RAD)*RAD_TO_DEG)*Vx);   
          L_Yaw=-(Yaw_offset+(cos((t-180)*DEG_TO_RAD))*Vt);
          L_Pitch=Pitch_offset;
          //---------------------------------------------------------------------------
          R_Z=(t<=180) ?    (Z_offset+(sin(t*DEG_TO_RAD)*RAD_TO_DEG)*Step_Height) : 
                            (Z_offset);    //z axis trajectory for right legs
         if(Vy>0)             // for avoidance of coming the Right leg to intorior side (Because of Mechanical restrictions, Value 60). and there are some equ for become leg open all the time
            R_Y=(t>=180) ?  (Y_offset+(sin((t-180)*DEG_TO_RAD)*RAD_TO_DEG)*Step_Height*(-Side_Y_Percent)) :
                            (Y_offset-((cos((t-180)*DEG_TO_RAD)*RAD_TO_DEG)*(-Vy)))+((Vy*60)) -((sin((t-180)*DEG_TO_RAD)*RAD_TO_DEG)*Step_Height*(Side_Y_Percent+1))*1.5;
         else  
            R_Y=(t>=180) ?  (Y_offset+(sin((t-180)*DEG_TO_RAD)*RAD_TO_DEG)*Step_Height*(-Side_Y_Percent)) :
                            (Y_offset-((cos((t-180)*DEG_TO_RAD)*RAD_TO_DEG)*(-Vy)))-((Vy*60)) -((sin((t-180)*DEG_TO_RAD)*RAD_TO_DEG)*Step_Height*(Side_Y_Percent+1))*1.5;                                                                 
                          
          R_Roll=(t>=180) ? (Roll_offset+(sin((t-180)*DEG_TO_RAD))*Step_Height*(Side_Roll_Perecent)) : 
                            (Roll_offset);
          R_X=-(X_offset+(cos(t*DEG_TO_RAD)*RAD_TO_DEG)*Vx);  
          R_Yaw=-(Yaw_offset-(cos(t*DEG_TO_RAD))*Vt);         
          R_Pitch=Pitch_offset;
           
          ik(0.98); //call inverse kinematic for 
          
          vTaskDelay ((100-(Gait_Frequency*100)));  
        }

       if(Change_State==1) // For Exiting From Improving the leg states
       {
           Vx=0;                    
           Vy=0;                     
           Vt=0; 
        
           X_offset=-5;//4;
           Step_Height=0.90;
          
           Change_State=0;
           togglePin(External_LED);
       }   
      }
      else
      {
        //something when not walking
          L_X=0;
          L_Y=0;
          L_Z=Z_offset;
          L_Roll=0;
          L_Pitch=0;
          L_Yaw=0;
  
          R_X=0;
          R_Y=0;
          R_Z=Z_offset;
          R_Roll=0;
          R_Pitch=0;
          R_Yaw=0;
          
          ik(0.6); //call inverse kinematic for         
      }    
      MCNTTaskCNT++;
      vTaskDelayUntil( &xLastWakeTime, xFrequency );  //tread timing    
    }
}

//*********************************************************************************
//the inverse kinematic function for each leg
void ik(double Speed) //, float L_X, float L_Y, float L_Z, float L_Roll, float L_Pitch, float L_Yaw, float R_X, float R_Y, float R_Z, float R_Roll, float R_Pitch, float R_Yaw )
{ 
  L_X=L_X+Left_Leg_X_Offset;
  L_Y=L_Y+Left_Leg_Y_Offset;
  L_Z=L_Z+Left_Leg_Z_Offset;
  
  R_X=R_X+Right_Leg_X_Offset;
  R_Y=R_Y+Right_Leg_Y_Offset;
  R_Z=R_Z+Right_Leg_Z_Offset;

  L_Roll  =L_Roll +Left_Leg_Roll_Offset + Left_Leg_Roll_turning;
  L_Pitch =L_Pitch+Left_Leg_Pitch_Offset;
  L_Yaw   =L_Yaw  +Left_Leg_Yaw_Offset;
  
  R_Roll  =R_Roll +Right_Leg_Roll_Offset + Right_Leg_Roll_turning;
  R_Pitch =R_Pitch+Right_Leg_Pitch_Offset;
  R_Yaw   =R_Yaw  +Right_Leg_Yaw_Offset;
  
  if(Speed<=0) Speed=0.0001;
  if(Speed>=1) Speed=1;
  
  int Knee_Speed=(int)(Speed*1023);
  int J_Speed   =(int)(Knee_Speed/2);
  
  for(byte i=0;i<=18;i++)
  { 
    D_MOVING_SPEED[i]=J_Speed;
  } 
  D_MOVING_SPEED[Left_Knee] =Knee_Speed;
  D_MOVING_SPEED[Right_Knee]=Knee_Speed;
  
  double Tmp_angle=0.0f;
  
  L_Z=leg_length-L_Z;
  R_Z=leg_length-R_Z;
  
  Angle[Left_Hip_Yaw] = -L_Yaw;
  Angle[Right_Hip_Yaw]=  R_Yaw; 
  
  double Tmp_L_X=(L_X*cos(L_Yaw)+L_Y*sin(L_Yaw));
  double Tmp_L_Y=(-L_X*sin(L_Yaw)+L_Y*cos(L_Yaw));
  Tmp_angle=atan2(Tmp_L_Y, L_Z); 
  Angle[Left_Hip_Roll] =Tmp_angle;
  Angle[Left_Foot_Roll]=Angle[Left_Hip_Roll]+L_Roll;
  
  
  double Tmp_R_X=(R_X*cos(R_Yaw)+R_Y*sin(R_Yaw));
  double Tmp_R_Y=(-R_X*sin(R_Yaw)+R_Y*cos(R_Yaw));
  Tmp_angle=atan2(Tmp_R_Y, R_Z); 
  Angle[Right_Hip_Roll]=-Tmp_angle;
  Angle[Right_Foot_Roll]=Angle[Right_Hip_Roll]+R_Roll;
  
  double Tmp_L_Z=sqrt((Tmp_L_Y*Tmp_L_Y)+(L_Z*L_Z)); 
  double L_dfoot=sqrt((Tmp_L_Z*Tmp_L_Z)+(Tmp_L_X*Tmp_L_X));
  double L_alpha=atan2(Tmp_L_X,Tmp_L_Z);
  double L_beta=acos(L_dfoot/(leg_length)); 
  Angle[Left_Hip_Pitch]=(L_alpha+L_beta)+Left_Leg_Hip_Pitch_Offset;
  Angle[Left_Knee]=(-2*L_beta)+Left_Leg_Knee_Offset;   
  Angle[Left_Foot_Pitch]=-(-L_alpha+L_beta)+L_Pitch+Left_Leg_Foot_Pitch_Offset;
  
  double Tmp_R_Z=sqrt((Tmp_R_Y*Tmp_R_Y)+(R_Z*R_Z)); 
  double R_dfoot=sqrt((Tmp_R_Z*Tmp_R_Z)+(Tmp_R_X*Tmp_R_X));
  double R_alpha=atan2(Tmp_R_X,Tmp_R_Z);
  double R_beta=acos(R_dfoot/(leg_length)); 
  Angle[Right_Hip_Pitch]=-(R_alpha+R_beta)+Right_Leg_Hip_Pitch_Offset;
  Angle[Right_Knee]=-(-2*R_beta)+Right_Leg_Knee_Offset;   
  Angle[Right_Foot_Pitch]=(-R_alpha+R_beta)-R_Pitch+Right_Leg_Foot_Pitch_Offset;
  
  /*
  for(byte i=7;i<=17;i+=2)
  {
    SerialUSB.print("j[");SerialUSB.print(i);SerialUSB.print("]=");SerialUSB.print(Angle[i]);SerialUSB.print("\t");
  }
  SerialUSB.println("");
  */
}
