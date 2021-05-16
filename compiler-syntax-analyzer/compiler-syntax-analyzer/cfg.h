#include <vector>
#include <string>

using namespace std;

const vector<string> state = {
    "vtype", "id", "semi", "assign", "literal", "character", "boolstr", "addsub", "multdiv",
    "lparen", "rparen", "num", "lbrace", "rbrace", "comma",	"if", "while", "comp", "else", "return",
    "class", "$", "CODE", "VDECL", "ASSIGN", "RHS", "EXPR", "EXPR_MD", "EXPR_T",
    "FDECL", "ARG", "MOREARGS", "BLOCK", "STMT", "COND", "ELSE", "RETURN", "CDECL", "ODECL"
};

typedef struct Transition {
    string lhs, rhs;
}