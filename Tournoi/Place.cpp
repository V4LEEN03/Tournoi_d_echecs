#include"Place.h"

using namespace std;


Place::Place() : num(0), type(" "),prix(0.0),sp() {}
Place::Place(int n,string t,double p,Spectateur& s) : num(n), type(t), prix(p),sp(s) {}
	
int Place::getNum() { return num; }
string Place::getType() { return type; } 
double Place::getPrix() { return prix; }
Spectateur Place::getspec() {return sp;}
    
void Place::setNum(int a){ num=a; }
void Place::setType(string t) { type = t; }
void Place::setPrix(double p) { prix  = p; }
void Place::setspec(Spectateur& s) { sp=s;}
    
void Place::afficherPlace()
	{
	cout<< "La place du spectateur :"<<endl;
	sp.affichage();	
	cout<<"numero de la place :"<<num<<endl;
	cout<<"type de la place :"<<type<<endl;
	} 