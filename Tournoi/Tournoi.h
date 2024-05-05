#include"Partie.h"
class Tournoi{
	private:
	vector<Joueur> joueurs;
	vector<Partie> parties;
	vector<Salle> salles;
	vector<Arbitre> arbitres;
	vector<Joueur> Elimines;
	public:
	Tournoi();
   bool existeJoueur(string );
   void ajouterjoueur(Joueur& );
    void Ajouterplusieurs() ;
    void supprimerjoueur(string );
    void afficherJoueurs();
    void afficherUnJoueur(string );
	void afficherElimines();
	void gagnant();
	void ajouterarbitre(Arbitre& ar);
    void AjouterplusieursArbitres();
    void afficherArbitres();
	void ajouterSalle(Salle& sa);
    void affichersalle(string n);
	void affichersalles();
	void suppSalle(string n);
	void PlaceDsalle(string n,Spectateur& sp);
	void creerParties() ;
    void resultats_Partie(int n);
	void PartiesDuNextRound();
	void affToutesLesParties();
	void affpartienum(int n);
	void litige(int n);
	void Interface_Menu();
    
};