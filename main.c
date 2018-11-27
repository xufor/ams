#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <process.h>
#include <string.h>
#include <stdlib.h>

int userChoice = 0;
int isLoginComplete = 0;
int entryComplete = 0;
int checkComplete = 0;
int semAttInfo[100][6];
long studentId;
long adminId;
long password;

void showMenu();
void askStudentAdmin();
void printRespectiveMenu();
void headingPrinter();
void askForCredentials();
void checkCredentials();
void customWeclomeText();
void initDataRandomly();
void printRespectiveMenu();
void functionality(int);
void printTotalAttPercent(int);
void checkDetainedOrNot(int);
void genDetainedList(rollno);

void main() {
    initDataRandomly();
    askStudentAdmin();
    if(isLoginComplete)
        while(checkComplete != 1) {
            askForCredentials();
            checkCredentials();
            if(checkComplete == 0) {
                printf("\nInvalid Credentials!\n");
                getch();
            }
        }
    showMenu();
}

void showMenu() {
    int menuChoice;
        while(1) {
            system("cls");
            customWeclomeText();
            printRespectiveMenu();
            printf("\n\nEnter your choice: ");
            scanf("%d",&menuChoice);
            functionality(menuChoice);
        }
}

void printRespectiveMenu() {
    if(userChoice == 1)
    {
        printf("1.To check your total attendance percentage.\n");
        printf("2.To check if you are detained in next examinations or not.\n");
        printf("3.To quit the system.");
    }
    else
    {
        printf("1.To generate a detained list in descending order.\n");
        printf("2.To quit the system.");
    }

}


void functionality(int choice) {
    int rollno;
        printf("\nEnter your roll no. : ");
        scanf("%d",&rollno);
    if (userChoice == 1) {
        switch(choice) {
            case 1:
                printTotalAttPercent(rollno);
                break;
            case 2:
                checkDetainedOrNot(rollno);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("\nEnter a valid choice.");
        }
    }
    else {
        switch(choice) {
            case 1:
                genDetainedList();
                break;
            case 2:
                exit(0);
                break;
            default:
                printf("\nEnter a valid choice.");
        }
    }
}


void printTotalAttPercent(int rollno) {

}


void checkDetainedOrNot(int rollno) {

}


void genDetainedList() {

}

void askStudentAdmin() {
    while(isLoginComplete != 1) {
        headingPrinter();
        printf("\nEnter 1 to login as student.\n");
        printf("Enter 2 to login as administrator.\n\n");
        scanf("%d",&userChoice);
        if(userChoice == 1 || userChoice == 2)
            isLoginComplete = 1;
        else {
            printf("\nInvalid Choice.Try Again!");
            getch();
            system("cls");
        }
    }
}

void checkCredentials () {
        if((studentId ==  || adminId ==001) && password == 123)
            checkComplete = 1;
}

void askForCredentials () {
    if(userChoice == 1) {
        printf("\nEnter Student UID: ");
        scanf("%ld",&studentId);
        printf("\nEnter Password: ");
        scanf("%ld",&password);
    }
    else if(userChoice == 2) {
        printf("\nEnter Admin UID: ");
        scanf("%ld",&adminId);
        printf("\nEnter Password: ");
        scanf("%ld",&password);
    }
    entryComplete = 1;
}

void initDataRandomly() {
    int i,j;
    int layout = 170971001;
    for(i=0;i<100;i++)
    {
       semAttInfo[i][0] = layout;
       layout ++;
    }
    for(i=0;i<100;i++)
        for(j=1;j<6;j++)
            semAttInfo[i][j] = (rand()%176)+1;
}

void headingPrinter() {
    printf("----------------------------------------------------------------------------\n");
    printf("/////-----------------  ATTENDANCE MANAGEMENT SYSTEM  -----------------/////\n");
    printf("/////-----------------            WELCOME             -----------------/////\n");
    printf("----------------------------------------------------------------------------\n\n");
}

void customWeclomeText() {
    printf("----------------------------------------------------------------------------\n");
    printf("/////-----------------  ATTENDANCE MANAGEMENT SYSTEM  -----------------/////\n");
    if(userChoice == 1)
        printf("/////-----------------         STUDENT PORTAL         -----------------/////\n");
    else
        printf("/////-----------------          ADMIN PORTAL          -----------------/////\n");
    printf("----------------------------------------------------------------------------\n\n");
}




