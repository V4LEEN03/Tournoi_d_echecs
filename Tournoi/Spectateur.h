#ifndef SPECTATEUR_H
#define SPECTATEUR_H
#include"Personne.h"

using namespace std;

class Spectateur:public Personne{

	public:
	Spectateur();
	Spectateur(string ,string ,string ,int );
    void EntrerDonnee();
	void affichage();
	
};
#endif