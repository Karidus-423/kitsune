#ifndef COMPILER
#define COMPILER

#include <stdlib.h>

typedef enum {
  TOKEN_SEMICOLON = 256,
  TOKEN_COLON,

  TOKEN_NUMBER,
  TOKEN_CHAR,
  TOKEN_STRING,
  TOKEN_IDENTIFIER,

  TOKEN_KEY_CONST,
  TOKEN_KEY_VAR,
  TOKEN_KEY_INT,
  TOKEN_KEY_CHAR,
  TOKEN_KEY_STRING,
  TOKEN_KEY_STRUCT,
  TOKEN_KEY_ENUM,
  TOKEN_KEY_IF,
  TOKEN_KEY_ELSE,
  TOKEN_KEY_FOR,
  TOKEN_KEY_WHILE,

  TOKEN_L_PAREN,
  TOKEN_R_PAREN,
  TOKEN_L_BRACKET,
  TOKEN_R_BRACKET,
  TOKEN_L_CURLY,
  TOKEN_R_CURLY,

  TOKEN_ERROR,
} Token_Type;

typedef struct Token {
  Token_Type type;
  int line;
  int column;
} token_t;

typedef struct Token_List {
  token_t *token;
  int list_size;
} token_list_t;

token_list_t *Lexer(char *buffer);

#endif
