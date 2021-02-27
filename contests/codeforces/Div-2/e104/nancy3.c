#include <stdio.h>

int factorialOf(int number){
    int factorial = 1;
    while(number){
        factorial*=number;
        number-=1;
    }
    return factorial;
}

int main(void) {
	int n;
	printf("Find factorial of ");
	scanf("%d",&n);
	printf("The factorial of %d is %d\n",n,factorialOf(n));
	return 0;
}