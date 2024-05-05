#include"Partie.h"

using namespace std;
int Partie::n=0;
Partie::Partie(){}
Partie::Partie(Joueur j1,Joueur j2, Arbitre a,  Salle s,int r1,int r2): jou1(j1),jou2(j2),arb(a),sa(s),resultat1(r1),resultat2(r2)
{ n++ ; decision = "Pas de litige";}
int Partie::getNum() { return n; }
Joueur Partie::getjou1(){  return jou1;  }
Joueur Partie::getjou2(){  return jou2;  }   
Salle Partie::getsalle(){  return sa;  }  
Arbitre Partie::getarbitre(){  return arb;  }  
int Partie::getres1() { return resultat1;}
int Partie::getres2() { return resultat2;}
string Partie::getDecision( ){ return decision; }
void Partie::setres1( int r ){ resultat1=r; }
void Partie::setres2( int r ){ resultat2=r; }
void Partie::setDecision( string D ){ decision=D; }
void Partie::afficherPartie()
{
	cout<<"----Infos Partie----"<<endl;
	cout<<"Partie N° "<<n<<endl;
	cout<<" joueur 1 : "<<endl;
	jou1.affichage();
	cout<<"Resultats du joueur 1 :"<<resultat1<<endl;
	cout<<" joueur 2 : "<<endl;
	jou2.affichage();
	cout<<"Resultats du joueur 2 :"<<resultat2<<endl;
	cout<<" Salle : "<<endl;
	sa.afficherSalle();
	cout<<" Arbitre: "<<endl;
	arb.affichage();
	cout<<" Litige :"<<decision<<endl;	
}