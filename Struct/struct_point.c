#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int day;
    int month;
    int year;
} Date;

int main()
{
    Date d1 = {1, 10, 2023};
    Date *d2 = &d1;             //d2 = {1,10,2023}
    d2->day = 2;                //d2 = {2,10,2023} d1 = {2,10,2023}
    Date *d3 = malloc(sizeof(Date));        
    *d3 = *d2;          //d3 = {2,10,2023}
    d3->month = 12;     //d3 = {2,12,2023} d2 = {2,10,2023} d1 = {2,10,2023}
    d3->day = 11;       //d3 = {11,12,2023} d2 = {2,10,2023} d1 = {2,10,2023}
    printf("Diff: %d/%d/%d\n", d3->day - d1.day, d3->month - d1.month, d3->year - d1.year);
    return 0;
}