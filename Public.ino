void RTC_Setup_Timer(long Period)
{
  Timer.pause();                                  // Pause the timer while we're configuring it
  Timer.setPeriod(Period);                // Set up period in microseconds
  Timer.setMode(TIMER_CH1, TIMER_OUTPUT_COMPARE); // Set up an interrupt on channel 1
  Timer.setCompare(TIMER_CH1, 1);                 // Interrupt 1 count after each update
  Timer.attachInterrupt(TIMER_CH1, RTC_INT);      // atach interrupt function to timer
  Timer.refresh();                                // Refresh the timer's count, prescale, and overflow
  Timer.resume(); 
}
//*************************************************************************************************************
void usbInterrupt(byte* buffer, byte nCount)
{
  //get data from PC For Controlling Parts
  if((buffer[0]==88)&&(buffer[1]==88)&&(buffer[2]==88))
  {    
      walking_state=buffer[3];           // (0= No Action, 1= In Place Walking, 2= Forward Walking)
      walking_speed=buffer[4];           // (1 to 5 is for walking Speed in which, its converting to 1/10 in -Vx)    
      Rotate_Direction=buffer[5];        // (0= No Turning, 1= Turn to Left, 2= Turn to Right)
      Rotate_Speed=buffer[6];            // (1 to 5, its for turning speed, its converting to 1/10 in -Vt)   
      Kicking_instructions=buffer[7];    // (0= No Kicking, 1 Kick left, 2= Kick Right)
      Side_Walk_Instructions=buffer[8];  // (0= No Action, 1 Go to Left, 2= Go to Right)      
      Other_Instructions=buffer[9];      // This is Reserve data For run Another instructions
      //---------------------------------------------------------------------------------------------------------
      togglePin(BOARD_LED_PIN);
      //---------------Walk-------------------
      if(walking_state==0) 
      { 
        Vx=0;
      }
      else if(walking_state==1) 
      {
        // It's for walking in place situation       
        Vx=0.33;                    
        Vy=0.0;                     
        Vt=0.0; 
        
        X_offset=0;
        Step_Height=0.55;
      }
      else if(walking_state==2) 
      {
        Step_Height=0.9;
        switch (walking_speed) // It's for walking to forward equation by income speed
        {
         case 1:
          {
             Vx=-0.1;
             break;
          } 
         case 2:
          {
             Vx=-0.2;
             break;
          } 
         case 3:
          {
             Vx=-0.3;
             break;
          } 
         case 4:
          {
             Vx=-0.4;
             break;
          } 
         case 5:
          {
             Vx=-0.5;
             break;
          }
         case 6:
          {
             Vx=-0.6;
             break;
          }  
         default:
          {
            break;
          }
        }
      }
      //----------Rotate------------
      if(Rotate_Direction==0) 
      { 
        Vt=0;   
        if((walking_state!=1) && (walking_state!=2))
          Vx=0;
      }
      else if(Rotate_Direction==1) 
      { 
        if((walking_state!=1) && (walking_state!=2))
          Vx=0.33;
        switch (Rotate_Speed) // It's for walking to forward equation by income speed
        {
         case 1:
          {
             Vt=0.05;
             break;
          } 
         case 2:
          {
             Vt=0.06;
             break;
          } 
         case 3:
          {
             Vt=0.07;
             break;
          } 
         case 4:
          {
             Vt=0.08;
             break;
          } 
         case 5:
          {
             Vt=0.09;
             break;
          } 
          case 6:
          {
             Vt=0.1;
             break;
          } 
          case 10:  //in this stage we use some smnaller scales for more precition in walking rotation, (this is not ordenal)
          {
             Vt=0.025;
             break;
          } 
         default:
          {
            break;
          }
        }
      }
      else if(Rotate_Direction==2) 
      {
        if((walking_state!=1) && (walking_state!=2))
          Vx=0;
        switch (Rotate_Speed) // It's for walking to forward equation by income speed
        {
         case 1:
          {
             Vt=-0.05;
             break;
          } 
         case 2:
          {
             Vt=-0.06;
             break;
          } 
         case 3:
          {
             Vt=-0.07;
             break;
          } 
         case 4:
          {
             Vt=-0.08;
             break;
          } 
         case 5:
          {
             Vt=-0.09;
             break;
          } 
          case 6:
          {
             Vt=-0.1;
             break;
          } 
          case 10:  //in this stage we use some smnaller scales for more precition in walking rotation, (this is not ordenal)
          {
             Vt=-0.025;
             break;
          } 
         default:
          {
            break;
          }
        }
      }
      //-------------------------------------
      //---------------Kick------------------
      // Its Set in MCNT
      //--------------Side Walk-------------
      if(Side_Walk_Instructions==0) 
      { 
       // Vy=0;
      }
      else if(Side_Walk_Instructions==1) 
      {
       // Vy=0.0;  // It's for go to Left
      }
      else if(Side_Walk_Instructions==2) 
      {
      //  Vy=-0.0; // It's for Rotate to Right
      }
      //------------------------------------
      //togglePin(BOARD_LED_PIN);
      
      //data is ready now
      /*  for(int i=0;i<=Side_Walk_Instructions;i++)
      {
        togglePin(BOARD_LED_PIN);
        delay(100);
      }
      */    
  }
  //request Data From Pc
  if((buffer[0]==75)&&(buffer[1]==75)&&(buffer[2]==75))
  {
    byte Data[12];
    Data[0]=65;
    Data[1]=65;
   
    //-----------------Sending X------------------------
    if(X>=0)// this is for posetive values
    {
      Data[2]=_LOBYTE((int)(X)*100);
      Data[3]=_HIBYTE((int)(X)*100);
      Data[4]=0;
    }
    else// this is for negetive values
    {
      Data[2]=_LOBYTE((int)(-X)*100);
      Data[3]=_HIBYTE((int)(-X)*100);
      Data[4]=1;
    }
    //-----------------Sending Y------------------------
    if(Y>=0)// this is for posetive values
    {
      Data[5]=_LOBYTE((int)(Y)*100);
      Data[6]=_HIBYTE((int)(Y)*100);
      Data[7]=0;
    }
    else// this is for negetive values
    {
      Data[5]=_LOBYTE((int)(-Y)*100);
      Data[6]=_HIBYTE((int)(-Y)*100);
      Data[7]=1;
    }
    //-----------------Sending Z------------------------
    if(Z>=0)// this is for posetive values
    {
      Data[8]=_LOBYTE((int)(Z)*100);
      Data[9]=_HIBYTE((int)(Z)*100);
      Data[10]=0;
    }
    else// this is for negetive values
    {
      Data[8]=_LOBYTE((int)(-Z)*100);
      Data[9]=_HIBYTE((int)(-Z)*100);
      Data[10]=1;
    }
   // Data[5]=(byte)(Z/10000)*100;;
    //Data[6]=18;
    //Data[7]=20;
    //Data[8]=22;
   // Data[9]=24;
    
    for(byte i=0;i<=11;i++)
      SerialUSB.print((char)Data[i]);
  }
  
}
//*************************************************************************************************************
// Hardware interrupt for real time clock
void RTC_INT(void) 
{  
  //calculate internal task frequency    
  DXLWTaskHz = DXLWTaskCNT;
  DXLWTaskCNT=0;
  
  DXLRTaskHz = DXLRTaskCNT;
  DXLRTaskCNT=0;
      
  SIMUTaskHz = SIMUTaskCNT;
  SIMUTaskCNT=0;
  
  MCNTTaskHz = MCNTTaskCNT;
  MCNTTaskCNT=0;
      
  ROBOTaskHz = ROBOTaskCNT;
  ROBOTaskCNT=0;
  
  REGUTaskHz = REGUTaskCNT;
  REGUTaskCNT=0;
  
  //this interrupt will heald in every 1 sec
}
//*************************************************************************************************************
//serial port interrupt for ttl communication
void Half_Duplex_serial_Interrupt(byte buffer)
{       
}
//*************************************************************************************************************
// Write register to i2c device with specific i2c
void i2c_writeRegister(byte deviceAddress, byte address, byte val) 
{
    Wire.beginTransmission(deviceAddress); // start transmission to device 
    Wire.write(address);       // send register address
    Wire.write(val);           // send value to write
    Wire.endTransmission();    // end transmission
}
//*************************************************************************************************************
//Read a byte from i2c device with specific address
byte i2c_readRegister(byte deviceAddress, byte address)
{
    Wire.beginTransmission(deviceAddress);
    Wire.write(address);                 // register to read
    Wire.endTransmission();
    Wire.requestFrom(deviceAddress, 2);  // read a byte
    while(!Wire.available()) { } //wait until ready
    return (byte)Wire.read();
}

