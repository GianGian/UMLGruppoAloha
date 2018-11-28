#ifndef __FORNITORE_H__
#define __FORNITORE_H__
#include <iostream>
#include "anagrafica.h"
#include "servizio.h"
#include <algorithm>
#include <set>
using namespace std;
/**
*Classe fornitore.
*/
class Fornitore:public Anagrafica{
private:
    char* denominazione;
    char* prodottiVenduti;
    set<Servizio> ser;

public:
	Fornitore(char* _nome,char* _telefono,char* _denominazione,char* _prodottiVenduti);
	bool operator <(const Fornitore& f) const;
	friend ostream &operator << (ostream & os, const Fornitore &f);
	void aggiungi_servizio(char* _nome, int _durata, int _franchigia, int _costoServizio);
	void togli_servizio(char* _nome);
	void lista_servizio();
	char* get_denominazione()const;
	char* get_prodottiVenduti()const;
	set<Servizio>::iterator get_servizio(const char* _nome)const;
};


ostream &operator << (ostream & os,const Fornitore &f);
#endif
