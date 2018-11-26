#include <cstdlib>
#include <iostream>
#include "metodoDiPagamento.h"
using namespace std;

MetodoDiPagamento::MetodoDiPagamento(char *_nome, int _massimale, int _commissione){
	nome = _nome;
	massimale = _massimale;
	commissione = _commissione;
}

int MetodoDiPagamento::get_commissione(){
	return commissione;
}

bool MetodoDiPagamento::operator== (const MetodoDiPagamento &m){
	return (m.commissione==commissione && m.massimale == massimale && m.nome == nome);
}

ostream& operator<<(ostream &os, MetodoDiPagamento &m){
	os<<m.nome<<" massimale: "<<m.massimale<<" commissione: "<<m.commissione;
	return os;
}
