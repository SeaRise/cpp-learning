#include "Token.h"


Token &Token::operator=(const Token &t) {
    switch (t.tok) {
        case CHAR: operator=(t.cval); break;
        case INT: operator=(t.ival); break;
        case DBL: operator=(t.dval); break;
        case STR: operator=(t.sval); break;
    }
    return *this;
}

Token &Token::operator=(const std::string &s) {
    if (tok == STR) {
        sval = s;
    } else {
        new(&sval) std::string(s);
        tok = STR;
    }
    return *this;
}

Token &Token::operator=(std::string &&s) {
    if (tok == STR) {
        sval = std::move(s);
    } else {
        new(&sval) std::string(std::move(s));
        tok = STR;
    }
    return *this;
}

Token &Token::operator=(char c) {
    freeIfStr();
    cval = c;
    tok = CHAR;
    return *this;
}

Token &Token::operator=(int i) {
    freeIfStr();
    ival = i;
    tok = INT;
    return *this;
}

Token &Token::operator=(double d) {
    freeIfStr();
    dval = d;
    tok = DBL;
    return *this;
}

void Token::copyUnion(const Token &t) {
    switch (t.tok) {
        case CHAR: cval = t.cval; break;
        case INT: ival = t.ival; break;
        case DBL: dval = t.dval; break;
        case STR: new(&sval) std::string(t.sval); break;
    }
}

void Token::copyUnion(Token &&t) {
    switch (t.tok) {
        case CHAR: cval = t.cval; break;
        case INT: ival = t.ival; break;
        case DBL: dval = t.dval; break;
        case STR: new(&sval) std::string(std::move(t.sval)); break;
    }
}

std::ostream &operator<<(std::ostream &os, const Token &t) {
    switch (t.tok) {
        case Token::CHAR: os << t.cval; break;
        case Token::INT: os << t.ival; break;
        case Token::DBL: os << t.dval; break;
        case Token::STR: os << t.sval; break;
    }
    return os;
}
