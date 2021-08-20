#ifndef CPP_LEARNING_TOKEN_H
#define CPP_LEARNING_TOKEN_H

#include <string>
#include <iostream>

class Token;

std::ostream &operator<<(std::ostream &, const Token &);

class Token {
    friend std::ostream &operator<<(std::ostream &, const Token &);
public:
    Token(): tok(CHAR), ival(0) {}
    Token(const Token &t): tok(t.tok) { copyUnion(t); }
    Token(Token &&t): tok(t.tok) { copyUnion(std::move(t)); };
    Token &operator=(const Token &);
    Token &operator=(Token &&);
    ~Token() {
        freeIfStr();
    }
    Token &operator=(const std::string &);
    Token &operator=(std::string &&);
    Token &operator=(char);
    Token &operator=(int);
    Token &operator=(double);
private:
    enum {CHAR, INT, DBL, STR} tok;
    union {
        char cval;
        int ival;
        double dval;
        std::string sval;
    };
    void copyUnion(const Token&);
    void copyUnion(Token&&);
    void freeIfStr() {
        if (tok == STR) {
            sval.std::string::~string();
        }
    }
};


#endif //CPP_LEARNING_TOKEN_H
