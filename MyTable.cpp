#include "MyTable.h"

MyTable::MyTable(int _TabSize)
{
	pMem = new pTTabRecord[_TabSize];
	for (int i = 0; i < _TabSize; i++) { pMem[i] = NULL; }
	TabSize = _TabSize;
	RecCount = 0;
}

int MyTable::FindRecord(double k)
{

	int mind; //cередина
	int pos;
	int L; //размер левой границы
	int R;//размер правой границы
	bool flag = false;
	L = 0;
	R = RecCount - 1;
	if(RecCount == 0)
	{
		return pos = -1;
	}
	while ((L <= R)&&(flag !=true))
	{
		mind = (L + R)/2;
		if ( pMem[mind]->Key == k)
		{
			pos = mind;
			flag = true;
		}
		else if (pMem[mind]->Key > k)
		{
			R = mind -1;
			pos = mind;
		}
		else if (pMem[mind]->Key < k)
		{
			L = mind+1;
			pos = mind;
		}
	}
	if (pMem[pos]->Key == k)
	{
		//cout << "This is" << endl;
		return pos;
	}
	else
	{
		//cout << "Don't find, but  ins  pos" << endl;
	return pos = -1;
	}
}

int MyTable::InsRecord (double k, int v, double info)
{
	int pos = FindRecord(k), res = 0;
	if (pos == -1)
	{
		if (RecCount < TabSize)
		{
			
			pMem[RecCount++] = new TTabRecord(k, v,info);
			Sortinsertion(pMem,RecCount);
		}
		else
			res = 1;
	}
	//else
		//pMem[pos]->Value += v;
	return res;
	
}

void MyTable:: DelTable()
{
	for (int i = 0; i < RecCount; i++)
	{
		delete pMem[i];
		pMem[i] = NULL;
	}
	//CurrPos = 0;
	RecCount = 0;
}

int MyTable::GetValue (int i)

{
	if ( RecCount == 0) return 0;
	else return pMem[i]->GetValue();
}

double MyTable::GetKey(int i)
{
	return pMem[i]->GetKey();
}

double MyTable::GetInfo(int i)
{
	if (RecCount == 0) return 0;
	return pMem[i]->GetInfo();
}

void MyTable::Print()
{
	for(int i = 0; i < RecCount; i++)
	{
		cout<<pMem[i]->GetKey()<<" | "<< pMem[i]->GetValue()<< " | "<< pMem[i]->GetInfo() << endl ;
	}
}

void MyTable::SetValue (int v,int i)
{
	pMem[i]->SetValue(v);
}

void MyTable::SetKey(double k, int i)
{
	pMem[i]->SetKey(k);
}

void MyTable::Sortinsertion(pTTabRecord *pMem, int RecCount)
{
	
	pTTabRecord *tem = new pTTabRecord [RecCount];
	int item;
	
	for ( int i = 0; i < RecCount; i++)
		tem[i] = NULL;
	
	for (int  i = 1; i < RecCount; i++)
	{
		tem[i] =  new TTabRecord(pMem[i]->Key,pMem[i]->Value,pMem[i]->Info);
		item = i-1;
		while (item >=0 && pMem[item]->Key > tem[i]->Key)
		{
			*pMem[item+1] = *pMem[item];
			*pMem[item] = *tem[i];
			item--;
		}
		
	}
	
}

int MyTable::DelRecord()
{
	
	int pos = 0, res = 0;
	//*if (pos == -1)
		//res = 1;*
	
		*pMem[pos] = *pMem[RecCount - 1];
		delete pMem[RecCount-1];
		pMem[RecCount--] = NULL;
		
	Sortinsertion(pMem,RecCount);
	return res;
}
