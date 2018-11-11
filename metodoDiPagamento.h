#ifndef __METODODIPAGAMENTO_H__
#define __METODODIPAGAMENTO_H__
#include <iostream>

using namespace std;

class MetodoDiPagamento{
private:
	char* nome;
	int massimale;
	int commissione;
	
public:
	MetodoDiPagamento(char* nome, int _ma ,int _co);
	~MetodoDiPagamento();
	int get_commissione()const;
	char* get_nome()const;
	//void stampa();
};

#endif
