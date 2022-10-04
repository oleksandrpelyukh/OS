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
    	p[i]= rand() % 10;
	}
}

void add(int *p, int N){
	printf("\n");
	N = N+1;
    p = (int *)realloc(p,N * sizeof(int));
    if (!p){ 
       printf("Lack of memory\n");
       exit(1);
    } 
    printf("Enter the value of new array element: ");
    scanf("%d",&p[N-1]);
}

void set(int *p, int n){
	int item, index;
	printf("\n");
	printf("Enter index of elemet: \n");
	scanf("%d", &index);
	if(index >= n || index < 0){
		printf("Wrong index\n");
       exit(1);
	}
	printf("Enter new value of chosen element: \n");
	scanf("%d", &item);
	p[index] = item;
}

void get(int *p, int n){
	int index;
	printf("\n");
	printf("Enter index of elemet: \n");
	scanf("%d", &index);
	if(index >= n || index < 0){
		printf("Wrong index\n");
       exit(1);
	}
	printf("Chosen element: %d\n", p[index]);
}

void remove_el(int *p, int N){
	int index,i;
	
	printf("\n");
	printf("Enter index of elemet: \n");
	scanf("%d", &index);
	if(index >= N || index < 0){
		printf("Wrong index\n");
       exit(1);
	}
	
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

void insert(int *p, int N){
	int index, i, value;
	
	printf("\n");
	printf("Enter index of inserted elemet: \n");
	scanf("%d", &index);
	if(index >= N || index < 0){
		printf("Wrong index\n");
       exit(1);
	}
	printf("Enter value of new element: \n");
	scanf("%d", &value);
	
	N = N+1;
    p = (int *)realloc(p,N * sizeof(int));
    if (!p){ 
       printf("Lack of memory\n");
       exit(1);
    } 
    
    for(i = N - 1; i >= index; i--){
        p[i] = p[i - 1];
    }
    p[index] = value;	
}

int main(){
    srand (time (NULL));
    int *p, N, i;
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
    while (1){
    	printf("1. Method add\n");
	    printf("2. Method insert\n");
	    printf("3. Method size\n");
	    printf("4. Method remove\n");
	    printf("5. Method set\n");
	    printf("6. Method get\n");
	    printf("7. Exit\n");
	    printf("Enter your choice: ");
	    a = getche();
	    switch(a){
	    case '1':
	           add(p,N);
	           N++;
	           printf("\nArray after add method\n");
	           show_mas(p,N);
	           break;
	    case '2':
	    		insert(p,N);
	    		N++;
				printf("\nArray after insert method\n");
				show_mas(p,N);
	    		break;
	    case '3':
	    	   printf("\nArray size = %d\n", N);
	           break;
	    case '4':
	           remove_el(p,N);
	           N--;
	    	   printf("\nArray after remove method\n");
	    	   show_mas(p,N);
	           break;
	    case '5':
	    	   set(p,N);
	           printf("\nArray after set method\n");
	           show_mas(p,N);
	           break;	           
	    case '6':
	    		get(p,N);
	           break;
	    case '7':
	           exit(0);
	   default:
	         printf("\nWrong value, try again\n");
	          break;
	   }
	}
    return 0;
}
