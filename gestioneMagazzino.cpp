#include <cstdlib>
#include <iostream>
#include "gestioneMagazzino.h"
using namespace std;

Magazzino::Magazzino(char* _via, char* _denominazione, int _fondoCassa){
	via = _via;
	denominazione = _denominazione;
	fondoCassa = _fondoCassa;
}

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
		it->second.disattiva_stato();
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
		if(it->second.get_stato()==0){
			cout<<" DISATTIVATO";
		}	
	}
}

/**
* \brief Funzione per cercare un dipendente data la matricola.
* \return 1 se trovato, 0 se non trovato.
*/
bool Magazzino::trova_dipendente(int matricola){
	map <int,Dipendente>::iterator it;
	it=dip.find(matricola);
	if(it!=dip.end()){
		if(it->second.get_stato()==1){
			return 1;
		}
	}
	else return 0;
}
/**
* \brief Funzione per aggiungere un fornitore.
* \arg _nome: corrisponde al nome del contatto del fornitore.
* \arg _telefono: corrisponde al numero di telefono
* \arg _denominazione: corrisponde al nome della ditta a cui il fornitore fa riferimento. CONSIDERATO UNIVOCO.
* \arg _prodottiVenduti: corrisponde ad una breve descrizione dei prodotti venduti. 
* \todo aggiungere verifica fornitore gia' inserito
*/
void Magazzino::aggiungi_fornitore(char* _nome,char*_telefono,char* _denominazione,char* _prodottiVenduti){
	forn.insert(pair<char*,Fornitore> (_denominazione, Fornitore(_nome, _telefono, _denominazione, _prodottiVenduti)));
}

void Magazzino::togli_fornitore(char* _denominazione){
	map<char*, Fornitore>::iterator it;
	it = forn.find(_denominazione);
	if(it!=forn.end()){
		//forn.erase(it);
		it->second.disattiva_stato();
		cout<<"Rimosso fornitore"<<endl;
	}
	else cout<<"Fornitore non trovato"<<endl;
}

void Magazzino::lista_fornitori(){
	map<char*, Fornitore>::iterator it;
	for(it = forn.begin(); it != forn.end(); ++it){
		cout<<it->second;
		if(it->second.get_stato()==0){
			cout<<" DISATTIVATO";
		}
		cout<<endl;
	}
}

void Magazzino::add_servizio_fornitore(char* _denominazione, char* _nome, int durata, int franchigia, int costo){
	map<char*, Fornitore>::iterator it;
	it=forn.find(_denominazione);
	if(it!=forn.end()){
		if(it->second.get_stato()==1){
		cout<<"Servizio aggiunto a fornitore "<<_denominazione<<endl;
		it->second.aggiungi_servizio(_nome, durata, franchigia, costo);
		}else{
			cout<<"Fornitore disattivato"<<endl;			
		}
	}
	else cout<<"Fornitore non trovato"<<endl;
}

Servizio* Magazzino::trova_servizio(char* _denominazione, char* _nome){
   map<char*, Fornitore>::iterator it;
	it=forn.find(_denominazione);
	if(it!=forn.end()){
		if(it->second.get_stato()==1){
		return it->second.get_servizio(_nome);
		}else{
			cout<<"Servizio associato a fornitore disattivato"<<endl;
	}
   }else{
   	cout<<"Servizio associato a fornitore non trovato"<<endl;
   	return NULL;
	}  
}

Fornitore* Magazzino::trova_fornitore(char* _denominazione){
	map<char*, Fornitore>::iterator it;
	it=forn.find(_denominazione);
	if(it!=forn.end()){
		if(it->second.get_stato()==1){
			return &it->second;
		}else{
			cout<<"Fornitore disattivato!"<<endl;
		}
	}else{
		cout<<"Fornitore non trovato"<<endl;
		return NULL;
	}
}
/**
* \brief Funzione per aggiungere una fattura.
*
*Il numero fattura viene gestito automaticamente dal sistema
*come ID univoco non modificabile in alcun modo dall'utente.
* \arg _vendita: 1=fattura di vendita, 0= fattura di acquisto.
*/
Fattura* Magazzino::aggiungi_fattura(int _totale, bool _vendita, int data){
	if(_vendita == 1){
		fondoCassa+=_totale;
	}else{
		fondoCassa-=_totale;
	}
	if(_totale > 0){
		Fattura f(_totale, _vendita, data);
		fat.insert(pair<int, Fattura> (f.get_n_Fattura(),f));
		map<int, Fattura>::iterator it;
		it = fat.find(f.get_n_Fattura());
		if(it != fat.end()){
			return &it->second;
			cout<<"Inserita fattura: "<<f.get_n_Fattura()<<" totale: "<<_totale<<endl;
		}
	}
else return NULL;	
	
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
void Magazzino::aggiungi_metodo_di_pagamento(char* _tipo, int _commissione, int _massimale){
	met.push_back(MetodoDiPagamento(_tipo,_massimale,_commissione));
	cout<<"Aggiunto metodo di pagamento "<<_tipo<<endl; 
}

void Magazzino::lista_metodo_di_pagamento(){
	vector<MetodoDiPagamento>::iterator iter;
	for(iter = met.begin(); iter != met.end(); ++iter)	{
		cout<<*iter;
		if(iter->get_stato()==0){
			cout<<" DISATTIVATO";
		}
		cout<<endl;
	}
}

MetodoDiPagamento* Magazzino::trova_metodo_di_pagamento(char* nome){
	vector<MetodoDiPagamento>::iterator iter;
	bool trovato = 0;
	for(iter = met.begin(); iter != met.end(); ++iter)	{
		if(iter->get_nome() == nome){
			if(iter->get_stato()==1){
				trovato = 1;
				return &*iter;
			}else{
				cout<<"Metodo disattivato"<<endl;
				return NULL;
			}
		}
	}
	if (trovato == 0){
		cout<<"Metodo non trovato"<<endl;
		return NULL;
	}
}

/**
* \brief Funzione per aggiungere un consumatore privato.
*/
void Magazzino::aggiungi_privato(char* _nome,char* _cognome,char* _telefono, char* _codiceFiscale, int _sconto){
	Privato p(_nome, _cognome, _telefono, _codiceFiscale, _sconto);
	if(pri.find(_codiceFiscale)==pri.end()){
		pri.insert(pair<char*, Privato> (_codiceFiscale, p));
		cout<<"Inserito privato ";
		p.stampa();
		cout<<endl;
	} else cout<<"Privato gia' inserito"<<endl;
	
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
		iter->second.disattiva_stato();
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
		iter->second.stampa();
		if(iter->second.get_stato()==0){
			cout<<" DISATTIVATO";	
		}
		cout<<endl;
	}
}

Privato* Magazzino::trova_privato(char* _cf){
	map<char*, Privato>::iterator it;
	it = pri.find(_cf);
	if(it!=pri.end()){
		if(it->second.get_stato()==1){
		return &it->second;
		}else{
			cout<<"Privato disattivato!"<<endl;
			return NULL;
		}
	}else{
		cout<<"Privato non trovato!"<<endl;
		return NULL;
	} 
}
/**
* \brief Funzione per inserire una nuova impresa nel database.
*/
void Magazzino::aggiungi_impresa(char* _nome,char* _telefono, char* _piva, int _sconto){
	Impresa i(_nome, _telefono, _piva, _sconto);
	if(imp.find(_piva) == imp.end()){
		imp.insert(pair<char*, Impresa> (_piva, i));
		cout<<"Inserita impresa ";
		i.stampa();
		cout<<endl;
	} else cout<<"Impresa gia' inserita"<<endl;
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
		iter->second.disattiva_stato();
		//imp.erase(iter);
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
		iter->second.stampa();
		if(iter->second.get_stato()==0){
			cout<<" DISATTIVA";
		}
		cout<<endl;
	}
}

Impresa* Magazzino::trova_impresa(char* _piva){
	map <char*, Impresa>::iterator it;
	it = imp.find(_piva);
	if(it != imp.end()){
		if(it->second.get_stato()==1){
			return &it->second;
		}else{
			cout<<"Impresa disattivata"<<endl;
			return NULL;	
		}
	}else{
		cout<<"Impresa non trovata"<<endl;
		return NULL;
	}
}

/**
* \brief Funzione per aggiungere prodotti in magazzino.
*/
void Magazzino::aggiungi_prodotto(int _quantita, char *_colore, char *_marca, int _costo, int _data,char* _tipologia, bool servizio){
	Prodotto p(_quantita, _colore, _marca, _costo, _data, _tipologia, servizio);
	pro.insert(pair<int, Prodotto>(p.getBarcode(), p));
	cout<<"Inserito prodotto: "<<p<<endl;
}

/**
* \brief Funzione per stampare il prodotto.
*/
void Magazzino::lista_prodotto(){
	map<int, Prodotto>::iterator iter;
	for(iter = pro.begin(); iter!=pro.end();++iter){
		cout<<iter->second;
		if(iter->second.get_stato()==0){
			cout<<" DISATTIVATO";
		}
		cout<<endl;
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
		iter->second.disattiva_stato();
	}
	else cout<<"Errore, prodotto non trovato."<<endl;
}

/**
* \brief Funzione per trovare un prodotto dato il barcode.
*
* Funzione usata al momento di creare l'ordine. (credo)
* \return Prodotto
*/
Prodotto* Magazzino::find_prodotto(int _barcode){
	map<int, Prodotto>::iterator iter;
	iter = pro.find(_barcode);
	if(iter != pro.end()){
		if(iter->second.get_stato()==1){
			return &iter->second;
		}else{
			cout<<"Errore, prodotto disattivato"<<endl;
		return NULL;
		}
	}else {
		cout<<"Errore, prodotto non trovato"<<endl;
		return NULL;
	}
}

/**
* \brief Funzione per aggiungere un costo ad un prodotto.
*
* La data va in serita in formato AAMMGG. La data inserita si 
* riferisce al giorno in cui iniziera' a valere il nuovo prezzo
* inserito e di conseguenza la fine del prezzo vecchio.
*
*/
void Magazzino::aggiungi_prezzo(int barcode, int prezzo, int data){
	map<int, Prodotto>::iterator iter;
	iter = pro.find(barcode);
	if(iter != pro.end()){
		iter->second.addCosto(prezzo, data);
	}
	else cout<<"Prodotto non trovato!"<<endl;
}

/**
* \brief Funzione per trovare un prezzo di un prodotto dato un barcode e una data.
*
* \return >0 se il prezzo e' stato trovato, -1 se ci sono stati problemi
*/
int Magazzino::trova_prezzo(int barcode, int data){
	map<int, Prodotto>::iterator iter;
	iter = pro.find(barcode);
	if(iter != pro.end()){
    	return iter->second.getPrezzo(data);
	}
	else {
		cout<<"Prodotto non trovato!"<<endl;
		return -1;
	}	
}


void Magazzino::crea_ordine_vendita(OrdineVendita o){
	o.add_fattura(aggiungi_fattura(o.conferma_ordine(), 1, o.get_data()));
	oven.insert(pair<int, OrdineVendita> (o.get_n_ordine(),o));
}

void Magazzino::lista_ordine_vendita(){
	map<int, OrdineVendita>::iterator it;
	for(it = oven.begin(); it!= oven.end(); ++it){
		cout<<it->second<<endl;
	}	
}

void Magazzino::crea_ordine_acquisto(OrdineAcquisto o){
	o.add_fattura(aggiungi_fattura(o.conferma_ordine(), 0, o.get_data()));
	oacq.insert(pair<int, OrdineAcquisto> (o.get_n_ordine(), o));
}

void Magazzino::lista_ordine_acquisto(){
	map<int, OrdineAcquisto>::iterator it;
	for(it = oacq.begin(); it!= oacq.end(); ++it){
		cout<<it->second<<endl;
	}	
}
	
ostream& operator<< (ostream& os, Magazzino &m){
	os<<"Magazzino "<<m.denominazione<<" in via "<<m.via<< " fondocassa: "<<m.fondoCassa;
	return os;
}
void test(){
	Magazzino m("Brombeis", "Mediaworld", 1000);
	cout<<m<<endl<<endl;
	
	cout<<"==== TEST DIPENDENTE ===="<<endl;
	m.aggiungi_dipendente("Anna","345679","Direttore",123456);	
	m.aggiungi_dipendente("Francesca","15678","Segretaria",1256);
	m.aggiungi_dipendente("Chiara","395847","Stagista",123456);
	m.lista_dipendenti();
	m.togli_dipendente(12576);
	m.togli_dipendente(1256);
	m.lista_dipendenti();
	cout<<m.trova_dipendente(12345)<<endl;
	cout<<m.trova_dipendente(123456)<<endl;	
	cout<<"==== FINE TEST DIPENDENTE ===="<<endl<<endl;
	
	cout<<"==== TEST FORNITORI ===="<<endl;
	m.aggiungi_fornitore("Silvia","3223245654","Lenovo","pc e tablet");
	m.aggiungi_fornitore("Giulia","3323245654","Asus","pc e tablet");
	m.aggiungi_fornitore("Giulia","3323245654","Asus","pc e tablet");//non mi permette di inserirne due uguali
	m.aggiungi_fornitore("Gianlor","3423245654","Samsung","pc, tablet e smartphone");
	m.lista_fornitori();
	m.togli_fornitore("Unitn");//se provo a metterne uno finto (basta togliere una lettera si impalla
	m.togli_fornitore("Lenovo");
	m.togli_fornitore("Lenono");
	m.add_servizio_fornitore("Samsun", "Kasko",1,10,100);
	m.add_servizio_fornitore("Samsung", "Assicurazione",1,100,1000);
	m.lista_fornitori();
	cout<<"==== FINE TEST FORNITORI ===="<<endl<<endl;
	/*
	cout<<"==== TEST FATTURA ===="<<endl;
	//creo tre fatture
	m.aggiungi_fattura(23,1,181112); 
	m.aggiungi_fattura(232,0,181112);
	m.aggiungi_fattura(2332,0,181112);
	m.lista_fattura(); //stampo le fattura
	//m.togli_fattura(5); //provo a rimuovere fattura non esistente
	//m.togli_fattura(1); //rimuovo fattura esistente NOTA: anche se la fattura viene eliminata, il numero rimane dedicato e non Ã¨ possibile riusarlo
	m.aggiungi_fattura(33333,1,181112); //questa fattura quindi avrÃ  numero 4, e la fattura 1 non verrÃ  stampata.
	m.lista_fattura(); //stampo di nuovo per verificare l'eliminazione
	cout<<"==== FINE TEST FATTURA ===="<<endl<<endl;
	*/
	cout<<"==== TEST METODO DI PAGAMENTO ===="<<endl;
	m.aggiungi_metodo_di_pagamento("Banconota", 100, 500);
	m.aggiungi_metodo_di_pagamento("Assegno", 200, 1000);
	m.aggiungi_metodo_di_pagamento("Carta", 200, 1000);
	cout<<*m.trova_metodo_di_pagamento("Banconota")<<endl;
	cout<<*m.trova_metodo_di_pagamento("Carta")<<endl;
	m.lista_metodo_di_pagamento();
	cout<<"==== FINE TEST METODO DI PAGAMENTO ===="<<endl<<endl;
	
	cout<<"==== TEST PRIVATO ===="<<endl;
	m.aggiungi_privato("Gianni", "Lunelli", "1264564", "ABCDEFG1234", 1);
	m.aggiungi_privato("Genoveffo", "Arte", "7878978977", "QWERTY123", 10);
	m.lista_privato();
	m.togli_privato("AAAAAAA"); //privato non esistente, dovrebbe dare errore
	m.togli_privato("QWERTY123");
	m.lista_privato();
	m.trova_privato("ABCDEFG1234")->stampa();
	cout<<endl; //test ricerca privato
	cout<<"==== FINE TEST PRIVATO ===="<<endl<<endl;
	
	cout<<"==== TEST IMPRESA ===="<<endl;
	m.lista_impresa();
	m.aggiungi_impresa("SMA", "123456789", "0123456789", 10);
	m.aggiungi_impresa("ASM", "987654321", "9876543210", 20);
	m.aggiungi_impresa("ASM", "987654321", "9876543210", 20);
	m.lista_impresa();
	m.togli_impresa("1231231"); //impresa inesistente
	m.togli_impresa("9876543210");
	m.lista_impresa();
	m.trova_impresa("0123456789")->stampa();
	//m.togli_impresa("0123456789");
	m.lista_impresa(); 
	cout<<"==== FINE TEST IMPRESA ===="<<endl<<endl;
	
	cout<<"==== TEST PRODOTTO ===="<<endl;
	m.aggiungi_prodotto(1, "rosso", "Lenovo", 500,181126,"PC",1); //0
	m.aggiungi_prodotto(10, "blu", "Apple", 1000,181126, "PC",1) ; //1
	m.aggiungi_prodotto(10, "rosa", "Asus", 1000,181126, "PC",1) ; //2
	m.aggiungi_prodotto(10, "trasparente", "Asus", 20,181126, "Vetro",0) ; //3
    m.aggiungi_prezzo(1, 100, 181129);
    cout<<m.trova_prezzo(1, 181125)<<endl;
    cout<<m.trova_prezzo(1, 181126)<<endl;
    cout<<m.trova_prezzo(1, 181201)<<endl;
	//cout<<*(m.find_prodotto(1))<<endl;
	m.lista_prodotto();
	m.togli_prodotto(10); //non trova il prodotto
	m.togli_prodotto(1); //elimina apple
	m.lista_prodotto();
	cout<<*(m.find_prodotto(0))<<endl; 
	m.aggiungi_prodotto(10, "blu", "Apple", 1000,181126, "PC", 1) ;
	cout<<"==== FINE TEST PRODOTTO ===="<<endl<<endl;
	m.lista_prodotto();
	
	cout<<"==== TEST SERVIZIO ===="<<endl;
	cout<<"==== FINE TEST SERVIZIO ===="<<endl<<endl;
	

	cout<<"==== TEST ORDINE ACQUISTO ===="<<endl;
	OrdineAcquisto a(123456, 181130, m.trova_fornitore("Samsung")); //matricola data fornitore
	a.addProdotto(200, 20, m.find_prodotto(0)); //ordino 10 PC LENOVO a prezzo 200
	a.addProdotto(300, 5, m.find_prodotto(2)); //ordino 5 PC ASUS a prezzo 300
	m.crea_ordine_acquisto(a);
	m.lista_ordine_acquisto();
	cout<<"==== FINE TEST ORDINE ACQUISTO ===="<<endl<<endl;
	
	cout<<"==== TEST ORDINE VENDITA ===="<<endl; 
	{
	OrdineVendita o("Brombeis",123456,181130, *m.trova_impresa("0123456789"));
	o.add_prodotto(5,m.find_prodotto(0)); //ricerco tramite barcode
	o.add_prodotto(20,m.find_prodotto(1)); //aggiungo prodotto disattivato
	o.add_prodotto(20,m.find_prodotto(0)); //aggiungo un prodotto già inserito in quantita non disponibile, mi darà errore e non verrà inserito
	cout<<"SUBTOTALE: "<<o.sub_totale()<<endl;
	o.add_prodotto(5,m.find_prodotto(3)); //ricerco tramite barcode il vetro (no servizio)
   	o.add_metodo_di_pagamento(m.trova_metodo_di_pagamento("Banconota"));
  	o.add_servizio(*m.trova_servizio("Samsung", "Assicurazione"));
	m.crea_ordine_vendita(o);
    }
	{
   	OrdineVendita o("Sommarive",123456,181130, *m.trova_privato("ABCDEFG1234"));
   	o.add_prodotto(1,m.find_prodotto(0));
   	o.add_metodo_di_pagamento(m.trova_metodo_di_pagamento("Assegno"));
   	//m.lista_fattura();
	m.crea_ordine_vendita(o);
	}
	//cout<<o;
	m.lista_ordine_vendita();	
	cout<<"==== FINE TEST ORDINE VENDITA ===="<<endl<<endl;
	
	cout<<m;
}


