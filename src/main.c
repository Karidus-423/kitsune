#include <stdio.h>
#include "compiler.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc < 2){
		printf("Pass file name\n");
		return 0;
	}

	FILE *input = fopen(argv[1],"r");
	char *buffer;
	if (input ==NULL){
		printf("File not found.\n");
		fclose(input);
		return 0;
	}else{
		fseek(input,0,SEEK_END);
		int input_size = ftell(input);
		rewind(input);

		buffer = malloc(input_size+1);

		fread(buffer,1,input_size,input);
	}
	fclose(input);

	token_list_t *tokens_list = Lexer(buffer);

	for(int i = 0; i < tokens_list->list_size; i++){
		printf("%d",tokens_list->token[i].type);
	}
}
