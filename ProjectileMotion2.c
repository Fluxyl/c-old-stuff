/*
 * Copy: Copyright (c) 2019 Flux
 * Vers: 1.0.0 01/30/2019 - Programming the framework and adding support for batch.
 * Desc: Calculates the values for 1D, 2D, and Beam Support problems.
 */
// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function Declarations
int projectile_1D_v2(double y_init);
int projectile_2D_v2(double v_y_init, double theta);
int simple_supported_beam_v2(double W, double L, double a);	
int help(void);

// Main Segment
int main(int argc, char* argv[]) {

	// Check if enough argumemnts were provided, or if /h was called. 
	if (argc < 3) {
		if (strcmp(argv[1],"/h") == 0) {
			help();
		}
		else {
			printf("\nError: Not enough inputs.\n");
			help();
		}
	}

	// Interactive Mode Triggers
	else if (argc == 3 && strcmp(argv[1],"/i") == 0) {
		if (strcmp(argv[2],"/1D") == 0) {
			double y_init;
			printf("\nInitial Height in Feet: ");
			scanf("%lf",&y_init);	
			projectile_1D_v2(0.00);
		}
		else if (strcmp(argv[2],"/2D") == 0) {
			double v_init, theta;
			printf("Initial height in meters: ");
			scanf("%lf",&v_init);
			printf("angle of theta in radians: ");
			scanf("%lf",&theta);
			projectile_2D_v2(v_init, theta);
		}
		else if (strcmp(argv[2],"/Beam") == 0) {
			double W, L, a;
			printf("Please input the force applied in pounds: ");
			scanf("%lf", &W);
			printf("Please input the length of the support beam: ");
			scanf("%lf", &L);
			printf("Please input the distance, a, from P1: ");
			scanf("%lf", &a);	
			simple_supported_beam_v2(W, L, a);
		}
		else {
			printf("\nInvalid selection.\n");
			help();
		}
	}
	
	// Parameter Mode Triggers
	
	else if ((argc > 3) && strcmp(argv[1],"/p") == 0) {
		if (strcmp(argv[2],"/1D") == 0 && argc == 4) {
			projectile_1D_v2(atof(argv[3]));
		}
		else if (strcmp(argv[2],"/2D") == 0 && argc == 5) {
			projectile_2D_v2(atof(argv[3]),atof(argv[4]));
		}
		else if (strcmp(argv[2],"/Beam") == 0 && argc == 6) {
			simple_supported_beam_v2(atof(argv[3]),atof(argv[4]),atof(argv[5]));
		}
		else {
			printf("\nInvalid selection.\n");
			help();
		}
	}
	else {
		help();
	}
	return 0;
	/*int i = 0;
	for (i = 0; i < argc; ++i) {
		printf("argv[%d] = %s\n",i,argv[i]);
	}*/
	//projectile_1D_v1();
	//projectile_2D_v1();
	//simple_supported_beam_v1();

}


/*
 * Name: void projectile_1D_v1(double y_init)
 * Desc: Calculates the values for the one dimensional motion portion of the assignment.
 */
int projectile_1D_v2(double y_init) {
	double a_init_y = -32.2;
		
	// Calculation for t_final
	double t_final = sqrt((-2*y_init)/(a_init_y));
	
	// Calculation for v_final_y
	double v_y_final = y_init/t_final;
	
	// Outputs
	printf("\n========================================\n");
	printf("y_init: %0.2f ft\n",y_init);	
	printf("y_final: 0.00 ft\n");	
	printf("t_initial: 0.00 s\n");	
	printf("t_final: %0.2f s\n",t_final);	
	printf("v_y_initial: 0.00 ft/s\n");	
	printf("v_y_final: %0.2f ft/s\n",v_y_final);	
	printf("a_y_init: -32.2ft/s^2\n");	
    printf("========================================\n");
    return(0);
}


/*
 * Name: void projectile_2D_v1(double v_y_init, double theta)
 * Desc: Calculates various values associated with a 2D Ball's projected path..
 */
int projectile_2D_v2(double v_y_init, double theta) {
	// Setup of Variables

	double v_init = 0.00;
	double y_init = 0.00;
 	double x_init = 0.00;
 	double t_initial = 0.00;
 	double a_x_init = 0.00;
 	double a_y_init = -32.2;

	// Calculations for <v_init_x, v_init_y, t_final, & y_final>
	double v_x_init = (v_init * cos(theta));
	if (v_y_init == 0.00) {
		v_y_init = (v_init * sin(theta));
	}
	else {
		// Continue as normal.
	}
	double t_final = ((-2 * v_y_init)/(-32.2));
	double y_final = (y_init + v_x_init * t_final + (1/2)*(-32.2)*pow(t_final,2));
	double x_final = (x_init + v_y_init * t_final + (1/2) * a_x_init * pow(t_final,2));
	

	// Calculations for <Final Positions>
	double v_x_final = (v_x_init + a_x_init * t_final);
	double v_y_final = (v_y_init + -32.2 * t_final);
	double v_final = v_init + a_y_init * t_final;

	// Outputs
    printf("\n========================================\n");
	printf("y_init: 0.00 ft\n");
	printf("y_final: 0.00 ft\n");
	printf("x_init: 0.00 ft\n");
	printf("x_final: %0.2f ft\n",x_final);
	printf("t_initial: 0.00 s\n");
	printf("t_final: %0.2f s\n",t_final);
	printf("v_init: %0.2f ft/s\n",v_init);
	printf("v_x_init: %0.2f ft/s\n",v_x_init);
	printf("v_y_init: %0.2f ft\n",v_y_init);
	printf("v_final: 0.00 ft/s^2\n",v_final);
	printf("v_x_final: %0.2f ft/s^2\n",v_x_final);
	printf("v_y_final: %0.2f ft/s^2\n",v_y_final);
	printf("a_y_init: -32.2 ft/s^2\n");
    printf("========================================\n");
    return(0);
}


/*
 * Name: simple_supported_beam_v1(double W, double L, double a)
 * Desc: Calculates a simple supported beam problem using length, distance, and point load.
 */
int simple_supported_beam_v2(double W, double L, double a) {

	double R1 = 0.00;
	double R2 = 0.00;

	// Calculations Portion
	R2 = (W * a) / L;
	R1 = (W - R2);

	// Output Portion
    printf("\n========================================\n");
	printf("\nW: %0.2f lbs\n", W);
	printf("L: %0.2f lbs\n", L);
	printf("a: %0.2f lbs\n", a);
	printf("R1: %0.2f lbs\n", R1);
	printf("R2: %0.2f lbs\n", R2);
    printf("========================================\n");
    return(0);
}


/* 
 * Name: int help(void)
 * Desc: Tells the user how to use the program.
 */
int help(void){
    printf("========================================\n");
    printf("Copy: Copyright (c) 2019 Flux\n");
    printf("Vers: 1.0.0 01/30/2018 - Initial Release\n");
    printf("Desc: 1D, 2D, and Beam Support Calculator\n");	
    printf("\n========================================\n");
	printf("Help mode: /h\n");
	printf("\n 	 /i - Interactive mode\n");
	printf("\t\t/1D   - Projectile 1D\n");
	printf("\t\t/2D   - Projectile 2D\n");
	printf("\t\t/Beam - Supported Beam\n");
	printf("\n 	 /p  - Parameter Mode\n");
	printf("\t\t/1D   - Projectile 1D\n");
	printf("\t\t/2D   - Projectile 2D\n");
	printf("\t\t/Beam - Supported Beam\n");
    printf("\n========================================\n");
    printf("Example: 'P3.exe /p /2D 20 30'\n");
    printf("========================================\n");
    return(0);
}