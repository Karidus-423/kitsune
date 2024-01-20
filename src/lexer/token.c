#include "../include/token.h"

token_K *init_token(char *value, int type) {
  token_K *token = calloc(1, sizeof(struct TOKEN_STRUCT));
  token->value = value;
  token->type = type;

  return token;
}
