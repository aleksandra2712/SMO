#include <iostream>
#include <string>
#include "TTabRecord.h"



using namespace std;

TTabRecord::TTabRecord(double _key, int _value, double _info)
{
	Key = _key;
	Value = _value;
	Info = _info;
}

void TTabRecord::SetKey(double k)
{
	Key = k;
}
void TTabRecord::SetValue(int v)
{
	Value = v;
}
double TTabRecord::GetKey(void)
{
	return Key;
}
double TTabRecord::GetInfo(void)
{
	return Info;
}
int TTabRecord::GetValue(void)
{
	return Value;
}

int TTabRecord::operator==(const TTabRecord &op2)
{
	return op2.Key == Key;
}

int TTabRecord::operator > (const TTabRecord &op2)
{
	return op2.Key > Key;
}

int TTabRecord::operator < (const TTabRecord &op2)
{
	return op2.Key < Key;
}

TTabRecord& TTabRecord::operator = (TTabRecord &op2)
{
	Key = op2.Key;
	Value = op2.Value;
	Info = op2.Info;
	return *this;
}

void TTabRecord::Print(void)
{
	cout << "Key: " << Key << " val: " << Value;
}

//int TTabRecord::GetCopy(void)
//{
//
//}