
package token

type TokenType string

type TokenType struct {
	Type TokenType
	Litteral string
}

const (
	ILLEGAL = "ILLEGAL"
	EOF = "EOF"

	IDENT = "IDENT"
	INT = "INT"

	ASSIGN = "ASSIGN"
	PLUS = "PLUS"

	COMMA = "COMMA"

	SEMICOLON = "SEMICOLON"

	LPAREN = "("
	RPAREN = ")"
	LBRACE = "{"
	RBRACE = "}"

	FUNCTION = "FUNCTION"
	LET = "LET"
)

