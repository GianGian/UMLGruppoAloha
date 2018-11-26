#ifndef __DATA_H__
#define __DATA_H__
typedef struct Data{
	   int data;	
	   Data(int _data);
	   bool operator< (const Data &d) const;
}Data;
#endif

