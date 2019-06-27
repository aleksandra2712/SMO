#include <iostream>
#include <cstdlib>
#include <time.h>
#ifndef _INTENSITY_
#define _INTENSITY_


using namespace std;


class Intensity
{
	
	public:
		double  **L;
		Intensity(int n = 2);
		~Intensity();

};
#endif