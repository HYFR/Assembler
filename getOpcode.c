#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int string(char string[1024]){
	printf("Provide assembly code: ");
	
	return fgets(string, 1024, stdin) == NULL;
}

int remove_newline(char line[1024]){
	line[strlen(line) - 1] = '\0';
	return 0;
}

int translate(char *portion){
	
	if (strcmp(portion, "NOP") == 0) {
		return 0;
	}
	else if (strcmp(portion, "LDD") == 0) {
		return 1;
	}
	else if (strcmp(portion, "LDI") == 0) {
		return 2;
	}
	else if (strcmp(portion, "STO") == 0) {
		return 3;
	}
	else if (strcmp(portion, "MOV") == 0) {
		return 4;
	}
	else if (strcmp(portion, "ADI") == 0) {
		return 5;
	}
	else if (strcmp(portion, "ADF") == 0) {
		return 6;
	}
	else if (strcmp(portion, "OR") == 0) {
		return 7;
	}
	else if (strcmp(portion, "AND") == 0) {
		return 8;
	}
	else if (strcmp(portion, "XOR") == 0) {
		return 9;
	}
	else if (strcmp(portion, "ROR") == 0) {
		return 10;
	}
	else if (strcmp(portion, "JMP") == 0) {
		return 11;
	}
	else if (strcmp(portion, "HLT") == 0) {
		return 12;
	}
	else if (strcmp(portion, "LDX") == 0) {
		return 13;
	}
	else if (strcmp(portion, "STX") == 0) {
		return 14;
	}
	else {
		return -1;
	}
	
	return 0;	
}


int main()
{
	char input[1024];	
	int opcode;
	char *p;
	int ret;
	
    string(input);
	/*removes new line from the end of the string */
	remove_newline(input);
    p = strtok(input, " ");
	
	opcode = translate(p);
	printf("%d", opcode);
	

	while(p != NULL)
	{
		printf("\"%s\"\n", p);
		
		p = strtok(NULL, ", ");
	}
	
	return 0;
}