#include "buffer.h"
#include <cstdint>
#include <cstdio>
#include <stdint.h>


class Buffer
{
    private:
    uint16_t buffer_size;
    uint16_t buffer_pos;
    int32_t* buffer_queue;

    public:
    Buffer(uint16_t);
    void push(int32_t);
    uint32_t pop();
};

Buffer::Buffer(uint16_t size)
{
    buffer_size = size;
    buffer_queue = new int32_t[size];
    buffer_pos = 0;
}

void Buffer::push(int32_t data)
{
    if(buffer_pos == 10)
    {
        printf("Buffer is full!");
        return;
    }
    buffer_queue[buffer_pos] = data;
    buffer_pos++;
}

uint32_t Buffer::pop()
{
    if(buffer_pos == 0)
    {
        printf("Buffer is empty!");
        return NULL;
    }
    uint32_t temp = buffer_queue[buffer_pos - 1];
    buffer_pos--;
    for(int i = 0; i < buffer_pos; i++)
}