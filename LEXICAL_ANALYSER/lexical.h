#ifndef LEXICAL_H
#define LEXICAL_H

#define SUCCESS 0
#define FAILURE -1
#define NOT_CLOSED -3
#define CLOSED 3
/* Header files */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_BUFF 100
// structures 
typedef struct bracket{
    int lineNumber;
    int openBracketCount;
    int closeBracketCount;
}Bracket;

typedef struct flowerBracket{
    int lineNumber;
    int openBracketCount;
    int closeBracketCount;
}FlowerBracket;

typedef struct squareBracket{
    int lineNumber;
    int openBracketCount;
    int closeBracketCount;
}SquareBracket;

extern int lineCount;
// functions to used
int readWord_and_tokenisation(char* file_name); 
int isKeyword(const char*);
int isSymbol(const char );
int isOperator(const char);
int isNumericConst(const char*);
int isIncrementOperator(const char ch);
int isDecrementOperator(const char ch);
int isCompoundOperator(const char ch);
int isMultiCharacterOperator(const char ch);
//int isTwoCharacterOperator(const char ch);

int isValid(int argc, char* argv[]);
int isCharacterConstant(FILE* fp);

void printKeyword(const char* );
void printSymbol(const char);
void printOperator(const char*);
void printNumericConst(const char*);
void printIdentifier(const char* str);
void printCharacterConstant(char);


int isOnlyDigits(char* str);
int checkIsValidIdentifier(char* str);
int isSpace(char);
void printStringLiteral(const char*);
void removePreprocessorDirective(FILE*);
//void removeComments(FILE* fp);
int checkIsComment(FILE* fp);
void removeSingleLineComment(FILE* fp);
void removeMultiLineComment(FILE* fp);
int checkForBrackets(char ch, Bracket* bracket, FlowerBracket* flowerBracket, SquareBracket* squareBracket);
int isDoubleQuotesClosed(FILE* fp);
//int isOneCharacter(FILE* fp);
//int isCharacter(const char*)
    
#endif