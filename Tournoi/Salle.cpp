#include"Salle.h"

using namespace std;
Salle::Salle() {}
Salle::Salle(string n, int c) : nomS(n), capacite(c) {}
    
string Salle::getNomS(){ return nomS; }
int Salle::getCapacite(){ return capacite; }
    
void Salle::setNomS(string n) { nomS = n; }
void Salle::setCapacite(int c) { capacite = c; }
    
void Salle::afficherSalle(){
   		cout<<" Nom de la Salle: "<<nomS<<endl;
		cout<<" Capacite de la salle: "<<capacite<<endl;
	}
void Salle::DonneesSalle()
	{
		cout<<" Nom de la Salle: ";
		cin>>nomS;
		cout<<" Capacite de la salle: ";
		cin>>capacite;
	}
void Salle::reserverPlace(Spectateur& sp)
	{
		string choix;
		if(( placesVip.size() + placesNor.size() )==capacite)
		cout<<"il n'y a plus de places pour reserver!!!!"<<endl;
		else{
			if(  placesVip.size()< 10  && placesNor.size()  < (capacite-10) )
			{ 
			  do{
			  	cout<<"---------------PRIX DES PLACES---------------"<<endl;
			  	cout<<"           + PRIX VIP :  100 dh"<<endl;
			  	cout<<"           + PRIX NORMALE :  50 dh"<<endl;
			  	cout<<"---------------------------------------------"<<endl;
				cout<<"choisissez le type : (VIP | normale) "<<endl;
			    cin>>choix;
			    }while(choix !="VIP" && choix !="normale" );
			
			if(choix=="VIP")
			{
			int n=placesVip.size(); 
			sp.EntrerDonnee();
			Place p(n+1,"VIP",100,sp);
			placesVip.push_back(p);
			cout<<"Votre place a ete reserve"<<endl;
			placesVip[n].afficherPlace();
		    }
		    else 
			{
		    int n=placesNor.size(); 
			sp.EntrerDonnee();
			Place p(n+1,"Normale",50,sp);
			placesNor.push_back(p);
			cout<<"Votre place a ete reserve"<<endl;
			placesNor[n].afficherPlace();	
			}
		    }
		}
	}