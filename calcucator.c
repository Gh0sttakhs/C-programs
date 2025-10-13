//Basic Calcucator

#include <stdio.h>

int main() {
	double a,b;
	char praxh;
	printf("Δώσε τον πρώτο αριθμό: ");
	scanf("%lf",&a);
	printf("Δώσε τον δεύτερο αριθμό: ");
	scanf("%lf",&b);
	printf("Δώσε την πράξη (+, -, *, /): ");
	scanf(" %c",&praxh);
	if (praxh=='+') {
		printf("%lf \n",a+b);
	} else if (praxh=='-') {
		printf("%lf \n",a-b);
	} else if (praxh=='*') {
		printf("%lf \n",a*b);
	} else {
		if (b!=0) {
			printf("%lf \n",a/b);
		} else {
			printf("b=0!\n");
		}
	}
	return 0;
}
