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
	list <Fornitore>::iterator it;
	it=find(forn.begin(), forn.end(), Fornitore (_nome, _telefono, _denominazione, _prodottiVenduti));
	if (it!=forn.end()){
		cout<<"Fornitore "<<_denominazione<<" gia' inserito"<<endl;
	}else{
		forn.push_back(Fornitore(_nome, _telefono, _denominazione, _prodottiVenduti));
		cout<<"Aggiunto Fornitore "<<_denominazione<<endl;
	}
}

/**
* \brief Funzione per togliere un fornitore.
*
* Per poterlo fare e' necessario conoscere esattamente tutti i parametri con cui questo era 
* inserito nel sistema. HA SENSO???
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

/**
* \brief Funzione per inserire nella lista dei metodi di pagamento un nuovo metodo
*/
void Magazzino:: aggiungi_metodo_di_pagamento(char* _tipo, int _commissione, int _massimale){
	met.push_back(MetodoDiPagamento(_tipo, _massimale, _commissione));
	cout<<"Creato metodo di pagamento "<< _tipo<<endl;
}

/**
* \brief Funzione per visualizzare tutti i metodi di pagamento disponibili
*/
void Magazzino::lista_metodo_di_pagamento(){
	list<MetodoDiPagamento>::iterator iter;
	for(iter = met.begin(); iter!=met.end();++iter){
		cout<<(*iter)<<endl;
	}
}

/**
* \brief Funzione per aggiungere un consumatore privato.
*/
void Magazzino::aggiungi_privato(char* _nome,char* _cognome,char* _telefono, char* _codiceFiscale, int _sconto){
	Privato p(_nome, _cognome, _telefono, _codiceFiscale, _sconto);
	pri.insert(pair<char*, Privato> (_codiceFiscale, p));
	cout<<"Inserito privato "<<p<<endl;
}

/**
* \brief Funzione per aggiungere un rimuovere un privato.
*
*La ricerca e' effettuata attraverso il codice fiscale.
*/

void Magazzino::togli_privato(char* _codiceFiscale){
	map <char*, Privato>::iterator iter;
	iter = pri.find(_codiceFiscale);
	if(iter != pri.end()){
		cout<<"Rimosso privato "<<_codiceFiscale<<endl;
		pri.erase(iter);
	}
	else{
		cout<<"Privato non trovato!"<<endl;
	}
}

/**
* \brief Funzione per stampare tutti i consumatori privati presenti nel database.
*/

void Magazzino::lista_privato(){
	map <char*, Privato>::iterator iter;
	for(iter = pri.begin(); iter !=pri.end(); ++iter){
		cout<<iter->second<<endl;
	}
}

/**
* \brief Funzione per inserire una nuova impresa nel database.
*/
void Magazzino::aggiungi_impresa(char* _nome,char* _telefono, char* _piva, int _sconto){
	Impresa i(_nome, _telefono, _piva, _sconto);
	imp.insert(pair<char*, Impresa> (_piva, i));
	cout<<"Inserita impresa "<<i<<endl;
}

/**
* \brief Funzione per rimuovere un'impresa nel database.
*
*La ricerca e' effettuata attraverso la partita iva che si suppone essere univoca per tutto 
*il database.
*/
void Magazzino::togli_impresa(char* _piva){
	map <char*, Impresa>::iterator iter;
	iter = imp.find(_piva);
	if(iter != imp.end()){
		cout<<"Rimossa impresa "<<_piva<<endl;
		imp.erase(iter);
	}
	else{
		cout<<"Impresa non trovata!"<<endl;
	}
}

/**
* \brief Funzione per stampare tutti i consumatori impresa presenti nel database.
*/
void Magazzino::lista_impresa(){
	map <char*, Impresa>::iterator iter;
	for(iter = imp.begin(); iter !=imp.end(); ++iter){
		cout<<iter->second<<endl;
	}
}
	
/**
* \brief Funzione per aggiungere prodotti in magazzino.
*/
void Magazzino::aggiungi_prodotto(int _quantita, char *_colore, char *_marca, double _costo){
	Prodotto p(_quantita, _colore, _marca, _costo);
	pro.insert(pair<int, Prodotto>(p.getBarcode(), p));
	cout<<"Inserito prodotto: "<<p<<endl;
}

/**
* \brief Funzione per stampare il prodotto.
*/
void Magazzino::lista_prodotto(){
	map<int, Prodotto>::iterator iter;
	for(iter = pro.begin(); iter!=pro.end();++iter){
		cout<<iter->second<<endl;
	}
}

/**
* \brief Funzione per togliere un prodotto dato il barcode.
*/
void Magazzino::togli_prodotto(int _barcode){
	map<int, Prodotto>::iterator iter;
	iter = pro.find(_barcode);
	if(iter !=pro.end()){
		cout<<"Eliminato prodotto "<<_barcode<<endl;
		pro.erase(iter);
	}
	else cout<<"Errore, prodotto non trovato."<<endl;
}

/**
* \brief Funzione per trovare un prodotto dato il barcode.
*
* Funzione usata al momento di creare l'ordine. (credo)
* \return Prodotto
*/
Prodotto Magazzino::find_prodotto(int _barcode){
	map<int, Prodotto>::iterator iter;
	iter = pro.find(_barcode);
	if(iter != pro.end()) return iter->second;
	else cout<<"Errore, prodotto non trovato"<<endl;
	
	/// \todo Capire cosa fare se non trovo il prodotto desiderato.
	//COSA DEVE FARE QUI???
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
	m.aggiungi_fornitore("Giulia","3323245654","Asus","pc e tablet");//non mi permette di inserirne due uguali
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
	
	cout<<"==== TEST METODO DI PAGAMENTO ===="<<endl;
	m.aggiungi_metodo_di_pagamento("Banconote", 100, 500);
	m.aggiungi_metodo_di_pagamento("Assegno", 200, 1000);
	m.lista_metodo_di_pagamento();
	cout<<"==== FINE TEST METODO DI PAGAMENTO ===="<<endl<<endl;
	
	cout<<"==== TEST PRIVATO ===="<<endl;
	m.aggiungi_privato("Gianni", "Lunelli", "1264564", "ABCDEFG1234", 1);
	m.aggiungi_privato("Genoveffo", "Arte", "7878978977", "QWERTY123", 10);
	m.lista_privato();
	m.togli_privato("AAAAAAA"); //privato non esistente, dovrebbe dare errore
	m.togli_privato("QWERTY123");
	m.lista_privato();
	cout<<"==== FINE TEST PRIVATO ===="<<endl<<endl;
	
	cout<<"==== TEST IMPRESA ===="<<endl;
	m.aggiungi_impresa("SMA", "123456789", "0123456789", 10);
	m.aggiungi_impresa("ASM", "987654321", "9876543210", 20);
	m.lista_impresa();
	m.togli_impresa("1231231"); //impresa inesistente
	m.togli_impresa("9876543210");
	m.lista_impresa();
	m.togli_impresa("0123456789");
	m.lista_impresa(); //cosa succede se tolgo tutte le imprese?
	cout<<"==== FINE TEST IMPRESA ===="<<endl<<endl;
	
	cout<<"==== TEST PRODOTTO ===="<<endl;
	m.aggiungi_prodotto(1, "rosso", "Lenovo", 500);
	m.aggiungi_prodotto(10, "blu", "Apple", 1000);
	m.lista_prodotto();
	m.togli_prodotto(3); //non trova il prodotto
	m.togli_prodotto(1); //elimina apple
	m.lista_prodotto();
	//cout<<(m.find_prodotto(0))<<endl; //da rivedere perch� non va
	cout<<"==== FINE TEST PRODOTTO ===="<<endl<<endl;
	
}


