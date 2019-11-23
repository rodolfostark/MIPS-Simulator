#ifndef TYPE_R_ARITMETIC_H
#define TYPE_R_ARITMETIC_H

#include <iostream>
#include <string>

using namespace std;

class type_r_aritmetic
{
public:
    type_r_aritmetic();
    ~type_r_aritmetic();
    int aritmetic_s(string op, string destiny, string first, string second, int * t, int * s);
    int aritmetic_t(string op, string destiny, string first, string second, int * t, int * s);
};

#endif // TYPE_R_ARITMETIC_H
