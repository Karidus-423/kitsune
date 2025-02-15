// Read input and output tokens.
#include "compiler.h"
#include <stdio.h>
#include <stdlib.h>


token_list_t *Lexer(char *buffer){
	token_list_t *tokens_list = malloc(sizeof(token_list_t));
	if (tokens_list == NULL){
		perror("Unable to allocate memory.");
		exit(EXIT_FAILURE);
	}

	return tokens_list;
}
