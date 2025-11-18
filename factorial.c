#include <stdio.h>
#include <stdlib.h>
// Compute the factorial of a number using the recursive
// formula.

int factorial(int number) {
    if (number == 0) return 1;
    else return number * factorial(number - 1);
}

int main(int argc, char **argv) {
    if (argc != 2) {
    printf("Program needs to be called as `./prog number`\n");
    return 1;
 }

 int number = atoi(argv[1]);
    printf("%d! = %d\n", number, factorial(number));
    return 0;
}