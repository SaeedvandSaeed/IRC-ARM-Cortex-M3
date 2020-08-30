//Internal register of Gyro sensor L3G4200D
#define L3G4200D_Address        (105)      // I2C address of the L3G4200D
#define CTRL_REG1               (0x20)
#define CTRL_REG2               (0x21)
#define CTRL_REG3               (0x22)
#define CTRL_REG4               (0x23)
#define CTRL_REG5               (0x24)

class GyroL3G4200D 
{
  public:
    GyroL3G4200D() 
    {
      X=Y=Z=0.0f;
      Raw_x=Raw_y=Raw_z=0.0f;
      Gyr_x_Drift=0.0f;
      Gyr_y_Drift=0.0f;
      Gyr_z_Drift=0.0f;
    };
    
    void init(int scale)
    {
      // Enable x, y, z and turn off power down:
      i2c_writeRegister(L3G4200D_Address, CTRL_REG1, 0b11111111); //for 800 Hz and 110 cut off

      // If you'd like to adjust/use the HPF, you can edit the line below to configure CTRL_REG2:
      i2c_writeRegister(L3G4200D_Address, CTRL_REG2, 0b00000000);

      // Configure CTRL_REG3 to generate data ready interrupt on INT2
      // No interrupts used on INT1, if you'd like to configure INT1
      // or INT2 otherwise, consult the datasheet:
      i2c_writeRegister(L3G4200D_Address, CTRL_REG3, 0b00001000);

      // CTRL_REG4 controls the full-scale range, among other things:
      if(scale == 250)
      {
        i2c_writeRegister(L3G4200D_Address, CTRL_REG4, 0b00000000);
      }
      else if(scale == 500)
      {
        i2c_writeRegister(L3G4200D_Address, CTRL_REG4, 0b00010000);
      }
      else //2000 dps
      {
        i2c_writeRegister(L3G4200D_Address, CTRL_REG4, 0b00110000);
      }

      // CTRL_REG5 controls high-pass filtering of outputs, use it
      i2c_writeRegister(L3G4200D_Address, CTRL_REG5, 0b00000000);
      
      initDrift(1);
    }
    
    /*
    * calculate gyro drifft
    */
    void initDrift(int Filter_Sampling)
    {
      for(unsigned long i=0;i<=(Filter_Sampling*1000);i++)
      {  
         Gyr_x_Drift += (float) ((1.0f/(Filter_Sampling*1000))*_getRawX()); 
         Gyr_y_Drift += (float) ((1.0f/(Filter_Sampling*1000))*_getRawY());
         Gyr_z_Drift += (float) ((1.0f/(Filter_Sampling*1000))*_getRawZ());
         togglePin(BOARD_LED_PIN);
         delay(1);
      }
      digitalWrite(BOARD_LED_PIN, HIGH);
    }

    /*
    * The angle should be in degrees and the rate should be in degrees per second and the delta time in seconds
    */
    float _getRawX() 
    {
        return (float)((signed short)(((byte) i2c_readRegister(L3G4200D_Address, 0x29)) << 8) | ((byte) i2c_readRegister(L3G4200D_Address, 0x28)));     
    };
    
    /*
    * The angle should be in degrees and the rate should be in degrees per second and the delta time in seconds
    */
    float _getRawY() 
    {
          return (float)((signed short)(((byte) i2c_readRegister(L3G4200D_Address, 0x2B)) << 8) | ((byte) i2c_readRegister(L3G4200D_Address, 0x2A)));    
    };
    
    /*
    * The angle should be in degrees and the rate should be in degrees per second and the delta time in seconds
    */
    float _getRawZ() 
    {
          return (float)((signed short)(((byte) i2c_readRegister(L3G4200D_Address, 0x2D)) << 8) | ((byte) i2c_readRegister(L3G4200D_Address, 0x2C)));
    };
    
    void ReadXYZ()
    { 
          Raw_x=_getRawX();
          Raw_y=_getRawY();
          Raw_z=_getRawZ(); 
          
          X=(float)(((Raw_x-Gyr_x_Drift)*70.0f)/1000.0f);
          Y=(float)(((Raw_y-Gyr_y_Drift)*70.0f)/1000.0f);
          Z=(float)(((Raw_z-Gyr_z_Drift)*70.0f)/1000.0f);  
    }
   
    //return dps (degree per second)
    float getX()
    {
      return (float)X;
    }
    
    float getY()
    {
      return (float)Y;
    }
    
    float getZ()
    {
      return (float)Z;
    }
    
    
    float getRawX()
    {
      return (float)Raw_x;
    }
    
    float getRawY()
    {
      return (float)Raw_y;
    }
    
    float getRawZ()
    {
      return (float)Raw_z;
    }
    
  private:
    float X,Y,Z;
    float Raw_x,Raw_y,Raw_z;
    
    float Gyr_x_Drift;
    float Gyr_y_Drift;
    float Gyr_z_Drift;
};







