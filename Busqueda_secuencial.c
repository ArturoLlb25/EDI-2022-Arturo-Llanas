#include <stdio.h>
#include <stdlib.h>

int busqueda_Secuencial(int array[],int N, int valBuscar);
int busqueda_Secuencial_Recursiva(int array[],int N, int valBuscar);
int main()
{
    int N=10;
    int array[10]={4,9,3,15,93,8,11,7,14,12};
    int bus,valBuscar;
    printf("ingrese un valor a buscar:\n");
    scanf("%d",&valBuscar);
    //bus=busqueda_Secuencial(array,valBuscar);
    bus=busqueda_Secuencial_Recursiva(array,N,valBuscar);
    if(bus==1){
        printf("el valor %d se encontro en el arreglo",valBuscar);
    }else{
        printf("el valor %d no se encontro en el arreglo",valBuscar);
    }
    return 0;
}
//funcion normal
int busqueda_Secuencial(int array[],int N,int valBuscar){
    for(int i=0;i<N;i++){
        if(array[i]==valBuscar){
            return 1;
        }
    }
    return 0;
}
//funcion recursiva
int busqueda_Secuencial_Recursiva(int array[],int N, int valBuscar){
    if(N<0){
        return 0;
    }
    if(array[N]==valBuscar){
        return 1;
    }
    busqueda_Secuencial_Recursiva(array,N-1,valBuscar);
}
