#include "lexical.h"

int checkForBrackets(char ch, Bracket* bracket, FlowerBracket* flowerBracket, SquareBracket* squareBracket)
{
    if(ch == '('|| ch == '{' || ch == '[' || ch == ']' || ch == '}'|| ch == ')')
    {
        if(ch == '(' || ch == ')')
        {
            if(ch == '(')
            {
                bracket->lineNumber = lineCount; // 4
                bracket->openBracketCount++; // 1
            }
            else if(ch == ')')
            {
                bracket->closeBracketCount++;
                if (bracket->closeBracketCount != bracket->openBracketCount) {
                printf("ERROR: unexpected ')' at line %d\n", lineCount);
                    return NOT_CLOSED;
                }
            }
        }
        else if(ch == '{' || ch == '}')
        {
            if(ch == '{')
            {
                flowerBracket->lineNumber = lineCount;
                flowerBracket->openBracketCount++;
            }
            else 
            {
                flowerBracket->closeBracketCount++;
            }
        }
        else if(ch == '[' || ch == ']')
        {
            if(ch == '[')
            {
                squareBracket->lineNumber = lineCount;
                squareBracket->openBracketCount++;
            }
            else if(ch == ']')
            {
                squareBracket->closeBracketCount++;
                if (squareBracket->closeBracketCount != squareBracket->openBracketCount) {
                    printf("ERROR: unexpected ']' at line %d\n", lineCount);
                    return NOT_CLOSED;
                }
            }
        }
    }

    // this check is for the normal bracket closing one exception for the for loop because there we are using ; inside (brackets)
    if((ch == '\n' || ch == '{')&& (bracket->openBracketCount != bracket->closeBracketCount))
    {
        if(bracket->openBracketCount > bracket->closeBracketCount)
        {
            printf("ERROR: expected \')\' at line %d\n", bracket->lineNumber);
        }
        else
        {
            printf("ERROR: expected \'(\' at line %d\n", lineCount-1);
        }
        
        return NOT_CLOSED;
    }
    /*else if ((ch == ';' || ch == '{')&& (bracket->openBracketCount == bracket->closeBracketCount))
    {
        bracket->openBracketCount = bracket->closeBracketCount = 0;
    }*/
    // this check is for the square bracket closing 
    if((ch == ';' || ch == '{')&& (squareBracket->openBracketCount != squareBracket->closeBracketCount))
    {
        if(squareBracket->openBracketCount > squareBracket->closeBracketCount)
        {
            printf("ERROR: excpected \']\' at line %d\n", squareBracket->lineNumber);
        }
        else
        {
            printf("ERROR: excpected \'[\' at line %d\n", lineCount);
        }
        //printf("open bracket = %d\nclose bracket = %d\n", squareBracket->openBracketCount, squareBracket->closeBracketCount);
        
        return NOT_CLOSED;
    }
    /*else if((ch == ';' || ch == '{')&& (squareBracket->openBracketCount == squareBracket->closeBracketCount))
    {
        squareBracket->openBracketCount = squareBracket->closeBracketCount = 0;
    }*/
    return CLOSED;
}
// now the error handling for the ; pending
/*
 -> For this i can take a flag for keywords (if, else, for, while, do while, switch)
    because after this semicolan is not needed 
 -> and if it is a structure then after flower bracket closing there should be semicolan
    (struct, enum at the end of the } there should be seicolan and if the } not there then its a error)
*/

// error handling for the { closing is pending

// error handling for " (double quatos is pending) and single quotes is pending
int isDoubleQuotesClosed(FILE* fp)
{
    char ch;
    int count = 0;
    while((ch = fgetc(fp))!=EOF)
    {
        count++;
        if(ch == '\\')
        {
            fgetc(fp);
            //continue;
        }
        if(ch == ';')
        {
            printf("ERROR: expected \" at line %d \n", lineCount);
            return NOT_CLOSED;
        }
        if(ch == '"')
        {
            fseek(fp, -count,SEEK_CUR);
            return CLOSED;
        }
       
    }
}

// error handling for multiple characters int the single quotes
/*int isOneCharacter(FILE* fp)
{
    char check = fgetc(fp);
    if(check == '\\')
    {
        fgetc(fp); // skipping the character after the slash
        char next = fgetc(fp);
        if(next != '\'')
        {
            printf("ERROR: at line %d SYNTAX IS NOT VALID\n", lineCount);
            return FAILURE;
        }
        else
        {
            return SUCCESS;
        }
    }
    else
    {
        char next = fgetc(fp);
        if(next != '\'')
        {
            printf("ERROR: at line %d SYNTAX IS NOT VALID\n", lineCount);
            return FAILURE;
        }
        else
            return SUCCESS;
    }
    /*char check = fgetc(fp); // skipping the character
    if(check == '\\')
    {
        fgetc(fp); // skip the character
        char next = fgetc(fp);
        if(next != '\'')
        {
            printf("ERROR: at line %d SYNTAX IS NOT VALID\n", lineCount);
            return FAILURE;
        }
        fseek(fp, -3, SEEK_CUR);
    }
    else
    {
        char next = fgetc(fp); // skip the character
        if(next != '\'')
        {
            printf("ERROR: at line %d SYNTAX IS NOT VALID\n", lineCount);
            return FAILURE;
        }
        fseek(fp, -2, SEEK_CUR);
    }
    
    
    return SUCCESS;
}*/

//error handling for the 