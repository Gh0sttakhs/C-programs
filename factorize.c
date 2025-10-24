#include <stdio.h>

int main() {
	int minnum,maxnum,num,temp,factor;
	printf("Please, give minimum number: ");
	scanf("%d", &minnum);
	printf("Please, give maximum number: ");
        scanf("%d", &maxnum);
	for (num=minnum ; num<=maxnum ; num++) {
		printf("Prime factors of %d are:", num);
		temp = num;
		factor = 2;
		while (factor*factor <= temp) {
			while (temp % factor == 0) {
				printf(" %d", factor);
				temp /= factor;
			}
			if (factor == 2) {
				factor = 3;
			} else if (factor % 6 == 1) {
				factor += 4;
			} else {
				factor +=2;
			}
		}
		if (temp != 1) {
			printf(" %d", temp);
		}
	printf("\n");
	}
	return 0;
}

