#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <process.h>
#include <string.h>
#include <stdlib.h>

int adminStudentChoice = 0;
int isLoginComplete = 0;
int entryComplete = 0;
int checkComplete = 0;
long studentRollNumber;
long adminId;
long password;

void showMenu();
void askStudentAdmin();
void headingPrinter();
void askForCredentials();
void checkCredentials();
void customWeclomeText();

void main() {
    askStudentAdmin();

    if(isLoginComplete)
        while(checkComplete != 1) {
            askForCredentials();
            checkCredentials();
            if(checkComplete == 2) {
                printf("\nInvalid Credentials!\n");
                getch();
            }
        }

    showMenu();
}

void showMenu() {
    system("cls");
    customWeclomeText();

}


void askStudentAdmin() {
    while(isLoginComplete != 1) {
        headingPrinter();
        printf("\nEnter 1 to login as student.\n");
        printf("Enter 2 to login as administrator.\n\n");
        scanf("%d",&adminStudentChoice);
        if(adminStudentChoice == 1 || adminStudentChoice == 2)
            isLoginComplete = 1;
        else {
            printf("\nInvalid Choice.Try Again!");
            getch();
            system("cls");
        }
    }
}

void checkCredentials () {
    if(adminStudentChoice = 1) {
        if(studentRollNumber == 001 && password == 123)
            checkComplete = 1;
        else
            checkComplete = 2;
    }
    else if(adminStudentChoice = 2) {
        if(adminId == 001 && password == 123)
            checkComplete = 1;
        else
            checkComplete = 2;
    }
}

void askForCredentials () {
    if(adminStudentChoice = 1) {
        printf("\nEnter Student Roll Number: ");
        scanf("%ld",&studentRollNumber);
        printf("\nEnter Password: ");
        scanf("%ld",&password);
    }
    else if(adminStudentChoice = 2) {
        printf("\nEnter Admin ID: ");
        scanf("%ld",&studentRollNumber);
        printf("\nEnter Password: ");
        scanf("%ld",&password);
    }
    entryComplete = 1;
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
    if(adminStudentChoice = 1)
        printf("/////-----------------         STUDENT PORTAL         -----------------/////\n");
    else
        printf("/////-----------------          ADMIN PORTAL          -----------------/////\n");
    printf("----------------------------------------------------------------------------\n\n");
}
