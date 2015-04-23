#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"

//Procedure 2 is what Lab1.c was initially designated to do.

//Procedure 1: Read the name of a text file, open the file, read from it a line at a time, and write those lines to the screen and to a second text file; close the files.
int remove_newline(char line[1024]){
	line[strlen(line) - 1] = '\0';
	return 0;
}

int file_modifyer(){
	char line[1024], file_name[1024];
	char destination_file[1024];
	FILE *fp;
	FILE *file_obj;
	
	printf("Provide the name of a file: ");
	fgets(file_name, 1024, stdin);
	remove_newline(file_name);
	
	printf("Where would you like the information to go?: ");
	fgets(destination_file, 1024, stdin);
	remove_newline(destination_file);
	
	file_obj = fopen(destination_file, "w"); // write mode
	fp = fopen(file_name, "r"); // read mode
	if (fp == NULL)
	{
		perror("There was an error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	
	printf("The contents of %s file are: \n", file_name);
	
	while(fgets(line, 1024, fp)){
		fputs(line, stdout);
		fputs(line, file_obj);
	}
	fclose(fp);
	fclose(file_obj);
	puts("\n");
	return 0;
}

//Procedure 2: Given a string and a set of delimiters, break the string into separate tokens.
int tokenizer()
{
	char input[1024];	
	char *p;
    string(input);
	/*removes new line from the end of the string */
	remove_newline(input);
    p = strtok(input, " ");
	

	while(p != NULL)
	{
		printf("\"%s\"\n", p);
		
		p = strtok(NULL, ", ");
	}
	
	return 0;
}

//Procedure 3: Given a string representing an assembly-language command (such as LDD), returns the machine-language opcode

int string(char string[1024]){
	printf("Provide assembly code: ");
	
	return fgets(string, 1024, stdin) == NULL;
}

//if the userinput matches the string comparison equivalent, 0 will be produced and the opcode equivalent will be returned.
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

int return_opcode()
{
	char input[1024];	
	int opcode;
	char *p;
	
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