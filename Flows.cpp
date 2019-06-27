#include "Flows.h"


 Flows::Flows(int n)
 {  

	 P = new double*[n];

	 for (int i = 0; i < n; i++)
	 {
		 P[i] = new double[n];
	 }
	 P[0][0] = 0.4;
	 P[0][1] = 0.2;
	 P[1][0] = 0.5;
	 P[1][1] = 0.1;
 }	

 

double Flows::exp_dist(double L)	
{
	double v;
	v = (double)rand()/RAND_MAX;
	double t;
	fflush(stdin);

	t = -1*log(1-v)/L;
	return t;

}

double Flows::random_variable_generation()
{
	return (double)rand() / RAND_MAX;
}


	int Flows::Swiching_Function(int c)
	{
		double size0 = Myqueue[0].size();
		double size1 = Myqueue[1].size();
		if (c == 1)//выбираем очередь, которая больше
		{
			if ((size0 == NULL) && (size1 == NULL))
				return 0;

			else if (size0 > size1)
				return 1;
			else return 2;
		}
		else if (c == 2)// первая очередь приорететней
		{
			if (size0 != NULL)
			{
				return 1;
			}
			else return 2;

		}
		else if (c = 3)// вторая очередь имеет приоритет
		{
			if (size1 != NULL) return 2;
			else return 1;
		}
	}


int Flows::Equipment (double t_curr,int c)
{

 	int r =  Swiching_Function(c);
	double q = 0;
	double u = 0;
	double y = 0;
	int z = 0;
	int o = 0;
	q = random_variable_generation();
	//if (r == 0) return z;

	
	
		u = Myqueue[r-1].front();
		o = r - 1;
		Myqueue[r-1].pop();
		y = P[0][0] + P[1][0];
		
		if (( q >= 0) && (q < P[0][0])) Myqueue[0].push(u);
		else if (( q >=P[0][0]) && ( q < y)) Myqueue[1].push(u);
		else if ((q >= y) && (q < 1))
		{
			
			t_admiss.push_back(u);
			dem.push_back(t_curr - u);
			demand++;
		
			
		}		
		return r;
}



double Flows::Tackt( double t_curr,  int s,int c)
{
	int x = a.GetValue(0);
	double t = 0;
	
	
	switch (x)
	{
	case 0:
	{
		tr++;
		Myqueue[x].push(t_curr);
		t_curr = a.GetKey(0);
		a.DelRecord();
		double z = exp_dist(l.L[x][s]);
		a.InsRecord(t_curr + z, x, s);
		
		
		break;
	}
	case 1:
	{
		tr++;
		Myqueue[x].push(t_curr);
		t_curr = a.GetKey(0);
		a.DelRecord();
		double z = exp_dist(l.L[x][s]);
		a.InsRecord(t_curr + z, x, s);
		
		break;
	}
	case 2:
	{
	
		t_curr = a.GetKey(0);
		 r = Equipment(a.GetKey(0),c);

		if (r == 1) a.InsRecord(t_curr + exp_dist(pr1), 3, 0);
		else a.InsRecord(t_curr + exp_dist(pr2), 3, 1);
		a.DelRecord();
		break;
	}
	case 3:
	{
		t_curr = a.GetKey(0); 
		a.DelRecord();
		if ((a.GetInfo(0) != s) && (a.GetInfo(1) != s))
		{
			a.DelRecord();
			a.DelRecord();
			a.InsRecord(t_curr + exp_dist(l.L[0][s]), 0, s);
			a.InsRecord(t_curr + exp_dist(l.L[1][s]), 1, s);
		}
		if (a.GetValue(0) == 0) a.InsRecord(t_curr + exp_dist(o1), 2, 0);
		else a.InsRecord(t_curr + exp_dist(o2), 2, 1);
		
	
	

		break;
	}
	

	}
	
	return t_curr;
	
}

double Flows::average_time()
{
	double j = 0;
	for (int i = 0; i < dem.size(); i++) j += dem[i];
	
	j = (double)j / demand;

	return j;

}
double Flows::Condition(double p0, double p1, double p2)
{
	double c = random_variable_generation();
	if (p0 == p1)
	{
		if (c < p1)
		{
			p0 = p1;
			
			
		}
		else
		{
			p0 = p2;
			
	
		}
	}
	else
	{
		if (c < p2)
		{
			p0 = p2;
			
		}
		else
		{
			p0 = p1;
		
		}
	}
	return p0;
}

Flows::~Flows()
{
	for (int i = 0; i < 2; i++)
		delete[] P[i];
	delete[] P;
}



