//vDXLRTask
void vDXLRTask( void *pvParameters )
{ 
    //Deffine local varible in this task
    //-------------------------------------------------------
    portTickType xLastWakeTime;
    const portTickType xFrequency = 100; 
    xLastWakeTime = xTaskGetTickCount ();    
    //--------------------------------------------------------   
    for( ;; )
    {         
      DXLRTaskCNT++;
      vTaskDelayUntil( &xLastWakeTime, xFrequency );      
    }
}
