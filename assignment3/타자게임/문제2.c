#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int Gcount = 0;
void pickRandomNum(int index, int num[], int random, int position, char* alphabet, char* sentence, int level) {
    while (index < num[random]) {
        int i;
        int alpha;
        if (level == 1) {
            i = rand() % 2 + 4;
            for (alpha = position; alpha < position + i; alpha++) {
                sentence[alpha] = alphabet[rand() % 26];
                sentence[alpha + 1] = ' ';
            }
            position = position + i + 1;
            index = alpha + 1;
        }
        else if (level == 2) {
            i = rand() % 5 + 3; //01
            for (alpha = position; alpha < position + i; alpha++) {
                sentence[alpha] = alphabet[rand() % 52];
                sentence[alpha + 1] = ' ';
            }
            position = position + i + 1;
            index = alpha + 1;
        }
        else {
            i = rand() % 10 + 1; //0
            for (alpha = position; alpha < position + i; alpha++) {
                sentence[alpha] = alphabet[rand() % 78];
                sentence[alpha + 1] = ' ';
            }
            position = position + i + 1;
            index = alpha + 1;
        }
    }
}
void eraseLastSpace(char* sentence) {
    for (int i = 0; i < 71; i++) {
        if (sentence[i] == '\0') {
            sentence[i - 1] = '\0';
            break;
        }
    }
}
void makeArray(char* sentence, char* alphabet, int level, int num[]) {
    int random = 0;
    int index = 0;
    int position = 0;
    if (level == 1) {
        random = rand() % 4; //0123
    }
    else if (level == 2) {
        random = rand() % 3; //012
    }
    else {
        random = rand()%2; //01
    }
    Gcount++;
    printf("(%d/10)다음을 입력하세요\n", Gcount);
    pickRandomNum(index, num, random, position, alphabet, sentence, level);
    eraseLastSpace(sentence);

}
int Speed(double duration, char* answer) {
    return (strlen(answer) / duration) * 60;
}
void findError(char* answer, char* sentence, int wrong) {
    printf(" = ");
    for (int i = 0; i < strlen(answer); i++) {
        if (sentence[i] != answer[i]) {
            wrong = i;
            break;
        }
        else if (sentence[i] != '\0' && answer[i + 1] == '\0') {
            wrong = i + 1;
            break;
        }
    }
    for (int i = 0; i < wrong; i++) {
        printf(" ");
    }
    printf("^\n");
}
int findHighscore(int score[]) {
    int i;
    double highscore = 0;
    for (i = 0; i < 10; i++) {
        if (score[i] > highscore) {
            highscore = score[i];
        }
    }
    return highscore;
}
void over60(double duration, int* score, char* answer) {
    if (duration < 60) {
        score[Gcount - 1] = (60 - duration) * 1000;
    }
    else {
        score[Gcount - 1] = 0;
    }
    printf("점수 : %d, 타수 : %d타/분\n", score[Gcount - 1], Speed(duration, answer));
}
int Perfect(int* score, int perfect){
    for(int i=0; i<10; i++){
        if(score[i]!=0){
            perfect ++;
        }
    }
    return perfect;
}
int main() {
    srand((unsigned int)time(NULL));
    printf("난이도를 선택하세요 (1 ~ 3)");
    int level;
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alphabet2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char alphabet3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()-=_+[]{}/?><.,`~";
    scanf("%d", &level);
    getchar();
    int num1[4] = { 50, 55, 60, 65 };
    int num2[3] = {50, 56, 63 };
    int num3[2] = {50, 60 };
    int wrong = 0;
    double duration;
    int score[10] = { 0 };
    int perfect =0;
    
    if (level == 1) {
        while (Gcount < 10) {
            char sentence[71] = { 0 };
            char answer[100] = { 0 };
            time_t start, end;
            makeArray(sentence, alphabet, level, num1);
            printf(" = %s\n", sentence);
            time(&start);
            printf(" = ");
            fgets(answer, 71, stdin);
            answer[strlen(answer) - 1] = '\0';
            time(&end);
            duration = difftime(end, start);
            if (strcmp(sentence, answer) == 0) {
                printf("맞았습니다.\n");
                over60(duration, score, answer);
                if (Gcount == 10 && Perfect(score, perfect) == 10 ) {
                    level = level + 1;
                    printf("Go to the next stage\n");
                    break;
                }
            }
            else {
                findError(answer, sentence, wrong);
                score[Gcount - 1] = 0;
                printf("타수 : %d타/분\n", Speed(duration, answer));
            }
        }
        printf("1단계 최고점수 : %d \n", findHighscore(score));
        Gcount = 0;
    }
    if (level == 2) {
        while (Gcount < 10) {
            char sentence[71] = { 0 };
            char answer[71] = { 0 };
            time_t start, end;
            makeArray(sentence, alphabet2, level, num2);
            printf(" = %s\n", sentence);
            time(&start);
            printf(" = ");
            fgets(answer, 71, stdin);
            answer[strlen(answer) - 1] = '\0';
            time(&end);
            duration = difftime(end, start);
            if (strcmp(sentence, answer) == 0) {
                printf("맞았습니다.\n");
                over60(duration, score, answer);
                printf("%d\n", Perfect(score, perfect));
                if (Gcount == 10 && Perfect(score, perfect) == 10) {
                    level = level + 1;
                    printf("Go to the next stage\n");
                    break;
                }
            }
            else {
                findError(answer, sentence, wrong);
                score[Gcount - 1] = 0;
                printf("타수 : %d타/분\n", Speed(duration, answer));
            }
        }
        printf("2단계 최고점수 : %d \n", findHighscore(score));
        Gcount = 0;
    }
    if (level == 3) {
        while (Gcount < 10) {
            char sentence[71] = { 0 };
            char answer[71] = { 0 };
            time_t start,end;
            makeArray(sentence, alphabet3, level, num3);
            printf(" = %s\n", sentence);
            time(&start);
            printf(" = ");
            fgets(answer, 72, stdin);
            answer[strlen(answer) - 1] = '\0';
            time(&end);
            duration = difftime(end, start);
            if (strcmp(sentence, answer) == 0) {
                printf("맞았습니다.\n");
                over60(duration, score, answer);
                if (Gcount == 10 && Perfect(score, perfect) == 10) {
                    printf("you won");
                }
            }
            else {
                findError(answer, sentence, wrong);
                score[Gcount - 1] = 0;
                printf("타수 : %d타/분\n", Speed(duration, answer));
            }
        }
        printf("3단계 최고점수 : %d \n", findHighscore(score));
    }

}


