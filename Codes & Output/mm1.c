				/***************************************************
				*	Name:  M/M/1 QUEUEING SIMULATION PROJECT 	   *
				*			with using SMPL						   *
				*			 									   *	
				*	Author:  Ahmet Yiðit YOL 					   *
				*			 Alican KARAMIL 					   *
				*			 Barýþcan ÇAMLIDERE 				   * 
				****************************************************/


//========================================================== file = mm1.c =====
//=  A simple M/M/1 queue simulation using SMPL                               =
//=============================================================================
//=  Notes: This program is adapted from "Figure 1.7" in Simulating Computer  =
//=         Systems, Techniques and Tools by M. H. MacDougall (1987)          =
//=---------------------------------------------------------------------------=
//=  Build: bcc32 mm1.c smpl.c bmeans.c rand.c                                =
//=         gcc mm1.c smpl.c bmeans.c rand.c -lm                              =
//=---------------------------------------------------------------------------=
//=  History: KJC (10/04/98) - Genesis                                        =
//=           KJC (02/18/05) - Cleaned-up for better understanding            =
//=============================================================================
//----- Include files ---------------------------------------------------------
#include <stdio.h>      // Needed for printf()
#include "smpl.h"       // Needed for SMPL

//===== Main program ==========================================================
void simulation(void)
{
  
  real Ta[10] = {1.0000, 0.2500, 0.1667, 0.1539, 0.1429, 0.1389, 0.1351, 0.1282, 0.1266, 0.1250}; // Mean interarrival times (seconds)
  real Ts = 0.1;        // Mean service time
  int customer = 1;     // Customer id (always '1' for this simulation)
  int event;            // Event (1 = arrival, 2 = request, 3 = completion)
  int server;           // Handle for server facility
  
  // Initialize SMPL subsystem
  smpl(0, "M/M/1 Queue");

  // Initialize server facility (single server)
  server=facility("server", 1);
	int  k;
	
  // Schedule arrival event at time 0 to kick-off simulation
  schedule(1, 0.0, customer);
  int package = 0;
  // Loop while simulation time is less than te
  for (k=0; k<10; k++){
	  package = 0;
	  reset();
	  
	  while (package < 10000)//10000 package
	  {
	    // "Cause" the next event on the event list
	    cause(&event,&customer);
	
	    // Process the event
	    switch(event)
	    {
	      case 1:  // *** Arrival
	        schedule(2, 0.0, customer);
	        schedule(1, expntl(Ta[k]), customer);
	        break;
	
	      case 2:  // *** Request Server
	        if (request(server, customer, 0) == 0)
	          schedule(3, expntl(Ts), customer);
	        break;
	
	      case 3:  // *** Release server
	        release(server, customer);
	        package++;
			break;
	    }
  }

  // Output standard SMPL report
  report();
  }
  
}
  
