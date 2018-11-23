#include <cstdlib>
#include <iostream>
#include "gestioneMagazzino.h"
using namespace std;

void Magazzino::aggiungi_dipendente(char* _nome, char* _telefono,char* _ruolo, int _matricola){
	if(dip.find(_matricola)==dip.end()){
		dip.insert(pair<int,Dipendente> (_matricola,Dipendente(_nome,_telefono,_ruolo,_matricola)));
		cout<<"Dipendente "<<_matricola<<" aggiunto correttamente "<<endl;
	}else{
		cout<<"Matricola gia' in uso"<<endl;
	}	
}

void Magazzino::togli_dipendente(int _matricola){
	map <int,Dipendente>::iterator it;
	it=dip.find(_matricola);
	if(it!=dip.end()){
		dip.erase(it);
		cout<<"Eliminato dipendente "<<_matricola<<endl;
	}else{
		cout<<"Dipendente non trovato"<<endl;
	}
	
	
}
void Magazzino::lista_dipendenti(){
	map <int,Dipendente>::iterator it;
	for(it=dip.begin();it!=dip.end();++it){
		cout<<it->second;
	}
}

void test(){
	Magazzino m;
	/*Privato Gigino("Gigino", "Dimaio", "123456789","GGGGGG", 100);
	Impresa Panineria("Ddimaio","123456789","001231567864",0);
	Fornitore SMA ("morino","03949505","sma","patate");
	Servizio vetro("vetro",60,1000,110);
	cout<<vetro.get_costo();
	cout<<Gigino.getSconto();
	cout<<endl;
	cout<<"//=================="<<endl;*/
	m.aggiungi_dipendente("Anna","345679","Direttore",123456);	
	m.aggiungi_dipendente("Francesca","15678","Segretaria",1256);
	m.aggiungi_dipendente("Chiara","395847","Stagista",123456);
	m.lista_dipendenti();
	m.togli_dipendente(12576);
	m.togli_dipendente(1256);
	m.lista_dipendenti();
	
}


