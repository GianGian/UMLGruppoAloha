#include <cstdlib>
#include <iostream>
#include "magazzino.h"
using namespace std;

int main(int argc, char *argv[]){
    Magazzino m("Rosmini","Leonardelli",500);
    m.stampa();
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
