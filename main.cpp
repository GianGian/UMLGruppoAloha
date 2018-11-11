#include <cstdlib>
#include <iostream>
#include "gestioneMagazzino.h"
#include "prodotto.h"
#include "privato.h"
#include "impresa.h"
#include "dipendente.h"
#include "fornitore.h"
#include "ordineVendita.h"
#include "ordineAcquisto.h"
#include "metodoDiPagamento.h"
#include "servizio.h"
using namespace std;

int main(int argc, char *argv[]){
    {
    Magazzino m("Rosmini","Leonardelli",500);
    m.stampa();
    /*Prodotto pc(10,"rosa","Apple",1200);
    pc.stampa();*/
    m.inserisci_prodotto(20,"bianco","HP",600,1234);
    /*Anagrafica a("Boh","123");
    Consumatore c("bah","124",5);
    Privato pp("Gian","3317926754",100,"msrglr97c04l378b","Moser");
    Impresa i("Fogarolli","1234567890",1,"00112939223");*/
    Dipendente d ("Sara","345678","cuoca",1234);
    //Fornitore f("morino","987654321","SMA",1000);
    Ordine o(400);
    MetodoDiPagamento bancomat("bancomat",5000, 3);
    OrdineVendita v(600,"sale'", &bancomat);
    OrdineAcquisto q(500,"boh",5);
    m.aggiungi_dipendente("Sara","345678","cuoca",1234);
    m.incrementa_cassa(-500,1234);
    m.incrementa_cassa(600,12345);//matricola non inserita
    m.inserisci_prodotto(20,"bianco","HP",600,1234);
    /*//test per provare l'inserimento di un servizio ad un prodotto
    Servizio s("assicurazione",15,200,10);
    Prodotto p(15, "giallo","HP",500);
    Prodotto p1(20, "rosa","HP",600);
    //fine test====================================================*/
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
