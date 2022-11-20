#include "mbed.h"
#include <cstdio>
#include <cstdlib>
#include <cstdint>

#define BUFFER_SIZE 10u

Mutex buffer_mutex;
Semaphore buffer_semaphore(0,BUFFER_SIZE);
int32_t* buffer = new int32_t[BUFFER_SIZE];
int32_t i = 0;

void fn_producer_thread();
void fn_consumer_thread();
void fn_consumer_thread_2();

int main()
{
    srand(time(NULL)); //for rng
    
    Thread* producer_thread = new Thread(osPriorityNormal, 2048, nullptr, "Producer Thread");
    Thread* consumer_thread = new Thread(osPriorityNormal, 2048, nullptr, "Consumer Thread");
    Thread* consumer_thread_2 = new Thread(osPriorityNormal, 2048, nullptr, "Consumer Thread 2");

    producer_thread->start(&fn_producer_thread);
    consumer_thread->start(&fn_consumer_thread);
    consumer_thread_2->start(&fn_consumer_thread_2);

    while (true);
}


void fn_producer_thread()
{
    while(true)
    {
        buffer_semaphore.release();
        buffer_mutex.lock();
        buffer[i] = rand() % 10 + 1;
        i++;
        printf("%d\n",i);
        buffer_mutex.unlock();
        thread_sleep_for(1000);
    }
}

void fn_consumer_thread()
{
    while(true)
    {
        buffer_semaphore.acquire();
        buffer_mutex.lock();
        int32_t data = buffer[i-1];
        i--;
        printf("%d\n",i);
        buffer_mutex.unlock();
        thread_sleep_for(1000);
    }
}

void fn_consumer_thread_2()
{
    while(true)
    {
        buffer_semaphore.acquire();
        buffer_mutex.lock();
        int32_t data = buffer[i-1];
        i--;
        printf("%d\n",i);
        buffer_mutex.unlock();
        thread_sleep_for(1000);
    }
}