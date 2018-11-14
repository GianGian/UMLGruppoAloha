#include <cstdlib>
#include <iostream>
#include "gestioneMagazzino.h"
using namespace std;

Magazzino::Magazzino(char* _via, char* _denominazione, double _fondoCassa){
    via=_via;
    denominazione=_denominazione;
    fondoCassa=_fondoCassa;
    cout<<"Creato magazzino "<<denominazione<<" in via "<<via<<" con fondocassa "<<fondoCassa<<endl;   
}

Magazzino::~Magazzino(){
    cout<<"Distrutto magazzino "<<denominazione<<" in via "<<via<<" con fondocassa "<<fondoCassa<<endl;   
}

void Magazzino::stampa()const{
    cout<<"Magazzino "<<denominazione<<" in via "<<via<<" con fondocassa "<<fondoCassa<<endl;
}

void Magazzino::stampadipendenti(){
    list <Dipendente>::iterator iter; 
            for(iter=listdip.begin(); iter!=listdip.end(); ++iter){
            iter->Dipendente::stampa();
            } 
           cout<<endl;
}

void Magazzino::inserisci_prodotto(int _quantita, char* _colore, char* _marca, double _costo, int _matricola){
    /*if(d==NULL){
        cout<<"non esiste la matricola"<<endl;
        return;
    }
    if(d->get_matricola()==_matricola){
        if(p==NULL){//se avessi più prodotti dovrei fare una lista?
        p= new Prodotto(_quantita,_colore,_marca, _costo);
        }
    }else{
        cout<<"utente non autorizzato per inserire un nuovo prodotto"<<endl;
    }*/
}

void Magazzino::aggiungi_dipendente(char* _nome,char* _n_Telefono,char* _ruolo,int _matricola){
    Dipendente temp(_nome,_n_Telefono,_ruolo,_matricola);//fatto così altrimenti da warning
    listdip.push_front(temp); 
}

void Magazzino::incrementa_cassa(double _fondoCassa, int _matricola){
    /*if(d->get_matricola()==_matricola){
        fondoCassa+=_fondoCassa;
        cout<<"incrementato valore fondocassa di "<<_fondoCassa;
        cout<<" fondocassa totale di "<<fondoCassa<<endl;
    }else{
    cout<<"utente non autorizzato per incrementare il fondocassa"<<endl;
    }*/
}

ostream& operator <<(ostream &os, Magazzino &m){
    list <Dipendente>::iterator iter; 
    for(iter=m.listdip.begin(); iter!=m.listdip.end(); ++iter){
        os<<(*iter);
    }
    cout<<endl;
    return os; 
}

void Magazzino::togli_dipendente(int _matricola,int _matricolamaster){//da pensare
    /*list <Dipendente>::iterator deliter;
    list <Dipendente>::iterator deliter2;
    deliter=find(listdip.begin(),listdip.end(),_matricolamaster);
    if(deliter!=listdip.end()){
       deliter2=find(listdip.begin(),listdip.end(),_matricola);
       if(deliter2!=listdip.end()){
          listdip.erase(deliter2);
    }
    }*/
}
