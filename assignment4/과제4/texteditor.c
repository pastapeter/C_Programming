#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void look(char *str[], int index) {
    int i = 0;
    
    if (index == 0) {
        printf("(내용이 없습니다.)\n");
    }
    while (i < index && index>0) {
        if (index < 9) {
            printf("0%d : %s\n", i + 1, str[i]);
        }
        else {
            printf("%d : %s\n", i + 1, str[i]);
        }
        i++;
    }
}
char* getText(){
    int size = 0;
    int total=0;
    char* text = NULL;
    char* temp = (char*)malloc(sizeof(char)*1000);
    while(1){
    fgets(temp, 1000, stdin);
    size = strlen(temp);
    total = total + size;
    if(text == NULL){
        text = (char*)malloc(sizeof(char)*(total+1));
        strcpy(text,temp);
    }
    else{
        text = (char*)realloc(text, sizeof(char)*(total+1));
        strcat(text,temp);
    }
    if(temp[size-1] == '\n'){
        text[strlen(text)-1] = '\0';
        break;
    }
    }
    free(temp);
    return text;
}
int main() { //전체보기 입력하기 삭제 바꾸기
    int index3 =0;
    int index4=0;
    char *str[index3];
    char *str2[index4];
    char copy_arr[21][81];
    char *order=NULL;
    char *wordarray[2] = {0} ;
    int index = 0;
    int index2 = 0;
    char *token = NULL;
    int i, j;
    char temp[81] = { 0 }; //I행 뒤에 있는 숫자 - temp행 앞에 추가하기
    while (1) {
        printf("order(L:LOOK I:INPUT D:DELETE C:CHANGE)");
        order = getText();
        order[0] = toupper((int)order[0]);
        switch (order[0]) {
        case ('L'):
            look(str, index);
            break;
        case ('I'):
            printf("문장을 입력하세요. 입력이 끝나면 첫 칸에 /를 입력하세요\n");
            if (order[1] == '\0') {
                while (1) {
                    str[index3] = getText();
                    if (str[index][0] == '/') {
                        break;
                    }
                    index++;
                    index3++;
                }
                look(str, index);
               //printf("%s\n", str[0]);
               //printf("%s\n", str[1]);
            }
            else {
                int i = 1;
                int j = 0;
                int start_index = 0;
                int copy_count = 0;

                index2 = 0;
                while (order[i] != '\0') {
                    temp[j] = order[i];
                    j++;
                    i++;
                }
                temp[j + 1] = '\0';
                int num = atoi(temp); //i 뒤에있는 숫자
                while (1) {
                    str2[index4]= getText();
                    if (str2[index4][0] == '/') {
                        //str[num]
                        break;
                    }
                    index4++;
                }

                start_index = num - 1;
                copy_count = index - num + 1;

                for (int i = start_index; i < copy_count + start_index + 1; i++)
                    strcpy(copy_arr[i], str[i]);

                for (int i = 0; i < index - num + 1; i++) { //index2 3 i 0 1 2 num 1
                    strcpy(str[num - 1 + index4 + i], copy_arr[num - 1 + i]);
                }
                for (int i = 0; i < index4; i++) {
                    strcpy(str[num -1 + i], str2[i]);
                }
                if (index == 0)
                    index += num - 1 + index4;
                else
                    index += index4;


                look(str, index);

            }
            break;
        case('D'):
            i = 1;
            j = 0;
            int start_index = 0;
            int copy_count = 0;

            while (order[i] != '\0') {
                temp[j] = order[i];
                j++;
                i++;
            }
            temp[j + 1] = '\0';
            int num = atoi(temp);

            start_index = num - 1;

            if (start_index >= index) {
                printf("outof range\n");
                continue;
            }

            copy_count = index - start_index;
    
            for (int i = start_index; i < copy_count + start_index; i++) {
                strcpy(str[i], str[i + 1]);
            }
            index--;

          //  look(str, index);
            break;
        case('C'):
                token = strtok(order+2,"/");
                wordarray[0] = token;
                while(token!=NULL){
                    wordarray[1] = token;
                    token = strtok(NULL,"/");
                }
                printf("%s\n%s\n",wordarray[0],wordarray[1]);
                
                char *ptr=NULL;
                for(int i=0;i<index;i++)
                {
                    ptr = strstr(str[i],wordarray[0]);
                    while(ptr != NULL)
                    {
                        int len = 0;
                        len = strlen(wordarray[0])-strlen(wordarray[1]);
                        if(len==0)
                        {
                            for(int j=0;j<strlen(wordarray[0]);j++)
                            {
                                *ptr = wordarray[1][j];
                                ptr++;
                            }
                        }
                        else if(len > 0){
                            int l = 0;
                            for(int j=0;j<strlen(wordarray[1]);j++){
                                *ptr = wordarray[1][j];
                                ptr++;
                                }
                            while(ptr[l]!=NULL){
                                ptr[l] = ptr[l+len];
                                l++;
                            }
                        }
                        else if(len < 0)
                        {
                            char * temp = NULL;
                            for(temp = str[i] + strlen(str[i])+abs(len);temp!=ptr-1;temp--)
                            {
                                *(temp) = *(temp-abs(len));
                            }
                            for(int j=0;j<strlen(wordarray[1]);j++)
                            {
                                *ptr = wordarray[1][j];
                                ptr++;
                            }
                        }
                        ptr = strstr(str[i],wordarray[0]);
                    }
                   printf("%s\n",str[i]);
                }
            break;
        }
    }
}
