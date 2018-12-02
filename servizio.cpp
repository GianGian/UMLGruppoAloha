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

char* Servizio::get_nome()const{
	return nome;
}

bool Servizio::operator<(const Servizio &s)const{
	return (s.nome<nome);
}
ostream& operator << (ostream& os, const Servizio& s){
	os<<s.nome<<" durata "<<s.durata<<" franchigia "<<s.franchigia<<" costo servizio "<<s.costoServizio;
}
