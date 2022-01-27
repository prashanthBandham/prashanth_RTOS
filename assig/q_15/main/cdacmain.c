#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>


TaskHandle_t xHandle_1;
TaskHandle_t xHandle_2;


void sensortask_1(void *pvparameters)
{
    int var=0;
    while(1)
    {
        printf("SENSOR TASK  RUNNING: \n");
        var++;
        
        if(var==12)
        {
              vTaskResume(xHandle_2); 
              var=0;  
        }
        vTaskDelay(100/ portTICK_PERIOD_MS);
    }
}
void Alarmtask_1(void *pvparameters)
{
    int count=0; 
    while(1)
    {
        
        printf("ALARM TASK \n");
        
        count++;
        if(count==12)
        {
            vTaskSuspend(NULL);
            printf("ALARM TASK SUSPENDED AFTER 1200ms\n");
            count=0;
        }
        vTaskDelay(100/ portTICK_PERIOD_MS);
    }
}
void app_main()
{
    BaseType_t result;
    
    result=xTaskCreate(sensortask_1,"sensortask_1",2048,NULL,5,&xHandle_1);

    if(result==pdPASS)
    {
        printf("sensortask created\n");
    }
    result=xTaskCreate(Alarmtask_1,"Alarmtask_1",2048,NULL,5,&xHandle_2);

    if(result==pdPASS)
    {
        printf("Alarmtask created\n");
    }
}
