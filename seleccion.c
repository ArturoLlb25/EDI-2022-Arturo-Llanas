#include <stdio.h>
#include <stdlib.h>
#define N 10
void Seleccion(int L[N]);
void Intercambia(int*a,int*b);
int main()
{
	int i,arr[N]={10,9,8,7,6,5,4,3,1,0};
   Seleccion(arr);
   for(i=0; i<N;i++){
   	printf("%d  ",arr[i]);
   }
   return 0;

}
void Seleccion(int arr[N]){
	int i,j,aux,min;
	for(i=0;i<N-1;i++){
		min=i;
		for(j=i+1;j<N;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		Intercambia(&arr[i],&arr[min]);
	}
}
void Intercambia(int*a,int*b){
	int aux;
	aux=*a;
	*a=*b;
	*b=aux;
}



