#include<stdio.h>

int factorial(int a){
    if (a < 1){
        return 1;
    }
    return a * factorial(a-1);
}

int main(){
    int n;
    printf("Enter n: \n");
    scanf("%d",&n);

    int fact = factorial(n);
    printf("Factorial of %d is %d\n",n,fact);
}