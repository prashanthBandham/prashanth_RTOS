#include <stdio.h>
#include <pthread.h>


void *greet_thread(void *arg)
 {

printf("%p Thread \n", arg);
return 0;
}


int app_main()
{
    pthread_t byeID;
    printf("Hello pthread\n");
    pthread_create(&byeID, NULL, greet_thread,"Bye");
    pthread_join(byeID, NULL);
      return 0;
}


