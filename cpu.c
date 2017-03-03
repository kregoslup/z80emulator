//
// Created by krego on 03.03.2017.
//

#include "cpu.h"

struct registers {
    // group in pairs
    //  ------- ------
    // | 15..8 | 7..0 |
    // | ----- | ---- |
    // |   A   |   F  |
    // | ----- | ---- |
    // |   B   |   C  |
    // | ----- | ---- |
    // |   D   |   E  |
    // | ----- | ---- |
    // |   H   |   L  |
    // | ----- | ---- |
    // |      SP      |
    // | ----- | ---- |
    // |      PC      |
    // | ----- | ---- |

    char A;
    char F;

    char B;
    char C;

    char D;
    char E;
    char H;
    char L;
};

struct cpu {
    struct registers reg;
    unsigned short stack_pointer;
    unsigned short program_counter;
    unsigned int cycles;
};

struct cpu c;

int cycle(){
    int opcode = get_opcode(c.program_counter);
    switch(opcode){
        case 0x06:

    }
}