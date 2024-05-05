#include"Personne.h"

using namespace std;	
	
Personne::Personne(){}
Personne::Personne(string id,string nom,string prenom,int age): id(id), nom(nom), prenom(prenom),age(age){ }
string Personne::getid() { return id; }
string Personne::getNom() { return nom; }
string Personne::getPNom() { return prenom; }
	
void Personne::setid(string i){ id=i; }
void Personne::setNom(string n){ nom=n; }
void Personne::setPNom(string p){ prenom=p; }
void Personne::affichage(){
	cout<<" id: "<<id<<endl;
	cout<<" nom: "<<nom<<endl;
	cout<<" Prenom: "<<prenom<<endl;
}
void Personne::EntrerDonnee()	{
	cout<<" Entrer id: ";
	cin>>id;
	cout<<" Entrer nom: ";
	cin>>nom;
	cout<<" Entrer Prenom: ";		
	cin>>prenom;
	cout<<" Entrer age: ";
	cin>>age;
}