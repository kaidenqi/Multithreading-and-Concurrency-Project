
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;

void *print_A()
{
    int index, i;
    for(index = 1; index <= 10; ++index)
    {
        pthread_mutex_lock(&mutex);
        for (i = 0; i < 5; ++i)
        {
            printf("%d", index);
            printf(":AAAAAAAAA\n");
        }
        printf("\n");
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void *print_B()
{
    int index, i;
    for(index = 1; index <= 10; ++index)
    {
        pthread_mutex_lock(&mutex);
        for (i = 0; i < 5; ++i)
        {
            printf("%d", index);
            printf(":BBBBBBBBB\n");
        }
        printf("\n");
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}
int main()
{
    pthread_t tid;
    
    pthread_setconcurrency(2);
    
    pthread_create(&tid, NULL, (void *(*)(void *))print_A, NULL);
    pthread_create(&tid, NULL, (void *(*)(void *))print_B, NULL);
   
    
    pthread_exit(0);
}


