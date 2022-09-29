#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
	 
	int n[6];
	int i, summ = 0, number = 0, position;
	float average, summa = 0;
	srand(time(NULL));
	
	printf("Array: ");
	for (i = 0; i<6; i++) {
	    	n[i] = (rand() %(10 + 10 + 1)) - 10;
	    	printf(" |%d| ", n[i]);
	}
	
	for(i = 0; i<6; i++){
		summa =summa+n[i];
	}
	
	average = summa/6;
	
	printf("\nAverage value of elemets: %5.3f\n", average);
	
	for(i = 0; i<6; i++){
		if(n[i]>average){
			number+=1;
		}
	}
	printf("Number of elements greater than the average value: %d\n", number);
	
	position = 0;
	for(i = 0; i<6; i++){
		if(n[i] < 0){
			position = i;
			break;
		}
	}
	
	if(position < 5){
		for(i = position+1; i<6;i++){
			summ= summ+abs(n[i]);
			printf("Summ %d\n", summ);
		}
	}
	
	printf("Summa of the modules of the array elements located after the first negative element: %d\n", summ);
	
	return 0;
}
