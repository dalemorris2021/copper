#ifndef COPPER_TYPE_H
#define COPPER_TYPE_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef char i8;
typedef short i16;

#if defined(__unix)
typedef unsigned int u32;
typedef unsigned long u64;
typedef unsigned long usize;
typedef int i32;
typedef long i64;
typedef long isize;
#endif

#if defined(_WIN32)
typedef unsigned long u32;
typedef unsigned long usize;
typedef long i32;
typedef long isize;
#endif

#if defined(_WIN64)
typedef unsigned long u32;
typedef unsigned long long u64;
typedef unsigned long long usize;
typedef long i32;
typedef long long i64;
typedef long long isize;
#endif

#define Bool u8
#define False ((Bool)0)
#define True ((Bool)1)

#endif // COPPER_TYPE_H
