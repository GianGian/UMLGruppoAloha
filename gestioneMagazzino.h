#ifndef __MAGAZZINO_H__
#define __MAGAZZINO_H__
#include <iostream>
#include "prodotto.h"
#include "privato.h"
#include "impresa.h"
#include "dipendente.h"
#include "fornitore.h"
#include "ordineVendita.h"
#include "ordineAcquisto.h"
#include "metodoDiPagamento.h"
#include "servizio.h"
#include "fattura.h"
#include <list>
#include <algorithm>
#include <map>
#include <list>
using namespace std;



class Magazzino{
private:
    char* via;
    char* denominazione;
    double fondoCassa;
    map <int,Dipendente> dip;
    map <int,Fattura> fat;
    list <Fornitore> forn;
   
public:
	void aggiungi_dipendente(char* _nome, char* _telefono,char* _ruolo, int _matricola);
	void togli_dipendente(int _matricola);
	void lista_dipendenti();
	void aggiungi_fornitore(char* _nome,char*_telefono,char* _denominazione,char* _prodottiVenduti);
	void togli_fornitore(char* _nome,char*_telefono,char* _denominazione,char* _prodottiVenduti);
	void lista_fornitori();
	void aggiungi_fattura(int _totale, bool _vendita);
	void togli_fattura(int _numero);
	void lista_fattura();
};
void test();
#endif
