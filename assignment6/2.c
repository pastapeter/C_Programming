#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char randompick() { // 랜덤한 문자열 생성
      return 'A' + (rand() % 26);
}

int main() {
   srand((unsigned int)time(NULL));
   char str[100][51] = {0};
   char *str2[100];
   char *temp;
   char bubblestr[51] = {0};
   char *bubble = NULL;
   int i,j, length;
   for(i=0;i<100;i++){
       length = rand()%21+30;
       for(j=0;j<length;j++){
           str[i][j] = randompick();
       }
   }
   for(i=0;i<100;i++){
       length = rand()%21+30;
       temp = (char*)malloc(sizeof(char)*length);
       for(j=0;j<length;j++){
           temp[j] = randompick();
       }
       str2[i] = (char*)malloc(sizeof(char)*strlen(temp));
       str2[i] = temp;
   }
   free(temp);
    for(i=0;i<99;i++){
       for(j=0;j<99-i;j++){
           if(strcmp(str[j],str[j+1])>0){
               strcpy(bubblestr, str[j]);
               strcpy(str[j], str[j+1]);
               strcpy(str[j+1],bubblestr);
           }
       } 
    }
    for(i=0;i<100;i++){
        printf("정적할당한 문자열 정렬 %s\n", str[i]);
    }
    for(i=0;i<99;i++){
       for(j=0;j<99-i;j++){
           if(strcmp(str2[j],str2[j+1])>0){
               bubble = str2[j];
               str2[j] = str2[j+1];
               str2[j+1] = bubble;
           }
       } 
    }
    for(i=0;i<100;i++){
        printf("동적할당한 문자열 정렬 %s\n", str2[i]);
    }
    for(i=0;i<100;i++){
        free(str2[i]);
    }
}