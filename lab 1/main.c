#include <stdio.h>
#include <time.h>
#include <string.h>

int main(){

    printf("Hello World\n");
    char name[80];
    printf("enter your name: ");
    fgets(name, 80, stdin);
    printf("\nhello ");
    printf("%79s", name);

    int year;
    printf("\nenter birth year: ");
    scanf("%d", &year);
    
    time_t seconds = time(NULL);
    struct tm* current_time = localtime(&seconds);
    printf("Current year = %d\n", (current_time -> tm_year + 1900));

    int current_year = (current_time -> tm_year + 1900);
    int age = current_year - year;

    printf("You are %d years old", age);


    return 0;
}   
