#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void makesame(int len1, int len2, char* s){
    int num = abs(len1 - len2);
        for(int k=0;k<num;k++){
            *(s+k) = '0';
        }
        s[num] = '\0';
}
void add(int len1, int len2, char *x, char*y, char *result){
    int sum = 0, upper =0, index = 0;
    int i,j;
    char add_x[100] = {0};
    char add_y[100] = {0};
    strcpy(add_x,x);
    strcpy(add_y, y);
    for(i=len1-1, j=len2-1; i>-1,j>-1; i--, j--){
            sum = (*(add_x+i)-'0') + (*(add_y+j)-'0') + upper;
            if(sum>=10){
                result[index] = sum%10+'0';
                upper = 1;
                if(i==0&&j==0){
                    result[index+1]=upper+'0';
                }
            }
            else if(sum<10){
                result[index] = sum+'0';
                upper =0;
            }
            index++;
        }
        result[index+1]= '\0';
}
void cha(int len1, int len2, char *x, char*y, char* result){
    int minus = 0, index = 0, upper =0;
    int i,j;
    char min_x[100] = {0};
    char min_y[100] = {0};
    strcpy(min_x,x);
    strcpy(min_y,y);
    for(i=len1-1, j=len2-1; i>-1, j>-1;i--, j--){
        if(strcmp(x,y)<0){
           if(*(min_y+j)>=*(min_x+i)){
            upper =0;
            minus = upper+(*(min_y+j)-'0') - (*(min_x+i)-'0');
            result[index] = minus+'0';
            }
            else{
                upper = 10;
                min_y[j-1] = min_y[j-1]-1;
                minus = upper+(*(min_y+j)-'0') - (*(min_x+i)-'0');
                result[index] = (minus)+'0';
            }
            result[len2] = '-';
        }
        else{
            if(*(min_x+i)>=*(min_y+j)){
            upper =0;
            minus = upper+(*(min_x+i)-'0') - (*(min_y+j)-'0');
            result[index] = minus+'0';
            }
            else{
                upper = 10;
                min_x[i-1] = min_x[i-1]-1;
                minus = upper+(*(min_x+i)-'0') - (*(min_y+j)-'0');
                result[index] = (minus)+'0';
            }
        }
        index ++;
    }
    result[index+1] = '\0';
}

void gop(int len1, int len2, char *str1, char*str2, char* result){
    int multi = 0,index = 0;
    unsigned long long int add[100] = {0};
    char multi_x[100] ={0};
    char multi_y[100] = {0};
    strcpy(multi_x, str1);
    strcpy(multi_y, str2);
    len1 = strlen(multi_x);
    len2 = strlen(multi_y);
    int i,j;
    for(i=len1-1; i>-1;i--){
        for(j=len2-1;j>-1;j--){
            multi = (multi_x[i]-'0') * (multi_y[j]-'0');
            if(multi > 9){
               add[i+j] += multi/10;
               add[i+j+1] += multi%10;
               printf("add[%d] = %d\n", i+j, add[i+j]);
                printf("add[%d] = %d\n", i+j+1, add[i+j+1]);
            }
            else{
                add[i+j+1] += multi;
                printf("add[%d] = %d\n", i+j+1, add[i+j+1]);
            }
        }
    }
 
    for(index=len1+len2; index>0;index--){
        if(add[index]>9 && add[index]<=99){
            add[index-1] += add[index]/10;
            add[index] = add[index]%10;
        }
        else if(add[index]>99 && add[index]<=999){
            add[index-2] += add[index]/100;
            add[index-1] += (add[index]%100)/10;
            add[index] = add[index]%10;
        }

    }
    for(int k=0; k<len1+len2; k++){
        if(add[0]!=0){
            result[k] = add[k]+'0';
            result[len1+len2] = '\0';
        }
        else{
           result[k] = add[k]+'0';
           result[len1+len2+1] = '\0';
        }

    }
    int printindex = 0;
    while(result[printindex]=='0'){
        printindex++;
    }
    printf("X * Y = ");
    for (int i = printindex;i<strlen(result);i++){
        printf("%c",result[i]);
    }
}
void print(char* result){
    for(int k = strlen(result)-1; k>-1;k--){
            printf("%c", result[k]);
        }
        printf("\n");
}
void plus(char *str1, char *str2){ //더하기 함수
    char result[100] = {0};
    char *x = str1;
    char *y = str2;
    char s[100] = {0};
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    //자리수 같을때
    if(len1==len2){
        add(len1, len2, x,y,result);
    }
    else{
        makesame(len1, len2, s);
        if(len1>len2){
            strcat(s,str2);
            add(len1, strlen(s), x,s,result);
        }
        else{
            strcat(s,str1);
            add(strlen(s), len2, s,y,result);
        }
    }
    printf("X + Y = ");
    print(result);
}

void minus(char *str1, char *str2){ // 빼기함수
    char result[100] = {0};
    char *x = {0};
    char *y = {0};
    x =str1;
    y = str2;
    char s[100] = {0};
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(len1>len2){
       makesame(len1, len2, s);
       strcat(s,y);
       cha(len1, strlen(s), x,s,result);
    }
    else if(len1<len2){
        makesame(len1, len2, s);
        strcat(s,x);
        cha(strlen(s), len2, s,y,result);
    }
    else if(len1==len2){
        cha(len1, len2, x,y,result);
    }
    printf("X - Y = ");
    print(result);
}
void multiply(char *str1, char *str2){ //곱하기 함수
    char result[120] = {0};
    char *x = {0};
    char *y = {0};
    x = str1;
    y = str2;
    char s[100] = {0};
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(len1>len2){
       makesame(len1, len2, s);
       strcat(s,str2);
       gop(len1, strlen(s), x,s,result);
    }
    else if(len1<len2){
        makesame(len1, len2, s);
        strcat(s,str1);
        gop(strlen(s), len2, s,y,result);
    }
    else if(len1==len2){
        gop(strlen(x), strlen(y), x,y,result);
    }
}

int main(){
    char strx[50] = {0};
    char stry[50] = {0};
    printf("input x");
   fgets(strx,100,stdin);
    strx[strlen(strx)-1] = '\0';
    printf("input y");
    fgets(stry,100,stdin);
    stry[strlen(stry)-1] = '\0';
    plus(strx, stry);
    minus(strx, stry);
    multiply(strx, stry);
    
    
}
