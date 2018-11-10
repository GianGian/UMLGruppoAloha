#ifndef __SERVIZIO_H__
#define __SERVIZIO_H__
class Servizio{
private:
	char* nome;
	int durata;
	int franchigia;
	int costoServizio;
public:
	Servizio(char* _nome, int _durata, int _franchigia, int _costoServizio);
	~Servizio();
};
#endif
