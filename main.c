#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "instructions/inits/init_ref_table.h"
#include "instructions/read_instruction.h"

#define CHAR_S sizeof(char)


int main() {
    FILE* fp = fopen("L.txt", "r");
    if(fp == NULL) exit(1);
    char* line = NULL;
    size_t j = 0;
    unsigned char ch;
    TRef* ref_table = InitRefTable();
    while(ref_table && (ch = fgetc(fp)) != (unsigned char) EOF) {
        if(ch != '\n') continue;
        const size_t i = ftell(fp);
        const size_t k = i-j;
        line = (char*) (line == NULL ? malloc(CHAR_S * k) : realloc(line, CHAR_S * k));
        memset(line, 0, CHAR_S * k);
        fseek(fp, j, SEEK_SET);
        fread(line, CHAR_S, k-1, fp);
        fgetc(fp);
        j = i;
        TInstruction instruction = { INSTRUCTION_UNKNOWN, NULL };
        read_instruction(line, &instruction);
        printf("%d [%s]\n", (int) instruction.instruction_type, instruction.instruction_value);
        if(instruction.instruction_value) free(instruction.instruction_value);
    }
    if(line) free(line);
    if(ref_table) free(ref_table);
    fclose(fp);
    return 0;
}