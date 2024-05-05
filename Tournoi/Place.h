#ifndef PLACE_H
#define PLACE_H
#include"Spectateur.h"
using namespace std;
class Place{
	protected:
	int num;
	string type;
	double prix;
	Spectateur sp;
	public:
	Place();
	Place(int ,string ,double ,Spectateur& ) ;
	
	int getNum();
    string getType() ;
    double getPrix() ;
    Spectateur getspec();
    
    void setNum(int );
    void setType(string ) ;
    void setPrix(double ) ;
    void setspec(Spectateur& ) ;
    
	void afficherPlace();
};
#endif