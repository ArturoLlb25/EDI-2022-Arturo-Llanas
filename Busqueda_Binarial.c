#include <stdio.h>
#include <stdlib.h>
#define N 10
int busqueda_Binaria(int array[],int n, int valBuscar);
int busqueda_Binaria_Recursiva(int array[],int izq,int der, int valBuscar);
int main()
{
    int array[N]={4,20,38,45,67,88,110,137,149,182};
    int bus,valBuscar;
    printf("ingrese un valor a buscar:\n");
    scanf("%d",&valBuscar);
    //bus=busqueda_Binaria(array,N,valBuscar);
    bus=busqueda_Binaria_Recursiva(array,0,N-1,valBuscar);
    if(bus==1){
        printf("el valor %d se encontro en el arreglo",valBuscar);
    }else{
        printf("el valor %d no se encontro en el arreglo",valBuscar);
    }
    return 0;
}
//funcion normal
int busqueda_Binaria(int array[],int n,int valBuscar){
    int izq=0,der=n-1,mitad;
    while(izq<=der){
        mitad=(izq+der)/2;
        if(array[mitad]==valBuscar){
            return 1;
        }else if(array[mitad]<valBuscar){
            izq=mitad+1;
        }else{
            der=mitad-1;
        }
    }
    return 0;
}
//funcion recursiva
int busqueda_Binaria_Recursiva(int array[],int izq,int der, int valBuscar){
    int mitad;
    if(izq>der){
    return 0;
   }
    mitad=(izq+der)/2;
    if(array[mitad]==valBuscar){
        return 1;
    }else if(array[mitad]<valBuscar){
            busqueda_Binaria_Recursiva(array,mitad+1,der,valBuscar);
        }else{
            busqueda_Binaria_Recursiva(array,izq,der-1,valBuscar);
        }
}
