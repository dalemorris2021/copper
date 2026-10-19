#ifndef COPPER_RESULT_H
#define COPPER_RESULT_H

#include "type.h"

#define ResultTag u8
#define Ok ((ResultTag)0)
#define Err ((ResultTag)1)

typedef struct {
    union {
        void *val;
        void *error;
    } data;
    ResultTag tag;
} Result;

Result Result_new_ok(ResultTag tag, void *data);

Result Result_new_err(ResultTag tag, void *data);

void *_Result_unwrap_ok(Result result);

void *_Result_unwrap_err(Result result);

#define Result_new(tag, data) tag == Ok ? Result_new_ok(tag, data) : Result_new_err(tag, data)

#define Result_unwrap_ok(T, result) &((T)*)_Result_unwrap_ok((result))

#define Result_unwrap_err(E, result) &((E)*)_Result_unwrap_err((result))

#endif // COPPER_RESULT_H
