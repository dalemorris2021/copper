#include "result.h"

Result Result_new_ok(ResultTag tag, void *val) {
    return (Result){
        .data.val = val,
        .tag = tag,
    };
}

Result Result_new_err(ResultTag tag, void *error) {
    return (Result){
        .data.error = error,
        .tag = tag,
    };
}

void *_Result_unwrap_ok(Result result) {
    return result.data.val;
}

void *_Result_unwrap_err(Result result) {
    return result.data.error;
}
