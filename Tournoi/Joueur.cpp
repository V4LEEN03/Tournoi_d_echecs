
#include"Joueur.h"

using namespace std;

Joueur::Joueur(){}
Joueur::Joueur(string i,string n,string p, int a , float s) : Personne(i,n,p,a), score(s) {}

int Joueur::getage() { return age; }
float Joueur::getScore() { return score; }
    
void Joueur::setage(int a){ age=a; }
void Joueur::setScore(float S) { score = S; }
    
void Joueur::affichage(){
    Personne::affichage();
	cout<<" age: "<<age<<endl;		cout<<" score: "<<score<<endl;
}
void Joueur::EntrerDonnee()
{
	cout<<"---Entrer les donnees du joueur---"<<endl;
	Personne::EntrerDonnee();
	cout<<" Entrer le score: ";
	cin>>score;
}
