#ifndef COPPER_ARRAY_H
#define COPPER_ARRAY_H

#include "type.h"

typedef struct {
    void *data;
    usize length;
} Array;

#define ARRAY_GET(T, array, index) *(i32*)Array_get(array, sizeof(T) * index)

Array Array_new(void *data, usize length);

void *Array_get(Array array, usize index);

#endif // COPPER_ARRAY_H
