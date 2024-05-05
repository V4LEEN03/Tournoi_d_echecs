#include"Arbitre.h"

using namespace std;

Arbitre::Arbitre(){ }
Arbitre::Arbitre(string i,string n,string p,int a) : Personne(i,n,p,a) {}
   
void Arbitre::affichage(){
		cout<<"===Arbitre==="<<endl;
		Personne::affichage();
	}
void Arbitre::EntrerDonnee()
	{
	cout<<"---Entrer les donnees d Arbitre---"<<endl;
	Personne::EntrerDonnee();	
	} 