#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1개 비트로 가능

int main(){
    FILE* fp;
    fp  = fopen("number.bmp", "rb");

    fseek(fp, 62, SEEK_SET);
    char data[10][12], ch;
    int i, j, k;

     for(i=0;i<10;i++){
        fread(data[9-i],12,1,fp);
    }
    for(i=0;i<10;i++){
        for(j=0;j<11;j++){
            ch = data[i][j];
            for(k=4;k<12;k++){
                if(ch & (1<<(12-k)))printf(" ");
                else printf("*");
            }
        }
    printf("\n");
    }
    fclose(fp);

}
