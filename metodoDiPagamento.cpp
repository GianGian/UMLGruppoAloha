#include <cstdlib>
#include <iostream>
#include "metodoDiPagamento.h"
using namespace std;

MetodoDiPagamento::MetodoDiPagamento(char *_nome, int _massimale, int _commissione){
	nome = _nome;
	massimale = _massimale;
	commissione = _commissione;
}
