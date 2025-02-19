#ifndef TOKEN_H
#define TOKEN_H

enum token_type { 
    ILLEGAL,
    EOF_TOK,  

    IDENT, 
    INT_TOK,   

    ASSIGN, 
    EQ,
    NOT_EQ,
    LT,
    GT,
    BANG,
    MULT,
    DIV,
    MINUS,
    PLUS,

    COMMA, 
    SEMICOLON,

    LPAREN, 
    RPAREN, 
    LBRACE, 
    RBRACE,

    FUNCTION, 
    RETURN,
    LET,

    IF,
    ELSE,
    TRUE,
    FALSE,
};


struct Token {
    enum token_type type;
    char* literal;
};

struct Token newToken(enum token_type type, char* literal);

struct Token getTokenFromLitteral(char*);

struct Token createStringWildcardToken();

#endif
