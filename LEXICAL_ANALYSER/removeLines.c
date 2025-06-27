#include "lexical.h"
void removePreprocessorDirective(FILE* fp)
{
    char ch;
    while ((ch = fgetc(fp))!='\n');
    lineCount++;
}
void removeSingleLineComment(FILE* fp)
{
    char ch;
    while((ch = fgetc(fp))!= '\n');
    lineCount++;
}
void removeMultiLineComment(FILE* fp) 
{
    char prev = '\0';
    char ch;
    while ((ch = fgetc(fp)) != EOF) 
    {
        if (prev == '*' && ch == '/') 
            break;
        prev = ch;
    }
}