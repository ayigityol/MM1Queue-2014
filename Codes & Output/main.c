				/***************************************************
				*	Name:  M/M/1 QUEUEING SIMULATION PROJECT 	   *
				*			with using SMPL						   *
				*			 									   *	
				*	Author:  Ahmet Yiðit YOL - 					   *
				*			 Alican KARAMÝL - 					   *
				*			 Barýþcan ÇAMLIDERE - 				   * 
				****************************************************/
				
#include <stdio.h>
#define R 5

int main(){
	int i = 0;
	simulationStartMsg();
	for (i = 0; i<R; i++){
		simulation();
		printf("Simulation for R = %d finished!\n",i+1);
	}
		
	simulationEndMsg();
}

void simulationStartMsg(){
	
	printf("Simulation started!\n");
	printf("Welcome to MM1 queue simulator for different rho values.\n");
	printf("This simulator based on SMPL lib. and coded by Ahmet Yigit YOL, Alican KARAMIL, Bariscan Camlidere.\n");
	printf("On the simulator, rho values are : {0.1, 0.4, 0.6, 0.65, 0.7, 0.72, 0.74, 0.78, 0.79, 0.8}\n\t lambda value is 10 pps.\n");
	printf("Please wait, simulation has been started.\n");
	
}

void simulationEndMsg(){
	
	printf("Simulation ended!\n");
	printf("output file \"samples.txt\" has been created.\n");
	printf("Simulation will be terminated.");
	printf("Thank you!");
	
}
