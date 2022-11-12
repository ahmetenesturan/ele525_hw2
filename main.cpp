#include "mbed.h"
#include "buffer.h"
#include <cstdio>
#include <cstdlib>
#include <cstdint>

#define BUFFER_SIZE 10

void fn_producer_thread();

Buffer* buffer = new Buffer(BUFFER_SIZE);


int main()
{
    srand(time(NULL));

    Thread* producer_thread = new Thread(osPriorityNormal, 2048, nullptr, "Producer Thread");
    producer_thread->start(&fn_producer_thread);


    while (true);
}


void fn_producer_thread()
{
    while(true)
    {
        int32_t data = rand() % 10 + 1;
        buffer->push(data);
        printf("Buffer:%d\n",buffer->buffer_pos);
    }
}