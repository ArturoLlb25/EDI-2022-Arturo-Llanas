#include <stdio.h>
#include <stdbool.h>
#define STACK 3
typedef struct {
    int arreglo[STACK];
    int tope;
}Stack;

void setupStack(Stack *s);
bool isStackEmpty(Stack *s);
bool isStackFull(Stack *q);
void push(Stack *s, int value);
int pop(Stack *s);

int main() {
    Stack stack;
    int dato;
    //hice una prueba de casos donde llene la pila, la vacie, volvi a insertar y volvi a eliminar
    setupStack(&stack);
    push(&stack,9);
    push(&stack,11);
    push(&stack,8);
    push(&stack,7);
    dato=pop(&stack);
    printf("sacado de la pila: %d \n",dato);
    dato=pop(&stack);
    printf("sacado de la pila: %d \n",dato);
    dato=pop(&stack);
    printf("sacado de la pila: %d \n",dato);
    dato=pop(&stack);
    printf("sacado de la pila: %d \n",dato);
    push(&stack,7);
    push(&stack,10);
    dato=pop (&stack);
    printf("sacado de la pila: %d \n",dato);
    return 0;
}
void setupStack (Stack *s)
{
    s->tope=0;
}
bool isStackEmpty(Stack *s)
{
    if(s->tope==0){
        return true;
    }
    return false;
}
bool isStackFull(Stack *s)
{
    if(s->tope==STACK ){
        return true;
    }
    return false;
}
void push(Stack *s, int value)
{
    if(isStackFull(s)){
        printf("ERROR: pila llena\n");
    }else{
        s->arreglo[s->tope]=value;
        s->tope++;
    }
}
int pop(Stack *s)
{
    if(isStackEmpty(s)){
        printf("ERROR: pila vacia\n");
        return -1;
    }else{
        s->tope--;
        return s->arreglo[s->tope];
    }
}