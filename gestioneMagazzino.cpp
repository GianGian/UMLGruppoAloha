#include <cstdlib>
#include <iostream>
#include "gestioneMagazzino.h"
using namespace std;

void test(){
	Privato Gigino("Gigino", "Dimaio", "123456789","GGGGGG", 100);
	Impresa Panineria("Ddimaio","123456789","001231567864",0);
	Fornitore SMA ("morino","03949505","sma","patate");
	Servizio vetro("vetro",60,1000,110);
	cout<<vetro.get_costo();
	cout<<Gigino.getSconto();
	
}
