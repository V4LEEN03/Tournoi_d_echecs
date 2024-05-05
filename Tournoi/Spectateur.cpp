#include"Spectateur.h"

using namespace std;

Spectateur::Spectateur() { }
Spectateur::Spectateur(string i,string n,string p ,int a) : Personne(i,n,p,a) {}
void Spectateur::EntrerDonnee()
	{
		cout<<"---Entrer les donnees du spactateur---"<<endl;
        Personne::EntrerDonnee();
	} 
void Spectateur::affichage(){
		cout<<"---Infos du spectateur---"<<endl;
		Personne::affichage();

	}