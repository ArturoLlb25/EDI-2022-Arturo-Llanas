#include <stdio.h>
#define N 3
#define M 4
void leeFuncion(int arr[N][M]);
void vecinos(int arr[N][M],int arrb[N][M]);
void imprime(int arrb[N][M]);
int main() {
    int arr[N][M];
    int arrb[N][M];
    leeFuncion(arr);
    printf("matriz original:\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    vecinos(arr,arrb);
    printf("matriz vecinos:\n");
    imprime(arrb);
    return 0;
}
void leeFuncion(int arr[N][M]){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("digite en la posicion[%d][%d]:",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
}
void vecinos(int arr[N][M],int arrb[N][M]){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(i==0 && j==0)
            {
                arrb[i][j]=arr[i][j]+arr[i][j+1]+arr[i+1][j];
            }
            if(i==0 && (j>0 && j<=M-2))
            {
                arrb[i][j]=arr[i][j]+arr[i][j+1]+arr[i+1][j]+arr[i][j-1];
            }
            if(i==0 && j==M-1)
            {
                arrb[i][j]=arr[i][j]+arr[i][j-1]+arr[i+1][j];
            }
            if(i==N-1 && j==0)
            {
                arrb[i][j]=arr[i][j]+arr[i-1][j]+arr[i][j+1];
            }
            if(i==N-1 && (j>0 && j<=M-2))
            {
                arrb[i][j]=arr[i][j]+arr[i][j-1]+arr[i-1][j]+arr[i][j+1];
            }
            if(i==N-1 && j==M-1)
            {
                arrb[i][j]=arr[i][j]+arr[i][j-1]+arr[i-1][j];
            }
            if(j==0 && (i>0 && i<=N-2))
            {
                arrb[i][j]=arr[i][j]+arr[i][j+1]+arr[i+1][j]+arr[i-1][j];
            }
            if(j==M-1 && (i>0 && i<=N-2))
            {
                arrb[i][j]=arr[i][j]+arr[i][j-1]+arr[i+1][j]+arr[i-1][j];
            }
            if((i>0 && i<=N-2)&&(j>0 && j<=M-2))
            {
                arrb[i][j]=arr[i][j]+arr[i][j-1]+arr[i+1][j]+arr[i-1][j]+arr[i][j+1];
            }
        }
    }
}
void imprime(int arrb[N][M]){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%d ",arrb[i][j]);
        }
        printf("\n");
    }
}
