#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include "m_math.h"

#define printBuffer(pBuffer, size, Type, printFn) { \
    const Type* util_pBuffer = (Type*)pBuffer; \
    for (int i = 0; i < size / sizeof(Type); i++) \
    { \
        printFn(&util_pBuffer[i]); \
    } \
} ;

void printVec2(const Vec2*);
void bitprint(const void *const thing, const size_t bitcount);

#endif /* end of include guard: UTILS_H */
