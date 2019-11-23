#ifndef BINARYMIPS_H
#define BINARYMIPS_H

#include <iostream>
#include <string>

using namespace std;


class binarymips
{
public:
    binarymips();
    ~binarymips();
    string binary_opcode(string str);
    string binary_regs(string str);
    string binary_imm(string str);
    string binary_funct(string str);
};

#endif // BINARYMIPS_H
