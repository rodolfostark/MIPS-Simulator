#include "binarymips.h"
#include <iostream>
#include <string>

using namespace std;

/*
   Função para passar um inteiro decimal para seu código binário de número de bits escolhido.
   Assim, para um inteiro "8" com 5 bits fica: 01000; Já o mesmo 8 para 10 bits fica: 0000001000.
*/
string int2bin(int i, int n){
    string r;
    while(i!=0){
        r=(i%2==0 ?"0":"1")+r; i/=2;
    }
    while(r.length()<n){
        r='0'+r;
    }
    return r;
}

binarymips::binarymips(){}
binarymips::~binarymips(){}


/*
   A função passa o texto do OPCODE para seu binário
*/
string binarymips::binary_opcode(string str){
    int dec;
    if((str == "add")||(str == "sub")){
        dec = 0;
    }
    if(str == "addi"){
        dec = 8;
    }
    string res = int2bin(dec, 6);
    return res;
}

/*
   A função passa o texto do registrador para seu binário
*/
string binarymips::binary_regs(string str){
    string aux=str;
    string res;
    int dec, a, b;
    if((str[0]=='$')){
        if(str=="$zero,"){
            return "00000";
        }else if(str[1]=='t'){
            a=1;
            aux[0]=aux[2];
            b=stoi(aux);
        }else if(str[1]=='s'){
            a=2;
            aux[0]=aux[2];
            b=stoi(aux);
        }else{
            return "ERROR";
        }
    }else{
        return "ERROR";
    }
    dec=(8*a)+b;
    res = int2bin(dec, 5);
    return res;
}

/*
   A função passa o texto do imediato para seu binário
*/
string binarymips::binary_imm(string str){
    int dec = stoi(str);
    string res = int2bin(dec, 16);
    return res;
}

/*
   A função passa o texto do funct para seu binário
*/
string binarymips::binary_funct(string str){
    int dec;
    if((str == "add")){
        dec = 32;
    }
    if(str == "sub"){
        dec = 34;
    }
    string res = int2bin(dec, 6);
    return res;
}
