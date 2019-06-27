#include <iostream>
#include <string>
#include "MyTable.h"
#include "Flows.h"
#include "Intensity.h"
using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	Flows p(2);
	//Intensity l(2);
	MyTable a(10000);

	vector <double> ti;
	ti.push_back(0);
	ti.push_back(0);
		

	int s;
	double key;
	int val;
	double c = 0;
	int end = 0;
	double t_curr = 0;
	double t_end = 8;

	//событие
	
	double Entr1 = 0; //поступление требования в первую очередь
	double Entr2 = 1; //поступление требования во вторую очередь
	double service = 2; // завершение обслуживания
	double changeover = 3;// завершение переналадки

	double p0 = 0; // переменная, которая хранит в себе текущее состояние
	
	double p1 = 0.7;//вероятность смены состояния среды из 1 во 2
	double p2 = 0.2;//вероятность смены состояния среды из 2 в 1

	double prodol = 0;
	/*cout << "Если вы хотите задать интенсивность, то введите один, иначе значения будут по умолчанию" << endl;
	cin >> end;
 
	if (end == 1)
	{
		cin >> p.l.L[0][0];
		cin >> p.l.L[0][1];
		cin >> p.l.L[1][0];
		cin >> p.l.L[1][1];

	}


	cout << "Eсли вы хотите задать вероятность поступления требования, то введите один, иначе значения будут по умолчанию" << endl;
	cin >> end;
	if (end == 1)
	{
		cin >> p.P[0][0];
		cin >> p.P[0][1];
		cin >> p.P[1][0];
		cin >> p.P[1][1];

	}
	cout << "Введи правило облуживания требований:" << endl << "1. Обслуживается очередь, в которой требований больше " << endl
		<< "2. Приоритет имеет первая очередь" << endl << "3. Приоритет имеет вторая очередь." << endl;
	int sys = 1;
	cin >> sys;
	cout << "Eсли вы хотите задать параметры системы, то введите 1 " << endl;
	cin >> end;
	if (end == 1)
	{
		cout << "Введите интенсивность обслуживания для первой очереди" << endl;
		cin >> p.o1;
		cout << "Введите интенсивность обслуживания для второй очереди" << endl;
		cin >> p.o2;
		cout << "Введите интенсивность переналадки для первой очереди" << endl;
		cin >> p.pr1;
		cout << "Введите интенсивность переналадки для второй очереди" << endl;
		cin >> p.pr2;
	}*/
	 //cin >> r2;
	do {
		cout << "Если вы хотите задать интенсивность, то введите один, иначе значения будут по умолчанию" << endl;
		cin >> end;

		if (end == 1)
		{
			cin >> p.l.L[0][0];
			cin >> p.l.L[0][1];
			cin >> p.l.L[1][0];
			cin >> p.l.L[1][1];

		}


		cout << "Eсли вы хотите задать вероятность поступления требования, то введите один, иначе значения будут по умолчанию" << endl;
		cin >> end;
		if (end == 1)
		{
			cin >> p.P[0][0];
			cin >> p.P[0][1];
			cin >> p.P[1][0];
			cin >> p.P[1][1];

		}
		cout << "Введи правило облуживания требований:" << endl << "1. Обслуживается очередь, в которой требований больше " << endl
			<< "2. Приоритет имеет первая очередь" << endl << "3. Приоритет имеет вторая очередь." << endl;
		int sys = 1;
		cin >> sys;
		cout << "Eсли вы хотите задать параметры системы, то введите 1 " << endl;
		cin >> end;
		if (end == 1)
		{
			cout << "Введите интенсивность обслуживания для первой очереди" << endl;
			cin >> p.o1;
			cout << "Введите интенсивность обслуживания для второй очереди" << endl;
			cin >> p.o2;
			cout << "Введите интенсивность переналадки для первой очереди" << endl;
			cin >> p.pr1;
			cout << "Введите интенсивность переналадки для второй очереди" << endl;
			cin >> p.pr2;
		}

		p0 = p1;
		c = p.random_variable_generation();
		if (c < p1)
		{
			p0 = p1;
			s = 0;
		}
		else
		{
			p0 = p2;
			s = 1;
		}
		cout << "Введите конечно время " << endl;
		cin >> t_end;


		for (int i = 0; i < 2; i++)
		{

			ti[i] = p.exp_dist(p.l.L[i][s]);
			p.a.InsRecord(ti[i], i, s);

		}
		if (p.a.GetKey(0) == ti[0]) p.a.InsRecord(p.a.GetKey(0) + p.exp_dist(p.o1), 2, 0);
		else p.a.InsRecord(p.a.GetKey(0) + p.exp_dist(p.o2), 2, 0);

		do
		{

			p.a.Print();
			cout << endl;
			if (p.a.GetValue(0) == 3)
			{
				p0 = p.Condition(p0, p1, p2);
				if (p0 == p1)s = 0;
				else s = 1;
				t_curr = p.Tackt(t_curr, s, sys);


			}
			else
			{
				if (p0 == p1) s = 0;
				else s = 1;
				t_curr = p.Tackt(t_curr, s, sys);
			}


		} while (t_curr < t_end);

		cout << "Количесто требований, которые покинули систему " << p.demand << endl;
		cout << "Количество требований, которые остались в первой очереди: " << p.Myqueue[0].size() << endl;
		cout << "Количество требований, которые остались во второй очереди: " << p.Myqueue[1].size() << endl;
		cout << "Количество требований, которые поступили в систему: " << p.tr << endl;

		for (int i = 0; i < p.t_admiss.size(); i++) cout << "Время прибытия требования: " << p.t_admiss[i] << " " << "Время, которое требование находилось в системе: " << p.dem[i] << endl;
		cout << "Cреднее время, которое требвание находится в системе: " << p.average_time() << endl;
		cout << "Хотите продолжить работу с системой введите 1" << endl;
		
		cin >> prodol;

		p.t_admiss.clear(); //for (int i = 0; i < p.t_admiss.size(); i++) cout << "Время прибытия требования: " << p.t_admiss[i] << endl;
		p.a.DelTable();
		
		p.dem.clear();
		t_curr = 0;
		while ((!p.Myqueue[0].empty()) && (!p.Myqueue[1].empty()))
		{
			for (int i = 0; i < p.Myqueue[0].size(); i++)  p.Myqueue[0].pop();
			for (int i = 0; i < p.Myqueue[1].size(); i++)  p.Myqueue[1].pop();
		}
	
	} while (prodol == 1);

	

	system("Pause");
}

