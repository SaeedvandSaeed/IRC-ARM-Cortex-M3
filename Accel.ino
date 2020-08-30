#define ADXL345_Address         (0x53)     // ADXL345 device address
#define ADXL345_POWER_CTL       (0x2d)
#define ADXL345_DATA_FORMAT     (0x31)

#define ADXL345_DATAX0          (0x32)
#define ADXL345_DATAX1          (0x33)
#define ADXL345_DATAY0          (0x34)
#define ADXL345_DATAY1          (0x35)
#define ADXL345_DATAZ0          (0x36)
#define ADXL345_DATAZ1          (0x37)

class AccelADXL345 
{
  public:
    AccelADXL345() 
    {
      X=Y=Z=0.0f;
      Raw_x=Raw_y=Raw_z=0.0f;
    };
    
    void init()
    {
          ADXL345_setRangeSetting(16);   //set range to +- 16g for gravity
          i2c_writeRegister(ADXL345_Address,ADXL345_POWER_CTL, 0);      
          i2c_writeRegister(ADXL345_Address,ADXL345_POWER_CTL, 16);
          i2c_writeRegister(ADXL345_Address,ADXL345_POWER_CTL, 8);
    }
    
    /*
    * The angle should be in degrees and the rate should be in degrees per second and the delta time in seconds
    */
    float _getRawX() 
    {
          return (float)((signed short)(((byte) i2c_readRegister(ADXL345_Address, ADXL345_DATAX1)) << 8) | ((byte) i2c_readRegister(ADXL345_Address, ADXL345_DATAX0)));
    };
    
    /*
    * The angle should be in degrees and the rate should be in degrees per second and the delta time in seconds
    */
    float _getRawY() 
    {
          return (float)((signed short)(((byte) i2c_readRegister(ADXL345_Address, ADXL345_DATAY1)) << 8) | ((byte) i2c_readRegister(ADXL345_Address, ADXL345_DATAY0)));
    };
    
    /*
    * The angle should be in degrees and the rate should be in degrees per second and the delta time in seconds
    */
    float _getRawZ() 
    {
          return (float)((signed short)(((byte) i2c_readRegister(ADXL345_Address, ADXL345_DATAZ1)) << 8) | ((byte) i2c_readRegister(ADXL345_Address, ADXL345_DATAZ0)));
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
    
    
    /*
    * Sets the range setting, possible values are: 2, 4, 8, 16
    */
    void ADXL345_setRangeSetting(int val) 
    {
	byte _s;
	byte _b;	
	switch (val) 
        {
		case 2:  
			_s = B00000000; 
			break;
		case 4:  
			_s = B00000001; 
			break;
		case 8:  
			_s = B00000010; 
			break;
		case 16: 
			_s = B00000011; 
			break;
		default: 
			_s = B00000000;
	}
	_b= (byte) i2c_readRegister(ADXL345_Address,ADXL345_DATA_FORMAT);
	_s |= (_b & B11101100);
	i2c_writeRegister(ADXL345_Address,ADXL345_DATA_FORMAT, _s);
    }

  private:
    float X,Y,Z;
    float Raw_x,Raw_y,Raw_z;
};







