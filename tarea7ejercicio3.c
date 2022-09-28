#include<stdio.h>
#define N 4
int precioMayor(int clave[N],float precio[N]);
int stockMenor(int clave[N],int stock[N]);
float sumaProductos(float precio[N],int stock[N]);
int main(){
	int i,mayor,menor;
	int clave[N],stock[N];
	float precio[N],suma;
	for(i=0;i<N;i++){
		printf("introduzca la clave del producto [%d]: ",i+1);
		scanf("%d",&clave[i]);
		printf("introduzca el precio del producto [%d]: ",i+1);
		scanf("%f",&precio[i]);
		printf("introduzca el stock del producto [%d]: ",i+1);
		scanf("%d",&stock[i]);
	}	 
	mayor=precioMayor(clave,precio);
	printf("clave del producto con mayor precio: %d\n",mayor);
	menor=stockMenor(clave,stock);
	printf("clave del prodcuto con menor stock: %d\n",menor);
	suma=sumaProductos(precio,stock);
	printf("total de venta esperada: %f",suma);
	
}

int precioMayor(int clave[N],float precio[N]){
	int i,promay=clave[0];
	float may=precio[0];
	for(i=0;i<N;i++){
		if(may<precio[i]){
			promay=clave[i];
		}
	}
	return promay;
}
int stockMenor(int clave[N],int stock[N]){
	int i,men=stock[0],smenor=clave[0];
	for(i=0;i<N;i++){
		if(men>stock[i]){
			smenor=clave[i];
		}
	}
	return smenor;
}
float sumaProductos(float precio[N],int stock[N]){
	int i;
	float total=0,multi=0;
	for(i=0;i<N;i++){
		multi=(float)precio[i]*stock[i];
		total=total+multi;
	}
	return total;
}
