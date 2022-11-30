#include <stdio.h>
#define SET 20
typedef struct{
    int data[SET];
    int size;
}Set;
void setupSet(Set *s);
int existElement(Set s,int value);
int addElement(Set *s,int value);
int deleteElement(Set *s,int value);
void intersect(Set a,Set b,Set *result);
void linked(Set a,Set b,Set *result);
void difference(Set a,Set b,Set *result);
void addition(Set *a,Set b);
void printSet(Set s);

int main() {
    int r;
    Set set1,set2,set3;
    setupSet(&set1);
    setupSet(&set2);
    setupSet(&set3);
    addElement(&set1,1);
    addElement(&set1,2);
    addElement(&set1,3);
    addElement(&set2,2);
    addElement(&set2,3);
    addElement(&set2,4);
    addElement(&set2,5);
    deleteElement(&set2,5);
    //linked(set1,set2,&set3);
    addition(&set1,set2);
    printSet(set1);
    return 0;
}
void setupSet(Set *s){
    s->size=0;
}
int existElement(Set s,int value){
    int found=0;
    for(int i=0;i<s.size && !found;i++){
        if(s.data[i]==value)
            found=1;
    }
    return found;
}
int addElement(Set *s,int value){
    if(existElement(*s,value)==0 && s->size<SET){
        s->data[s->size]=value;
        s->size++;
        return 1;
    }
    return 0;
}
int deleteElement(Set *s,int value){
    int found=-1;
    for(int i=0;i<s->size && found==-1;i++){
        if(s->data[i]==value)
            found=i;
    }
    if(found!=1){
        s->size--;
        for(int actual=found;actual<s->size;actual++){
            s->data[actual]=s->data[actual+1];
        }
        return 1;
    }
    return 0;
}
void intersect(Set a,Set b,Set *result){
    for(int i=0;i<a.size;i++){
        if(existElement(b,a.data[i])==1){
            addElement(result,a.data[i]);
        }
    }
}
void linked(Set a,Set b,Set *result){
    for(int i=0;i<a.size;i++){
        addElement(result,a.data[i]);
    }
    for(int j=0;j<b.size;j++){
        if(existElement(a,b.data[j])==0){
            addElement(result,b.data[j]);
        }
    }
}
void difference(Set a,Set b,Set *result){
    for(int i=0;i<a.size;i++){
        if(existElement(b,a.data[i])==0){
            addElement(result,a.data[i]);
        }
    }
}
void addition(Set *a,Set b){
    for(int i=0;i<b.size;i++){
        if(existElement(*a,b.data[i])==0){
            addElement(a,b.data[i]);
        }
    }

}
void printSet(Set s){
    for(int i=0;i<s.size;i++){
        printf("%d",s.data[i]);
    }
    printf("\n");
}