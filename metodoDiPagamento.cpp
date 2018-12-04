#include <cstdlib>
#include <iostream>
#include "metodoDiPagamento.h"
using namespace std;

MetodoDiPagamento::MetodoDiPagamento(char *_nome, int _massimale, int _commissione){
	nome = _nome;
	massimale = _massimale;
	commissione = _commissione;
	stato=1;
}

int MetodoDiPagamento::get_commissione(){
	return commissione;
}

int MetodoDiPagamento::get_massimale(){
	return massimale;
}

char* MetodoDiPagamento::get_nome() const{
	return nome;
}


ostream& operator<<(ostream &os, const MetodoDiPagamento &m){
	os<<m.nome<<" massimale: "<<m.massimale<<" commissione: "<<m.commissione;
	return os;
}

bool MetodoDiPagamento::get_stato()const{
	return stato;
}

void MetodoDiPagamento::disattiva_stato(){
	stato=0;
}
