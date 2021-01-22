//
//  main.c
//  타자게임
//
//  Created by abc on 2020/10/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printWord(int index, int len, char *word, int p){
    for(int index=0;index<len;index++){
        if(index==p){
            printf("(%c)",word[index]);
        }
        else {printf("%c", word[index]);
        }
    }
}

int wordlen(char *word ){
    int firstlen = strlen(word);
    if(firstlen<3){
        printf("too short\n");
        return 0;
    }
    return 1;
}

void compareWord(char *word1, char *word2){
    int i;
    int index2=0;
    int index=0;
    int len = strlen(word2);
    int len2 = strlen(word1);

    for(i=0;i<len;i++){
        char *ptr = strchr(word1, word2[i]);
        if(ptr != NULL){
            for(int j=0;j<len2;j++){
                if(word1[j] == *ptr){
                    printWord(index2, len2, word1,j);
                    printf(" - ");
                    printWord(index, len, word2,i);
                    printf("\n");
                    break;
                }
            }
            break;
        }
    }
    if(i==len){
        printf("no cross word\n");
    }
};

int main() {
    printf("3~10 사이의 글자입력\n");
    char word1[11];
    char word2[11];
    while(1){
        printf("Word?");
        scanf("%10s%*s",word1);
        if(wordlen(word1))
           break;
    }
    while(1){
        printf("Word?");
        scanf("%10s",word2);
        if(wordlen(word2)){
            compareWord(word1, word2);
            strncpy(word1, word2,sizeof(word1));
            word2[0] = '\0';
        }

    }
    return 0;
}
