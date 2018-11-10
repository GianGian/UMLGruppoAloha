#include "servizio.h"
#include <iostream>
using namespace std;

Servizio::Servizio(char* _nome, int _durata, int _franchigia, int _costoServizio){
	nome = _nome;
	durata = _durata;
	franchigia = _franchigia;
	costoServizio = _costoServizio;
	cout<<"Creato servizio: "<<nome<< " durata "<< durata << " franchigia "<<franchigia<< " costo "<<costoServizio<<endl;
}
Servizio::~Servizio(){
	cout<<"Distrutto servizio "<<nome<<endl;
}
