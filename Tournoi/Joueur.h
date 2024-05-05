#ifndef JOUEUR_H
#define JOUEUR_H
#include"Personne.h"

using namespace std;

class Joueur:public Personne{
	protected:
	float score;
	public:
	Joueur();
	Joueur(string ,string ,string , int  , float );

    int getage() ;
    float getScore();
    
    void setage(int );
    void setScore(float );
    
    void affichage();
	void EntrerDonnee();
	
};
#endif