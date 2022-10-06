#include <stdio.h>
void compara(int a,int *b,int *c);
int main() {
    int a,b,c;
    printf("dame el valor de a:");
    scanf("%d",&a);
    printf("dame el valor de b:");
    scanf("%d",&b);
    printf("dame el valor de c:");
    scanf("%d",&c);
    compara(a,&b,&c);
    printf("a=%d,b=%d,c=%d",a,b,c);
    return 0;
}
void compara(int a,int *b,int *c){
    int auxb=*b,auxc=*c;
    if(a>*b){
        auxb=*b*2;
    }
    if(a<*b){
        auxc=*c-a;
    }
    if(*c<0){
        auxc=*c*-1;
    }
    *b=auxb;
    *c=auxc;
}
