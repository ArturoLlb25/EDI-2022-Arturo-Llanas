#include <stdio.h>
#include <stdlib.h>
#define N 10
void Burbuja(int array[N]);
void Burbuja_Optimizado(int array[N]);
void Intercambia(int*a,int*b);
int main()
{
	int i,array[N]={10,9,8,7,6,5,4,3,1,0};
   //Burbuja(array);
   Burbuja_Optimizado(array);
   for(i=0; i<N;i++){
   	printf("%d  ",array[i]);
   }
   return 0;

}
void Burbuja(int array[N]){
	int i,j;
	for(j=1;j<N;j++){
		for(i=0;i<N-j;i++){
			if(array[i]>array[i+1]){
				Intercambia(&array[i],&array[i+1]);
			}
		}
	}

}
void Burbuja_Optimizado(int array[N]){
	int i,j,cont=0;
	for(j=1;j<N;j++){
		for(i=0;i<N-j;i++){
			if(array[i]>array[i+1]){
				Intercambia(&array[i],&array[i+1]);
			}else{
                cont++;
			}
			if(cont==N-j){
                return;
			}
		}
		cont=0;
	}

}

void Intercambia(int*a,int*b){
	int aux;
	aux=*a;
	*a=*b;
	*b=aux;
}

