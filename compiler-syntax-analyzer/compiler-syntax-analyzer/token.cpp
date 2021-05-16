#include <vector>
#include "token.h"

const vector<string> token_str = {
    "TYPE",	"NUMBER",	"CHAR",	"STRING", "BOOLEAN",
    "ID",	"IF",	"ELSE",	"WHILE",	"RETURN",
    "ASSIGN",	"COMPARE",	"LPAREN",	"RPAREN",	"LBRACE",
	"RBRACE",	"LBRACKET",	"RBRACKET",	"COMMA",	"SEMICOLON",
    "WSPACE",	"CLASS",	"OPER"
};

Token::Token(TOKEN_TYPE t, string v): type(t) {
    switch(type){
    case CHAR:
    case STRING:
        v = v.substr(1, v.size() - 2);
    case NUMBER:
    case BOOLEAN:
    case ID:
    case TYPE:
    case COMPARE:
    case OPER:
        value = v;
    }
}

ostream& operator<<(ostream& os, const Token& token){
	if (!token.value.empty()) {
		os << token_str[token.type] << ": " << token.value << '\n';
	}
	else {
		os << token_str[token.type] << '\n';
	}
	return os;
}

TOKEN_TYPE revConvert(const string origin) {
	for (uint32_t i = 0; i < token_str.size(); i++) {
		if (origin == token_str[i]) {
			return (TOKEN_TYPE)i;
		}
	}
	return (TOKEN_TYPE)-1;
}
