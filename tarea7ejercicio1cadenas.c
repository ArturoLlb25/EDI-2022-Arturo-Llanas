#include<stdio.h>
#include<string.h>
#define MAX 100
void pideCadena(char cadena[MAX]);
void pideCaracter(char *caracter);
int busca(char cadena[MAX],char caracter);
int main(){
	char cadena[MAX];
	char caracter;
	int cont;
	pideCadena(cadena);
	printf("Usted escribio: %s\n",cadena);
	pideCaracter(&caracter);
	printf("usted escribio el caracter: %c\n", caracter);
	cont=busca(cadena,caracter);
	printf("El caracter %c aparece %d veces en la cadena.",caracter,cont);
}
void pideCadena(char cadena[MAX]){
 	do{
 		printf("escriba cualquier texto(maximo 100 caracteres):\n");
 		gets(cadena);
 		if(strlen(cadena)>100){
 		printf("ERROR vuelva a digitar el texto\n");
		 }
	}while(strlen(cadena)>100);
 }
void pideCaracter(char *caracter){
 	printf("digite el caracter a buscar en la cadena:");
 	scanf("%c",*&caracter);
 }
int busca(char cadena[MAX],char caracter){
	int i,cuenta=0;
 	for(i=0;i<strlen(cadena);i++){
 		if(cadena[i]==caracter){
			cuenta++; 
		}
	}
	return(cuenta); 
}
 
 
