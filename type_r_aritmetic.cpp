#include "type_r_aritmetic.h"
#include <iostream>
#include <string>

using namespace std;

type_r_aritmetic::type_r_aritmetic(){}
type_r_aritmetic::~type_r_aritmetic(){}

int type_r_aritmetic::aritmetic_s(string op, string destiny, string first, string second, int * taux, int * saux){

    int s[8];
    int t[8];

    for(int x=0; x<8; x++){
        s[x] = *saux;
        t[x] = *taux;
        saux++;
        taux++;
    }

    if(op=="add"){

        //S=S+S
        if((destiny[1]=='s')&&(first[1]=='s')&&(second[1]=='s')){
            string aux1=destiny;
            string aux2=first;
            string aux3=second;
            aux1[0]=aux1[2];
            aux2[0]=aux2[2];
            aux3[0]=aux3[2];
            s[stoi(aux1)]=s[stoi(aux2)]+s[stoi(aux3)];
            return s[stoi(aux1)];
        }

        //S=S+T
        else if((destiny[1]=='s')&&(first[1]=='s')&&(second[1]=='t')){
            string aux1=destiny;
            string aux2=first;
            string aux3=second;
            aux1[0]=aux1[2];
            aux2[0]=aux2[2];
            aux3[0]=aux3[2];
            s[stoi(aux1)]=s[stoi(aux2)]+t[stoi(aux3)];
            return s[stoi(aux1)];
        }

        //S=T+S
        else if((destiny[1]=='s')&&(first[1]=='t')&&(second[1]=='s')){
            string aux1=destiny;
            string aux2=first;
            string aux3=second;
            aux1[0]=aux1[2];
            aux2[0]=aux2[2];
            aux3[0]=aux3[2];
            s[stoi(aux1)]=t[stoi(aux2)]+s[stoi(aux3)];
            return s[stoi(aux1)];
        }

        //S=T+T
        else if((destiny[1]=='s')&&(first[1]=='t')&&(second[1]=='t')){
            string aux1=destiny;
            string aux2=first;
            string aux3=second;
            aux1[0]=aux1[2];
            aux2[0]=aux2[2];
            aux3[0]=aux3[2];
            s[stoi(aux1)]=t[stoi(aux2)]+t[stoi(aux3)];
            return s[stoi(aux1)];
        }



    }else if(op=="sub"){

        //S=S-S
        if((destiny[1]=='s')&&(first[1]=='s')&&(second[1]=='s')){
            string aux1=destiny;
            string aux2=first;
            string aux3=second;
            aux1[0]=aux1[2];
            aux2[0]=aux2[2];
            aux3[0]=aux3[2];
            s[stoi(aux1)]=s[stoi(aux2)]-s[stoi(aux3)];
            return s[stoi(aux1)];
        }

        //S=S-T
        else if((destiny[1]=='s')&&(first[1]=='s')&&(second[1]=='t')){
            string aux1=destiny;
            string aux2=first;
            string aux3=second;
            aux1[0]=aux1[2];
            aux2[0]=aux2[2];
            aux3[0]=aux3[2];
            s[stoi(aux1)]=s[stoi(aux2)]-t[stoi(aux3)];
            return s[stoi(aux1)];
        }

        //S=T-S
        else if((destiny[1]=='s')&&(first[1]=='t')&&(second[1]=='s')){
            string aux1=destiny;
            string aux2=first;
            string aux3=second;
            aux1[0]=aux1[2];
            aux2[0]=aux2[2];
            aux3[0]=aux3[2];
            s[stoi(aux1)]=t[stoi(aux2)]-s[stoi(aux3)];
            return s[stoi(aux1)];
        }

        //S=T-T
        else if((destiny[1]=='s')&&(first[1]=='t')&&(second[1]=='t')){
            string aux1=destiny;
            string aux2=first;
            string aux3=second;
            aux1[0]=aux1[2];
            aux2[0]=aux2[2];
            aux3[0]=aux3[2];
            s[stoi(aux1)]=t[stoi(aux2)]-t[stoi(aux3)];
            return s[stoi(aux1)];
        }

    }
}

int type_r_aritmetic::aritmetic_t(string op, string destiny, string first, string second, int * taux, int * saux){

    int s[8];
    int t[8];

    for(int x=0; x<8; x++){
        s[x] = *saux;
        t[x] = *taux;
        saux++;
        taux++;
    }

    if(op=="add"){

        //T=S+S
        if((destiny[1]=='t')&&(first[1]=='s')&&(second[1]=='s')){
            string aux1=destiny;
            string aux2=first;
            string aux3=second;
            aux1[0]=aux1[2];
            aux2[0]=aux2[2];
            aux3[0]=aux3[2];
            t[stoi(aux1)]=s[stoi(aux2)]+s[stoi(aux3)];
            return t[stoi(aux1)];
        }

        //T=S+T
        else if((destiny[1]=='t')&&(first[1]=='s')&&(second[1]=='t')){
            string aux1=destiny;
            string aux2=first;
            string aux3=second;
            aux1[0]=aux1[2];
            aux2[0]=aux2[2];
            aux3[0]=aux3[2];
            t[stoi(aux1)]=s[stoi(aux2)]+t[stoi(aux3)];
            return t[stoi(aux1)];
        }

        //T=T+S
        else if((destiny[1]=='t')&&(first[1]=='t')&&(second[1]=='s')){
            string aux1=destiny;
            string aux2=first;
            string aux3=second;
            aux1[0]=aux1[2];
            aux2[0]=aux2[2];
            aux3[0]=aux3[2];
            t[stoi(aux1)]=t[stoi(aux2)]+s[stoi(aux3)];
            return t[stoi(aux1)];
        }

        //T=T+T
        else if((destiny[1]=='t')&&(first[1]=='t')&&(second[1]=='t')){
            string aux1=destiny;
            string aux2=first;
            string aux3=second;
            aux1[0]=aux1[2];
            aux2[0]=aux2[2];
            aux3[0]=aux3[2];
            t[stoi(aux1)]=t[stoi(aux2)]+t[stoi(aux3)];
            return t[stoi(aux1)];
        }



    }else if(op=="sub"){

        //T=S-S
        if((destiny[1]=='t')&&(first[1]=='s')&&(second[1]=='s')){
            string aux1=destiny;
            string aux2=first;
            string aux3=second;
            aux1[0]=aux1[2];
            aux2[0]=aux2[2];
            aux3[0]=aux3[2];
            t[stoi(aux1)]=s[stoi(aux2)]-s[stoi(aux3)];
            return t[stoi(aux1)];
        }

        //T=S-T
        else if((destiny[1]=='t')&&(first[1]=='s')&&(second[1]=='t')){
            string aux1=destiny;
            string aux2=first;
            string aux3=second;
            aux1[0]=aux1[2];
            aux2[0]=aux2[2];
            aux3[0]=aux3[2];
            t[stoi(aux1)]=s[stoi(aux2)]-t[stoi(aux3)];
            return t[stoi(aux1)];
        }

        //T=T-S
        else if((destiny[1]=='t')&&(first[1]=='t')&&(second[1]=='s')){
            string aux1=destiny;
            string aux2=first;
            string aux3=second;
            aux1[0]=aux1[2];
            aux2[0]=aux2[2];
            aux3[0]=aux3[2];
            t[stoi(aux1)]=t[stoi(aux2)]-s[stoi(aux3)];
            return t[stoi(aux1)];
        }

        //T=T-T
        else if((destiny[1]=='t')&&(first[1]=='t')&&(second[1]=='t')){
            string aux1=destiny;
            string aux2=first;
            string aux3=second;
            aux1[0]=aux1[2];
            aux2[0]=aux2[2];
            aux3[0]=aux3[2];
            t[stoi(aux1)]=t[stoi(aux2)]-t[stoi(aux3)];
            return t[stoi(aux1)];
        }

    }
}
