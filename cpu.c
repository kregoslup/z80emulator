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
struct registers reg;

int cycle(){
    int opcode = get_opcode(c.program_counter);
    switch(opcode){
        // LD r1, r2
        case 0x7F:
            reg.A = reg.A;
            c.cycles += 4;
            c.program_counter += 1;
            break;
        case 0x78:
            reg.A = reg.B;
            c.cycles += 4;
            c.program_counter += 1;
            break;
        case 0x79:
            reg.A = reg.C;
            c.cycles += 4;
            c.program_counter += 1;
            break;
        case 0x7A:
            reg.A = reg.D;
            c.cycles += 4;
            c.program_counter += 1;
            break;
        case 0x7B:
            reg.A = reg.E;
            c.cycles += 4;
            c.program_counter += 1;
            break;
        case 0x7C:
            reg.A = reg.H;
            c.cycles += 4;
            c.program_counter += 1;
            break;
        case 0x7D:
            reg.A = reg.L;
            c.cycles += 4;
            c.program_counter += 1;
            break;
        case 0x0A:
            reg.A = pair_register(reg.B, reg.C);
            c.cycles += 4;
            c.program_counter += 1;
            break;
        case 0x1A:
            reg.A = pair_register(reg.D, reg.E);
            c.cycles += 4;
            c.program_counter += 1;
            break;
        case 0x7E:
            reg.A = pair_register(reg.H, reg.L);
            c.cycles += 4;
            c.program_counter += 1;
            break;
        case 0xFA:
            reg.A = pair_register(reg.B, reg.C);
            c.cycles += 4;
            c.program_counter += 1;
            break;
        case 0x47:
            reg.B = reg.A;
            c.cycles += 4;
            c.program_counter += 1;
            break;
    }
}

char pair_register(char reg1, char reg2){
    return
}
