#ifndef COMPILER
#define COMPILER

typedef enum {
  TOKEN_SEMICOLON = 256,

  TOKEN_NUMBER,
  TOKEN_INT,
  TOKEN_STRING,

  TOKEN_KEY_CONST,
  TOKEN_KEY_VAR,
  TOKEN_KEY_STRUCT,
  TOKEN_KEY_ENUM,

  TOKEN_ERROR,
} Token_Type;

typedef struct {
  Token_Type type;
  int line;
  int column;
} Token;

char *Lexer(char *buffer);

#endif
