#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char** str = (char**)malloc(sizeof(char*) * 5);
    char sentence[100];
    char data_temp[80];
    char temp[20] = { 0 }; // 명령어 입력
    char temp_1[20][81] = { 0 };
    char temp_2[20][81] = { 0 };
    int index = 0, flag = 0, flag2 = 0, flag3 = 0, flag4 = 0;
    char change[2][10];
    int spot[2];
    char* ptr;

    while (1) {
        printf("명령 (L : 전체 보기, I : 입력하기, D: 삭제, C : 바꾸기) : \n");
        gets(temp);
        switch (temp[0]) {
        case 'L':
            if (index == 0) {
                printf("(내용이 없습니다)\n");
            }
            else {
                for (int i = 0; i < flag + index; i++

                    ) {
                    printf("%d : %s\n", i + 1, str[i]);
                }
            }
            break;
        case 'I':
            printf("문장을 입력하세요. 입력이 끝나면 첫 칸에 /를 입력하세요.\n");
            if (temp[1] == '\0') { // I만 입력했을때
                while (1) {
                    gets(sentence);
                    if (sentence[0] == '/') break;
                    str[index] = (char*)malloc(sizeof(char) * (strlen(sentence) + 1));
                    strcpy(str[index], sentence);
                    index++;
                    
                    if (index >= 5) {
                       str = (char**)realloc(str, sizeof(char*) * (index + 1));
                    }
                    
                }
                for (int i = 0; i < index; i++) {
                    printf("%d : %s\n", i + 1, str[i]);
                }
            }
            /*
            else if (temp[1] != '\0') { // I와 숫자 입력
                while (1) {
                    gets(temp_1[flag]);
                    if (temp_1[flag][0] == '/') break;
                    flag++;
                }

                for (int i = temp[1] - '1';i < index;i++) {
                    strcpy(temp_2[flag2], data[i]);
                    flag2++;
                }


                for (int i = 0; i < flag;i++) {
                    strcpy(data[i + temp[1] - '1'], temp_1[i]);
                }


                for (int i = temp[1] - '1' + flag;i < flag + index;i++) {
                    strcpy(data[i], temp_2[flag3]);
                    flag3++;
                }

                // 출력
                for (int i = 0; i < flag + index; i++) {
                    printf("%d : %s\n", i + 1, data[i]);
                }
            }
            */
            break;
            /*
        case 'D':

            for (int i = temp[1] - '1'; i < flag + index; i++) {
                strcpy(data[i], data[i + 1]);
            }
            index--;
            // 출력
            for (int i = 0; i < flag + index;i++) {
                printf("%d : %s\n", i + 1, data[i]);
            }
            break;

        case 'C': // C/nice/good
            for (int i = 0;temp[i] != '\0';i++) {
                if (temp[i] == '/') {
                    spot[flag4] = i;
                    flag4++;
                }
            }

            flag4 = 0;
            for (int i = spot[0] + 1; i < spot[1];i++) {
                change[0][flag4] = temp[i];
                flag4++;
            }
            change[0][flag4] = '\0';


            flag4 = 0;
            for (int i = spot[1] + 1; temp[i] != '\0'; i++) {
                change[1][flag4] = temp[i];
                flag4++;
            }
            change[1][flag4] = '\0';

            for (int i = 0; i < index + flag;i++) {
                while (1) {
                    ptr = strstr(data[i], change[0]);
                    if (ptr != NULL) {
                        // you are nice person
                        strcpy(data_temp, ptr + strlen(change[0]));
                        strncpy(ptr, change[1], strlen(change[1]));
                        strcpy(ptr + strlen(change[1]), data_temp);
                    }
                    else break;
                    ptr++;
                }

            }

            //출력

            for (int i = 0; i < flag + index; i++) {
                printf("%d : %s\n", i + 1, data[i]);
            }

            break;
            */
        }
        
    }

    return 0;
}