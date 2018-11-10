#ifndef __ORDINE_H__
#define __ORDINE_H__
#include <iostream>
using namespace std;

class Ordine{
private:
    int quantita;
    static int n_ordine;  
public:
    Ordine (int _quantita);
    ~Ordine();
};
#endif
