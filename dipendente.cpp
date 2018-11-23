#include <cstdlib>
#include <iostream>
#include "dipendente.h"
using namespace std;

Dipendente::Dipendente(char* _nome, char* _telefono,char* _ruolo, int _matricola):Anagrafica(_nome,_telefono){
	ruolo=_ruolo;
	matricola=_matricola;
}

ostream& operator<<(ostream& os,Dipendente& dip){
	os<<"Dipendente "<<dip.nome<<" con ruolo "<<dip.ruolo<<" e matricola "<<dip.matricola<<endl;
	//os<<dip.matricola;
	return os;
}
