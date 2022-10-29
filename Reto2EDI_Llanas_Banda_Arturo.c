#include <stdio.h>
#define MAX 100
void leer(int arr[],int N);
void imprimir(int array[],int N);
void arreglo_Completo(int array1[],int array2[], int array3[], int n, int m);
void quick_sort(int L[],int ini, int fin);

int main(void) {
    int n,m,num1[MAX],num2[MAX],num3[MAX];
    do {
        printf("digite el valor de n: ");
        scanf("%d",&n);
        printf("digite el valor de m: ");
        scanf("%d",&m);

    }while(m>100  || n>100);
    leer(num1,n);
    leer(num2,m);
    arreglo_Completo(num1,num2, num3, n, m+n);
    quick_sort(num3,0,(m+n)-1);
    printf("arreglo combinado y ordenado:");
    imprimir(num3,n+m);

}

void leer(int arr[],int N)
{
    printf("digite los valores del arreglo:\n");
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);

    }

}

void imprimir(int array[],int N)
{
    for(int i=0;i<N;i++){
        printf("[%d]",array[i]);
    }
    printf("\n");
}

void arreglo_Completo(int array1[],int array2[], int array3[], int n, int m)
{
    int cont=0;
    for (int i=0;i<n;i++)
    {
        array3[i]=array1[i];
        if(i==n-1)
        {
            for (int j=i+1;j<m;j++)
            {
                array3[j]=array2[cont];
                cont++;
            }
        }
    }
}
void quick_sort(int arr[],int ini, int fin){
    int piv,izq,der,med;
    if(ini<fin){
        piv=arr[ini];
        izq=ini;
        der=fin;
        while(izq<der){
            while(der>izq && arr[der]>piv)
                der--;
            if(der>izq){
                arr[izq]=arr[der];
                izq++;
            }
            while(izq<der && arr[izq]<piv)
                izq++;
            if(izq<der){
                arr[der]=arr[izq];
                der--;
            }
        }
        arr[der]=piv;
        med=der;
        quick_sort(arr,ini,med-1);
        quick_sort(arr,med+1,fin);

    }
}

