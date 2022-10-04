#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void show_mas(int*p, int n){
	int i;
	printf("Array N:  \n");
	for (i=0; i<n; ++i){
		printf("%d\t",p[i]);
	}
	printf("\n");
}

void generate_mas(int*p, int n){
	int i;
	for (i=0; i<n; ++i){
    	p[i]= rand() % 500;
	}
}

void remove_el(int *p, int N, int index){
	int i;

	for(i=index; i<N-1; i++){
        p[i] = p[i + 1];
    }
        
	N = N-1;
    p = (int *)realloc(p,N * sizeof(int));
    if (!p){ 
       printf("Lack of memory\n");
       exit(1);
    } 
}

void set(int *p, int n, int index, int item){
	if(index < 1){
		p[index+1] = p[index+1]+item;
	}
	else{
		p[index-1] = p[index-1]+item;
	}
}

int smaller(int *p, int N){
	int i,index = 0,value = 10;
	
	value = p[0];
	
	for(i=1;i<N;++i){
		if(p[i] < value){
			value = p[i];
			index = i;
		}
	}
	return index;
}

int main(){
    srand (time (NULL));
    int *p, N, index;
    char a;
    printf("Enter array size N:  ");
    scanf("%d", &N);
    p = (int *)malloc(N * sizeof(int));
    if (!p){ 
       printf("Lack of memory\n");
       exit(1);
    } 
    generate_mas(p,N);
	printf("Array N, filled by random values\n");
	show_mas(p,N);
	while(N!=1){
		index = smaller(p,N);
		printf("Smallest value index: %d\n",index);
		printf("Smallest value: %d\n",p[index]);
		set(p,N,index,p[index]);
		remove_el(p,N,index);
		N--;
		show_mas(p,N);	
	}
	
    return 0;
}
