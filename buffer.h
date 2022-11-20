#pragma once
#include <cstdint>
#include <cstdio>

class Buffer
{
    public:
    uint16_t buffer_size;
    int16_t buffer_pos;
    int32_t* buffer_queue;
    Buffer(int16_t size);
    void push(int32_t data);
    int32_t pop();
};