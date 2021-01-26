
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char *str[10] ={"START", "Seoul","Tokyo","Sydney","LA","Cairo","Phuket","New delhi","Hanoi","Paris" };
struct city {
    char name[20];
    int owner;
    int spot;
    int fee;
    int price;
    char new_name[25];
    
}city[10] = {{"START", 0, 0, 500, 300},{"Seoul", 0,1, 500, 300},{"Tokyo", 0, 2, 500, 300},{"Sydney", 0,3, 500, 300},{"LA", 0,4, 500, 300},{"Cairo", 0, 5, 500, 300},{"Phuket", 0, 6, 500, 300} ,{"New delhi", 0, 7, 500, 300},{"Hanoi", 0 , 8, 500, 300},{"Paris",0,9, 500, 300}};
// 도시의 소유권  0 은 아무도 없음 , 1은 사용자1 2는 사용자2가 소유
struct player{
    int balance;
    int dice;
    int location;
}player1, player2;
void makemap1(int num1,int num2, int num3, int num4, int num5){
    if (player1.location == num1) {
        printf("                                                  (%d)\n", 1);
    }
    else if (player1.location == num2) {
        printf("                                       (%d)\n", 1);
    }
    else if (player1.location == num3) {
        printf("                            (%d)\n", 1);
    }
    else if (player1.location == num4) {
        printf("                (%d)\n", 1);
    }
    else if (player1.location == num5) {
        printf("      (%d)\n", 1);
    }
    
}
void makemap2(int num1,int num2, int num3, int num4, int num5){
      if (player2.location == num1) {
         printf("                                                  (%d)\n", 2);
      }
      else if (player2.location == num2) {
         printf("                                       (%d)\n", 2);
      }
      else if (player2.location == num3) {
         printf("                            (%d)\n", 2);
      }
      else if (player2.location == num4) {
         printf("                (%d)\n", 2);
      }
      else if (player2.location == num5) {
         printf("      (%d)\n", 2);
      }
}
void whowin(){
    if (player1.balance > player2.balance) {
       printf("player1 win!\n");
    }
    else if (player1.balance < player2.balance) {
       printf("player2 win!\n");
    }
}
int main() {
    srand((unsigned int)time(NULL));
    int turn = 1;
    
    player1.balance = 4000;
    player2.balance = 4000;
    player1.location = 0;
    player2.location = 0;
    
    while(turn <= 30){ //30턴이 돌았을때까지 게임 진행
        printf("turn : %d \n", turn);
        
   // ----------------  player1 first turn ------------------- //
        player1.dice = rand()%6 +1 ; // 주사위 돌리기
        printf("player 1 got %d\n", player1.dice);
        
        player1.location = (player1.location + player1.dice)%10;
        
        if(player1.location ==0){
            printf("START\n");
            printf("player 1's balance is %d\n", player1.balance);
        }
        else{
            if(city[player1.location].owner == 0){ // seoul empty
                printf("%s(%s)\n",city[player1.location].name, "empty");
                if(player1.balance >= city[player1.location].price){
                    printf("player1 buys %s\n", city[player1.location].name);
                    player1.balance = player1.balance-city[player1.location].price;
                    city[player1.location].owner = 1;
                    printf("player 1's balance is %d\n", player1.balance);
                    str[player1.location] = strcat(city[player1.location].name,"(1)");
                }
                else{
                    printf("cannot buy %s", city[player1.location].name);
                }
            }
            else if(city[player1.location].owner == 1){ // player1's city
               // printf("%s(%s)\n",city[player1.location].name, "1");
                printf("%s\n",city[player1.location].name);
                printf("player 1's balance is %d\n", player1.balance);
            }
            else if(city[player1.location].owner ==2){ //player2's city
                //printf("%s(%s)\n",city[player1.location].name, "2");
                printf("%s\n",city[player1.location].name);
                if(player1.balance < city[player2.location].fee){
                    printf("bankrupted\n");
                    break;
                }
                player1.balance = player1.balance - city[player1.location].fee;
                player2.balance = player2.balance + city[player1.location].fee;
                printf("player 1's balance is %d\n", player1.balance);
            }
        }
        printf("\n");
        //-------------------------------player2 ---------------------------------
        player2.dice = rand()%6+1;
        printf("player2 got %d\n", player2.dice);
        player2.location = (player2.location + player2.dice)%10;
        if(player2.location ==0){
            printf("START\n");
            printf("player 2's balance is %d\n", player2.balance);
        }
        else{
            if(city[player2.location].owner == 0){ // seoul empty
                printf("%s(%s)\n",city[player2.location].name, "empty");
                if(player2.balance >= city[player2.location].price){
                    printf("player2 buys %s\n", city[player2.location].name);
                    player2.balance = player2.balance-city[player2.location].price;
                    city[player2.location].owner = 1;
                   str[player2.location] = strcat(city[player2.location].name,"(2)");
                    printf("player2's balance is %d\n", player2.balance);
                }
                else{
                    printf("cannot buy %s", city[player2.location].name);
                }
            }
            else if(city[player2.location].owner == 2){ // player2's city
//                printf("%s(%s)\n",city[player2.location].name, "2");
                printf("%s\n",city[player2.location].name);
                printf("player2's balance is %d\n", player2.balance);
            }
            else if(city[player2.location].owner ==1){ //player1's city
                //printf("%s(%s)\n",city[player2.location].name, "1");
                printf("%s\n",city[player2.location].name);
                if(player2.balance < city[player1.location].fee){
                    printf("bankrupted\n");
                    break;
                }
                player2.balance = player2.balance - city[player1.location].fee;
                player1.balance = player1.balance + city[player2.location].fee;
                printf("player 2's balance is %d\n", player2.balance);
            }
        }
        printf("\n");
// -------------------------------빙고판 ----------------------------------
        printf("%10s %10s %10s %10s %10s\n", city[5].name,city[6].name,city[7].name,city[8].name,city[9].name );
        makemap1(9,8,7,6,5);
        makemap2(9,8,7,6,5);
        printf("\n\n\n");
        printf("%10s %10s %10s %10s %10s\n", city[4].name,city[3].name,city[2].name,city[1].name,city[0].name );
        makemap1(0,1,2,3,4);
        makemap2(0,1,2,3,4);
        printf("\n\n\n");
        if(player1.balance<0 || player2.balance<0)break;
        printf("Type Enterkey to Next turn");
        char str[10];
        fgets(str, 10, stdin);
        if(!strcmp(str,"\n")){
            turn++;
        }
    }
    printf("\n");
    whowin();
       
    return 0;
}
