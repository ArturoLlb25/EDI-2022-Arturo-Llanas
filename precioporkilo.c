#include<stdio.h>
int main(){
	float offer,price,weight,finalprice;
	printf("ingrese el precio por kilo:");
	scanf("%f",&price);
	printf("ingrese el peso en kilos que compro:");
	scanf("%f",&weight);
	if(weight<=2){
		finalprice=price*weight;
	}
	if(weight>2 && weight <=5){
		price*=weight;
		offer=price*.10;
		finalprice=price-offer;
	}
	if(weight>5 && weight<=10){
		price*=weight;
		offer=price*.15;
		finalprice=price-offer;
	}
	if(weight>10){
		price*=weight;
		offer=price*.20;
		finalprice=price-offer;
	}
	printf("el total a pagar es: %.2f",finalprice);
	return 0;
}
