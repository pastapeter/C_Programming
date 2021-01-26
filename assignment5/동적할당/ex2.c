#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * ReadUserName(){
    char* name = (char*)malloc(sizeof(char)*30);
    printf("What's your name?");
    fgets(name,29,stdin);
    name[strlen(name)-1] = '\0';
    return name;
}
int main(){
    int index=0;
    int index2=0;
    char* name1;
    char* name2;
    char* name3[index];
    char* name4[index];
    for(int i =0;i<3;i++){
        name3[i] = ReadUserName();
        index++;
    }
    for(int i =0;i<2;i++){
        name4[i] = ReadUserName();
        index2++;
    }

    for(int i =0;i<3;i++){
        printf("%s\n", name3[i]);
    }
    
   /* name1 = ReadUserName();
    printf("%s\n", name1);
    name2 = ReadUserName();
    printf("%s\n", name2);
    printf("%s\n", name1);
    printf("%s\n", name2);*/


    free(name1);
    free(name2);
}