#include "option.h"

Option _Option_new(OptionTag tag, void *data) {
    return (Option){
        .data = data,
        .tag = tag,
    };
}

void *_Option_unwrap(Option option) {
    return option.data;
}
