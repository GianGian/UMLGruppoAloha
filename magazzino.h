#ifndef __MAGAZZINO_H__
#define __MAGAZZINO_H__
#include <iostream>
#include "prodotto.h"
using namespace std;

class Magazzino{
private:
    char* via;
    char* denominazione;
    double fondoCassa;
    Prodotto *p;
public:
    Magazzino(char* _via, char* _denominazione, double _fondoCassa);//da aggiungere man mano che si aggiungono le classi
    ~Magazzino();
    void stampa()const;
    void inserisci_prodotto(int _quantita, char* _colore, char* _marca, double _costo);
    
};

#endif
