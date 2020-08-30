//vROBOTask
void vROBOTask( void *pvParameters )
{ 
    //Deffine local varible in this task
    //-------------------------------------------------------
    portTickType xLastWakeTime;
    const portTickType xFrequency = 100; 
    xLastWakeTime = xTaskGetTickCount ();    
    //--------------------------------------------------------   
    for( ;; )
    { 
      /*
      SerialUSB.print("X= ");
      SerialUSB.print(X); SerialUSB.print("\t");
    
      SerialUSB.print("Y= ");
      SerialUSB.print(Y); SerialUSB.print("\t");
    
      SerialUSB.print("Z= ");
      SerialUSB.print(Z); SerialUSB.print("\t");
      
    
      SerialUSB.print("DXLW:");SerialUSB.print(DXLWTaskHz);SerialUSB.print("\t");
      //SerialUSB.print("DXLR:");SerialUSB.print(DXLRTaskHz);SerialUSB.print("\t");
      SerialUSB.print("SIMU:");SerialUSB.print(SIMUTaskHz);SerialUSB.print("\t");      
      SerialUSB.print("MCNT:");SerialUSB.print(MCNTTaskHz);SerialUSB.print("\t");
      SerialUSB.print("ROBO:");SerialUSB.print(ROBOTaskHz);SerialUSB.print("\t");
      //SerialUSB.print("REGU:");SerialUSB.print(REGUTaskHz);SerialUSB.print("\t");
      
      SerialUSB.println("");
      */
      
      ROBOTaskCNT++;
      vTaskDelayUntil( &xLastWakeTime, xFrequency );      
    }
}
