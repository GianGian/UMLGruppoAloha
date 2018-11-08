#include <cstdlib>
#include <iostream>
#include "magazzino.h"
#include "prodotto.h"
using namespace std;

int main(int argc, char *argv[]){
    {
    Magazzino m("Rosmini","Leonardelli",500);
    m.stampa();
    Prodotto prod(10,"rosa","Apple",1200);
    m.inserisci_prodotto(20,"bianco","HP",600);
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
