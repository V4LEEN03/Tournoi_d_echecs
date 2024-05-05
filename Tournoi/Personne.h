#ifndef PERSONNE_H
#define PERSONNE_H
#include<iostream>
#include<string>
using namespace std;
class Personne{
	protected:
	string id;
	string nom;
	string prenom;
	int age;
	public:
	Personne();
	Personne(string ,string ,string ,int);
	string getid() ;
	string getNom() ;
	string getPNom()  ;
	
	void setid(string );
	void setNom(string );
	void setPNom(string );
	void affichage();
	void EntrerDonnee();

};
#endif