#ifndef __MAGAZZINO_H__
#define __MAGAZZINO_H__
#include <iostream>
using namespace std;

class Magazzino{
private:
    char* via;
    char* denominazione;
    double fondoCassa;
public:
    Magazzino(char* _via, char* _denominazione, double _fondoCassa);//da aggiungere man mano che si aggiungono le classi
    ~Magazzino();
    void stampa()const;
};

#endif
