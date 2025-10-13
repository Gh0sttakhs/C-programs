#include <stdio.h>

int main() {
        int num, maxnum=40000000, divisor, sum;
        for (num = 2 ; num<=maxnum ; num++) {
                sum=1;
                for(divisor = 2 ; divisor * divisor < num ; divisor++) {
                        if (num % divisor == 0) {
                                sum += divisor + num/divisor;
                        }
                }
                if (divisor * divisor ==num) {
                        //Einai teleio tetragono?
                        sum += divisor;
                }
                if (sum  == num) {
                        printf("%d is a perfect number\n", num);
                }
        }
        return 0;
}
