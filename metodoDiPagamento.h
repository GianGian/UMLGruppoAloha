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
MetodoDiPagamento(char *_nome, int _massimale, int _commissione);
};

#endif
