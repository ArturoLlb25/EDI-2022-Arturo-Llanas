#include <stdio.h>
#include<string.h>
#include<ctype.h>
void cambia(char cadena[20]);
int main( )
{
    char cadena[20];
    printf("ingrese la cadena: ");
    scanf("%[^\n]",cadena);
    cambia(cadena);
    printf("la cadena es:\n");
    printf("%s",cadena);
    return 0;
}
void cambia(char cadena[20])
{
    for(int j=0;j<strlen(cadena);j++)
    {
        if(cadena[j]=='a'){
            cadena[j]=toupper(cadena[j]);
        }else if(cadena[j]=='A'){
            cadena[j]= tolower(cadena[j]);
        }
        if(cadena[j]=='e'){
            cadena[j]=toupper(cadena[j]);
        }else if(cadena[j]=='E'){
            cadena[j]= tolower(cadena[j]);
        }
        if(cadena[j]=='i'){
            cadena[j]=toupper(cadena[j]);
        }else if(cadena[j]=='I'){
            cadena[j]= tolower(cadena[j]);
        }
        if(cadena[j]=='o'){
            cadena[j]=toupper(cadena[j]);
        }else if(cadena[j]=='O'){
            cadena[j]= tolower(cadena[j]);
        }
        if(cadena[j]=='u'){
            cadena[j]=toupper(cadena[j]);
        }else if(cadena[j]=='U'){
            cadena[j]= tolower(cadena[j]);
        }

    }
}
