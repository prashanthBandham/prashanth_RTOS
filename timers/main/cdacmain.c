#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<freertos/timers.h>


TimerHandle_t motor_handle;

void MoterOff(TimerHandle_t xtimer)
{
  printf("Timer is off");
}

int app_main()
{
  motor_handle = xTimerCreate("MotorOFF", pdMS_TO_TICKS(2000),pdTRUE, NULL,MoterOff);
    xTimerStart(motor_handle,0); 
while(1){
  vTaskDelay(1000/portTICK_PERIOD_MS);
}
      return 0;
}
