#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "binarymips.h"
#include "type_r_aritmetic.h"

using namespace std;

int main()
{
    /*
       Inicialização do objeto da biblioteca criada para traduzir as linhas de código e aritimétrica.
    */
    binarymips bin;
    type_r_aritmetic arit;

    /*
       Variável que "guarda" o arquivo txt que conterá os comandos a serem usados no simulador do
       processador MIPS.
    */
    ifstream code_textfile;

    /*
       A função "abre o arquivo txt em nossa variável". Isso integra o arquivo de teste em nosso código.
    */
    code_textfile.open("C:/Users/iagop/Desktop/teste.txt");

    /*
       Este if verifica se o arquivo foi aberto corretamente. Caso não tenha sido, ele informa o usuário
       e cancela a execução do simulador.
    */
    if(code_textfile.is_open() == false){
        cout << "Nao foi possivel abrir o arquivo." << endl;
        cout << "Por favor, verifique o caminho dentro de code_textfile.open()" << endl;
        cout << "Cancelando a axecuçao do simulador" << endl;
        exit(0);
    }

    /*
       O vetor "all_lines" irá gradar as linhas de texto do nosso arvivo
       em formato de string, para guardar na memória de nosso código as linhas
       de comando escritas no .txt.

       "reading_line" será a string que atuará dentro do while para guardar todas
       as lines em nosso vetor "all_lines".

       "res" são as respostas dos 32bits que irão ser traduzidas de linha de comando do
       código em Assembly.

       As variáveis com terminação "_text" são as variáveis que receberão as partes da linha
       de código do Assembly em string de texto. Sendo OPCODE, RD, RS, RT, IMMEDIATE.

       As variáveis com terminção "_bin" são as partes anteriores agora traduzidas para binario
       assim como por exemplo: "add" -> 000000 ||| "$t0" -> 8 -> 01000 ||| "$s1" -> 17 -> 10001.
    */
    vector<string> all_lines;
    string reading_line, res;
    string opcode_text, rs_text, rt_text, rd_text, imm_text;
    string opcode_bin, rs_bin, rt_bin, rd_bin, funct_bin, imm_bin;

    /*
       Vetores que representam os valores decimais dos registradores do MIPS.
    */
    int t[]={0,0,0,0,0,0,0,0};
    int s[]={0,0,0,0,0,0,0,0};

    /*
       O while coloca as linhas de texto do nosso txt dentro do "all_lines".
    */
    while(getline(code_textfile, reading_line)){
        all_lines.push_back(reading_line);
    }

    /*
       Nesse for, em cada interação, uma linha de código é subdividida. Assim as partes de
       OPCODE, REGISTRADORES, IMMEDIATE, etc.. São guardas nas variáveis de terminação "_text".

       A medida que vai se dividindo as partes em strings, vai se chamando as funções da biblioteca criada
       "binarymips" para traduzir o texto do das partes para a tradução binária. Assim, os textos do "_text" são
       traduzidos em códigos binários do "_bin".
    */
    for(int i=0; i<all_lines.size(); i++){

        stringstream line_part(all_lines[i]);

        line_part >> opcode_text;

        // TIPO R:
        if(opcode_text[3]!='i'){
            //Tradução para binário:
            line_part >> rd_text;
            line_part >> rs_text;
            line_part >> rt_text;
            opcode_bin = bin.binary_opcode(opcode_text);
            rs_bin = bin.binary_regs(rs_text);
            rt_bin = bin.binary_regs(rt_text);
            rd_bin = bin.binary_regs(rd_text);
            funct_bin = bin.binary_funct(opcode_text);
            res = opcode_bin + rs_bin + rt_bin + rd_bin + "00000" + funct_bin;

            //Aritimética decimal com os registradores:
            if(rd_text[1]=='s'){
                rd_text[0]=rd_text[2];
                s[stoi(rd_text)] = arit.aritmetic_s(opcode_text, rd_text, rs_text, rt_text, t, s);

            }else if(rd_text[1]=='t') {
                rd_text[0]=rd_text[2];
                t[stoi(rd_text)] = arit.aritmetic_t(opcode_text, rd_text, rs_text, rt_text, t, s);
            }

        }

        // TIPO I:
        else{
            //Tradução para binário:
            line_part >> rt_text;
            line_part >> rs_text;
            line_part >> imm_text;
            opcode_bin = bin.binary_opcode(opcode_text);
            rs_bin = bin.binary_regs(rs_text);
            rt_bin = bin.binary_regs(rt_text);
            imm_bin = bin.binary_imm(imm_text);
            res = opcode_bin + rs_bin + rt_bin + imm_bin;

            //Aritimética decimal com os registradores:
            if(rt_text[1]=='t'){
                string aux_str = rt_text;
                aux_str[0]=aux_str[2];
                int aux_int = stoi(aux_str);
                t[aux_int]=t[aux_int]+stoi(imm_text);
            }else if(rt_text[1]=='s'){
                string aux_str = rt_text;
                aux_str[0]=aux_str[2];
                int aux_int = stoi(aux_str);
                s[aux_int]=s[aux_int]+stoi(imm_text);
            }
        }
        cout<<"Instrucao "<<i+1<<": "<<res<<endl;
    }

    for (int i=0;i<8;i++){
        cout<<"$t"<<i<<" = "<<t[i]<<endl;
    }

    for (int i=0;i<8;i++){
        cout<<"$s"<<i<<" = "<<s[i]<<endl;
    }
    return 0;
}
