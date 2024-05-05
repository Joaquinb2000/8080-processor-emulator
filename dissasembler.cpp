#include <iostream>

using namespace std;

int main(){

    return 0;
};

int Dissasemble8080Op(unsigned char *codebuffer, int pc){
    unsigned char *code = &codebuffer[pc];
    int opbytes = 1;
    printf("%04x", pc);

    switch(*code){
        case 0x06: printf("MVI B, #$%02x$02x", code[2], code[1]); opbytes = 2; break;
        case 0x0e: printf("MVI C, #$%02x$02x", code[2], code[1]); opbytes = 2; break;
        case 0x16: printf("MVI D, #$%02x$02x", code[2], code[1]); opbytes = 2; break;
        case 0x1e: printf("MVI E, #$%02x$02x", code[2], code[1]); opbytes = 2; break;
        case 0x26: printf("MVI H, #$%02x$02x", code[2], code[1]); opbytes = 2; break;
        case 0x2e: printf("MVI L, #$%02x$02x", code[2], code[1]); opbytes = 2; break;
        case 0x3e: printf("MVI A, #$%02x$02x", code[2], code[1]); opbytes = 2; break;
        case 0x36: printf("MVI M, #$%02x$02x", code[2], code[1]); opbytes = 2; break;
        case 0x40: printf("MOV B, B"); break;
        case 0x41: printf("MOV B, C"); break;
        case 0x42: printf("MOV B, D"); break;
        case 0x43: printf("MOV B, E"); break;
        case 0x44: printf("MOV B, H"); break;
        case 0x45: printf("MOV B, L"); break;
        case 0x46: printf("MOV B, M"); break;
        case 0x47: printf("MOV B, A"); break;
        case 0x48: printf("MOV C, B"); break;
        case 0x49: printf("MOV C, C"); break;
        case 0x4a: printf("MOV C, D"); break;
        case 0x4b: printf("MOV C, E"); break;
        case 0x4c: printf("MOV C, H"); break;
        case 0x4d: printf("MOV C, L"); break;
        case 0x4e: printf("MOV C, M"); break;
        case 0x4f: printf("MOV C, A"); break;
        case 0x50: printf("MOV D, B"); break;
        case 0x51: printf("MOV D, C"); break;
        case 0x52: printf("MOV D, D"); break;
        case 0x53: printf("MOV D, E"); break;
        case 0x54: printf("MOV D, H"); break;
        case 0x55: printf("MOV D, L"); break;
        case 0x56: printf("MOV D, M"); break;
        case 0x57: printf("MOV D, A"); break;
        case 0x58: printf("MOV E, B"); break;
        case 0x59: printf("MOV E, C"); break;
        case 0x5a: printf("MOV E, D"); break;
        case 0x5b: printf("MOV E, E"); break;
        case 0x5c: printf("MOV E, H"); break;
        case 0x5d: printf("MOV E, L"); break;
        case 0x5e: printf("MOV E, M"); break;
        case 0x5f: printf("MOV E, A"); break;
        case 0x60: printf("MOV H, B"); break;
        case 0x61: printf("MOV H, C"); break;
        case 0x62: printf("MOV H, D"); break;
        case 0x63: printf("MOV H, E"); break;
        case 0x64: printf("MOV H, H"); break;
        case 0x65: printf("MOV H, L"); break;
        case 0x66: printf("MOV H, M"); break;
        case 0x67: printf("MOV H, A"); break;
        case 0x68: printf("MOV L, B"); break;
        case 0x69: printf("MOV L, C"); break;
        case 0x6a: printf("MOV L, D"); break;
        case 0x6b: printf("MOV L, E"); break;
        case 0x6c: printf("MOV L, H"); break;
        case 0x6d: printf("MOV L, L"); break;
        case 0x6e: printf("MOV L, M"); break;
        case 0x6f: printf("MOV L, A"); break;
        case 0x70: printf("MOV M, B"); break;
        case 0x71: printf("MOV M, C"); break;
        case 0x72: printf("MOV M, D"); break;
        case 0x73: printf("MOV M, E"); break;
        case 0x74: printf("MOV M, H"); break;
        case 0x75: printf("MOV M, L"); break;
        case 0x77: printf("MOV M, A"); break;
        case 0x78: printf("MOV A, B"); break;
        case 0x79: printf("MOV A, C"); break;
        case 0x7a: printf("MOV A, D"); break;
        case 0x7b: printf("MOV A, E"); break;
        case 0x7c: printf("MOV A, H"); break;
        case 0x7d: printf("MOV A, L"); break;
        case 0x7e: printf("MOV A, M"); break;
        case 0x7f: printf("MOV A, A"); break;
        default: printf("Not registered yet!"); break;
    }


    return opbytes;
}
