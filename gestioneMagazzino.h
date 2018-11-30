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
#include <vector>
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
    map <int, OrdineVendita> oven;
    map <int, OrdineAcquisto> oacq;
    map <char*, Fornitore> forn;
    vector <MetodoDiPagamento> met;
   
public:
	void aggiungi_dipendente(char* _nome, char* _telefono,char* _ruolo, int _matricola);
	void togli_dipendente(int _matricola);
	void lista_dipendenti();
	bool trova_dipendente(int matricola);
	
	void aggiungi_fornitore(char* _nome,char*_telefono,char* _denominazione,char* _prodottiVenduti);
	void togli_fornitore(char* _denominazione);
	void lista_fornitori();
	void add_servizio_fornitore(char* _denominazione, char* _nome, int durata, int franchigia, int costo);
	Servizio*  trova_servizio(char* _denominazione, char* _nome);
	Fornitore* trova_fornitore(char* _denominazione);
	
	Fattura* aggiungi_fattura(int _totale, bool _vendita, int data);
	//void togli_fattura(int _numero);
	void lista_fattura();
	
	void aggiungi_metodo_di_pagamento(char* _tipo, int _commissione, int _massimale);
	void lista_metodo_di_pagamento();
	MetodoDiPagamento* trova_metodo_di_pagamento(char* nome);
	
	void aggiungi_privato(char* _nome,char* _cognome,char* _telefono, char* _codiceFiscale, int _sconto);
	void togli_privato(char* _codiceFiscale);
	void lista_privato();
	Privato* trova_privato(char* _cf);
	
	void aggiungi_impresa(char* _nome,char* _telefono, char* _piva, int _sconto);
	void togli_impresa(char* _piva);
	void lista_impresa();
	Impresa* trova_impresa(char* _piva);
	
	void aggiungi_prodotto(int _quantita, char *_colore, char *_marca, int _costo, int _data, char* _tipologia);
	void lista_prodotto();
	void togli_prodotto(int _barcode);
	Prodotto* find_prodotto(int _barcode);
	void aggiungi_prezzo(int barcode, int prezzo, int data);
	int trova_prezzo(int barcode, int data);
	
	//void crea_ordine_vendita(int matricola, int data, char* piva, char* cognome = 0);
};
void test();
#endif
