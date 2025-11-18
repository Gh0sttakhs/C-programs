#include <stdio.h>

int fibon(int i) {
	int x,y,z,j;
	if (i==0){
		return 0;
	}
	if (i==1){
		return 1;
	}
	x=0;
	y=1;
	for (j=2 ; j<=i ; j++) {
		z=x+y;
		x=y;
		y=z;
	}
	return z;
}

int main() {
	int i,max,fib;
	scanf("%d",&max);
	for (i=0 ; i<=max ; i++) {
		fib=fibon(i);
		printf("fib[%d]= %d\n",i,fib);
	}
	return 0;
}
