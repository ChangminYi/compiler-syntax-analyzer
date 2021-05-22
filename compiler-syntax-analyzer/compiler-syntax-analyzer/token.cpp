#include <vector>
#include <unordered_map>
#include "token.h"

const vector<string> token_str = {
    "TYPE",	"NUMBER",	"CHAR",	"STRING", "BOOLEAN",
    "ID",	"IF",	"ELSE",	"WHILE",	"RETURN",
    "ASSIGN",	"COMPARE",	"LPAREN",	"RPAREN",	"LBRACE",
	"RBRACE",	"LBRACKET",	"RBRACKET",	"COMMA",	"SEMICOLON",
    "WSPACE",	"CLASS",	"OPER", "ENDMARKER"
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
    if(!token.value.empty())
        os << "<" << token_str[token.type] << ", " << token.value << ">";
    else
        os << "<" << token_str[token.type] << ">";
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

string tokenToTerminal(const Token &token) {
	switch (token.type) {
	case TYPE:
		return "vtype";	// int, boolean 등의 variable type
	case NUMBER:
		return "num";	// 정수값
	case CHAR:
		return "character";	// 한 글자의 char
	case STRING:
		return "literal";	// string
	case BOOLEAN:
		return "boolstr";	// true, false
	case ID:
		return "id";	// 변수, 함수, 클래스 이름
	case IF:
		return "if";	// if 문
	case ELSE:
		return "else";	// else 문
	case WHILE:
		return "while";	// while 문
	case RETURN:
		return "return";	// return 명령어
	case ASSIGN:
		return "assign";	// 대입연산자
	case COMPARE:
		return "comp";	// >, <등의 비교 연산자
	case LPAREN:
		return "lparen";	// (
	case RPAREN:
		return "rparen";	// )
	case LBRACE:
		return "lbrace";	// {
	case RBRACE:
		return "rbrace";	// }
	/* action table에 없음
	case LBRACKET:
		return "lbracket";
	case RBRACKET:
		return "rbracket";
	*/
	case COMMA:
		return "comma";	// ,
	case SEMICOLON:
		return "semi";	// ;
	/* 이미 wspace가 없는 입력만 들어옴
	case WSPACE:
		return "wspace";
	*/
	case CLASS:
		return "class";	// class 선언
	case OPER:
		if (token.value == "+" || token.value == "-") {
			return "addsub";	// 사칙연산자: +와 -
		}
		else {
			return "multdiv";	// 사칙연산자: *와 /
		}
	case ENDMARKER:
		return "$";
	}
	return "error";
}