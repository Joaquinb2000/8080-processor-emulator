#ifndef DISASSEMBLER8080OP_H
#define DISASSEMBLER8080OP_H

#include <iostream>

int Disassemble8080Op(unsigned char *codebuffer, int pc){
    unsigned char *code = &codebuffer[pc];
    int opbytes = 1;
    printf("%04x ", pc);

    switch(*code){
        case 0x00: printf("NOP"); opbytes = 1; break;
        case 0x01: printf("LXI B-C, #$%02x%02x", code[2], code[1]); opbytes = 3; break;
        case 0x02: printf("STAX B-C"); opbytes = 1; break;
        case 0x03: printf("INX B-C"); opbytes = 1; break;
        case 0x04: printf("INR B"); opbytes = 1; break;
        case 0x05: printf("DCR B"); opbytes = 1; break;
        case 0x06: printf("MVI B #$%02x%02x", code[2], code[1]); opbytes = 2; break;
        case 0x07: printf("RLC"); opbytes = 1; break;
        case 0x09: printf("DAD B-C"); opbytes = 1; break;
        case 0x0a: printf("LDAX B-C"); opbytes = 1; break;
        case 0x0b: printf("DCX B-C"); opbytes = 1; break;
        case 0x0c: printf("INR C"); opbytes = 1; break;
        case 0x0d: printf("DCR C"); opbytes = 1; break;
        case 0x0e: printf("MVI C #$%02x%02x", code[2], code[1]); opbytes = 2; break;
        case 0x0f: printf("RRC"); opbytes = 1; break;
        case 0x11: printf("LXI D-E, #$%02x%02x", code[2], code[1]); opbytes = 3; break;
        case 0x12: printf("STAX D-E"); opbytes = 1; break;
        case 0x13: printf("INX D-E"); opbytes = 1; break;
        case 0x14: printf("INR D"); opbytes = 1; break;
        case 0x15: printf("DCR D"); opbytes = 1; break;
        case 0x16: printf("MVI D #$%02x%02x", code[2], code[1]); opbytes = 2; break;
        case 0x17: printf("RAL"); opbytes = 1; break;
        case 0x19: printf("DAD D-E"); opbytes = 1; break;
        case 0x1a: printf("LDAX D-E"); opbytes = 1; break;
        case 0x1b: printf("DCX D-E"); opbytes = 1; break;
        case 0x1c: printf("INR E"); opbytes = 1; break;
        case 0x1d: printf("DCR E"); opbytes = 1; break;
        case 0x1e: printf("MVI E #$%02x%02x", code[2], code[1]); opbytes = 2; break;
        case 0x1f: printf("RAR"); opbytes = 1; break;
        case 0x21: printf("LXI H-L, #$%02x%02x", code[2], code[1]); opbytes = 3; break;
        case 0x22: printf("SHLD  $%02x%02x", code[2], code[1]); opbytes = 3; break;
        case 0x23: printf("INX H-L"); opbytes = 1; break;
        case 0x24: printf("INR H"); opbytes = 1; break;
        case 0x25: printf("DCR H"); opbytes = 1; break;
        case 0x26: printf("MVI H #$%02x%02x", code[2], code[1]); opbytes = 2; break;
        case 0x27: printf("DAA"); opbytes = 1; break;
        case 0x29: printf("DAD H-L"); opbytes = 1; break;
        case 0x2a: printf("LHDL  $%02x%02x", code[2], code[1]); opbytes = 3; break;
        case 0x2b: printf("DCX H-L"); opbytes = 1; break;
        case 0x2c: printf("INR L"); opbytes = 1; break;
        case 0x2d: printf("DCR L"); opbytes = 1; break;
        case 0x2e: printf("MVI L #$%02x%02x", code[2], code[1]); opbytes = 2; break;
        case 0x2f: printf("CMA"); opbytes = 1; break;
        case 0x31: printf("LXI SP, #$%02x%02x", code[2], code[1]); opbytes = 3; break;
        case 0x32: printf("STA  $%02x%02x", code[2], code[1]); opbytes = 3; break;
        case 0x33: printf("INX SP"); opbytes = 1; break;
        case 0x34: printf("INR M"); opbytes = 1; break;
        case 0x35: printf("DCR M"); opbytes = 1; break;
        case 0x36: printf("MVI M #$%02x%02x", code[2], code[1]); opbytes = 2; break;
        case 0x37: printf("STC"); opbytes = 1; break;
        case 0x39: printf("DAD SP"); opbytes = 1; break;
        case 0x3a: printf("LDA  $%02x%02x", code[2], code[1]); opbytes = 3; break;
        case 0x3b: printf("DCX SP"); opbytes = 1; break;
        case 0x3c: printf("INR A"); opbytes = 1; break;
        case 0x3d: printf("DCR A"); opbytes = 1; break;
        case 0x3e: printf("MVI A #$%02x%02x", code[2], code[1]); opbytes = 2; break;
        case 0x3f: printf("CMC"); opbytes = 1; break;
        case 0x40: printf("MOV B, B"); opbytes = 1; break;
        case 0x41: printf("MOV B, C"); opbytes = 1; break;
        case 0x42: printf("MOV B, D"); opbytes = 1; break;
        case 0x43: printf("MOV B, E"); opbytes = 1; break;
        case 0x44: printf("MOV B, H"); opbytes = 1; break;
        case 0x45: printf("MOV B, L"); opbytes = 1; break;
        case 0x46: printf("MOV B, M"); opbytes = 1; break;
        case 0x47: printf("MOV B, A"); opbytes = 1; break;
        case 0x48: printf("MOV C, B"); opbytes = 1; break;
        case 0x49: printf("MOV C, C"); opbytes = 1; break;
        case 0x4a: printf("MOV C, D"); opbytes = 1; break;
        case 0x4b: printf("MOV C, E"); opbytes = 1; break;
        case 0x4c: printf("MOV C, H"); opbytes = 1; break;
        case 0x4d: printf("MOV C, L"); opbytes = 1; break;
        case 0x4e: printf("MOV C, M"); opbytes = 1; break;
        case 0x4f: printf("MOV C, A"); opbytes = 1; break;
        case 0x50: printf("MOV D, B"); opbytes = 1; break;
        case 0x51: printf("MOV D, C"); opbytes = 1; break;
        case 0x52: printf("MOV D, D"); opbytes = 1; break;
        case 0x53: printf("MOV D, E"); opbytes = 1; break;
        case 0x54: printf("MOV D, H"); opbytes = 1; break;
        case 0x55: printf("MOV D, L"); opbytes = 1; break;
        case 0x56: printf("MOV D, M"); opbytes = 1; break;
        case 0x57: printf("MOV D, A"); opbytes = 1; break;
        case 0x58: printf("MOV E, B"); opbytes = 1; break;
        case 0x59: printf("MOV E, C"); opbytes = 1; break;
        case 0x5a: printf("MOV E, D"); opbytes = 1; break;
        case 0x5b: printf("MOV E, E"); opbytes = 1; break;
        case 0x5c: printf("MOV E, H"); opbytes = 1; break;
        case 0x5d: printf("MOV E, L"); opbytes = 1; break;
        case 0x5e: printf("MOV E, M"); opbytes = 1; break;
        case 0x5f: printf("MOV E, A"); opbytes = 1; break;
        case 0x60: printf("MOV H, B"); opbytes = 1; break;
        case 0x61: printf("MOV H, C"); opbytes = 1; break;
        case 0x62: printf("MOV H, D"); opbytes = 1; break;
        case 0x63: printf("MOV H, E"); opbytes = 1; break;
        case 0x64: printf("MOV H, H"); opbytes = 1; break;
        case 0x65: printf("MOV H, L"); opbytes = 1; break;
        case 0x66: printf("MOV H, M"); opbytes = 1; break;
        case 0x67: printf("MOV H, A"); opbytes = 1; break;
        case 0x68: printf("MOV L, B"); opbytes = 1; break;
        case 0x69: printf("MOV L, C"); opbytes = 1; break;
        case 0x6a: printf("MOV L, D"); opbytes = 1; break;
        case 0x6b: printf("MOV L, E"); opbytes = 1; break;
        case 0x6c: printf("MOV L, H"); opbytes = 1; break;
        case 0x6d: printf("MOV L, L"); opbytes = 1; break;
        case 0x6e: printf("MOV L, M"); opbytes = 1; break;
        case 0x6f: printf("MOV L, A"); opbytes = 1; break;
        case 0x70: printf("MOV M, B"); opbytes = 1; break;
        case 0x71: printf("MOV M, C"); opbytes = 1; break;
        case 0x72: printf("MOV M, D"); opbytes = 1; break;
        case 0x73: printf("MOV M, E"); opbytes = 1; break;
        case 0x74: printf("MOV M, H"); opbytes = 1; break;
        case 0x75: printf("MOV M, L"); opbytes = 1; break;
        case 0x76: printf("HLT"); opbytes = 1; break;
        case 0x77: printf("MOV M, A"); opbytes = 1; break;
        case 0x78: printf("MOV A, B"); opbytes = 1; break;
        case 0x79: printf("MOV A, C"); opbytes = 1; break;
        case 0x7a: printf("MOV A, D"); opbytes = 1; break;
        case 0x7b: printf("MOV A, E"); opbytes = 1; break;
        case 0x7c: printf("MOV A, H"); opbytes = 1; break;
        case 0x7d: printf("MOV A, L"); opbytes = 1; break;
        case 0x7e: printf("MOV A, M"); opbytes = 1; break;
        case 0x7f: printf("MOV A, A"); opbytes = 1; break;
        case 0x80: printf("ADD B"); opbytes = 1; break;
        case 0x81: printf("ADD C"); opbytes = 1; break;
        case 0x82: printf("ADD D"); opbytes = 1; break;
        case 0x83: printf("ADD E"); opbytes = 1; break;
        case 0x84: printf("ADD H"); opbytes = 1; break;
        case 0x85: printf("ADD L"); opbytes = 1; break;
        case 0x86: printf("ADD M"); opbytes = 1; break;
        case 0x87: printf("ADD A"); opbytes = 1; break;
        case 0x88: printf("ADC B"); opbytes = 1; break;
        case 0x89: printf("ADC C"); opbytes = 1; break;
        case 0x8a: printf("ADC D"); opbytes = 1; break;
        case 0x8b: printf("ADC E"); opbytes = 1; break;
        case 0x8c: printf("ADC H"); opbytes = 1; break;
        case 0x8d: printf("ADC L"); opbytes = 1; break;
        case 0x8e: printf("ADC M"); opbytes = 1; break;
        case 0x8f: printf("ADC A"); opbytes = 1; break;
        case 0x90: printf("SUB B"); opbytes = 1; break;
        case 0x91: printf("SUB C"); opbytes = 1; break;
        case 0x92: printf("SUB D"); opbytes = 1; break;
        case 0x93: printf("SUB E"); opbytes = 1; break;
        case 0x94: printf("SUB H"); opbytes = 1; break;
        case 0x95: printf("SUB L"); opbytes = 1; break;
        case 0x96: printf("SUB M"); opbytes = 1; break;
        case 0x97: printf("SUB A"); opbytes = 1; break;
        case 0x98: printf("SBB B"); opbytes = 1; break;
        case 0x99: printf("SBB C"); opbytes = 1; break;
        case 0x9a: printf("SBB D"); opbytes = 1; break;
        case 0x9b: printf("SBB E"); opbytes = 1; break;
        case 0x9c: printf("SBB H"); opbytes = 1; break;
        case 0x9d: printf("SBB L"); opbytes = 1; break;
        case 0x9e: printf("SBB M"); opbytes = 1; break;
        case 0x9f: printf("SBB A"); opbytes = 1; break;
        case 0xa0: printf("ANA B"); opbytes = 1; break;
        case 0xa1: printf("ANA C"); opbytes = 1; break;
        case 0xa2: printf("ANA D"); opbytes = 1; break;
        case 0xa3: printf("ANA E"); opbytes = 1; break;
        case 0xa4: printf("ANA H"); opbytes = 1; break;
        case 0xa5: printf("ANA L"); opbytes = 1; break;
        case 0xa6: printf("ANA M"); opbytes = 1; break;
        case 0xa7: printf("ANA A"); opbytes = 1; break;
        case 0xa8: printf("XRA B"); opbytes = 1; break;
        case 0xa9: printf("XRA C"); opbytes = 1; break;
        case 0xaa: printf("XRA D"); opbytes = 1; break;
        case 0xab: printf("XRA E"); opbytes = 1; break;
        case 0xac: printf("XRA H"); opbytes = 1; break;
        case 0xad: printf("XRA L"); opbytes = 1; break;
        case 0xae: printf("XRA M"); opbytes = 1; break;
        case 0xaf: printf("XRA A"); opbytes = 1; break;
        case 0xb0: printf("ORA B"); opbytes = 1; break;
        case 0xb1: printf("ORA C"); opbytes = 1; break;
        case 0xb2: printf("ORA D"); opbytes = 1; break;
        case 0xb3: printf("ORA E"); opbytes = 1; break;
        case 0xb4: printf("ORA H"); opbytes = 1; break;
        case 0xb5: printf("ORA L"); opbytes = 1; break;
        case 0xb6: printf("ORA M"); opbytes = 1; break;
        case 0xb7: printf("ORA A"); opbytes = 1; break;
        case 0xb8: printf("CMP B"); opbytes = 1; break;
        case 0xb9: printf("CMP C"); opbytes = 1; break;
        case 0xba: printf("CMP D"); opbytes = 1; break;
        case 0xbb: printf("CMP E"); opbytes = 1; break;
        case 0xbc: printf("CMP H"); opbytes = 1; break;
        case 0xbd: printf("CMP L"); opbytes = 1; break;
        case 0xbe: printf("CMP M"); opbytes = 1; break;
        case 0xbf: printf("CMP A"); opbytes = 1; break;
        case 0xc0: printf("Rcondition NZ"); opbytes = 1; break;
        case 0xc1: printf("POP B-C"); opbytes = 1; break;
        case 0xc2: printf("JC NZ"); opbytes = 3; break;
        case 0xc3: printf("JMP  $%02x%02x", code[2], code[1]); opbytes = 3; break;
        case 0xc4: printf("CC NZ"); opbytes = 3; break;
        case 0xc5: printf("PUSH B-C"); opbytes = 1; break;
        case 0xc6: printf("ADI DATA, #$%02x", code[1]); opbytes = 2; break;
        case 0xc7: printf("RST 0"); opbytes = 1; break;
        case 0xc8: printf("Rcondition Z"); opbytes = 1; break;
        case 0xc9: printf("RET"); opbytes = 1; break;
        case 0xca: printf("JC Z"); opbytes = 3; break;
        case 0xcc: printf("CC Z"); opbytes = 3; break;
        case 0xcd: printf("CALL  $%02x%02x", code[2], code[1]); opbytes = 3; break;
        case 0xce: printf("ACI D, #$%02x", code[1]); opbytes = 2; break;
        case 0xcf: printf("RST 1"); opbytes = 1; break;
        case 0xd0: printf("Rcondition NC"); opbytes = 1; break;
        case 0xd1: printf("POP D-E"); opbytes = 1; break;
        case 0xd2: printf("JC NC"); opbytes = 3; break;
        case 0xd3: printf("OUT port"); opbytes = 1; break;
        case 0xd4: printf("CC NC"); opbytes = 3; break;
        case 0xd5: printf("PUSH D-E"); opbytes = 1; break;
        case 0xd6: printf("SUI DATA, #$%02x", code[1]); opbytes = 2; break;
        case 0xd7: printf("RST 2"); opbytes = 1; break;
        case 0xd8: printf("Rcondition C"); opbytes = 1; break;
        case 0xda: printf("JC C"); opbytes = 3; break;
        case 0xdb: printf("IN port"); opbytes = 1; break;
        case 0xdc: printf("CC C"); opbytes = 3; break;
        case 0xde: printf("SBI data, #$%02x", code[1]); opbytes = 2; break;
        case 0xdf: printf("RST 3"); opbytes = 1; break;
        case 0xe0: printf("Rcondition PO"); opbytes = 1; break;
        case 0xe1: printf("POP H-L"); opbytes = 1; break;
        case 0xe2: printf("JC PO"); opbytes = 3; break;
        case 0xe3: printf("XTHL"); opbytes = 1; break;
        case 0xe4: printf("CC PO"); opbytes = 3; break;
        case 0xe5: printf("PUSH H-L"); opbytes = 1; break;
        case 0xe6: printf("ANI D%02x", code[1]); opbytes = 2; break;
        case 0xe7: printf("RST 4"); opbytes = 1; break;
        case 0xe8: printf("Rcondition PE"); opbytes = 1; break;
        case 0xe9: printf("PCHL"); opbytes = 1; break;
        case 0xea: printf("JC PE"); opbytes = 3; break;
        case 0xeb: printf("XCHG"); opbytes = 1; break;
        case 0xec: printf("CC PE"); opbytes = 3; break;
        case 0xee: printf("XRI D#$%02x", code[1]); opbytes = 2; break;
        case 0xef: printf("RST 5"); opbytes = 1; break;
        case 0xf0: printf("Rcondition P"); opbytes = 1; break;
        case 0xf1: printf("POP PSW"); opbytes = 1; break;
        case 0xf2: printf("JC P"); opbytes = 3; break;
        case 0xf3: printf("DI"); opbytes = 1; break;
        case 0xf4: printf("CC P"); opbytes = 3; break;
        case 0xf5: printf("PUSH PSW"); opbytes = 1; break;
        case 0xf6: printf("ORI #$%02x", code[1]); opbytes = 2; break;
        case 0xf7: printf("RST 6"); opbytes = 1; break;
        case 0xf8: printf("Rcondition M"); opbytes = 1; break;
        case 0xf9: printf("SPHL"); opbytes = 1; break;
        case 0xfa: printf("JC M"); opbytes = 3; break;
        case 0xfb: printf("EI"); opbytes = 1; break;
        case 0xfc: printf("CC M"); opbytes = 3; break;
        case 0xfe: printf("CPI D#$%02x", code[1]); opbytes = 2; break;
        case 0xff: printf("RST 7"); opbytes = 1; break;
        default: throw code;
    }

    printf("\n");

    return opbytes;
}

#endif

