#include <string.h>
#include "init_ref_table.h"


TRef* InitRefTable() {
    TRef* ref_table = (TRef*) malloc(sizeof(TRef) * REF_TABLE_SIZE);
    if(ref_table) memset(ref_table, 0, sizeof(TRef) * REF_TABLE_SIZE);
    return ref_table;
}