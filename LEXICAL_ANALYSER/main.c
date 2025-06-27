/*
Name: Sudarshan S Halse

*/
#include "lexical.h"

int main(int argc, char* argv[])
{
    if(isValid(argc, argv) == FAILURE)
    {
        puts("ERROR: FILE validation Failed");
        return FAILURE;
    }
    else 
    {
        puts("INFO: Validation successfull");
    }

    // do the parsing
    if(readWord_and_tokenisation(argv[1]) == FAILURE)
    {
        return FAILURE;
    }

}