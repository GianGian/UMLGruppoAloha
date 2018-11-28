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
int get_commissione(); ///< permette di ottenere la commissione dato il metodo di pagamento
friend ostream & operator<<(ostream &os, const MetodoDiPagamento &m); 
bool operator< (const MetodoDiPagamento &m)const;
};

ostream & operator<<(ostream &os, const MetodoDiPagamento &m); ///< Overload per poter stampare da gestioneMagazzino tramite cout<<metododipagamento.
#endif
