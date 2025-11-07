//Swaps two numbers

#include <stdio.h>

void swap(int *x,int *y) {
	int tmp;
	tmp= *y;
	*y=*x;
	*x=tmp;
}

int main() {
	int a,b;
	printf("Give me one number:");
	scanf("%d",&a);
	printf("Give me another number:");
        scanf("%d",&b);
	swap(&a,&b);
	printf("%d %d\n",a,b);
	return 0;
}
