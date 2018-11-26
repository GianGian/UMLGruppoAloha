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
    int fondoCassa;
    map <int,Dipendente> dip;
    map <int,Fattura> fat;
    map <char*, Privato> pri;
    map <char*, Impresa> imp;
    map <int, Prodotto> pro;
    list <Fornitore> forn;
    list <MetodoDiPagamento> met;
   
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
	void aggiungi_metodo_di_pagamento(char* _tipo, int _commissione, int _massimale);
	void lista_metodo_di_pagamento();
	void aggiungi_privato(char* _nome,char* _cognome,char* _telefono, char* _codiceFiscale, int _sconto);
	void togli_privato(char* _codiceFiscale);
	void lista_privato();
	void aggiungi_impresa(char* _nome,char* _telefono, char* _piva, int _sconto);
	void togli_impresa(char* _piva);
	void lista_impresa();
	void aggiungi_prodotto(int _quantita, char *_colore, char *_marca, int _costo, int _data, char* _tipologia);
	void lista_prodotto();
	void togli_prodotto(int _barcode);
	Prodotto* find_prodotto(int _barcode);
};
void test();
#endif
