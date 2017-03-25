#include "HString_Util.h"

char* createstr(const char* init)
{
    return strdup(init);
}

void freestr(char* string)
{
    if(string == NULL){
        return;
    }

    free(string);
}

char* initnstr(int n)
{
    if(n == 0){
        return NULL;
    }

    char* string = malloc(n * sizeof(char));
    memset(string,'\0',n);

    return string;
}

char* extendstr(char* string,int n)
{
    int strLen = strlen(string);
    int newstrlen = (strLen + n + 1);
    char* newString = malloc(newstrlen * sizeof(char));

    memset(newString,'\0',newstrlen);
    strncpy(newString,string,strLen);

    freestr(string);
    string = newString;

    return string;
}

char** splitstr(char* string, char* delims)
{
    int n_tokens = 1;
    char* stringcpy = strdup(string);//copy for strtok to destroy.
    char** strArray = malloc(n_tokens * sizeof(char*));

    char* token = strtok(stringcpy,delims);
    while(token != NULL){
        strArray[n_tokens - 1] = createstr(token);
        strArray = realloc(strArray, ++n_tokens * sizeof(char*));

        token = strtok(NULL,delims);
    }

    freestr(stringcpy);
    return strArray;
}