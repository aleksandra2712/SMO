#include "Intensity.h"

Intensity::Intensity(int n)
 {  
	
	L = new double*[n];

	for (int i = 0; i < n; i++)
	{
		L[i] = new double[n];
	}
	L[0][0] = 0.8;
	L[0][1] = 0.5;
	L[1][0] = 0.6;
	L[1][1] = 0.45;
	
 }	

Intensity::~Intensity()
{
	for (int i = 0; i < 2; i++)
		delete[] L[i];
	delete[] L;
}