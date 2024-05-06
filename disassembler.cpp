#include <iostream>
#include <fstream>
#include "disassembler8080Op.h"

using namespace std;

int main(int argc, char *argv[]){
    if(argc != 2){
        cerr << "No file suppplied" << endl;
        exit(1);
    }

    FILE *f = fopen(argv[1], "rb");

    if(f == NULL){
        cerr << "Error: Couldn't open " << argv[1];
        exit(1);
    }

    fseek(f, 0L, SEEK_END);
    int fsize = ftell(f);
    fseek(f, 0L, SEEK_SET);

    unsigned char *buffer = (unsigned char*) malloc(fsize);

    fread(buffer, fsize, 1, f);
    fclose(f);

    int pc = 0;
    try{
        while(pc < fsize){
            pc += Disassemble8080Op(buffer, pc);
        }
    }catch(unsigned char* e){
        printf("Unknown code: %02x \n", *e);
        exit(1);
    }

    return 0;
};
