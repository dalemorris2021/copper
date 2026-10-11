#include "array.h"

Array Array_new(void *data, usize length) {
    return (Array){
        .data = data,
        .length = length,
    };
}

void *Array_get(Array array, usize index) {
    return (char *)array.data + index;
}
