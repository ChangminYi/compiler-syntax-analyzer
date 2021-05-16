#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#ifndef FILE_LOADER
#define FILE_LOADER

#define ROW 85
#define COL 39
#define ERROR 'e'

vector<map<string, string>> LoadParsingTable();

const vector<string> state = {
    "vtype", "id", "semi", "assign", "literal", "character", "boolstr", "addsub", "multdiv",
    "lparen", "rparen", "num", "lbrace", "rbrace", "comma",	"if", "while", "comp", "else", "return",
    "class", "$", "CODE", "VDECL", "ASSIGN", "RHS", "EXPR", "EXPR_MD", "EXPR_T",
    "FDECL", "ARG", "MOREARGS", "BLOCK", "STMT", "COND", "ELSE", "RETURN", "CDECL", "ODECL"
};

#endif