#include "data.h"

Data::Data(int _data){
	data = _data;
}

bool Data::operator<(const Data &d)const{
	return data>d.data;
}
