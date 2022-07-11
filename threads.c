#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *up_count(void *arg)
{
    pthread_mutex_lock(&mutex);
    int *num = (int *)arg;
    counter++;
    printf("message is %d, thread id = %ul modified the counter to %d\n", *num, pthread_self(), counter);
    printf("message is %d, thread id = %ul read the counter %d\n", *num, pthread_self(), counter);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t threads[10];
    int msgNums[10] = {0,1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 10; i++)
    {
        pthread_create(&threads[i], NULL, up_count, (void *)&msgNums[i]);
    }
    for(int i = 0; i < 10; i++)
    {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
