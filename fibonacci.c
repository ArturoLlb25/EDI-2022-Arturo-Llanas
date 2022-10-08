#include <stdio.h>
#include <stdlib.h>
int fibonacci(int n);
int main()
{
    int n;
    printf("ingrese n:");
    scanf("%d",&n);
    int fibo=fibonacci(n);
    printf("%d",fibo);
    return 0;
}
int fibonacci(int n)
{
    if(n<2)
        return n;
    return fibonacci(n-1)+fibonacci(n-2);
}
