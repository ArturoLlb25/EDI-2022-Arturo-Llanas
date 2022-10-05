#include <stdio.h>

int main( )
{
    int a = 5;
    int b = 0;
    while(a > 0){
        for(int i = a; i > 0; i--)
        {
            if(i % 2 == 0)
                printf("!");
            else
                printf("*");
        }
        printf(" ");
        for(int j = 0; j < b; j++)
        {
            printf("*");
        }
        printf("\n");
        a--;
        b++;
    }
    return 0;
}
