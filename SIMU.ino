AccelADXL345 Accel;
GyroL3G4200D Gyro;
CompassHMC5883L Compass;

Kalman kalmanX; // Create the Kalman instances
Kalman kalmanY;
Kalman kalmanZ;

void vSIMUTask( void *pvParameters )
{
  portTickType xLastWakeTime;
  const portTickType xFrequency =10; // shows frequency of this task (10 means 100Hz)
  xLastWakeTime = xTaskGetTickCount ();
  
  Accel.init();
  Gyro.init(2000);
  Compass.init();
  
  kalmanX.setAngle(0.0f); // Set starting angle
  kalmanY.setAngle(0.0f);
  kalmanZ.setAngle(0.0f);
  
  float PrevTime=0.0f, dt=0.0f;
  float Angle_X=0.0f, Angle_Y=0.0f, Angle_Z=0.0f;

  for(;;)
  { 
    if ((SIMUTaskCNT==1) || (SIMUTaskCNT==10))
    {
      ////////////////////togglePin(BOARD_LED_PIN);
    }
    
    vTaskSuspendAll();   //Suspend all other tasks
    {
      Accel.ReadXYZ();
      Gyro.ReadXYZ();
      Compass.ReadXYZ();
      dt = (float)(micros() - PrevTime) / 1000000.0f; // Calculate delta time
      PrevTime = micros();    
    }
    xTaskResumeAll();    //Resume all other tasks
    
    //Gyro_X_Integral += (float)(Gyro.getX()*dt);
    //Gyro_Y_Integral += (float)(Gyro.getY()*dt);
    //Gyro_Z_Integral += (float)(Gyro.getZ()*dt);
    
    Angle_X = atan(Accel.getY() / sqrt((Accel.getX() * Accel.getX()) + (Accel.getZ() * Accel.getZ()))) * RAD_TO_DEG; //calculate roll angle from accelorometer sensor
    Angle_Y = atan2(-Accel.getX(), Accel.getZ()) * RAD_TO_DEG; //calculate pich angle from accelorometer
    Angle_Z = atan2(Compass.getX(), Compass.getZ()) * RAD_TO_DEG; //calculate pich angle from accelorometer
    
    X = kalmanX.getAngle(Angle_X, Gyro.getX(), dt); // Calculate the angle using a Kalman filter
    Y = kalmanY.getAngle(Angle_Y, Gyro.getY(), dt);
    Z = kalmanZ.getAngle(Angle_Z, Gyro.getZ(), dt);
    
       //   SerialUSB.print("Raw_z_1= ");
  //  SerialUSB.print(Compass.getX()); SerialUSB.print("\t\t\n");
    
    /*
    SerialUSB.print("X= ");
    SerialUSB.print(X); SerialUSB.print("\t\t ");
    
    SerialUSB.print("Y= ");
    SerialUSB.print(Y); SerialUSB.print("\t\t ");
    
    SerialUSB.print("Z= ");
    SerialUSB.print(Z); SerialUSB.print("\t\t\n");
    */

          
    /*
    //accelorometer test
    SerialUSB.print("x= ");
    SerialUSB.print(Accel.getX()); SerialUSB.print("\t ");
    
    SerialUSB.print("\t\t y= ");
    SerialUSB.print(Accel.getY());SerialUSB.print("\t ");
    
    SerialUSB.print("\t\t z= ");
    SerialUSB.print(Accel.getZ());SerialUSB.println("\t ");
    */
    
    /*
    //gyro test
    SerialUSB.print("x= ");
    SerialUSB.print(Gyro.getX()); SerialUSB.print("\t ");
    
    SerialUSB.print("\t\t y= ");
    SerialUSB.print(Gyro.getY());SerialUSB.print("\t ");
    
    SerialUSB.print("\t\t z= ");
    SerialUSB.print(Gyro.getZ());SerialUSB.println("\t ");
    */
    
    /*
    //compass test
    SerialUSB.print("x= ");
    SerialUSB.print(Compass.getX()); SerialUSB.print("\t ");
    
    SerialUSB.print("\t\t y= ");
    SerialUSB.print(Compass.getY());SerialUSB.print("\t ");
    
    SerialUSB.print("\t\t z= ");
    SerialUSB.print(Compass.getZ());SerialUSB.println("\t ");
    */
    
    SIMUTaskCNT++;
    vTaskDelayUntil( &xLastWakeTime, xFrequency );  
  }

}




