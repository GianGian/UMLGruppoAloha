#ifndef __DATA_H__
#define __DATA_H__
#include <iostream>
using namespace std;
typedef struct Data{
	   int data;	
	   Data(int _data);
	   bool operator< (const Data &d) const;
}Data;

ostream& operator<<(ostream & os, Data &d);
#endif

