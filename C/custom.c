#include <stdio.h>
#include "cs50.c"

int main(void){
    string userName;
    printf("What's your name? \n");
    userName = GetString();
    printf("hello, %s\n", userName);
}