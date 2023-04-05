/*
DOUBLE COMA
===========
an esolang similar to Thue or /// by that it replaces text.
It has only one function(commas) with three parameters - rmv,dbl,fmt
rmv - removes all instances of a character in a string (if rmv is acb and fmt is abcde, the output string is de)
dbl - doubles all instances off a character in a string (if dbl is cba and fmt is abcde, the output is aabbccde)
fmt - formatted string
(also, any string cant be empty and cannot contain coma. have fun :) )
examples:
acb,bca,abcde -> de
t,el,telephone ->eelleephonee
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* rmStr(char* fmft, char* rmv){
    for(int x=0;x<sizeof(fmft);x++){
        if(strchr(rmv,fmft[x])!=NULL){
            fmft[x]='\a';
        }
    }
    return fmft;
}
char* dblStr(char* fmt, char* dbl){
    char* data = malloc(sizeof(fmt)*2+1+1000);
    int offset=0;
    for(int x=0;x<strlen(fmt);x++){
        data[x+offset]=fmt[x];
        if(strchr(dbl,fmt[x])!=NULL){
            data[x+1+offset]=fmt[x];
            offset++;
        }
    }
    char* result= strdup(data);
    free(data);
    return result;
    
}

void main(){
    char *code = malloc(10000*sizeof(char));
    //loads and tokenizes string
    printf("\n>> ");
    fgets(code, 1000, stdin);
    if (code[strlen(code) - 1] == '\n'){
        code[strlen(code) - 1] = '\0';
    }
    char* rmv= strtok(code,",");
    if(rmv==NULL){main();printf("\nSYNTAX ERR\n");}
    char* dbl= strtok(NULL,",");
    if(dbl==NULL){main();printf("\nSYNTAX ERR\n");}
    char* fmt= strtok(NULL,",");
    if(fmt==NULL){main();printf("\nSYNTAX ERR\n");}

    //actually does stuff
    char* data = malloc(sizeof(fmt)*2+1);
    int offset=0;
    printf("<< %s", dblStr(rmStr(fmt, rmv), dbl));

    main();

}