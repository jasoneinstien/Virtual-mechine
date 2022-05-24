//VM --> stimulatehardware componets and CPU 
//The vm we write is LC-3 
//

//Memory Storage 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/termios.h>
#include <sys/mman.h>
#include <stdint.h>

#define MEMORY_MAX (1<<16)
uint16_t memory[MEMORY_MAX];

//registers : a slot for storing a single value on the CPU data -> CPU on the work bench
// there are 10 registers: 8 general purpose , 1 program counter , 1 condition flag 
// general purpose -> any program calculations , program counter -> address for nextt instruction , confition flgs -> information about pervious calculations 
//

enum
{
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC, //program counter 
    R_COND,//flag counter 
    R_COUNT
};

//store the registers in an arrary 
uint16_t reg[R_COUNT];
//Instruction set it is a command tells CPU to do fundermental task ie) add two numbers
//
enum
{
    OP_BR = 0, /* branch */
    OP_ADD,    /* add  */
    OP_LD,     /* load */
    OP_ST,     /* store */
    OP_JSR,    /* jump register */
    OP_AND,    /* bitwise and */
    OP_LDR,    /* load register */
    OP_STR,    /* store register */
    OP_RTI,    /* unused */
    OP_NOT,    /* bitwise not */
    OP_LDI,    /* load indirect */
    OP_STI,    /* store indirect */
    OP_JMP,    /* jump */
    OP_RES,    /* reserved (unused) */
    OP_LEA,    /* load effective address */
    OP_TRAP    /* execute trap */
};

//condition flags
// store condition flag -> provide information about the most recent executed calculation --> allow the programs to check logics 
enum{
    FL_POS = 1 << 0, /* P */
    FL_ZRO = 1 << 1, /* Z */
    FL_NEG = 1 << 2, /* N */  
};

//main loop procedure
//load one instruction from memory at the address of the PC register 
//Increment the PC register 
//Look at the instruction set to determine which type of instruction it should perform 
//Perform the instruction and go back to step load one instruction from memory 
//
//main

int main(int argc , const char* argv[]){
    //load argument 
    //set up 
    
    //since one condition flag should be set at any given time 
    reg[R_COND] = FL_ZRO;
     
    //0x3000 is the default
    enum {PC_START = 0x3000};
    //set first data as start position 
    reg[R_PC] = PC_START; 

    int running = 1;

    while (running){
        uint16_t instr = mem_read(reg[R_PC] ++);
        uint16_t op = instr >>12;
    
    }
    restore_input_buffering();
}











