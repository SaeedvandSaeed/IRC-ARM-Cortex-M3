void Kick_Left(double Speed)
{
   //-----------------L0---------------------
   Angle[Left_Arm_Pitch]=0*DEG2RAD;    // negative is for go forward
   Angle[Right_Arm_Pitch]=0*DEG2RAD;   // posetive is for go forward
   
   L_X=0;
   L_Y=0;
   L_Z=Z_offset-30;
   L_Roll=0;
   L_Pitch=0;
   L_Yaw=0;

   R_X=0;
   R_Y=0;
   R_Z=Z_offset-30;
   R_Roll=0;
   R_Pitch=0;
   R_Yaw=0;
        
   ik(Speed); //call inverse kinematic for
   delay(1000);
   //-----------------L1---------------------
   Angle[Left_Arm_Pitch]=15*DEG2RAD;    // negative is for go forward
   Angle[Right_Arm_Pitch]=15*DEG2RAD;   // posetive is for go forward
   L_X=0;
   L_Y=0;
   L_Z=Z_offset-30;
   L_Roll=0.175;
   L_Pitch=0;
   L_Yaw=0;

   R_X=0;
   R_Y=0;
   R_Z=Z_offset-30;
   R_Roll=0.175;//
   R_Pitch=0;
   R_Yaw=0;
        
   ik(Speed); //call inverse kinematic for
   delay(700);
   //-----------------L2---------------------
   Angle[Left_Arm_Pitch]=30*DEG2RAD;    // negative is for go forward
   Angle[Right_Arm_Pitch]=30*DEG2RAD;   // posetive is for go forward
   
   L_X=0;
   L_Y=0;
   L_Z=Z_offset+20;
   L_Roll=0.175;
   L_Pitch=0;
   L_Yaw=0;

   R_X=0;
   R_Y=0;
   R_Z=Z_offset-30;
   R_Roll=0.175;//
   R_Pitch=0;
   R_Yaw=0;
        
   ik(Speed); //call inverse kinematic for
   delay(700);           
   //------------------L3-------------------- (Left Leg Back)
   Angle[Left_Arm_Pitch]=30*DEG2RAD;    // negative is for go forward
   Angle[Right_Arm_Pitch]=30*DEG2RAD;   // posetive is for go forward
     
   L_X=-180;      // negativie is for leg back
   L_Y=50;        // positive is for leg open
   L_Z=Z_offset+70;
   L_Roll=0.05;   // positive is for interior side up
   L_Pitch=0.2;   // positive is for front side of foot up
   L_Yaw=0;

   R_X=0;
   R_Y=0;         // negative is for leg open
   R_Z=Z_offset-30;
   R_Roll=0.175;
   R_Pitch=-0.01;//-0.04; // negative is for front side of foot up
   R_Yaw=0;
        
   ik(Speed);     //call inverse kinematic for
   delay(2000);
   //-----------------L4--------------------- (Kick)
   Angle[Left_Arm_Pitch]=-20*DEG2RAD;    // negative is for go forward
   Angle[Right_Arm_Pitch]=-20*DEG2RAD;   // posetive is for go forward
   
   L_X=220;
   L_Y=60;
   L_Z=Z_offset+70;
   L_Roll=0.05;
   L_Pitch=-0.4;
   L_Yaw=0;

   R_X=0;
   R_Y=0;
   R_Z=Z_offset-30;
   R_Roll=0.175;
   R_Pitch=0.08;//0.05;
   R_Yaw=0;
        
   ik(0.6); //call inverse kinematic for
   delay(2100);
   //-----------------L5---------------------(2)
   Angle[Left_Arm_Pitch]=0*DEG2RAD;    // negative is for go forward
   Angle[Right_Arm_Pitch]=0*DEG2RAD;   // posetive is for go forward
   
   L_X=0;
   L_Y=59;
   L_Z=Z_offset+20;
   L_Roll=0.05;
   L_Pitch=0;
   L_Yaw=0;

   R_X=0;
   R_Y=0;
   R_Z=Z_offset-30;
   R_Roll=0.175;//
   R_Pitch=0.05;//0.03;
   R_Yaw=0;  
        
   ik(Speed); //call inverse kinematic for
   delay(1000);     
   //-----------------L6---------------------(1)
   Angle[Left_Arm_Pitch]=0*DEG2RAD;    // negative is for go forward
   Angle[Right_Arm_Pitch]=0*DEG2RAD;   // posetive is for go forward
   
   L_X=0;
   L_Y=40;
   L_Z=Z_offset-30;
   L_Roll=0.175;
   L_Pitch=0;
   L_Yaw=0;

   R_X=0;
   R_Y=0;
   R_Z=Z_offset-30;
   R_Roll=0.175;
   R_Pitch=0;
   R_Yaw=0;

   ik(Speed); //call inverse kinematic for
   delay(1000);
   //-----------------L7---------------------(0)
   L_X=0;
   L_Y=30;
   L_Z=Z_offset-30;
   L_Roll=0;
   L_Pitch=0;
   L_Yaw=0;

   R_X=0;
   R_Y=0;
   R_Z=Z_offset-30;
   R_Roll=0;
   R_Pitch=0;
   R_Yaw=0;
        
   ik(Speed); //call inverse kinematic for
   delay(1000);
  //-----------------L8---------------------(Normal mode)
  L_X=0;
  L_Y=0;
  L_Z=Z_offset;
  L_Roll=0;
  L_Pitch=0;
  L_Yaw=0;

  R_X=0;
  R_Y=-0;
  R_Z=Z_offset;
  R_Roll=0;
  R_Pitch=0;
  R_Yaw=0;
   
  ik(0.04); //call inverse kinematic for 
  
  vTaskDelay(1000);  
}
//********************************************************************************************************************************
//********************************************************************************************************************************
//********************************************************************************************************************************
void Kick_Right(double Speed)
{
    //-----------------R0---------------------
   Angle[Left_Arm_Pitch]=0*DEG2RAD;    // negative is for go forward
   Angle[Right_Arm_Pitch]=0*DEG2RAD;   // posetive is for go forward
   
   L_X=0;
   L_Y=0;
   L_Z=Z_offset-30;
   L_Roll=0;
   L_Pitch=0;
   L_Yaw=0;

   R_X=0;
   R_Y=0;
   R_Z=Z_offset-30;
   R_Roll=0;
   R_Pitch=0;
   R_Yaw=0;
        
   ik(Speed); //call inverse kinematic for
   delay(1000);
   //-----------------R1---------------------
   L_X=0;
   L_Y=0;
   L_Z=Z_offset-30;
   L_Roll=-0.168;
   L_Pitch=0;
   L_Yaw=0;

   R_X=0;
   R_Y=0;
   R_Z=Z_offset-35;
   R_Roll=-0.25;
   R_Pitch=0;
   R_Yaw=0;
        
   ik(Speed); //call inverse kinematic for
   delay(1000);
   //-----------------R2---------------------
   Angle[Left_Arm_Pitch]=30*DEG2RAD;    // negative is for go forward
   Angle[Right_Arm_Pitch]=30*DEG2RAD;   // posetive is for go forward
   
   L_X=0;
   L_Y=0;
   L_Z=Z_offset-30;
   L_Roll=-0.168;
   L_Pitch=0;
   L_Yaw=0;

   R_X=0;
   R_Y=0;
   R_Z=Z_offset+20;
   R_Roll=0.05;
   R_Pitch=0;
   R_Yaw=0;
        
   ik(Speed); //call inverse kinematic for
   delay(1000);    
   //------------------R3-------------------- (Left Leg Back)
   Angle[Left_Arm_Pitch]=30*DEG2RAD;    // negative is for go forward
   Angle[Right_Arm_Pitch]=30*DEG2RAD;   // posetive is for go forward
     
   L_X=0;      // negativie is for leg back
   L_Y=0;        // positive is for leg open
   L_Z=Z_offset-30;
   L_Roll=-0.168;   // positive is for interior side up
   L_Pitch=-0.0;   // positive is for front side of foot down
   L_Yaw=0;

   R_X=-180;
   R_Y=60;         // positive is for leg open
   R_Z=Z_offset+70;
   R_Roll=0.05;
   R_Pitch=0.2; // negative is for front side of foot up
   R_Yaw=0;
        
   ik(Speed);     //call inverse kinematic for
   delay(1500);
   //-----------------R4--------------------- (Kick)
   Angle[Left_Arm_Pitch]=-20*DEG2RAD;    // negative is for go forward
   Angle[Right_Arm_Pitch]=-20*DEG2RAD;   // posetive is for go forward
   
   L_X=0;      // negativie is for leg back
   L_Y=0;        // positive is for leg open
   L_Z=Z_offset-30;
   L_Roll=-0.168;   // positive is for interior side up
   L_Pitch=0.07;   // positive is for front side of foot down
   L_Yaw=0;

   R_X=220;
   R_Y=60;
   R_Z=Z_offset+70;
   R_Roll=0.05;
   R_Pitch=-0.4;
   R_Yaw=0;
   
   ik(0.6); //call inverse kinematic for
   delay(2100);
   //-----------------R5---------------------(2)
   Angle[Left_Arm_Pitch]=0*DEG2RAD;    // negative is for go forward
   Angle[Right_Arm_Pitch]=0*DEG2RAD;   // posetive is for go forward
   
   L_X=0;
   L_Y=0;
   L_Z=Z_offset-30;
   L_Roll=-0.168;
   L_Pitch=0.05;
   L_Yaw=0;

   R_X=0;
   R_Y=59;
   R_Z=Z_offset+30;
   R_Roll=0.05;
   R_Pitch=0;
   R_Yaw=0;
        
   ik(Speed); //call inverse kinematic for
   delay(1000);  
   //-----------------R6---------------------(1)
   Angle[Left_Arm_Pitch]=0*DEG2RAD;    // negative is for go forward
   Angle[Right_Arm_Pitch]=0*DEG2RAD;   // posetive is for go forward
   
   L_X=0;
   L_Y=0;
   L_Z=Z_offset-30;
   L_Roll=-0.168;
   L_Pitch=0.01;
   L_Yaw=0;

   R_X=0;
   R_Y=40;
   R_Z=Z_offset-25;
   R_Roll=-0.195;
   R_Pitch=0;
   R_Yaw=0;

   ik(Speed); //call inverse kinematic for
   delay(1000);
   //-----------------R7---------------------(0)
   L_X=0;
   L_Y=0;
   L_Z=Z_offset-30;
   L_Roll=0;
   L_Pitch=0;
   L_Yaw=0;

   R_X=0;
   R_Y=25;
   R_Z=Z_offset-30;
   R_Roll=0;
   R_Pitch=0;
   R_Yaw=0;
        
   ik(Speed); //call inverse kinematic for
   delay(1000);
  //-----------------R8---------------------(Normal mode)
  L_X=0;
  L_Y=0;
  L_Z=Z_offset;
  L_Roll=0;
  L_Pitch=0;
  L_Yaw=0;

  R_X=0;
  R_Y=-0;
  R_Z=Z_offset;
  R_Roll=0;
  R_Pitch=0;
  R_Yaw=0;
  
  ik(0.04); //call inverse kinematic for 
  
  vTaskDelay(1000);  
}
//**************************************************************************************
//********************************************************************************************************************************
//********************************************************************************************************************************
//********************************************************************************************************************************
