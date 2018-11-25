#include <cstdlib>
#include <iostream>
#include "gestioneMagazzino.h"
using namespace std;

/**
* \brief Funzione per aggiungere un dipendente al magazzino
*/
void Magazzino::aggiungi_dipendente(char* _nome, char* _telefono,char* _ruolo, int _matricola){
	if(dip.find(_matricola)==dip.end()){
		dip.insert(pair<int,Dipendente> (_matricola,Dipendente(_nome,_telefono,_ruolo,_matricola)));
		cout<<"Dipendente "<<_matricola<<" aggiunto correttamente "<<endl;
	}else{
		cout<<"Matricola gia' in uso"<<endl;
	}	
}

/**
* \brief Funzione per togliere un dipendente dal magazzino. La ricerca avviene tramite matricola.
*/
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

/**
* \brief Funzione per stampare la lista dei dipendenti.
*/
void Magazzino::lista_dipendenti(){
	map <int,Dipendente>::iterator it;
	for(it=dip.begin();it!=dip.end();++it){
		cout<<it->second;
	}
}

/**
* \brief Funzione per aggiungere un fornitore.
* \arg _nome: corrisponde al nome del contatto del fornitore.
* \arg _telefono: corrisponde al numero di telefono
* \arg _denominazione: corrisponde al nome della ditta a cui il fornitore fa riferimento.
* \arg _prodottiVenduti: corrisponde ad una breve descrizione dei prodotti venduti. 
*/

void Magazzino::aggiungi_fornitore(char* _nome,char*_telefono,char* _denominazione,char* _prodottiVenduti){
	forn.push_back(Fornitore(_nome, _telefono, _denominazione, _prodottiVenduti));
	cout<<"Aggiunto Fornitore "<<_denominazione<<endl;
}

/**
* \brief Funzione per togliere un fornitore.
*
* Per poterlo fare e' necessario conoscere esattamente tutti i parametri con cui questo era 
* inserito nel sistema.
*/
void Magazzino::togli_fornitore(char* _nome,char*_telefono,char* _denominazione,char* _prodottiVenduti){
	list <Fornitore>::iterator deliter;
	Fornitore f(_nome, _telefono, _denominazione, _prodottiVenduti);
	//deliter=find(forn.begin(), forn.end(), Fornitore (_nome, _telefono, _denominazione, _prodottiVenduti));
	deliter=find(forn.begin(), forn.end(), f);
	if (deliter!=forn.end()){
		forn.erase(deliter);
		cout<<"Eliminato fornitore: "<<_denominazione<<endl;
	}else{
		cout<<"Fornitore "<<_denominazione<<" non trovato"<<endl;
	}
}

/**
* \brief Funzione per stampare la lista dei fornitori.
*/
void Magazzino::lista_fornitori(){
	list <Fornitore>:: iterator iter;
	for(iter=forn.begin(); iter!=forn.end();++iter){
		cout<<*iter;
	}
}

/**
* \brief Funzione per aggiungere una fattura.
*
*Il numero fattura viene gestito automaticamente dal sistema
*come ID univoco non modificabile in alcun modo dall'utente.
* \arg _vendita: 1=fattura di vendita, 0= fattura di acquisto.
*/
void Magazzino::aggiungi_fattura(int _totale, bool _vendita){
	Fattura f(_totale, _vendita);
	fat.insert(pair<int, Fattura> (f.get_n_Fattura(),f));	
	cout<<"Inserita fattura: "<<f.get_n_Fattura()<<" totale: "<<_totale<<endl;
}

/**
* \brief Funzione per togliere una fattura.
* Toglie una fattura partendo dal suo numero univoco. Il campo
* numero fattura resta pero' sempre dedicato alla fattura 
* eliminata quindi non puo' essere assunto da altre fatture.
*/
void Magazzino::togli_fattura(int _numero){
	map<int,Fattura>::iterator iter;
	iter = fat.find(_numero);
	if(iter!=fat.end()){
		cout<<"Eliminata fattura numero: "<<_numero<<endl;
		fat.erase(iter);
	}else{
		cout<<"Fattura non trovata!"<<endl;
	}
}

/**
* \brief Funzione per stampare l'elenco dei dipendenti.
*
*/
void Magazzino::lista_fattura(){
	map<int,Fattura>::iterator iter;
	for(iter = fat.begin(); iter!=fat.end();++iter){
		cout<<iter->second<<endl;
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
	cout<<"==== TEST DIPENDENTE ===="<<endl;
	m.aggiungi_dipendente("Anna","345679","Direttore",123456);	
	m.aggiungi_dipendente("Francesca","15678","Segretaria",1256);
	m.aggiungi_dipendente("Chiara","395847","Stagista",123456);
	m.lista_dipendenti();
	m.togli_dipendente(12576);
	m.togli_dipendente(1256);
	m.lista_dipendenti();
	cout<<"==== FINE TEST DIPENDENTE ===="<<endl<<endl;
	
	cout<<"==== TEST FORNITORI ===="<<endl;
	m.aggiungi_fornitore("Silvia","3223245654","Lenovo","pc e tablet");
	m.aggiungi_fornitore("Giulia","3323245654","Asus","pc e tablet");
	m.aggiungi_fornitore("Gianlor","3423245654","Samsung","pc, tablet e smartphone");
	m.lista_fornitori();
	m.togli_fornitore("Sil","3223245654","Unitn","pc e tablet");//se provo a metterne uno finto (basta togliere una lettera si impalla
	m.togli_fornitore("Silvia","3223245654","Lenovo","pc e tablet");
	m.togli_fornitore("Silvia","322324564","Lenono","pc e tablet");
	m.lista_fornitori();
	cout<<"==== FINE TEST FORNITORI ===="<<endl<<endl;
	
	cout<<"==== TEST FATTURA ===="<<endl;
	//creo tre fatture
	m.aggiungi_fattura(23,1); 
	m.aggiungi_fattura(232,0);
	m.aggiungi_fattura(2332,0);
	m.lista_fattura(); //stampo le fattura
	m.togli_fattura(5); //provo a rimuovere fattura non esistente
	m.togli_fattura(1); //rimuovo fattura esistente NOTA: anche se la fattura viene eliminata, il numero rimane dedicato e non è possibile riusarlo
	m.aggiungi_fattura(33333,1); //questa fattura quindi avrà numero 4, e la fattura 1 non verrà stampata.
	m.lista_fattura(); //stampo di nuovo per verificare l'eliminazione
	cout<<"==== FINE TEST FATTURA ===="<<endl<<endl;
	
}


