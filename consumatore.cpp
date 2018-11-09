#include <cstdlib>
#include <iostream>
#include "consumatore.h"
using namespace std;

Consumatore::Consumatore(char* _nome,char* _n_Telefono,int _sconto):Anagrafica(_nome,_n_Telefono){
    sconto=_sconto;
    cout<<"Creato consumatore con sconto "<<sconto<<endl;
}
Consumatore::~Consumatore(){
    cout<<"Distrutto consumatore con sconto "<<sconto<<endl;
}
