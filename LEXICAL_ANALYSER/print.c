#include "lexical.h"

void printKeyword(const char* str)
{
    printf("%-18s:\t %s\n", "KEYWORD", str);
}

void printSymbol(const char ch)
{
    printf("%-18s:\t %c\n","SYMBOL", ch);
}

void printOperator(const char* str)
{
    printf("%-18s:\t %s\n","OPERATOR", str);
}

void printNumericConst(const char* str)
{
    printf("%-18s:\t %s\n","NUMERIC CONSTANT", str);
}

void printIdentifier(const char* str)
{
    printf("%-18s:\t %s\n","IDENTIFIER", str);
}
void printStringLiteral(const char* str)
{
    printf("%-18s:\t %s\n","STRING CONSTANT", str);
}
void printCharacterConstant(char ch)
{
    printf("%-18s:\t '%c'\n","CHARACTER CONSTANT", ch);
}