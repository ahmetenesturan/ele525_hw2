#include "mbed.h"
#include "buffer.h"
#include <cstdio>
#include <cstdlib>
#include <cstdint>

#define BUFFER_SIZE 10

void fn_producer_thread();
void fn_consumer_thread();

Buffer* buffer = new Buffer(BUFFER_SIZE);


int main()
{
    srand(time(NULL));

    Thread* producer_thread = new Thread(osPriorityNormal, 2048, nullptr, "Producer Thread");
    Thread* consumer_thread = new Thread(osPriorityNormal, 2048, nullptr, "Consumer Thread");
    producer_thread->start(&fn_producer_thread);
    consumer_thread->start(&fn_consumer_thread);


    while (true)
    {
        printf("%d\n",buffer->buffer_pos);
    }
}


void fn_producer_thread()
{
    while(true)
    {
        int32_t data = rand() % 10 + 1;
        buffer->push(data);
        //printf("%d\n",buffer->buffer_pos);
        //thread_sleep_for(500);
    }
}

void fn_consumer_thread()
{
    while(true)
    {
        int32_t data = buffer->pop();
        //printf("%d\n",buffer->buffer_pos);
        //thread_sleep_for(500);
        //if(buffer->buffer_pos == 0) break;
    }
}