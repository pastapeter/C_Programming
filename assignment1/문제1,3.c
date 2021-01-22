#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HORIZON '_' // 가로선
#define VERTICAL '|' //세로선
#define BLANK ' ' //빈칸
#define HEIGHT 20
#define HEIGHT2 15

enum route { A, B, C, D, E };
char player[5] = { '1','2','3','4','5' };

int result[5][5] = { 0 }; //통계값을 찾자
char makeway[5] = {0}; // 결과값 저장


void makeLadder(int arr[][9], int col, int row) { //사다리만들기
    char route = 'A';
    int count = 0;
    // 0행에 플레이어들
    for (int i = 0; i < 9; i = i + 2) {
        arr[0][i] = player[count];
        count++;
    }
    for (int i = 1; i < 9; i = i + 2) {
        arr[0][i] = ' ';
    }
    //19행에 루트들
    for (int i = 0; i < 9; i = i + 2) {
        arr[14][i] = route;
        route++;
    }
    for (int i = 1; i < 9; i = i + 2) {
        arr[14][i] = ' ';
    }

    // 세로줄 만들기
    for (int i = 1; i < HEIGHT2 - 1; i++) {
        for (int j = 0; j < col; j++) {
            if (j % 2 == 0) { //세로줄 생성
                arr[i][j] = VERTICAL;
            }
            else {
                arr[i][j] = BLANK;
            }
        }
    }

    // 가로줄 만들기인데 세로부터 시작
    int verticalStart = 1;
    int slash = 0;

    while (verticalStart < 9) {

        while (slash < 4) {
            int random = rand() % (HEIGHT2 - 2) + 1; // 1~ 18사이에 랜덤 뽑기

            if (arr[random][verticalStart] != HORIZON) {

                //verticalStart가 1인거 예외
                if (verticalStart > 2 && arr[random][verticalStart - 2] == HORIZON)
                    continue;

                arr[random][verticalStart] = HORIZON;
                slash++;
            }
            else
                continue;
        }
        verticalStart = verticalStart + 2;
        slash = 0;
    }

    for (int j = 1; j < col; j = j + 2) {
        for (int i = 1; i < row - 1; i++)
        {
            int random = rand() % (HEIGHT2 - 2) + 1;
            int verticalStart = (rand() % 4 * 2) + 1;

            if (verticalStart == 1) { //맨 왼쪽 줄
                if (arr[random][verticalStart] != HORIZON && arr[random][verticalStart + 2] != HORIZON) {
                    if (rand() % 2 != 0) {
                        arr[random][verticalStart] = HORIZON;
                    }
                    else {
                        arr[random][verticalStart] = BLANK;
                    }
                }
            }
            else if (verticalStart == 7) { //맨 오른쪽 줄
                if (arr[random][verticalStart] != HORIZON && arr[random][verticalStart - 2] != HORIZON) {
                    if (rand() % 2 != 0) {
                        arr[random][verticalStart] = HORIZON;
                    }
                    else {
                        arr[random][verticalStart] = BLANK;
                    }
                }
            }
            else { //가운데 2줄
                if (arr[random][verticalStart] != HORIZON && arr[random][verticalStart - 2] != HORIZON && arr[random][verticalStart + 2] != HORIZON) {
                    if (rand() % 2 != 0) {
                        arr[random][verticalStart] = HORIZON;
                    }
                    else {
                        arr[random][verticalStart] = BLANK;
                    }
                }
            }
        }
    }

};

void printLadder(int arr[][9], int col, int row) { //사다리프린트
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
};

void rideLadder(int arr[][9], int col, int row) {
    int j = 0;
    int person = 1;
    char route[5] = {'A','B','C','D','E'};
    while (person <= 5)
    {
        j = 2 * (person - 1);
        for (int i = 1; i < HEIGHT2 - 1; i++) {
            // j=0이면 사람A
            if (arr[i][j + 1] == HORIZON) {
                j = j + 2;
            }
            else if (j >= 2 && arr[i][j - 1] == HORIZON) {
                j = j - 2;
            }
        }// 0 2 4 6 8 -> 01234
        if (j == 0) { //A번에 도착할 경우 k는 사람 j는 도착
            printf("%d는 %c\n", person, route[j/2]);
            result[person - 1][j/2]++;
            makeway[person-1] = j/2+1;
        }
        else if (j == 2) { //B번에 도착할 경우
            printf("%d는 %c\n", person, route[j/2]);
            result[person - 1][j/2]++;
            makeway[person-1] = j/2+1;
        }
        else if (j == 4) { //C번에 도착할 경우
            printf("%d는 %c\n", person,route[j/2]);
            result[person - 1][j/2]++;
            makeway[person-1] = j/2+1;
        }
        else if (j == 6) { //D번에 도착할경우
            printf("%d는 %c\n", person, route[j/2]);
            result[person - 1][j/2]++;
            makeway[person-1] = j/2+1;
        }
        else { //E번에 도착할경우
            printf("%d는 %c\n", person, route[j/2]);
            result[person - 1][j/2]++;
            makeway[person-1] = j/2+1;
        }
        person++;
    }
};

void newRideLadder(int arr[][9]) {
    int j = 0;
    int person = 1;
    char route[5] = {'A','B','C','D','E'};
    while (person <= 5)
    {
        j = 2 * (person - 1);
        for (int i = 1; i < HEIGHT - 1; i++) {
            // j=0이면 사람A
            if (arr[i][j + 1] == HORIZON) {
                j = j + 2;
            }
            else if (j >= 2 && arr[i][j - 1] == HORIZON) {
                j = j - 2;
            }
        }// 0 2 4 6 8 -> 01234
        if (j == 0) { //A번에 도착할 경우 k는 사람 j는 도착
            printf("%d는 %c\n", person, route[j/2]);
        
        }
        else if (j == 2) { //B번에 도착할 경우
            printf("%d는 %c\n", person, route[j/2]);
        
        }
        else if (j == 4) { //C번에 도착할 경우
            printf("%d는 %c\n", person,route[j/2]);
            
        }
        else if (j == 6) { //D번에 도착할경우
            printf("%d는 %c\n", person, route[j/2]);
        }
        else { //E번에 도착할경우
            printf("%d는 %c\n", person, route[j/2]);

        }
        person++;
    }
};


int main() {
    srand((unsigned)time(NULL));
    int ladder[HEIGHT][9] = { 0 };
    int col = sizeof(ladder[0]) / sizeof(int);
    int row = sizeof(ladder) / sizeof(ladder[0]);
    printf("사다리 그리기\n");
    makeLadder(ladder, col, row);
    printLadder(ladder, col, row);
    
    //3번문제
    makeLadder(ladder, col,row);
    printLadder(ladder, col, row);
    rideLadder(ladder, col, row);
   
    for(int i=14; i<HEIGHT-1 ; i++){
    for (int j=0; j<col; j++){
        ladder[i][j] = BLANK;
    }
    }
    int num1, num2;
    printf("숫자를 입력하세요\n");
    scanf("%d %d",&num1, &num2);
    
    
    //num 4이면
    char route ='A';
    //최대 E에서 A로 갈경우 4개의 짝대기를 그어줘야함
     for (int i = 14; i < 20; i++) {
        for (int l = 0; l < col; l++) {
            if (l % 2 == 0) { //세로줄 생성
                ladder[i][l] = VERTICAL;
                if(i==19){ ladder[19][l]  = route;
                                    route++;}
            }
            else {
                ladder[i][l] = BLANK;
            }
        }
    }
    
    int drawhorizon1 = makeway[num1-1]-1; //첫번째에서 그려줘야할 짝대기수
    int index1 = 2*(makeway[num2-1]-1);
    if(drawhorizon1==0){ //첫째 뽑은 수가 A로가는거지
        if(index1 == 8){
            ladder[14][7] = HORIZON;
            ladder[15][5] = HORIZON;
            ladder[16][3] = HORIZON;
        }
        else if(index1 == 6){
            ladder[14][5] = HORIZON;
            ladder[15][3] = HORIZON;
        } 
        else if(index1 == 4){
            ladder[15][3] = HORIZON;
        }
    }
    else if(drawhorizon1==1){ //첫째 뽑은 수가 B로 간 상태
        int j =14;
        for(int i = 2*drawhorizon1-1; i>0; i=i-2){
                  ladder[j][i] = HORIZON;
                  j++;
        }
        if(index1 == 8){
            ladder[14][7] = HORIZON;
            ladder[15][5] = HORIZON;
            ladder[16][3] = HORIZON;
        }
        else if(index1 == 6){
            ladder[14][5] = HORIZON;
            ladder[15][3] = HORIZON;
        }
        else if(index1 == 4){
            ladder[15][3] = HORIZON;
        }

    }
    else if(drawhorizon1==2){ //첫째 뽑은 수가 C로 간 상태
        int j = 14;
       for(int i = 2*drawhorizon1-1; i>0; i=i-2){
                 ladder[j][i] = HORIZON;
                 j++;
        }
        if(index1 == 8){
            ladder[14][7] = HORIZON;
            ladder[15][5] = HORIZON;
            ladder[16][3] = HORIZON;
        }
        else if(index1 == 6){
            ladder[15][5] = HORIZON;
            ladder[16][3] = HORIZON;
        }
        else if(index1 == 2){
            ladder[16][3] = HORIZON;
        }
    }
    else if(drawhorizon1==3){ //첫째 뽑은 수가 D로 간 상태
        int j =14;
        for(int i = 2*drawhorizon1-1; i>0; i=i-2){
               ladder[j][i] = HORIZON;
               j++;
        }
        if(index1 == 8){
            ladder[15][7] = HORIZON;
            ladder[16][5] = HORIZON;
            ladder[17][3] = HORIZON;
        }
        else if(index1 == 4){
            ladder[16][5] = HORIZON;
            ladder[17][3] = HORIZON;
        }
        else if(index1 == 2){
            ladder[17][3] = HORIZON;
        }
    }
    else { //첫째 뽑은 수가 E로 간상태
        int j = 14;
        for(int i = 2*drawhorizon1-1; i>0; i=i-2){
                ladder[j][i] = HORIZON;
                j++;
        }
        if(index1 ==2){
            ladder[14][1] = HORIZON;
        }
        else if(index1 ==4){
            ladder[14][3] = HORIZON;
            ladder[15][1] = HORIZON;
        }
        else if(index1 == 6){
            ladder[16][7] = HORIZON;
            ladder[17][5] = HORIZON;
            ladder[18][3] = HORIZON;
        }
    }
    printLadder(ladder, col, row);
    newRideLadder(ladder);
   
return 0;
};



