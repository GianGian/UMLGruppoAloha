#ifndef __MAGAZZINO_H__
#define __MAGAZZINO_H__
#include <iostream>
#include "prodotto.h"
#include "dipendente.h"
#include <list>
#include <algorithm>
using namespace std;

class Magazzino{
private:
    char* via;
    char* denominazione;
    double fondoCassa;
    list <Dipendente> listdip;
public:
    Magazzino(char* _via, char* _denominazione, double _fondoCassa);//da aggiungere man mano che si aggiungono le classi?
    ~Magazzino();
    void stampa()const;
    void inserisci_prodotto(int _quantita, char* _colore, char* _marca, double _costo, int _matricola);
    void aggiungi_dipendente(char* _nome,char* _n_Telefono,char* _ruolo,int _matricola);
    void incrementa_cassa(double _fondoCassa, int _matricola);
    void stampadipendenti();
    friend ostream& operator <<(ostream &os, Magazzino &m);
    void togli_dipendente(int _matricola, int _matricolamaster);
};

#endif
