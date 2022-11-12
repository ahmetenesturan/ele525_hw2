#include "buffer.h"

Buffer::Buffer(uint16_t size)
{
    buffer_size = size;
    buffer_queue = new int32_t[size];
    buffer_pos = 0;
}

void Buffer::push(int32_t data)
{
    if(buffer_pos == buffer_size)
    {
        printf("Buffer is full!\n\n");
        return;
    }
    buffer_queue[buffer_pos] = data;
    buffer_pos++;
}

int32_t Buffer::pop()
{
    if(buffer_pos == 0)
    {
        printf("Buffer is empty!\n\n");
        return NULL;
    }
    int32_t r = buffer_queue[0];
    for(int i = buffer_pos - 1; i > 0; i--)
    {
        buffer_queue[i-1] = buffer_queue[i];
    }
    buffer_pos--;
    return r;
}
