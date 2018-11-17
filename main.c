#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <process.h>
#include <string.h>

int adminStudentChoice = 0;
int isLoginComplete = 0;

void askStudentAdmin();
void headingPrinter();

void main() {

}

void headingPrinter() {

}

void ask_student_admin() {
    while(isLoginComplete != 1) {
        printf("Enter 1 to login as student.\n");
        printf("Enter 2 to login as administrator.\n");
        scanf("%d",&adminStudentChoice);
        if(adminStudentChoice == 1 || adminStudentChoice == 2)
            isLoginComplete = 1;
        else {
            printf("\nInvalid Choice.Try Again!");
            getch();
            clrscr();
        }
    }
}

