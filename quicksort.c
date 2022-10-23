#include <stdio.h>
#include <stdlib.h>
#define N 10
void quick_sort(int L[],int ini, int fin);
int main()
{
	int i,arr[N]={10,9,8,7,6,5,4,3,1,0};
   quick_sort(arr,0,N-1);
   for(i=0; i<N;i++){
   	printf("%d  ",arr[i]);
   }
   return 0;

}
void quick_sort(int arr[N],int ini, int fin){
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
