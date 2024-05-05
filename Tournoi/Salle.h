#ifndef SALLE_H
#define SALLE_H
#include"Place.h"
#include<vector>
using namespace std;
class Salle {
    private:
    vector<Place> placesVip;
    vector<Place> placesNor;
    string nomS;
    int capacite;
    public:
    Salle();
    Salle(string , int ) ;
    

    string getNomS();
    int getCapacite();
    
    void setNomS(string ) ;
    void setCapacite(int ) ;
    
    void afficherSalle();
	void DonneesSalle();
	void reserverPlace(Spectateur& );
};
#endif