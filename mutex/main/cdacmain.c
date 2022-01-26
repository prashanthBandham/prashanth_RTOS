#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<freertos/semphr.h>

  SemaphoreHandle_t sem;
  BaseType_t result;
  TaskHandle_t xHandle,xHandle2;

void sensor_task(void *pv)
 {
   int sensor_data =0;
   while(1){

  sensor_data++;
  printf("sensor task:%d\n",sensor_data); 
  vTaskDelay(1000/portTICK_PERIOD_MS);

    if(sensor_data==10){
  
       xSemaphoreGive(sem);
    }
   }
}

void processing_task(void *pv)
 {
   int recieved_data=0;
  xSemaphoreTake(sem,portMAX_DELAY);
   printf("data is:%d\n",recieved_data); 
   vTaskDelay(1000/portTICK_PERIOD_MS);
} 

int app_main()
{

    sem =xSemaphoreCreateMutex();
    printf("Hello pthread\n");  
    result = xTaskCreate(sensor_task,"Sensor",2048,NULL,5,&xHandle);   
    result = xTaskCreate(processing_task,"processing_task",2048,NULL,4,&xHandle2);
    xSemaphoreTake(sem,portMAX_DELAY);

      return 0;
}
