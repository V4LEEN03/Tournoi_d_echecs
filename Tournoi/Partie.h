#ifndef PARTIE_H
#define PARTIE_H
#include"Joueur.h"
#include"Arbitre.h"
#include"Salle.h"
#include<cstdlib>
using namespace std;
class Partie {		
   protected:
   static int n;
   Joueur jou1;
   Joueur jou2; 
   Arbitre arb;  
   Salle   sa;
   int resultat1;
   int resultat2;
   string decision;
   public:
   Partie();
   Partie(Joueur ,Joueur , Arbitre , Salle ,int ,int );
    int getNum() ;
   	Joueur getjou1();
   	Joueur getjou2(); 
   	Salle getsalle();
   	Arbitre getarbitre();
   	int getres1() ;
	int getres2() ;
	string getDecision( );
	void setres1( int  );
	void setres2( int  );
	void setDecision( string  );
	void afficherPartie();
};
#endif