#include <iostream>
#include <queue>
#include <vector>
#include "MyTable.h"
#include "Intensity.h"


using namespace std;


class Flows
{
public:
	MyTable a;

	Intensity l;
	vector <int> S;
	vector<double> t_admiss;
	vector <double> dem;
	queue<double>Myqueue[2];

	double **P;
	double o1 = 0.2; //������������ ������������ ������ �������
	double o2 = 0.3; //������������ ������������ ������ �������
	double pr1 = 0.4; // ������������ ����������� ������ �������
	double pr2 = 0.3; //������������� ����������� ������ �������
	int r = 0;
	
	Flows(int n);
	~Flows();
	//long int fact(int N);
	//double dist_funct_PF(int L, double t);
	double exp_dist (double L);
	double random_variable_generation();
	int Swiching_Function(int s);
	int Equipment (double t_cuur, int s);
	double Tackt(double t,   int s,int c);
//	double Changeover (double l);
	int demand = 0;
	int tr = 0;
	//int s = 0;
	double average_time();
	double Condition(double p0,double p1,double p2);
	

private:
	int n;
	


};