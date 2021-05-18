#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include "cfg.h"

using namespace std;

#ifndef TABLE_LOADER
#define TABLE_LOADER

#define ROW 91
#define COL 39
#define ERROR 'e'

vector<map<string, string>> LoadParsingTable(string file_name);

const vector<string> symbol = {
    "vtype", "id", "semi", "assign", "literal", "character", "boolstr", "addsub", "multdiv",
    "lparen", "rparen", "num", "lbrace", "rbrace", "comma",	"if", "while", "comp", "else", "return",
    "class", "$", "S", "CODE", "VDECL", "ASSIGN", "RHS", "EXPR", "EXPR_MD", "EXPR_T",
    "FDECL", "ARG", "MOREARGS", "BLOCK", "STMT", "COND", "ELSE", "RETURN", "CDECL", "ODECL"
};

#endif