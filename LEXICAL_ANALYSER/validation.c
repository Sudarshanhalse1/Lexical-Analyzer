#include "lexical.h"

int isValid(int argc, char* argv[])
{
    // files should be exactly 2
    if(argc != 2)
    {
        puts("ERROR: ./lexical_analyser.out < c_file.c >");
        return FAILURE;
    }

    // file should be with ".c" extension
    if((strstr(argv[1], ".txt")==NULL) || (strcmp(strstr(argv[1], ".txt"), ".txt")!=0))
    {
        puts("ERROR: File is not having \".c\" extension");
        return FAILURE;
    } 

    // file must be valid
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        puts("ERROR: File does not exist");
        return FAILURE;
    }

    // file should not be empty
    fseek(fp, 0, SEEK_END);
    if(ftell(fp) == 0)
    {
        puts("ERROR: File is empty");
        fclose(fp);
        return FAILURE;
    }
    return SUCCESS;
}