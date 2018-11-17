#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <process.h>
#include <string.h>
#include <stdlib.h>

struct student {
    int rollno;
    int totalAttendance;
};

struct weekStatus {
    int totalOfDay;
};

struct monthStatus {
    int totalOfMonth;
};

int userChoice = 0;
int isLoginComplete = 0;
int entryComplete = 0;
int checkComplete = 0;
struct student studentInfo[5];
struct weekStatus weeklyAttInfo[5][7];
struct monthStatus monthlyAttInfo[5][12];
long studentRollNumber;
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
    system("cls");
    customWeclomeText();
    printRespectiveMenu(userChoice);
    printf("\n\nEnter your choice: ");
    scanf("%d",&menuChoice);
}

void printRespectiveMenu() {
    if(userChoice == 1)
    {
        printf("1.To mark todays attendance.\n");
        printf("2.To see your todays's attendance status.\n");
        printf("3.To see your current week's attendance status.\n");
        printf("4.To check your total attendance percentage.\n");
        printf("5.To check if you are detained in next examinations or not.\n");
        printf("5.To quit the system.");
    }
    else
    {
        printf("1.To check a student's attendance records.\n");
        printf("2.To check a student's weekly attendance.\n");
        printf("3.To check a student's total attendance pecentage.\n");
        printf("4.To generate a detained list.\n");
        printf("5.To quit the system.");
    }

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
        if((studentRollNumber == 001 || adminId ==001) && password == 123)
            checkComplete = 1;
}

void askForCredentials () {
    if(userChoice == 1) {
        printf("\nEnter Student Roll Number: ");
        scanf("%ld",&studentRollNumber);
        printf("\nEnter Password: ");
        scanf("%ld",&password);
    }
    else if(userChoice == 2) {
        printf("\nEnter Admin ID: ");
        scanf("%ld",&adminId);
        printf("\nEnter Password: ");
        scanf("%ld",&password);
    }
    entryComplete = 1;
}

void initDataRandomly() {
    int i,j;
    int layout = 170971001;
    for(i=0;i<5;i++)
    {
       studentInfo[i].rollno = layout;
       layout ++;
       studentInfo[i].totalAttendance = (rand()%100)+1;
    }
    for(i=0;i<5;i++)
        for(j=0;j<7;j++)
            weeklyAttInfo[i][j].totalOfDay = (rand()%8)+1;
    for(i=0;i<5;i++)
        for(j=0;j<12;j++)
            weeklyAttInfo[i][j].totalOfDay = (rand()%20)+1;
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




