#include <iostream>
#include "servizio.h"
using namespace std;

Servizio::Servizio(char* _nome, int _durata, int _franchigia, int _costoServizio){
		nome=_nome;
		durata=_durata;
		franchigia=_franchigia;
		costoServizio=_costoServizio;
}

int Servizio::get_costo(){
	return costoServizio;
}
