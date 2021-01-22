#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


int index1[12]={0};
int index2[12] = {0};
int count1 =0;
int count2 = 0;
int horizonBingoCheck1(int bingo1[][5], int x, int hori1, int hori2, int hori3, int hori4, int hori5){
    return  bingo1[x][hori1]==100&&bingo1[x][hori2]==100&&bingo1[x][hori3]==100&&bingo1[x][hori4]==100&&bingo1[x][hori5]==100;
};
int horizonBingoCheck2(int bingo2[][5], int x, int hori1, int hori2, int hori3, int hori4, int hori5){
    return  bingo2[x][hori1]==100&&bingo2[x][hori2]==100&&bingo2[x][hori3]==100&&bingo2[x][hori4]==100&&bingo2[x][hori5]==100;
};
void outOfCheck1(int index1[12], int i){
    if(index1[i]==0){
        count1++;
    }
    index1[i] =1;
};
void outOfCheck2(int index2[12], int i){
    if(index2[i]==0){
        count2++;
    }
    index2[i] =1;
};
int verticalBingoCheck1(int bingo1[][5], int y, int vert1, int vert2, int vert3, int vert4, int vert5){
    return bingo1[vert1][y]==100&&bingo1[vert2][y]==100&&bingo1[vert3][y]==100&&bingo1[vert4][y]==100&&bingo1[vert5][y]==100;};

int verticalBingoCheck2(int bingo2[][5], int y, int vert1, int vert2, int vert3, int vert4, int vert5){
    return bingo2[vert1][y]==100&&bingo2[vert2][y]==100&&bingo2[vert3][y]==100&&bingo2[vert4][y]==100&&bingo2[vert5][y]==100;};

void printbingo(int arr[][5], int arr2[][5], int personOrCom){
    if(personOrCom == 1){
        printf("너의 빙고판\n");
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(arr[i][j]==100){printf("(%2d)", arr2[i][j]);}
                else{
                    printf(" %2d ", arr2[i][j]);
                }
            }
            printf("\n");
        }
    }
    else if(personOrCom==2){
        printf("컴퓨터의 빙고판\n");
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(arr[i][j]==100){printf("(%2d)", arr2[i][j]);}
                else{
                    printf(" %2c ", arr2[i][j]);
                }
            }
            printf("\n");
        }
    }
};


void makeNum(int arr[25]){
    for(int i=0; i<25; i++){
        arr[i] = i+1;
    }
};
void mixNum(int arr[25], int mixCount){
    for(int i=0; i< mixCount; i++){
        int temp;
       int x = rand()%25;
       int y = rand()%25;
        if(x!=y){
        temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;}
    }
};
void makeBingo(int bingo1[][5], int bingo2[][5], int num[25], int index){
    for(int i=0;i<5;i++){
         for(int j=0;j<5;j++){
             printf("사람이 숫자 고른다\n");
             printf("1 ~ 25까지 사용하시오\n");
             scanf("%d", &bingo1[i][j]);
             printf("컴퓨터가 숫자를 고를차례\n");
             bingo2[i][j] = num[index];
             index++;
         }
     }
};
void avoidRepeat(int chosenNum[25], int i){
    srand((unsigned)time(NULL));
    int temp=0;
    int flag;
    while(1){
        flag =1;
        temp = (rand()%25) +1;
        for(int k=0; k<i; k++){
            if(temp == chosenNum[k]){
                    flag = 0;
                }
        }
        if(flag == 1){
            chosenNum[i] = temp;
            break;
                }
    }
};
void makeCheck(int bingo1[][5], int bingo2[][5],int bingo3[][5], int bingo4[][5], int chosenNum[25], int i,int check){
    for(int a=0; a<5;a++){
        for(int b=0; b<5; b++){
            if(bingo1[a][b]==chosenNum[i]){
                bingo1[a][b] = check;
            }
            if(bingo2[a][b]==chosenNum[i]){
                int temp = bingo2[a][b];
                bingo2[a][b] = check;
                bingo3[a][b] = temp;
            }
        }
    }
};
int main(){
    srand( (unsigned)time(NULL) );
    int bingo1[5][5] = {0};
    int bingo2[5][5] = {0};
    int bingo3[5][5] = {0};
    int bingo4[5][5] = {0};
    int i;
    int index=0;
    int num[25];
    makeNum(num); //25개 차례로 만들기
    mixNum(num, 50); // 25개 섞어주기 50번
    makeBingo(bingo1, bingo2, num, index);
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            bingo3[i][j] = '-';
        }
    }
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            bingo4[i][j] = bingo1[i][j];
        }
    }
    printbingo(bingo1,bingo4, 1);
    printbingo(bingo2, bingo3, 2);


    int chosenNum[25] = {0};
    i =0;
    int check = 100;
    int col[5];
    int row[5];
    int right;
    int left;
    while(1){
        for(int l=0; l<5; l++){
            col[l] = 0;
            row[l] = 0;
        }
        right = 0;
        left = 0;
        for(int k=0; k< 5; k++){
            if(bingo2[0][k]==100){
                row[0]++;
                }
            if(bingo2[1][k]==100){
                row[1]++;
            }
            if(bingo2[2][k]==100){
                row[2]++;
            }
            if(bingo2[3][k]==100){
                row[3]++;
            }
            if(bingo2[4][k]==100){
                row[4]++;
            }
            if(bingo2[k][0]==100){
                col[0]++;
            }
            if(bingo2[k][1]==100){
                col[1]++;
            }
            if(bingo2[k][2]==100){
                col[2]++;
            }
            if(bingo2[k][3]==100){
                col[3]++;
            }
            if(bingo2[k][4]==100){
                col[4]++;
            }
            if(bingo2[k][k] == 100){
                left++;
            }
            if(bingo2[4-k][k]==100){
                right++;
            }
        }
        if(i<2){
            printf("사람 숫자를 골라주세요\n");
            scanf("%d", &chosenNum[i]);
            makeCheck(bingo1,bingo2,bingo3, bingo4, chosenNum, i,check);
            i++;
            printf("컴퓨터 숫자를 골라주세요\n"); // 처음에 컴퓨터 가운데 숫자고르기
            if(chosenNum[i-1] != bingo2[2][2]){
                chosenNum[i] = bingo2[2][2];
            }
            printf("%d\n", chosenNum[i]);
            makeCheck(bingo1,bingo2,bingo3, bingo4,chosenNum, i,check);
            i++;
            printbingo(bingo1,bingo4, 1);
            printbingo(bingo2, bingo3, 2);
        }
        else {
            printf("사람 숫자를 골라주세요\n");
            scanf("%d", &chosenNum[i]);
            makeCheck(bingo1,bingo2,bingo3, bingo4,chosenNum, i,check);
            i++;
            
            if(col[0]==4){
                for(int k=0;k<5;k++){
                    if(bingo2[k][0] != 100){
                        chosenNum[i] = bingo2[k][0];
                        break;
                    }
                }
            }
            else if(col[1]==4){
                for(int k=0;k<5;k++){
                    if(bingo2[k][1] != 100){
                        chosenNum[i] = bingo2[k][1];
                        break;
                    }
                }
            }
            else if(col[2]==4){
                for(int k=0;k<5;k++){
                    if(bingo2[k][2] != 100){
                        chosenNum[i] = bingo2[k][2];
                        break;
                    }
                }
            }
            else if(col[3]==4){
                for(int k=0;k<5;k++){
                    if(bingo2[k][3] != 100){
                        chosenNum[i] = bingo2[k][3];
                        break;
                    }
                }
            }
            else if(col[4]==4){
                for(int k=0;k<5;k++){
                    if(bingo2[k][4] != 100){
                        chosenNum[i] = bingo2[k][4];
                        break;
                    }
                }
            }
            else if(row[0]==4){
                for(int k=0;k<5;k++){
                    if(bingo2[0][k] != 100){
                        chosenNum[i] = bingo2[0][k];
                        break;
                    }
                }
            }
            else if(row[1]==4){
                for(int k=0;k<5;k++){
                    if(bingo2[1][k] != 100){
                        chosenNum[i] = bingo2[1][k];
                        break;
                    }
                }
            }
            else if(row[2]==4){
                for(int k=0;k<5;k++){
                    if(bingo2[2][k] != 100){
                        chosenNum[i] = bingo2[2][k];
                        break;
                    }
                }
            }
            else if(row[3]==4){
                for(int k=0;k<5;k++){
                    if(bingo2[3][k] != 100){
                        chosenNum[i] = bingo2[3][k];
                        break;
                    }
                }
            }
            else if(row[4]==4){
                for(int k=0;k<5;k++){
                    if(bingo2[4][k] != 100){
                        chosenNum[i] = bingo2[4][k];
                        break;
                    }
                }
            }
            else if(left==4){
                for(int k=0;k<5;k++){
                    if(bingo2[k][k] != 100){
                        chosenNum[i] = bingo2[k][k];
                        break;
                    }
                }
            }
            else if(right==4){
                for(int k=0;k<5;k++){
                    if(bingo2[4-k][k] != 100){
                        chosenNum[i] = bingo2[4-k][k];
                        break;
                    }
                }
            }
            else{ printf("컴퓨터 숫자를 골라주세요\n");
                avoidRepeat(chosenNum, i);
            }
            printf("%d\n", chosenNum[i]);
            makeCheck(bingo1,bingo2,bingo3, bingo4, chosenNum, i,check);
            i++;
            printbingo(bingo1,bingo4, 1);
            printbingo(bingo2,bingo3,2);
            }
            
    
        
        //가로빙고
            while(horizonBingoCheck1(bingo1,0,0,1,2,3,4)){
                   outOfCheck1(index1, 0);
                   break;
                   }
               while(horizonBingoCheck2(bingo2, 0, 0, 1, 2, 3, 4)){
                   outOfCheck2(index2, 0);
                   break;
                   }
               while(horizonBingoCheck1(bingo1, 1, 0, 1, 2, 3, 4)){
                 outOfCheck1(index1, 1);
                 break;
                 }
               while(horizonBingoCheck2(bingo2, 1, 0, 1, 2, 3, 4)){
                 outOfCheck2(index2, 1);
                 break;
                 }
               while(horizonBingoCheck1(bingo1,2,0,1,2,3,4)){
                   outOfCheck1(index1, 2);
                   break;
                   }
               while(horizonBingoCheck2(bingo2,2,0,1,2,3,4)){
                   outOfCheck2(index2, 2);
                   break;
                   }
               while(horizonBingoCheck1(bingo1,3,0,1,2,3,4)){
                   outOfCheck1(index1, 3);
                   break;
                   }
               while(horizonBingoCheck2(bingo2,3,0,1,2,3,4)){
                   outOfCheck2(index2, 3);
                   break;
                   }
               while(horizonBingoCheck1(bingo1,4,0,1,2,3,4)){
                   outOfCheck1(index1, 4);
                   break;
                   }
               while(horizonBingoCheck2(bingo2,4,0,1,2,3,4)){
                   outOfCheck2(index2, 4);
                   break;
                   }
               //세로빙고
               while(verticalBingoCheck1(bingo1,0,0,1,2,3,4)){
                   outOfCheck1(index1, 5);
                   break;
                   }
               while(verticalBingoCheck2(bingo2,0,0,1,2,3,4)){
                   outOfCheck2(index2, 5);
                   break;
                   }
               while(verticalBingoCheck1(bingo1,1,0,1,2,3,4)){
                   outOfCheck1(index1, 6);
                   break;
                   }
               while(verticalBingoCheck2(bingo2,1,0,1,2,3,4)){
                   outOfCheck2(index2, 6);
                   break;
                   }
               while(verticalBingoCheck1(bingo1,2,0,1,2,3,4)){
                   outOfCheck1(index1, 7);
                   break;
                   }
               while(verticalBingoCheck2(bingo2,2,0,1,2,3,4)){
                   outOfCheck2(index2, 7);
                   break;
                   }
               while(verticalBingoCheck1(bingo1,3,0,1,2,3,4)){
                   outOfCheck1(index1, 8);
                   break;
                   }
               while(verticalBingoCheck2(bingo2,3,0,1,2,3,4)){
                   outOfCheck2(index2, 8);
                   break;
                   }
               while(verticalBingoCheck1(bingo1,4,0,1,2,3,4)){
                   outOfCheck1(index1, 9);
                   break;
                   }
               //대각선 빙고
              while(bingo1[0][0]==100&&bingo1[1][1]==100&&bingo1[2][2]==100&&bingo1[3][3]==100&&bingo1[4][4] == 100){
                  outOfCheck1(index1, 10);
                  break;
                  }
               while(bingo2[0][0]==100&&bingo2[1][1]==100&&bingo2[2][2]==100&&bingo2[3][3]==100&&bingo2[4][4] == 100){
                   outOfCheck2(index2, 10);
                   break;
                   }
              while(bingo1[0][4]==100&&bingo1[1][3]==100&&bingo1[2][2]==100&&bingo1[3][1]==100&&bingo1[4][0] == 100){
                  outOfCheck1(index1, 11);
                  break;
                  }
               while(bingo2[0][4]==100&&bingo2[1][3]==100&&bingo2[2][2]==100&&bingo2[3][1]==100&&bingo2[4][0] == 100){
                   outOfCheck2(index2, 11);
                   break;
                   }

        printf("나의 빙고 현황 : %d 컴퓨터의 빙고 현황: %d\n", count1, count2);
        if(count1 >4 || count2>4)break; // 5개 되면 while문 나오기
    }

if(count1 >4){
    printf("사람 승\n");
    
}
else{
    printf("컴퓨터승\n");
}

    return 0;
}
