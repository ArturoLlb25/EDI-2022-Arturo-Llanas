#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 75000
#define M 75000
void genera(int L[N], int T);
void Burbuja(int L[N], int T);
void Baraja(int L[N],int T);
void Seleccion(int L[N],int T);
void quick_sort(int L[N],int ini, int fin);
void Intercambia(int*a,int*b);
void imprime(float A[3]);
int main()
{
    int L[N];
    int S[M];
	int ti,tf, T,r;
	float bur[2],bar[2],sel[2],q[2],bur2[2],bar2[2],sel2[2],q2[2];
    float prom;
    //50K
    T=50000;
    //burbuja pasada 1
    genera(L,T);
    ti=time(0);
    Burbuja(L,T);
    tf=time(0);
    bur[0]=tf-ti;
    //burbuja pasada 2
    genera(L,T);
    ti=time(0);
    Burbuja(L,T);
    tf=time(0);
    bur[1]=tf-ti;

    bur[2]=((bur[0]+bur[1])/2);
    //baraja pasada 1
    genera(L,T);
    ti=time(0);
    Baraja(L,T);
    tf=time(0);
    bar[0]=tf-ti;
    //baraja pasada 2
    genera(L,T);
    ti=time(0);
    Baraja(L,T);
    tf=time(0);
    bar[1]=tf-ti;

    bar[2]=((bar[0]+bar[1])/2);
    //Seleccion pasada 1
    genera(L,T);
    ti=time(0);
    Seleccion(L,T);
    tf=time(0);
    sel[0]=tf-ti;
    //Seleccion pasada 2
    genera(L,T);
    ti=time(0);
    Seleccion(L,T);
    tf=time(0);
    sel[1]=tf-ti;

    sel[2]=((sel[0]+sel[1])/2);
    //quicksort pasada 1
    genera(L,T);
    ti=time(0);
    quick_sort(L,0,T-1);
    tf=time(0);
    q[0]=tf-ti;
    //quicksort pasada 2
    genera(L,T);
    ti=time(0);
    quick_sort(L,0,T-1);
    tf=time(0);
    q[1]=tf-ti;

    q[2]=((q[0]+q[1])/2);
    printf("datos con N=50000\n");

    printf("Burbuja    |");
    imprime(bur);
    printf("Baraja     |");
    imprime(bar);
    printf("Seleccion  |");
    imprime(sel);
    printf("Quicksort  |");
    imprime(q);
    printf("\n");
    printf("\n");
    printf("datos con N=75000\n");
    //75K
    r=75000;
    //burbuja pasada 1
    genera(L,r);
    ti=time(0);
    Burbuja(L,r);
    tf=time(0);
    bur2[0]=tf-ti;
    //burbuja pasada 2
    genera(L,r);
    ti=time(0);
    Burbuja(L,r);
    tf=time(0);
    bur2[1]=tf-ti;

    bur2[2]=((bur2[0]+bur2[1])/2);
    //baraja pasada 1
    genera(L,r);
    ti=time(0);
    Baraja(L,r);
    tf=time(0);
    bar2[0]=tf-ti;
    //baraja pasada 2
    genera(L,r);
    ti=time(0);
    Baraja(L,r);
    tf=time(0);
    bar2[1]=tf-ti;

    bar2[2]=((bar2[0]+bar2[1])/2);
    //Seleccion pasada 1
    genera(L,r);
    ti=time(0);
    Seleccion(L,r);
    tf=time(0);
    sel2[0]=tf-ti;
    //Seleccion pasada 2
    genera(L,r);
    ti=time(0);
    Seleccion(L,r);
    tf=time(0);
    sel2[1]=tf-ti;

    sel2[2]=((sel2[0]+sel2[1])/2);
    //quicksort pasada 1
    genera(L,r);
    ti=time(0);
    quick_sort(L,0,r-1);
    tf=time(0);
    q2[0]=tf-ti;
    //quicksort pasada 2
    genera(L,r);
    ti=time(0);
    quick_sort(L,0,r-1);
    tf=time(0);
    q2[1]=tf-ti;
    q2[2]=((q2[0]+q2[1])/2);
    //tiempos

    printf("\n");
    printf("\n");
    printf("datos con N=75000\n");

    printf("Burbuja    |");
    imprime(bur2);
    printf("Baraja     |");
    imprime(bar2);
    printf("Seleccion  |");
    imprime(sel2);
    printf("Quicksort  |");
    imprime(q2);
}
void genera(int L[N], int T){
    int i;
    for (i=0;i<T;i++){
        L[i]=rand()%100;
    }
}

void Burbuja(int L[N], int T){
	int i,j;
	for(j=1;j<T;j++){
		for(i=0;i<T-j;i++){
			if(L[i]>L[i+1]){
				Intercambia(&L[i],&L[i+1]);
			}
		}
	}
}


void Baraja(int L[N], int T){
	int i,j;
	for(i=1;i<T;i++){
		for(j=i;j>0 && L[j]<L[j-1];j--){
			Intercambia(&L[j],&L[j-1]);
		}
	}
}

void Seleccion(int L[N], int T){
	int i,j,aux,min;
	for(i=0;i<T;i++){
		min=i;
		for(j=i+1;j<T;j++){
			if(L[j]<L[min]){
				min=j;
			}
		}
		Intercambia(&L[i],&L[min]);
	}
}
void quick_sort(int L[N],int ini, int fin){
	int piv,izq,der,med;
	if(ini<fin){
		piv=L[ini];
		izq=ini;
		der=fin;
		while(izq<der){
			while(der>izq && L[der]>piv)
			der--;
			if(der>izq){
				L[izq]=L[der];
				izq++;
			}
			while(izq<der && L[izq]<piv)
			izq++;
			if(izq<der){
				L[der]=L[izq];
				der--;
			}
		}
		L[der]=piv;
		med=der;
		quick_sort(L,ini,med-1);
		quick_sort(L,med+1,fin);
	}
}

void Intercambia(int*a,int*b){
	int aux;
	aux=*a;
	*a=*b;
	*b=aux;
}
void imprime(float A[3]){
	int i;
	for(i=0;i<3;i++){
		printf("%.2f  ",A[i]);
	}
	printf("\n");
}