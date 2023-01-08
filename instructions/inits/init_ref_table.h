#ifndef __INIT_REF_TABLE_H__
#define __INIT_REF_TABLE_H__

#include <stdlib.h>

#define REF_TABLE_SIZE 1024

typedef enum {
    UNKNOWN = -1,
    UNSET,
    CONSTANT,
    VARIABLE
} ERefType;

typedef struct {
    ERefType ref_type;
    void* ref_address;
    size_t ref_byte_size;
} TRef;


TRef* InitRefTable();

#endif // __INIT_REF_TABLE_H__