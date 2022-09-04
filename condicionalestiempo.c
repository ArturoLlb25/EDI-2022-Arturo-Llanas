#include<stdio.h>
int main(){
	int hour,minute;
	printf("ingrese la hora:");
	scanf("%d",&hour);
	printf("ingrese los minutos:");
	scanf("%d",&minute);
	if(hour>23 || minute>59){
		printf("opcion no valida");
		return 0;
	}
	if(hour<=11){
		printf("buenos dias :)");
	}
	if(hour>=12 && hour<=17){
		printf("buenas tardes :)");
	}
	if(hour>=18 && hour<=23){
		printf("buenas noches :)");
	}
	return 0;
}
