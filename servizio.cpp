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

bool Servizio::operator==(const Servizio &s){
	return (nome == s.nome&& durata == s.durata && franchigia == s.franchigia && costoServizio == s.costoServizio);
}
ostream& operator << (ostream& os, Servizio& s){
	os<<s.nome<<" Durata "<<s.durata<<" Franchigia"<<s.franchigia<<" Costo Servizio "<<s.costoServizio<<endl;
}
