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

void Magazzino::aggiungi_fornitore(char* _nome,char*_telefono,char* _denominazione,char* _prodottiVenduti){
	forn.push_back(Fornitore(_nome, _telefono, _denominazione, _prodottiVenduti));
	cout<<"Aggiunto Fornitore "<<_denominazione<<endl;
}

void Magazzino::togli_fornitore(char* _nome,char*_telefono,char* _denominazione,char* _prodottiVenduti){
	list <Fornitore>::iterator deliter;
	deliter=find(forn.begin(), forn.end(), Fornitore (_nome, _telefono, _denominazione, _prodottiVenduti));
	if (deliter!=forn.end()){
		forn.erase(deliter);
		cout<<"Eliminato fornitore: "<<_denominazione<<endl;
	}else{
		cout<<"Fornitore "<<_denominazione<<" non trovato"<<endl;
	}
}

void Magazzino::lista_fornitori(){
	list <Fornitore>:: iterator iter;
	for(iter=forn.begin(); iter!=forn.end();++iter){
		cout<<*iter;
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
	//cout << "stampo fornitori"<< endl;
	m.aggiungi_fornitore("Silvia","3223245654","Lenovo","pc e tablet");
	m.aggiungi_fornitore("Giulia","3323245654","Asus","pc e tablet");
	m.aggiungi_fornitore("Gianlor","3423245654","Samsung","pc, tablet e smartphone");
	m.lista_fornitori();
	m.togli_fornitore("Silvia","3223245654","Lenono","pc e tablet");//se provo a metterne uno finto (basta togliere una lettera si impalla
	m.togli_fornitore("Silvia","3223245654","Lenovo","pc e tablet");
	m.togli_fornitore("Silvia","322324564","Lenono","pc e tablet");
	m.lista_fornitori();
	
}


