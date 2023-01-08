CSRCS=./main.c
CSRCS+= ./instructions/inits/init_ref_table.c
CSRCS+= ./instructions/read_instruction.c
CFLAGS=-std=c11

all:
	gcc $(CSRCS) $(CFLAGS) -o main