Name:  M/M/1 QUEUEING SIMULATION PROJECT with using SMPL

Author:  Ahmet Yiðit YOL    
         Alican KARAMIL    
		 Barýþcan ÇAMLIDERE 

Project Files:
	Calculated  Sample:
		calcSamples.txt
		- a text file that contains samples which are used in calculations in the report.
	Codes & Output:
		smpl.c
		- a C file that contains functions of SMPL

		smpl.h
		- a header file that contains function definitions of SMPL and rand.c

		rand.c
		- a C file that contains function of RNG and its variates

		mm1.c
		- a C file that includes all major changes according to given values

		main.c
		- a main C file that wraps up all these files which are mentioned above and runs according to replication value

		tp1.dev
		- project information file in DevC environment.

		tp1.exe
		- executable for simulation which outputs samples.txt

How to Load/Run:

- Open a new project from your IDE (Visual Studio, DevC++ etc.)
- Add all files which are mentioned above
- Build and run from main.c tab

Important note:

- If you are using Visual Studio as your main IDE do not forget to add code line which is mentioned below to prevent scan issues

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif



