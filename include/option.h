#ifndef COPPER_OPTION_H
#define COPPER_OPTION_H

#include "type.h"

#define OptionTag u8
#define None ((OptionTag)0)
#define Some ((OptionTag)1)

typedef struct {
    void *data;
    OptionTag tag;
} Option;

Option _Option_new(OptionTag tag, void *data);

void *_Option_unwrap(option);

#define Option_new(T, tag, data) _Option_new((tag), (data))

#define Option_unwrap(T, option) &((T)*)_Option_unwrap((option))

#endif // COPPER_OPTION_H
