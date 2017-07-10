#include <stdio.h>
#include <pthread.h>
void threads(void)
{
    int i;
    for(i=0;i<3;i++){
        printf("this is process thread\n");
    }
}
int test(void)
{
    pthread_t id;
    int i,ret;
    ret=pthread_create(&id,NULL,(void *) threads,NULL);
    if(ret!=0){
        printf ("Create pthread error!\n");
        exit(1);
    }
    for(i=0; i<3; i++)
        printf("This is the main process.\n");
    pthread_join(id,NULL);
    return (0);
}
