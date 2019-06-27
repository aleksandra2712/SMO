#ifndef MYTABLE_H
#define MYTABLE_H

#include <iostream>
#include "TTabRecord.h"
#include <string.h>
using namespace std;


class MyTable
{
public:
	int TabSize;
	
	pTTabRecord *pMem;


	//void Merge( pTTabRecord *pMem, int RecCount, pTTabRecord *pRight,int R, pTTabRecord *pLeft, int L);
	//void MergeSort (pTTabRecord *pMem,int RecCount);	
	void Sortinsertion(pTTabRecord *pMem,int RecCount);

public:
	int RecCount;
	MyTable (int _size = 25);
	int FindRecord (double k);
	int GetValue (int i);
	double GetKey(int i);
	double GetInfo(int i);
	void SetValue (int v,int i);
	void SetKey(double k, int i);
	int InsRecord(double k, int v, double info);
	int DelRecord();
	//int operator [](int i);
	void DelTable();

	void Print();

	

};

#endif