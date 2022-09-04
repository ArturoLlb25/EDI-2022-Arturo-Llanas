#include<stdio.h>
int main(){
	int ladoA,ladoB,ladoC;
	printf("ingrese el primer lado del triangulo: ");
	scanf("%d",&ladoA);
	printf("ingrese el segundo lado del triangulo: ");
	scanf("%d",&ladoB);
	printf("ingrese el tercer lado del triangulo: ");
	scanf("%d",&ladoC);
	if(( (ladoA+ladoB)<ladoC) || ( (ladoA+ladoC)<ladoB) || ( (ladoB+ladoC)<ladoA) ){
		printf("ese triangulo no existe");
	}else{
		if(ladoA!=ladoB && ladoA!=ladoC && ladoB!=ladoC ){
			printf("este triangulo es escaleno"); 
		}
		if(((ladoA==ladoB)&&(ladoA!=ladoC))|| ((ladoA==ladoC)&&(ladoA!=ladoB)) || ((ladoC==ladoB)&&(ladoC!=ladoA)) ){
			printf("este triangulo es isosceles");
		}
	}
	if( (ladoA==ladoB) && (ladoB==ladoC )){
		printf("este triangulo es equilatero");
	}
	return 0;
}
