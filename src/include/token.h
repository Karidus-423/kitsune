#ifndef KIT_TOKEN_H
#define KIT_TOKEN_H

typedef struct TOKEN_STRUCT {
  char *value;
  enum {
    TOKEN_ID,
    TOKEN_COLON,
    TOKEN_INT,
    TOKEN_FUNC,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACE,
    TOKEN_GIVE,
    TOKEN_NUM,
    TOKEN_SEMI,
    TOKEN_RBRACE,
  } type;
} token_K;

token_K *init_token(char *value, int type);
#endif
