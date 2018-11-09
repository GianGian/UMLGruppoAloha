#include <cstdlib>
#include <iostream>
#include "impresa.h"
using namespace std;

Impresa::Impresa(char* _nome,char* _n_Telefono,int _sconto,char* _piva):Consumatore(_nome,_n_Telefono,_sconto){
    piva=_piva;
    cout<<"Creata azienda con pIVA "<<piva<<endl;
}
Impresa::~Impresa(){
    cout<<"Distrutta azienda con pIVA "<<piva<<endl;
}
