#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp;
    fp = fopen("dict_test_utf8.txt", "r");
    char word[100];
    char input[100];
    int cnt=0;
    char *tok;
    if(fp == NULL){
            printf("ERROR\n");
    }
    else{    
        while(1){
        printf("단어?");
        fgets(input, 100, stdin);
        input[strlen(input)-1]='\0';
        while(fgets(word,100,fp)!=NULL){
            tok = strtok(word, " :");
            if(strcmp(tok,input)==0){
                while(tok!=NULL){
                    printf("%s", tok);
                    tok = strtok(NULL, ":");
                }
                break;
            }         
        }
        rewind(fp);      
    }
    fclose(fp);   
    }
}