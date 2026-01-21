#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int myint;

typedef struct {
    char username[100];
    char email[100];
    char password[100];    
}   student;

int main() {
    char a[100],b[100];
    myint a = 5;
    student nikos = {"xodros","nikosalexandris07@gmail.com","Niklar"};
    printf("Give me your username/email:");
    scanf("%s",a);
    if (strcmp(a,"xodros")!=0 && strcmp(a,"nikosalexandris07@gmail.com")!=0){
        printf("Wrong Credentials\n");
        return 1;
    }
    printf("Give me your password:");
    scanf("%s",b);
    if (strcmp(b,"Niklar")!=0){
        printf("Wrong Password\n");
        return 1;
    } else {
        printf("Succesful Log in!\n");
    }
    return 0;
}