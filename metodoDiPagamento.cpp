#include <cstdlib>
#include <iostream>
#include "metodoDiPagamento.h"
using namespace std;

MetodoDiPagamento::MetodoDiPagamento(char* _no,int _ma ,int _co){
	nome= _no;
	massimale= _ma;
	commissione= _co;
	cout<<"Creato metodo di pagamento "<< nome <<endl;
}

MetodoDiPagamento::~MetodoDiPagamento(){
	cout<<"Distrutto metodo di pagamento "<< nome<<endl;
}


int MetodoDiPagamento::get_commissione()const{
	return commissione;
}

char* MetodoDiPagamento::get_nome()const{
	return nome;
}

/*void MetodoDiPagamento::stampa(){
	cout << "Metodo di pagamento:"<< nome << " massimale:" << massimale << " commissione:"<< commissione << endl;
}*/
