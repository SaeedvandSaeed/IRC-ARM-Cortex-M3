#define HMC5883L_Address        (0x1E)     // Address of i2c Device Magnometer HMC5883
#define HMC5883L_Config         (0x02)

#define HMC5883L_DATAX0         (0x03)
#define HMC5883L_DATAX1         (0x04)
#define HMC5883L_DATAY0         (0x05)
#define HMC5883L_DATAY1         (0x06)
#define HMC5883L_DATAZ0         (0x07)
#define HMC5883L_DATAZ1         (0x08)

class CompassHMC5883L 
{
  public:
    CompassHMC5883L() 
    {
      X=Y=Z=0.0f;
      Raw_x=Raw_y=Raw_z=0.0f;
    };
    
    void init()
    {
        i2c_writeRegister(HMC5883L_Address, HMC5883L_Config, 0x00);
    }
    
    /*
    * The angle should be in degrees and the rate should be in degrees per second and the delta time in seconds
    */
    float _getRawX() 
    {
        return (float)((signed short)(((byte) i2c_readRegister(HMC5883L_Address, HMC5883L_DATAX0)) << 8) | ((byte) i2c_readRegister(HMC5883L_Address, HMC5883L_DATAX1)));
    };
    
    /*
    * The angle should be in degrees and the rate should be in degrees per second and the delta time in seconds
    */
    float _getRawY() 
    {
          return (float)((signed short)(((byte) i2c_readRegister(HMC5883L_Address, HMC5883L_DATAY0)) << 8) | ((byte) i2c_readRegister(HMC5883L_Address, HMC5883L_DATAY1)));
    };
    
    /*
    * The angle should be in degrees and the rate should be in degrees per second and the delta time in seconds
    */
    float _getRawZ() 
    {
        return (float)((signed short)(((byte) i2c_readRegister(HMC5883L_Address, HMC5883L_DATAZ0)) << 8) | ((byte) i2c_readRegister(HMC5883L_Address, HMC5883L_DATAZ1)));
    };
    
    void ReadXYZ()
    { 
          Raw_x=_getRawX();
          Raw_y=_getRawY();
          Raw_z=_getRawZ();
          
          float norm = (float) sqrt((Raw_x*Raw_x) + (Raw_y*Raw_y) + (Raw_z*Raw_z)); 
      
          X =(float)(Raw_x / norm);
          Y =(float)(Raw_y / norm);
          Z =(float)(Raw_z / norm);  
    }
    
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
};







