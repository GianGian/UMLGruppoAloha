#ifndef __SERVIZIO_H__
#define __SERVIZIO_H__
#include <iostream>
using namespace std;
class Servizio{
private:
	char* nome;
	int durata;
	int franchigia;
	int costoServizio;
public:
	Servizio(char* _nome, int _durata, int _franchigia, int _costoServizio);
	int get_costo();
	char* get_nome()const;
	friend ostream& operator << (ostream& os, const Servizio& s);
	bool operator<(const Servizio &s)const;
};
ostream& operator << (ostream& os, Servizio& s);
#endif
