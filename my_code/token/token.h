struct Token {
    char* type;
    char* literal;
};

enum token_type {
    ILLEGAL, EOF_TOK,  
    IDENT, INT_TOK,   
    ASSIGN, PLUS,
    COMMA, SEMICOLON,
    LPAREN, RPAREN, LBRACE, RBRACE,
    FUNCTION, LET
};


