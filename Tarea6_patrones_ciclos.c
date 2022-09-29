#include<stdio.h>
#define N 10
void clean(int arr[N][N]);
void imprime(int arr[N][N]);
void patron1(int arr[N][N]);
void patron2(int arr[N][N]);
void patron3(int arr[N][N]);
void genera3(int arr[N][N],int dis);
void patron6(int arr[N][N]);
int main(){
    int arr[N][N];
    clean(arr);
    patron1(arr);
    printf("patron a:\n");
    imprime(arr);
    clean(arr);
    patron2(arr);
    printf("patron b:\n");
    imprime(arr);
    clean(arr);
    patron3(arr);
    printf("patron c:\n");
    imprime(arr);
    clean(arr);
    //patron4(arr); lo intente pero no me salio, abajo sale la funcion
    patron6(arr);
    printf("patron f:\n");
    imprime(arr);
}
void clean(int arr[N][N]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            arr[i][j]=0;
        }
    }
}
void imprime(int arr[N][N]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("[%d]",arr[i][j]);
        }
        printf("\n");
    }
}
void patron1(int arr[N][N]){
    int i;
    for(i=0;i<N;i++){
        arr[0][i]=1;
        arr[N-1][i]=1;
        arr[i][0]=1;
        arr[i][N-1]=1;
    }
}

void patron2(int arr[N][N]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(i==j || (i+j)==N-1 ){
                arr[i][j]=1;
            }
        }
    }
}
void patron3(int arr[N][N]){
    int dis;
    for(dis=0;dis<N/2;dis+=2){
        genera3(arr,dis);
    }

}
void genera3(int arr[N][N],int dis){
    int i;
    for(i=dis;i<N-dis;i++){
        arr[dis][i]=1;
        arr[N-dis-1][i]=1;
        arr[i][dis]=1;
        arr[i][N-dis-1]=1;
    }
}
void patron6(int arr[N][N]) {
    int i,j,cont,band;
    clean(arr);
    cont=1;
    band=0;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(cont%2==1){
                arr[i][j]=1;
            }
            band++;
            if(band==cont){
                cont++;
                band=0;
            }

        }

    }
}
//void patron4(int arr[N][N]){
//	int i,j,k,m,o;
//	clean(arr);
//	for(i=0;i<N;i+=2){
//		for(j=i;j<N-i;j++){
//			arr[i][j]=1;
//		}
//		for(k=1;k<N-i;k++){
//			arr[k][N-1]=1;
//		}
//		for(m=N-1;m>0+i;m--){
//			arr[N-i][m]=1;
//		}
//		for(o=N-i;o>0+i;o--){
//			arr[o][0+i-1]=1;
//		}
//	}
//}

