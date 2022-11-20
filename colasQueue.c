#include <stdio.h>
#include <stdbool.h>
#define QUEUE 4
typedef struct {
    int arreglo[QUEUE];
    int start;
    int end;
}Queue;

void setupQueue(Queue *q);
bool isQueueEmpty(Queue *q);
bool isQueueFull(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);

int main() {
    Queue queue;
    int dato;
    //hice una prueba de casos donde llene la cola, la vacie, volvi a insertar y volvi a eliminar
    setupQueue(&queue);
    enqueue(&queue,9);
    enqueue(&queue,11);
    enqueue(&queue,8);
    enqueue(&queue,7);
    dato=dequeue(&queue);
    printf("sacado de la cola: %d \n",dato);
    dato=dequeue(&queue);
    printf("sacado de la cola: %d \n",dato);
    dato=dequeue(&queue);
    printf("sacado de la cola: %d \n",dato);
    dato=dequeue(&queue);
    printf("sacado de la cola: %d \n",dato);
    enqueue(&queue,10);
    enqueue(&queue,7);
    dato=dequeue(&queue);
    printf("sacado de la cola: %d \n",dato);
    return 0;
}
void setupQueue(Queue *q)
{
    q->start=0;
    q->end=0;
}
bool isQueueEmpty(Queue *q)
{
    if(q->start==q->end){
        return true;
    }
    return false;
}
bool isQueueFull(Queue *q)
{
    if((q->end+1)%(QUEUE)==q->start ){
        return true;
    }
    return false;
}
void enqueue(Queue *q, int value)
{
    if(isQueueFull(q)){
        printf("ERROR: cola llena\n");
    }else{
        q->arreglo[q->end]=value;
        q->end=(q->end+1)%QUEUE;
    }
}
int dequeue(Queue *q)
{
    int value;
    if(isQueueEmpty(q)){
        printf("ERROR: cola vacia\n");
        return -1;
    }else{
        value=q->arreglo[q->start];
        q->start=(q->start+1)%QUEUE;
        return value;
    }
}