#include <string>
#include <iostream>
using namespace std;

#ifndef TOKEN
#define TOKEN

enum TOKEN_TYPE {
    TYPE,
    NUMBER, CHAR, STRING, BOOLEAN,
    ID,
    IF, ELSE, WHILE, RETURN,
    ASSIGN, COMPARE,
    LPAREN, RPAREN,
    LBRACE, RBRACE,
    LBRACKET, RBRACKET,
    COMMA, SEMICOLON,
    WSPACE,
    CLASS,
    OPER
};

class Token{
public:
    TOKEN_TYPE type;
    string value;
	Token() {};
	Token(TOKEN_TYPE t);
	Token(TOKEN_TYPE t, string v);
    friend ostream& operator<<(ostream& os, const Token& token);
};

void initRevConvert();
TOKEN_TYPE revConvert(const string origin);
string tokenToTerminal(const Token &token);

#endif