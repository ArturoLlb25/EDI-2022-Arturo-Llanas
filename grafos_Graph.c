#include <stdio.h>
#define GRAPH 10
typedef struct {
    char elements[GRAPH];
    int noElements;
    int matrix[GRAPH][GRAPH];
}Graph;
void setupGraph(Graph *g);
int addVertice(Graph *g,char vertice);
int findVertice(char elements[GRAPH],int size, char value);
int addRelation(Graph *g, char vertice1, char vertice2);
void printGraph(Graph g);
int deleteRelation(Graph *g, char vertice1, char vertice2);
int deleteVertice(Graph *g,char vertice);


int main() {
    Graph graph;
    setupGraph(&graph);
    addVertice(&graph,'A');
    addVertice(&graph,'C');
    addVertice(&graph,'D');
    addVertice(&graph,'Z');
    addVertice(&graph,'W');
    addVertice(&graph,'X');
    addRelation(&graph,'A','Z');
    addRelation(&graph,'A','C');
    addRelation(&graph,'W','D');
    addRelation(&graph,'C','X');
    addRelation(&graph,'W','X');
    printGraph(graph);
    printf("\n");
    deleteVertice(&graph,'W');
    printGraph(graph);
    return 0;
}
void setupGraph(Graph *g){
    g->noElements=0;
    for(int renglon=0;renglon<GRAPH;renglon++){
        for(int columna=0;columna<GRAPH;columna++){
            g->matrix[renglon][columna]=0;
        }
    }
}
int addVertice(Graph *g,char vertice){
    if(g->noElements<GRAPH){
        g->elements[g->noElements]=vertice;
        g->noElements++;
        return 1;
    }
    return 0;
}
int addRelation(Graph *g, char vertice1, char vertice2){
    int posVertice1=findVertice(g->elements,g->noElements,vertice1);
    int posVertice2=findVertice(g->elements,g->noElements,vertice2);
    if(posVertice1!=-1 && posVertice2!=-1){
        g->matrix[posVertice1][posVertice2]=1;
        g->matrix[posVertice2][posVertice1]=1;
        return 1;
    }
    return 0;
}
int findVertice(char elements[GRAPH],int size, char value){
    int pos=-1;
    for(int i=0;i<size && pos==-1;i++){
        if(elements[i]==value)
            pos=i;
    }
    return pos;
}
void printGraph(Graph g){
    printf("\t");
    for(int i=0;i<g.noElements;i++){
        printf("%c\t",g.elements[i]);
    }
    printf("\n");
    for(int r=0;r<g.noElements;r++){
        printf("%c\t",g.elements[r]);
        for(int c=0;c<g.noElements;c++){
            printf("%d\t",g.matrix[r][c]);
        }
        printf("\n");
    }
}
int deleteRelation(Graph *g, char vertice1, char vertice2){
    int posVertice1=findVertice(g->elements,g->noElements,vertice1);
    int posVertice2=findVertice(g->elements,g->noElements,vertice2);
    if(posVertice1!=-1 && posVertice2!=-1){
        g->matrix[posVertice1][posVertice2]=0;
        g->matrix[posVertice2][posVertice1]=0;
        return 1;
    }
    return 0;
}
int deleteVertice(Graph *g,char vertice){
    int posVertice=findVertice(g->elements,g->noElements,vertice);
    if(posVertice!=-1){
        if(posVertice==g->noElements-1){
            g->noElements--;
        }else{
            for(int j=posVertice;j<g->noElements;j++){
                g->elements[j]=g->elements[j+1];
            }
            for(int i=posVertice;i<g->noElements;i++){
                for(int r=0;r<g->noElements;r++){
                    if(r==(g->noElements)){
                        g->matrix[i-1][r]=g->matrix[i+1][r];
                    } else{
                        g->matrix[i][r]=g->matrix[i+1][r];
                    }
                }
                for(int c=0;c<g->noElements;c++){
                    if(c==(g->noElements)){
                        g->matrix[c][i-1]=g->matrix[c][i+1];
                    } else{
                        g->matrix[c][i]=g->matrix[c][i+1];
                    }
                }
            }
            g->noElements--;
            return 1;

        }
    }
    return 0;
}
