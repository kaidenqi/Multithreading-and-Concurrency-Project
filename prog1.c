
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>



void *print_A()
{
    int index, i;
    for(index = 1; index <= 10; ++index)
    {
        for (i = 0; i < 5; ++i)
        {
            printf("%d", index);
            printf(":AAAAAAAAA\n");
        }
        printf("\n");
        //sleep(1);
    }
}

void *print_B()
{
    int index, i;
    for(index = 1; index <= 10; ++index)
    {
        for (i = 0; i < 5; ++i)
        {
            printf("%d", index);
            printf(":BBBBBBBBB\n");
        }
        printf("\n");
        //sleep(1);
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


