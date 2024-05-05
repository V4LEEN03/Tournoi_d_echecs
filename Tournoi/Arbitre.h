#ifndef ARBITRE_H
#define ARBITRE_H
#include"Personne.h"

using namespace std;

class Arbitre:public Personne{
	public:
	Arbitre();
	Arbitre(string ,string ,string ,int) ;
   
   void affichage() ;
   void EntrerDonnee();
};
#endif