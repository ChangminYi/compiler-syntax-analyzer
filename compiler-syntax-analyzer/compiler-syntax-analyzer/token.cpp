#include <vector>
#include <unordered_map>
#include "token.h"

const vector<string> token_str = {
    "TYPE",	"NUMBER",	"CHAR",	"STRING", "BOOLEAN",
    "ID",	"IF",	"ELSE",	"WHILE",	"RETURN",
    "ASSIGN",	"COMPARE",	"LPAREN",	"RPAREN",	"LBRACE",
	"RBRACE",	"LBRACKET",	"RBRACKET",	"COMMA",	"SEMICOLON",
    "WSPACE",	"CLASS",	"OPER"
};

//초기화 후에 빠르게 변환하기 위함
unordered_map<string, TOKEN_TYPE> rev_token_map;


Token::Token(TOKEN_TYPE t): type(t){
}

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

void initRevConvert() {
	for (uint32_t i = 0; i < token_str.size(); i++) {
		rev_token_map.insert(make_pair(token_str[i], (TOKEN_TYPE)i));
	}
	return;
}

TOKEN_TYPE revConvert(const string origin) {
	if (rev_token_map.find(origin) != rev_token_map.end()) {
		return rev_token_map[origin];
	}
	else {
		return (TOKEN_TYPE)-1;
	}
}
