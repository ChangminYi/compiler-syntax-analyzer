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

//�ʱ�ȭ �Ŀ� ������ ��ȯ�ϱ� ����
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
		return "vtype";	// int, boolean ���� variable type
	case NUMBER:
		return "num";	// ������
	case CHAR:
		return "character";	// �� ������ char
	case STRING:
		return "literal";	// string
	case BOOLEAN:
		return "boolstr";	// true, false
	case ID:
		return "id";	// ����, �Լ�, Ŭ���� �̸�
	case IF:
		return "if";	// if ��
	case ELSE:
		return "else";	// else ��
	case WHILE:
		return "while";	// while ��
	case RETURN:
		return "return";	// return ��ɾ�
	case ASSIGN:
		return "assign";	// ���Կ�����
	case COMPARE:
		return "comp";	// >, <���� �� ������
	case LPAREN:
		return "lparen";	// (
	case RPAREN:
		return "rparen";	// )
	case LBRACE:
		return "lbrace";	// {
	case RBRACE:
		return "rbrace";	// }
	/* action table�� ����
	case LBRACKET:
		return "lbracket";
	case RBRACKET:
		return "rbracket";
	*/
	case COMMA:
		return "comma";	// ,
	case SEMICOLON:
		return "semi";	// ;
	/* �̹� wspace�� ���� �Է¸� ����
	case WSPACE:
		return "wspace";
	*/
	case CLASS:
		return "class";	// class ����
	case OPER:
		if (token.value == "+" || token.value == "-") {
			return "addsub";	// ��Ģ������: +�� -
		}
		else {
			return "multdiv";	// ��Ģ������: *�� /
		}
	case ENDMARKER:
		return "$";
	}
	return "error";
}