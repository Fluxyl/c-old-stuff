#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Creating the Structure to hold the values.
struct Numbers{ 
	double a; 
	double b; 
	double c; 

};

// Function Declaration
struct Numbers numGrabber(void);
void displayVals(struct Numbers numVals);
void Calculations(struct Numbers numVals);


int main(void) {
	
	struct Numbers numVals;
	numVals = numGrabber();
	displayVals(numVals);
	Calculations(numVals);
	return(0);
}

struct Numbers numGrabber(void){
	
	struct Numbers numVals;

	printf("Please input the value for a\n: ");
	scanf("%lf",&numVals.a);
	printf("Please input the value for b\n: ");
	scanf("%lf",&numVals.b);
	printf("Please input the value for c\n: ");
	scanf("%lf",&numVals.c);

	return(numVals);
}

void displayVals(struct Numbers numVals) {
	printf("The first number is %0.2f\n",numVals.a);
	printf("The second number is %0.2f\n",numVals.b);
	printf("The third number is %0.2f\n",numVals.c);
}

void Calculations(struct Numbers numVals) {
	double valOne = (-numVals.b + sqrt(pow(numVals.b,2) - 4 * numVals.a * numVals.c)) / (2 * numVals.a);
	double valTwo = (-numVals.b - sqrt(pow(numVals.b,2) - 4 * numVals.a * numVals.c)) / (2 * numVals.a);
	printf("\n=================================");
	printf("\nThe final values are %0.2f & %0.2f",valOne,valTwo);
	printf("\n=================================\n");
}