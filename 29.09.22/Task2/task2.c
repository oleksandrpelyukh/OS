#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int main(){
	 
	int n[6];
	int i, number, position;
	float average, summ = 0;
	srand(time(NULL));
	
	printf("Array: ");
	for (i = 0; i<6; i++) {
    	n[i] = (rand() %(10 + 10 + 1)) - 10;
    	printf(" |%d| ", n[i]);
	}
	
	/*for (i = 0; i<6; i++){
	    printf("Enter a[%d] = ", i);
	    scanf("%d", &n[i]); 
  	}*/
  	
	for(i = 0; i<6; i++){summ =summ+n[i];}
	average = summ/6;
	
	printf("\nAverage value of elemets: %5.3f\n", average);
	
	for(i = 0; i<6; i++){
		if(n[i]>average){
			number++;
		}
	}
	printf("Number of elements greater than the average value: %d\n", number-1);
	
	for(i = 0; i<6; i++){
		if(n[i]<0){
			i = position;
			break;
		}
	}
	
	summ = 0;
	
	if(position < 5){
		for(i = position+1; i<6;i++){
			summ= summ+ fabs(n[i]);	
		}
	}
	
	printf("Summa of the modules of the array elements located after the first negative element: %2.0f\n", summ);
	
	return 0;
}
