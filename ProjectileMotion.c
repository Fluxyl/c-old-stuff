/*
 * Copy: Copyright (c) 2019 You know who made it ;)
 * Vers: 2.2.0 01/23/2019 - Added batch input support.
 * Vers: 2.1.0 01/22/2019 - General bug fixes and cleanup of code.
 * Vers: 2.0.0 01/19/2019 - Addition of 2D and Beam Support Functions.
 * Vers: 1.0.0 01/16/2019 - Programming 1D and the basic framework.
 * Desc: Calculates the values required for 1D and 2D motion.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void projectile_1D_v1(void);
void projectile_2D_v1(void);
void simple_supported_beam_v1(void);

int main(void) {
	//projectile_1D_v1();
	//projectile_2D_v1();
	//simple_supported_beam_v1();
	return 0;
}

/*
 * Name: void projectile_1D_v1(void)
 * Desc: Calculates the values for the one dimensional motion portion of the assignment.
 */
void projectile_1D_v1(void) {
	double y_init = 0.0;
	double a_init_y = -32.2;
	printf("\nInitial Height in Feet: ");
	scanf("%lf",&y_init);
	
	// Calculation for t_final
	double t_final = sqrt((-2*y_init)/(a_init_y));
	
	// Calculation for v_final_y
	double v_y_final = y_init/t_final;
	
	// Outputs
	printf("y_init: %0.2f ft\n",y_init);	
	printf("y_final: 0.00 ft\n");	
	printf("t_initial: 0.00 s\n");	
	printf("t_final: %0.2f s\n",t_final);	
	printf("v_y_initial: 0.00 ft/s\n");	
	printf("v_y_final: %0.2f ft/s\n",v_y_final);	
	printf("a_y_init: -32.2ft/s^2\n");	
}



/*
 * Name: void projectile_2D_v1(void)
 * Desc: Calculates various values associated with a 2D Ball's projected path..
 */
void projectile_2D_v1(void) {
	// Setup of Variables
	double v_init = 0.00;
	double y_init = 0.00;
 	double x_init = 0.00;
 	double t_initial = 0.00;
 	double a_x_init = 0.00;
 	double a_y_init = -32.2;
 	double theta = 0.00; 


 	// Input
	printf("Initial height in meters: ");
	scanf("%lf",&v_init);
	printf("angle of theta in radians: ");
	scanf("%lf",&theta);

	
	// Calculations for <v_init_x, v_init_y, t_final, & y_final>
	double v_x_init = (v_init * cos(theta));
	double v_y_init = (v_init * sin(theta));
	double t_final = ((-2 * v_y_init)/(-32.2));
	double y_final = (y_init + v_x_init * t_final + (1/2)*(-32.2)*pow(t_final,2));
	double x_final = (x_init + v_y_init * t_final + (1/2) * a_x_init * pow(t_final,2));
	

	// Calculations for <Final Positions>
	double v_x_final = (v_x_init + a_x_init * t_final);
	double v_y_final = (v_y_init + -32.2 * t_final);
	double v_final = v_init + a_y_init * t_final;

	// Outputs
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
}



/*
 * Name: simple_supported_beam_v1(void)
 * Desc: Calculates a simple supported beam problem using length, distance, and point load.
 */
void simple_supported_beam_v1(void) {
	double W  = 0.00;
	double L  = 0.00;
	double a  = 0.00;
	double R1 = 0.00;
	double R2 = 0.00;

	// Input portion.
	printf("Please input the force applied in pounds: ");
	scanf("%lf", &W);
	printf("Please input the length of the support beam: ");
	scanf("%lf", &L);
	printf("Please input the distance, a, from P1: ");
	scanf("%lf", &a);
	

	// Calculations Portion
	R2 = (W * a) / L;
	R1 = (W - R2);


	// Output Portion
	printf("\nW: %0.2f lbs\n", W);
	printf("L: %0.2f lbs\n", L);
	printf("a: %0.2f lbs\n", a);
	printf("R1: %0.2f lbs\n", R1);
	printf("R2: %0.2f lbs\n", R2);

}