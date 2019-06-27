#ifndef _TTABRECORD_H_
#define _TTABRECORD_H_

#include <iostream>
#include <string>

using namespace std;

class TTabRecord;

typedef TTabRecord *pTTabRecord;

class TTabRecord
{
protected:
	double Key;
	int  Value;
	double Info;
public:
	TTabRecord(double _key = 0.0, int _value = 0.0, double _info =0.0);

	void SetKey(double k);
	void SetValue(int v);

	int GetValue(void);
	double  GetKey(void);
	double GetInfo(void);

	TTabRecord& operator = (TTabRecord& op2);

	int operator ==(const TTabRecord& op2);
	int operator > (const TTabRecord& op2);
	int operator < (const TTabRecord& op2);
	//virtual int GetCopy(void);

protected:
	virtual void Print(void);

	friend class MyTable;
	//friend class TScanTable;
	//friend class TSortTable;
};
#endif
