#include <cstdlib>
#include <iostream>
#include "gestioneMagazzino.h"
using namespace std;

Magazzino::Magazzino(char* _via, char* _denominazione, double _fondoCassa){
    via=_via;
    denominazione=_denominazione;
    fondoCassa=_fondoCassa;
    p=NULL;
    d=NULL;
    cout<<"Creato magazzino "<<denominazione<<" in via "<<via<<" con fondocassa "<<fondoCassa<<endl;   
}

Magazzino::~Magazzino(){
    if(p!=NULL){
    delete p;
    }
    if(d!=NULL){
    delete d;
    }
    cout<<"Distrutto magazzino "<<denominazione<<" in via "<<via<<" con fondocassa "<<fondoCassa<<endl;   
}

void Magazzino::stampa()const{
    cout<<"Magazzino "<<denominazione<<" in via "<<via<<" con fondocassa "<<fondoCassa<<endl;
}

void Magazzino::inserisci_prodotto(int _quantita, char* _colore, char* _marca, double _costo, int _matricola){
    if(d==NULL){
        cout<<"non esiste la matricola"<<endl;
        return;
    }
    if(d->get_matricola()==_matricola){
        if(p==NULL){//se avessi più prodotti dovrei fare una lista?
        p= new Prodotto(_quantita,_colore,_marca, _costo);
        }
    }else{
        cout<<"utente non autorizzato per inserire un nuovo prodotto"<<endl;
    }
}

void Magazzino::aggiungi_dipendente(char* _nome,char* _n_Telefono,char* _ruolo,int _matricola){
    if(d==NULL){
        d= new Dipendente(_nome,_n_Telefono,_ruolo,_matricola);
    }
}

void Magazzino::incrementa_cassa(double _fondoCassa, int _matricola){
    if(d->get_matricola()==_matricola){
        fondoCassa+=_fondoCassa;
        cout<<"incrementato valore fondocassa di "<<_fondoCassa;
        cout<<" fondocassa totale di "<<fondoCassa<<endl;
    }else{
    cout<<"utente non autorizzato per incrementare il fondocassa"<<endl;
    }
}
