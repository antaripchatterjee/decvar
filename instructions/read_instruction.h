#ifndef __READ_INSTRUCTION_H__
#define __READ_INSTRUCTION_H__

typedef enum {
    INSTRUCTION_UNKNOWN = -1,
    INSTRUCTION_ALLOC,
    INSTRUCTION_END,
    INSTRUCTION_PUSHD,
    INSTRUCTION_PUSHR,
    INSTRUCTION_START,
    INSTRUCTION_SYSCALL,
    INSTRUCTION_SYSLIB,
    INSTRUCTION_WRITE
} EInstructionType;


#define INSTRUCTIONS { \
    "ALLOC", "END", "PUSHD", \
    "PUSHR", "START", "SYSCALL", \
    "SYSLIB", "WRITE" \
}

typedef struct {
    EInstructionType instruction_type;
    char* instruction_value;
} TInstruction;


void read_instruction(char* line, TInstruction* instruction);

#endif // __READ_INSTRUCTION_H__