#include "lexical.h"

/* array of operator*/
static const char *operators[] = {
    "+", "-", "*", "/", "%", "!", "~", "(", ")", "[", "]", "->", ".", "++", "--", 
    "+", "-", "&", "sizeof", "<<", ">>", "<", ">", "<=", ">=", "==", "!=", "^", "|", 
    "&&", "||", "=", "+=", "-=", "*=", "/=", "%=", "<<=", ">>=", "&=", "^=", "|=", ","
    };

/* array of keywords */
static const char* keywords[] = {
        "char", "int", "float", "double", "signed", "unsigned", "short",
        "long", "const", "volatile", "for", "while", "do", "goto", "break", "continue",
        "if", "else", "switch", "case", "default", "auto", "register", "static", "extern",
        "struct", "union", "enum", "typedef", "void", "return" };

/* special symbols */
static const char* symbols[] = {
    ";", "{", "}", ":"
};
// size of each array
int no_of_keywords = sizeof(keywords) / sizeof(keywords[0]);
int no_of_operators = sizeof(operators) / sizeof(operators[0]);
int no_of_symbols = sizeof(symbols) / sizeof(symbols[0]);


int isKeyword(const char* str)
{
    for (int i = 0; i < no_of_keywords; i++)
        if(strcmp(str, keywords[i])==0)
            return 1;
    return 0;
}
int isOperator(const char ch)
{
    char str[2] = {ch, '\0'};
    for (int i = 0; i < no_of_operators; i++)
        if(strcmp(str, operators[i])==0)
            return 1;
    return 0;
}
int isSymbol(const char ch)
{  
    char str[2] = {ch, '\0'};
    for (int i = 0; i < no_of_symbols; i++)
        if(strcmp(str, symbols[i])==0)
            return 1;
    return 0;
}

int isOnlyDigits(char* str)
{
    
    if(str[0] == '0') // this is for the diffrent number system
    {
        if(str[1] == 'b' || str[1] == 'B')
        {
            for(int i=2; str[i]; i++) // the digits must be between 1 and 0
            {
                if(str[i] < '0' || str[i] > '1')
                    return FAILURE;
            }
        }
        else if(str[1] == 'x' || str[1] == 'X') // for this case digits must be between 0 to F
        {
            for(int i=2; str[i]; i++)
            {
                if((!isdigit(str[i])) && (!(str[i] >= 'a' && str[i] <= 'f')) && (!(str[i] >= 'A' && str[i] <= 'F')))
                    return FAILURE;
            }
        }
        else 
        {
            for(int i=1; str[i]; i++)
            {
                if(!(str[i]>='0' && str[i]<='7'))
                    return FAILURE;
            }
        }
    }
    else
    {
        for(int i=0; str[i]; i++)
            if(!(isdigit(str[i])))
                return FAILURE;
    }

    return SUCCESS;
}

int isSpace(char ch)
{
    if(ch == ' ' || ch == '\n' || ch == '\t')
    {
        if (ch == '\n')
            lineCount++;
        return 1;
    }
    return 0;
}

int checkIsComment(FILE* fp)
{
    char nextCharacter;
    nextCharacter = fgetc(fp);
    if(nextCharacter == '/' || nextCharacter == '*')
    {
        if(nextCharacter == '/') // if it is a single line comment
            removeSingleLineComment(fp);
        else
            removeMultiLineComment(fp); // remove multiline comment
        return 1;
    }
    // if it is not the comment then return to previous character
    fseek(fp, -1, SEEK_CUR);
    return 0;
}
int isCharacterConstant(FILE* fp)
{
    char check = fgetc(fp);
    if(check == '\\')
    {
        fgetc(fp); // skip one more character
        char next = fgetc(fp);
        if(next != '\'')
        {
            return FAILURE;
        }
        fseek(fp, -3, SEEK_CUR);
        return SUCCESS;
    }
    check = fgetc(fp);
    if(check != '\'')
    {
        return FAILURE;
    }
    fseek(fp, -2, SEEK_CUR);
    return SUCCESS;
    
    /*fgetc(fp); // skipping character
    char ch = fgetc(fp);
    if(ch == '\'')
    {
        fseek(fp, -2, SEEK_CUR);
        return SUCCESS;  
    }
    fseek(fp, -2, SEEK_CUR);
    return FAILURE;*/
}
int checkIsValidIdentifier(char* str)
{
    if(isdigit(str[0]))
        return FAILURE;
    return SUCCESS;
}
int isMultiCharacterOperator(const char ch)
{
    if(ch == '+' || ch == '-' || ch == '<' || ch == '>' || ch == '*' || ch == '/' || ch == '%' || ch == '&' || ch == '^' || ch == '|' || ch == '=')
    {
        return SUCCESS;
    }
    return FAILURE;
}
int isTwoCharacterOperator(const char ch)
{
    if(ch == '+' || ch == '-'|| ch == '*' || ch == '/' || ch == '%' || ch == '&' || ch == '^' || ch == '|')
    {
        return SUCCESS;
    }
    return FAILURE;
}
int isIncrementOperator(const char ch)
{
    if(ch == '+')
        return SUCCESS;
    return FAILURE;
}
int isDecrementOperator(const char ch)
{
    if(ch == '-')
        return SUCCESS;
    return FAILURE;
}
int isCompoundOperator(const char ch)
{
    if(ch == '=')
        return SUCCESS;
    return FAILURE;
}
