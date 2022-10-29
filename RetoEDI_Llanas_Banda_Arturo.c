#include <stdio.h>
#include <stdlib.h>
#define N 5
int busqueda_Binaria(int array[],int n, int valBuscar);
int main(){
    int objetivo,salida,nums[N]={1,3,5,6,10};
    printf("digite el objetivo que busca en el arreglo: ");
    scanf("%d",&objetivo);
    salida=busqueda_Binaria(nums,N,objetivo);
    printf("se enuentra en la posicion:%d ",salida);
}

int busqueda_Binaria(int array[],int n,int valBuscar){
    int izq=0,der=n-1,mitad;
    while(izq<=der){
        mitad=(izq+der)/2;
        if(array[mitad]==valBuscar){
            return mitad;
        }else if(array[mitad]<valBuscar){
            izq=mitad+1;
        }else{
            der=mitad-1;
        }
    }
    if(izq==der){
        if(array[mitad]<valBuscar){
            return mitad+1;
        }else{
            return mitad-1;
        }
    }
}

