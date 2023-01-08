#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "read_instruction.h"

static EInstructionType get_instruction_type(const char* instruction_text){
    const char* instructions[] = INSTRUCTIONS;
    int instruction_count = (int) (sizeof(instructions)/sizeof(char*));
    int start_index = 0, end_index = instruction_count - 1;
    while(start_index <= end_index) {
        int middle = start_index + (end_index - start_index)/2;
        int comparison_result = strcmp(instructions[middle], instruction_text);
        if(comparison_result == 0) {
            return (EInstructionType) middle;
        } else if(comparison_result < 0) {
            start_index = middle + 1;
        } else {
            end_index = middle - 1;
        }
    }
    return INSTRUCTION_UNKNOWN;
}

void read_instruction(char* instruction_line, TInstruction* instruction) {
    char instruction_text[20] = { 0 };
    sscanf(instruction_line, "%s", instruction_text);
    if(strlen(instruction_line) == 0) return;
    instruction->instruction_type = get_instruction_type(instruction_text);
    size_t count_of_leading_spaces = 0ULL;
    size_t count_of_trailing_spaces = 0ULL;
    size_t instruction_len = strlen(instruction_text);
    size_t instruction_line_size = strlen(instruction_line);
    for(;isspace((int) instruction_line[instruction_len + count_of_leading_spaces]);count_of_leading_spaces++);
    for(;isspace((int) instruction_line[instruction_line_size - count_of_trailing_spaces - 1]);count_of_trailing_spaces++);
    size_t instruction_value_size = instruction_line_size - instruction_len - count_of_leading_spaces - count_of_trailing_spaces + 1;
    if(instruction_line_size > instruction_len + count_of_leading_spaces + count_of_trailing_spaces) {
        instruction->instruction_value = (char*) malloc(sizeof(char) * instruction_value_size);
        memset(instruction->instruction_value, 0, sizeof(char) * instruction_value_size);
        memmove(instruction->instruction_value, &instruction_line[instruction_len + count_of_leading_spaces], sizeof(char) * (instruction_value_size-1));
    }
}