#include <stdio.h>
#include <stdlib.h>
#define N 10
void Baraja(int arr[N]);
void Intercambia(int*a,int*b);
int main()
{
	int i,arr[N]={10,9,8,7,6,5,4,3,1,0};
   Baraja(arr);
   for(i=0; i<N;i++){
   	printf("%d  ",arr[i]);
   }
   return 0;

}
void Baraja(int arr[N]){
	int i,j;
	for(i=1;i<N;i++){
		for(j=i;j>0 && arr[j]<arr[j-1];j--){
			Intercambia(&arr[j],&arr[j-1]);
		}
	}
}
void Intercambia(int*a,int*b){
	int aux;
	aux=*a;
	*a=*b;
	*b=aux;
}

