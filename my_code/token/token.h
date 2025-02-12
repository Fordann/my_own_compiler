
enum token_type { 
    ILLEGAL, EOF_TOK,  
    IDENT, INT_TOK,   
    ASSIGN, PLUS,
    COMMA, SEMICOLON,
    LPAREN, RPAREN, LBRACE, RBRACE,
    FUNCTION, LET
};


struct Token {
    enum token_type type;
    char* literal;
};
