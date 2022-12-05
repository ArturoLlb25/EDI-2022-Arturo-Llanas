#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct {
    char name[50];
    char lastName[50];
    float average;
} Alumno;
int leer(FILE *file,Alumno alumnos[]);
void ordena(Alumno alumnos[],int tam);
void intercambia(Alumno *a,Alumno *b);
void imprime(Alumno alumnos[],int tam);

int main(void){
    FILE *file;
    int tam;
    Alumno alumnos[MAX];
    file=fopen("aprendizaje2.dat","rb");
    if(file==NULL){
        printf("ERROR: no se puede abrir el archivo");
        exit(EXIT_FAILURE);
    }else{
        tam=leer(file,alumnos);
        fclose(file);
        ordena(alumnos,tam);
        imprime(alumnos,tam);
    }
}

int leer(FILE *file,Alumno alumnos[]){
    int i=0;
    int tam=0;
    size_t size;
    fseek(file,0,SEEK_SET);
    do{
        size=fread(&alumnos[i],sizeof(Alumno),1,file);
        i++;
        tam++;
    }while(size!=0);
    return tam;
}

void ordena(Alumno alumnos[],int tam){
    for(int i=1;i<tam-1;i++){
        for(int j=i;j>0 && (strcmp(alumnos[j].lastName,alumnos[j-1].lastName)<0);j--){
            intercambia(&alumnos[j],&alumnos[j-1]);
        }
    }
}
void intercambia(Alumno *a,Alumno *b){
    Alumno aux;
    aux=*a;
    *a=*b;
    *b=aux;

}
void imprime(Alumno alumnos[],int tam){
    for(int i=0;i<tam-1;i++){
        printf("Nombre: %s\n",alumnos[i].name);
        printf("Apellido: %s\n",alumnos[i].lastName);
        printf("Promedio: %f\n",alumnos[i].average);
        printf("\n");
    }
}

