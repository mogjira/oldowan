#include "utils.h"
#include <stdio.h>

void printVec2(const Vec2* vec)
{
    printf("x: %f, y: %f\n", vec->x, vec->y);
}

static void printGeo(const Geo* geo, const Vertex* buffer)
{
    printf("Vertex count: %d\n", geo->vertCount);
    for (int i = 0; i < geo->vertCount; i++) 
    {
        printf("Vertex %d: ", i);
        printVec2(buffer + geo->vertIndex + i);
    }
}

void bitprint(const void* const thing, const size_t bitcount)
{
    int mask;
    for (int i = bitcount - 1; i >= 0; i--) {
        mask = 1 << i;   
        if (mask & *(int*)thing)
            putchar('1');
        else
            putchar('0');
    }
    putchar('\n');
}
