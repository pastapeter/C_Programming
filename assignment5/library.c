#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 책목룍 표시, 

typedef struct USER{
    char name[10];
    char birthday[10];
    char phonenum[20];
    int lend;
}User;

typedef struct BOOK{
    char title[30];
    char author[30];
    char publisher[40];
    int lend;
    int booknum;
}Book;

typedef struct LEND{
    char lendday[9];
    char returnday[9];
    char lender[20];
    char bookname[30];
}Lend;

void lender(Lend *rlend){
    char lenderinfo[20]={0};
    char bookinfo[30]={0};
    char lenddayinfo[9]={0};
    printf("enter the [namelast4digitofphonenum]\n");
    fgets(lenderinfo, 20, stdin);
    lenderinfo[strlen(lenderinfo)-1]='\0';
    strcpy(rlend->lender, lenderinfo);
    printf("enter the [booktitle/booknum]\n");
    fgets(bookinfo, 30, stdin);
    bookinfo[strlen(bookinfo)-1]='\0';
    strcpy(rlend->bookname, bookinfo);
    printf("enter the [lendday]\n");
    fgets(lenddayinfo,9,stdin);
    lenddayinfo[strlen(lenddayinfo)-1]='\0';
    strcpy(rlend->lendday, lenddayinfo);
}
void findlastnum(Lend **rlend, char username[], char lastnum[]){
    int i,j;
    for(i=0;i<strlen((*rlend)->lender);i++){ //lender에서 이름만 빼기
        username[i] = (*rlend)->lender[i];
        if((*rlend)->lender[i]>47&&(*rlend)->lender[i]<58){ //숫자라면
            username[i]='\0';
            break;
        }
    }
    for(j=0;j<4;j++){ //4글자 빼기
        lastnum[j]=(*rlend)->lender[i];
        i++;
    }
    lastnum[4]='\0';
}
void linkUser(Lend *rlend, User *ruser[5]){
    char username[20]={0};
    char lastnum[5]={0};
    char lastnum2[5]={0};
    int k,l;
    findlastnum(&rlend, username, lastnum);
    for(k=0;k<5;k++){ //01027160593
        if(!strcmp(username, ruser[k]->name)){
            for(l=7;l<strlen(ruser[k]->phonenum);l++){
                lastnum2[l-7]=ruser[k]->phonenum[l];    
            }
            lastnum2[4]='\0';
            if(!strcmp(lastnum, lastnum2)){
                ruser[k]->lend = 0;
                break;
            }
        }
    }
}
void returnUser(Lend *rlend, User *ruser[5]){
    char username[20]={0};
    char lastnum[5]={0};
    char lastnum2[5]={0};
    int k,l;
    findlastnum(&rlend, username, lastnum);
    for(k=0;k<5;k++){ //01027160593
        if(!strcmp(username, ruser[k]->name)){
            for(l=7;l<strlen(ruser[k]->phonenum);l++){
                lastnum2[l-7]=ruser[k]->phonenum[l];    
            }
            lastnum2[4]='\0';
            printf("lastnum %s\n", lastnum2);
            if(!strcmp(lastnum, lastnum2)){
                ruser[k]->lend = 1;
                break;
            }
        }
    }
}
void findslash(char str[], int *num_index){
    char num[10]={0};
    for(int j=strlen(str)-1;j>-1;j--){
        if(str[j]==47){
            strcpy(num,&str[j+1]);
            str[j]='\0';
            break;
        }
    }
    *num_index = atoi(num);
}
void linkBook(Lend *rlend, Book *rbooklist[10]){
    char bookname_buf[30]={0};
    int num_index=0;
    strcpy(bookname_buf, rlend->bookname);
    findslash(bookname_buf, &num_index);
   // printf("num_index= %d\n", num_index);
    for(int i=0;i<10;i++){
        if(!strcmp(bookname_buf, rbooklist[i]->title)&&num_index==rbooklist[i]->booknum){
            rbooklist[i]->lend =0;
            break;
        }
    }
}
void findBook(Lend *rlend, Book *rbooklist[10], int *book_index){
     char bookname_buf[30]={0};
    strcpy(bookname_buf, rlend->bookname);
    int num_index=0;
    findslash(bookname_buf, &num_index);
    for(int i=0;i<10;i++){
        if(!strcmp(bookname_buf, rbooklist[i]->title)&&num_index==rbooklist[i]->booknum){
            *book_index = i;
            break;
        }
    }
}
void findUser(Lend *rlend, User *ruser[5], int *user_index){
    char username[20]={0};
    char lastnum[5]={0};
    char lastnum2[5]={0};
    int k,l;
    findlastnum(&rlend, username, lastnum);
    for(k=0;k<5;k++){ //01027160593
        if(!strcmp(username, ruser[k]->name)){
            for(l=7;l<strlen(ruser[k]->phonenum);l++){
                lastnum2[l-7]=ruser[k]->phonenum[l];    
            }
            lastnum2[4]='\0';
            if(!strcmp(lastnum, lastnum2)){
                *user_index = k;
                break;
            }
        }
    }
}
void returnBook(Lend *rlend, Book *rbooklist[10]){
    int i;
    char bookname_buf[30]={0};
    strcpy(bookname_buf, rlend->bookname);
    int num_index=0;
    findslash(bookname_buf, &num_index);
    for(i=0;i<10;i++){
        if(!strcmp(bookname_buf, rbooklist[i]->title)&&num_index==rbooklist[i]->booknum){
            rbooklist[i]->lend =1;
            break;
        }
    }
}


int main(){

  Book *booklist[10];
  User *user[5];
  char *name[5] ={"Dohyun", "Jisoo", "Jenny", "Hyojin", "Nayeon"};
  char *birthday[5] = {"970603", "950103", "960116", "800404", "950922" };
  char *phonenum[5] = {"01027160593", "01023456789", "01034562319", "01087945432", "01044562341"};
  char *title[10]= {"Harrypotter", "Twilight", "IT", "The Chronicles of Narnia", "Hunger Games", "Maze Runner", "Hobbit", "The Lord of the Rings", "StarWars", "The Game of Thrones"};
  char *author[10]= {"J.K.Rowling", "Stephenie Meyer", "Steven King", "C.S.Luis", "Susan Collins", "James Dashner", "J.R.R Tolkien", "J.R.R Tolkien", "George Lucas", "R.R Martin"};
  char *publisher[10]= {"Scholostic", "Brown and Company", "HarperCollins", "Macmillan", "Scholastic", "Dell", "Allen&Unwin", "Allen&Unwin", "Disney", "Bantam Spectra"};
  for(int i=0;i<sizeof(booklist)/sizeof(Book *);i++){
      booklist[i] = malloc(sizeof(Book));
      strcpy(booklist[i]->title, title[i]);
      strcpy(booklist[i]->author, author[i]);
      strcpy(booklist[i]->publisher, publisher[i]);
      booklist[i]->booknum = 1;
      booklist[i]->lend = 1;
  }
  for(int i=0;i<sizeof(user)/sizeof(User *);i++){
      user[i] = malloc(sizeof(User));
      strcpy(user[i]->name, name[i]);
      strcpy(user[i]->birthday, birthday[i]);
      strcpy(user[i]->phonenum, phonenum[i]);
      user[i]->lend=1;
  }
int option=0;
int index=0;
Lend *lend;
lend = (Lend*)malloc(sizeof(Lend)*index); // 동적할당
while(1){
  printf("1.책목록 표시 2.대출등록 3.반납하기 4.대출목록표시하기\n");
  scanf("%d", &option);
  getchar();
  if(option==1){
      // 책 목록표시
    for(int i=0;i<sizeof(booklist)/sizeof(Book *);i++){
        if(booklist[i]->lend == 1){
            printf("%s %s %s %s\n", booklist[i]->title, booklist[i]->author, booklist[i]->publisher, "보유중");
        }
        else{
            printf("%s %s %s %s\n", booklist[i]->title, booklist[i]->author, booklist[i]->publisher, "대출중");
        }
    }
  }
if(option==2){//대출등록하기3
        lender(&lend[index]);
        linkBook(&lend[index], &booklist[0]);
        linkUser(&lend[index], &user[0]);
        index++;
}
if(option==3){
    char booktitle[30]={0};
    char lender[20]={0};
    char returnday[9]={0};
    int i;
    int user_index=0;
    printf("Enter the [booktitle/booknum]\n");
    fgets(booktitle, 30, stdin);
    booktitle[strlen(booktitle)-1]='\0';
    printf("Enter the [name4digitofphonenum]\n");
    fgets(lender,20,stdin);
    lender[strlen(lender)-1]='\0';
    for(i=0;i<=index;i++){   
        if(!strcmp(booktitle, lend[i].bookname)&&!strcmp(lender, lend[i].lender)){ //lend 구조체 index값 찾기 returnday만 넣어준거임
            findUser(&lend[i], &user[0], &user_index);
            if(user[user_index]->lend ==0){
            printf("Enter the [returning day]\n");
            fgets(returnday,9,stdin);
            returnday[strlen(returnday)-1]='\0';
            strcpy(lend[i].returnday, returnday);
            break;
            }
            else{
                printf("대출중이 아닙니다.\n");
            }
        }
    }
    returnBook(&lend[i],&booklist[0]);
    returnUser(&lend[i],&user[0]);
}

if(option==4){
    int i;
    int user_index=0;
    int book_index=0;
    for(i=0;i<index;i++){
        findUser(&lend[i], &user[0], &user_index);
        findBook(&lend[i],&booklist[0], &book_index);
        if(booklist[book_index]->lend==0){
            printf("%s %s(%s) %s %s\n",lend[i].bookname, user[user_index]->name, user[user_index]->phonenum,lend[i].lendday, "대출중" );
        }
        else if(booklist[book_index]->lend==1){
            printf("%s %s(%s) %s %s\n",lend[i].bookname, user[user_index]->name, user[user_index]->phonenum,lend[i].lendday, lend[i].returnday );
        }      
    } 
}
}

//동적할당 메모리 반납
  free(lend);
  for(int i=0;i<sizeof(user)/sizeof(User *);i++){
     free(user[i]);
  }
 for(int i=0;i<sizeof(booklist)/sizeof(Book *);i++){
     free(booklist[i]);
  }
}
