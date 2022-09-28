#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10
int pospar(int arreglo[MAX]);
int valpar(int arreglo[MAX]);
int sumaxima(int arreglo[MAX],int *sumafinal);
int main(){
	int arreglo[MAX];
	int i,sumapos,sumaval,cont,sumafinal=0;
	srand(time(NULL));
	for(i=0;i<MAX;i++){
		arreglo[i]=rand()%101;
		printf("[%d]",arreglo[i]);	
	}	
	printf("\n");
	sumapos=pospar(arreglo);
	printf("suma de los valores en posiciones pares: %d\n",sumapos);
	sumaval=valpar(arreglo);
	printf("suma de los valores pares: %d\n",sumaval);
	cont=sumaxima(arreglo,&sumafinal);
	printf("la suma final de todos los numeros sin sobrepasar el 100 es: %d\n",sumafinal);
	printf("se sumaron %d numeros",cont);
}
int pospar(int arreglo[MAX]){
	int sum=0,i;
	for(i=0;i<MAX;i++){
		if(i%2==0){
			sum=sum+arreglo[i];
		}
	}
	return(sum);
}
int valpar(int arreglo[MAX]){
	int sum=0,i;
	for(i=0;i<MAX;i++){
		if(arreglo[i]%2==0){
			sum=sum+arreglo[i];
		}
	}
	return(sum);
}
int sumaxima(int arreglo[MAX],int *sumafinal){
	int i;
	for(i=0;i<MAX && *sumafinal<100;i++){
		if(*sumafinal+arreglo[i]>100){
			break;
		}
		*sumafinal=*sumafinal+arreglo[i];
	}
	return(i);
}
