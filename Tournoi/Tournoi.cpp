#include"Tournoi.h"
using namespace std;
Tournoi::Tournoi(){ }
//                                ------------------------TRAITEMENT DES JOUEURS-----------------------------	
    // VERIFIER EXISTANCE DU JOUEUR
   bool Tournoi::existeJoueur(string testId)
   {
   	for(int i=0 ; i<joueurs.size() ; i++)
   	{
	 if(joueurs[i].getid() == testId)
	 return true;
    }
	return false;
   }
   

    // AJOUTER JOUEUR
   void Tournoi::ajouterjoueur(Joueur& jj) {
        if (existeJoueur(jj.getid())==false) {
            joueurs.push_back(jj);
            cout << "joueur ajoute avec succes" << endl;
        } else {
            cout << "Ce joueur existe deja" << endl;
        }
    }
    void Tournoi::Ajouterplusieurs() {
        Joueur jj;

   	int n;
   	do{
   		cout<<"Entrer le nbre de joueur qui doit etre paire: ";
        cin>>n;
	}while(n % 2 != 0);
;
        for (int i = 0; i < n; i++) {
            jj.EntrerDonnee();
            ajouterjoueur(jj);
            //car loop infinie 
            if (joueurs.size() == n) {
            break;
        }
        }
    }

     // SUPPRIMER JOUEUR
    void Tournoi::supprimerjoueur(string id) {
    	vector<Joueur>::iterator i;
        for ( i = joueurs.begin() ; i != joueurs.end(); i++) {
            if (i->getid() == id) {
                joueurs.erase(i);
                cout << "joueur Supprimee avec succes" << endl;
            }
        }
        cout << "Ce joueur n'existe pas" << endl;
    }
    // AFFICHER tous les JOUEURS
    void Tournoi::afficherJoueurs(){
    for(int i=0 ; i<joueurs.size() ; i++)
   	{
   		cout<<"--------------------- joueur "<<i+1<<" ---------------------"<<endl;
   		joueurs[i].affichage();
    }
	}
	
	//AFFICHER UN SEUL JOUEUR
	void Tournoi::afficherUnJoueur(string n){
		int comp=0;
    for(int i=0 ; i<joueurs.size() ; i++)
   	{
   		if(joueurs[i].getid()==n)
		{
   		joueurs[i].affichage();
   		comp++;
		}
    }
    if(comp==0)
			{
			cout<<"ce joueur n'existe pas!!!"<<endl;
			}
	}

	// AFFICHER JOUEURS ELIMINES
	void Tournoi::afficherElimines(){
	if(Elimines.empty())
    cout<<"il n'y a pas encore d'eliminations "<<endl;
    else
	{

	    for(int i=0 ; i<Elimines.size() ; i++)
	   	{
	   		cout<<"--------------------- joueur "<<i+1<<" elimine ---------------------"<<endl;
	   		Elimines[i].affichage();
	    }
    }
	}
	//afficher GAGNANT
	void Tournoi::gagnant()
	{
		int x=0;
	for(int i=1 ; i<joueurs.size() ; i++)
   	{   
   	if(joueurs[i].getScore()>joueurs[x].getScore())	{ x=i; }
    }
    cout<<"--------------------- joueur gagnant ---------------------"<<endl;
   	joueurs[x].affichage();
	}
//         -------------------------------------TRAITEMENT ARBITRES------------------------------------------------
    //ajout d'un seul arbitre
		void Tournoi::ajouterarbitre(Arbitre& ar)
        {
            arbitres.push_back(ar);
            cout << "arbitre ajoute avec succes" << endl;
        
        }

    // AFFICHAGE ARBITRES
    void Tournoi::afficherArbitres(){
    for(int i=0 ; i<arbitres.size() ; i++)
   	{
   		cout<<"--------------------- Arbitre "<<i+1<<" ---------------------"<<endl;
   		arbitres[i].affichage();
    }
	}
//         -------------------------------------TRAITEMENT SALLES------------------------------------------------
       // AJOUTER UNE SALLE
	    void Tournoi::ajouterSalle(Salle& sa)
        {
            salles.push_back(sa);
            cout << "Salle ajoute avec succes" << endl;
        
        }
        //afficher une salle
        void Tournoi::affichersalle(string n){
        for(int i=0 ; i<salles.size() ; i++)
   	    {
   		if(salles[i].getNomS()==n)
   		 salles[i].afficherSalle();
       }
	   }
	   //afficher plusieurs salles
	   void Tournoi::affichersalles(){
        for(int i=0 ; i<salles.size() ; i++)
   	    {
   		cout<<"--------------------- Salle "<<i+1<<" ---------------------"<<endl;
   		salles[i].afficherSalle();
        }
	   }
	   //supprimer salle
	   void Tournoi::suppSalle(string n)
	   {
	   	vector<Salle>::iterator i;
        for ( i = salles.begin() ; i != salles.end(); i++) {
            if (i->getNomS()==n) {
                salles.erase(i);
                cout << "salles Supprimee avec succes" << endl;
            }
        }
        cout << "Cette salle n'existe pas" << endl;
	   	
	   }
	   //Reservation d'une place
	   void Tournoi::PlaceDsalle(string n,Spectateur& sp)
	   {
        for(int i=0 ; i<salles.size() ; i++)
   	    {
   		if(salles[i].getNomS()==n)
   		salles[i].reserverPlace(sp);
       }
	   }
        
//         -------------------------------------TRAITEMENT DES PARTIES---------------------------------------------
	// CREATION DES PARTIES :
	void Tournoi::creerParties() 
	{
		if (joueurs.empty()) {
        cout << "Erreur: il n'y a pas de joueurs pour cr?er des parties." << endl;
        return;
        }
         if (salles.empty()) {
        cout << "Erreur: il n'y a pas de salles pour cr?er des parties." << endl;
        return;
        }

        if (arbitres.empty()) {
        cout << "Erreur: il n'y a pas d'arbitres pour cr?er des parties." << endl;
        return;
        }
		//Permutation des joueurs pour une selection aleatoire
        for (int i = 0; i < joueurs.size(); i++) 
		{
        int j = rand() % joueurs.size();
        swap(joueurs[i], joueurs[j]);
        }
        
        for (int i = 0; i < (joueurs.size() / 2); i++) {
            Joueur joueur1 = joueurs[2 * i];
            Joueur joueur2 = joueurs[2 * i + 1];
            Salle salle = salles[i % salles.size()]; // Attribution des salles aleatoirement
            Arbitre arbitre = arbitres[i % arbitres.size()]; // Attribution des arbitres aleatoirement

            Partie partie(joueur1, joueur2, arbitre, salle, 0, 0);
            parties.push_back(partie);
        }
        cout<<"Parties crees avec succes !!"<<endl;
    }
    //Enregistrer les resultats d'une partie
    void Tournoi::resultats_Partie(int n){//il faut choisir le num de la partie
    	int r;
    	float f;
    	for(int i =0 ; i< parties.size() ; i++)
    	{
    		if(parties[i].getNum()==n)
			{
			cout<<"Pour la partie num :"<<parties[i].getNum()<<endl;
    		cout<<"Joueur 1 : "<<endl;
    		parties[i].getjou1().affichage();
    		cout<<"Joueur 2 : "<<endl;
    		parties[i].getjou2().affichage();
    		cout<<"Entrer le resultat du joueur1 : ";
    		cin>>r;
    		parties[i].setres1(r);
    		f=parties[i].getjou1().getScore();
    		parties[i].getjou1().setScore(f+r);
    		cout<<"Entrer le resultat du joueur2 : ";
    		cin>>r;
    		parties[i].setres2(r);
    		f=parties[i].getjou2().getScore();
    		parties[i].getjou2().setScore(f+r);
		    }
		}
	}
	//Creation des parties du next round
	void Tournoi::PartiesDuNextRound()
	{
		vector<Joueur> Nvjoueurs;  // tab temporaire
		for( int i=0 ; i< parties.size() ; i++)
		{
			if(parties[i].getres1()>parties[i].getres2())
			{
			Nvjoueurs.push_back(parties[i].getjou1());  //stocker les joueurs qui passe au next round
			Elimines.push_back(parties[i].getjou2());	  //stocker les joueurs elimines
			}
			else{
					Nvjoueurs.push_back(parties[i].getjou2());     //stocker les joueurs qui passe au next round
					Elimines.push_back(parties[i].getjou1());      //stocker les joueurs elimines
			}
		
		}
		
		for (int i = 0; i < Nvjoueurs.size(); i++) 	//NOUVELLESPARTIES
		{
        int j = rand() % Nvjoueurs.size();
        swap(joueurs[i], Nvjoueurs[j]);
        }
        
        for (int i = 0; i < (Nvjoueurs.size() / 2); i++) {
            Joueur joueur1 = Nvjoueurs[2 * i];
            Joueur joueur2 = Nvjoueurs[2 * i + 1];
            Salle salle = salles[i % salles.size()]; // Attribution des salles aleatoirement
            Arbitre arbitre = arbitres[i % arbitres.size()]; // Attribution des arbitres aleatoirement
            
            Partie partie(joueur1, joueur2, arbitre, salle, 0, 0);
            parties.push_back(partie);
        }
	}
	//affichage de toutes les parties
	void Tournoi::affToutesLesParties()
	{
		int cpt=0;
		for( int i=0 ; i<parties.size() ; i++)
		{
			if(i< (joueurs.size()/2))
			{
				if(cpt==0){
					cout<<"-----------Parties du 1er round-----------"<<endl;
					cpt++;
				}
			}
			if(i>= (joueurs.size()/2) && i< (joueurs.size()/2)+(joueurs.size()/4))
			{
				if(cpt==1){
					cpt++;
				cout<<"-----------Parties du 2eme round-----------"<<endl;}
			}
			if(i>=(joueurs.size()/2)+(joueurs.size()/4))
			{
				if(cpt==2){
				cpt++;
				cout<<"-----------Parties du 3eme round-----------"<<endl;}
			}
			
			parties[i].afficherPartie();
			cout<<"--------------------------------------"<<endl;
		}
	}
	//affichage d'une seule partie par son num
	void Tournoi::affpartienum(int n)
	{
	    for(int i =0 ; i< parties.size() ; i++)
    	{
    		if(parties[i].getNum()==n)
			{
			parties[i].afficherPartie();
		    }
		}
	}
	//litige
	void Tournoi::litige(int n)
	{
		string l;
	for(int i =0 ; i< parties.size() ; i++)
    	{
    		if(parties[i].getNum()==n)
			{
				cout<<"Saisir la decision arbitrale: ";
				cin>> l;
				parties[i].setDecision(l);
		    }
    	}
    }
    //Interface_Menu
void Tournoi::Interface_Menu(){
		int choix=0;
		do{
	system("cls");
	cout<<"\t \t MENU: "<<endl;
	cout<<"=========================================="<<endl;
	cout<<"\t 1.GESTION DES JOUEURS "<<endl;
	cout<<"\t 2.GESTION DES ARBITRES "<<endl;
	cout<<"\t 3.CONTROLE DES SALLES"<<endl;
	cout<<"\t 4.GESTION DES PARTIES "<<endl;
    cout<<"\t 5.QUITTER"<<endl;	
	cout<<"=========================================="<<endl;
	cout<<"Choisissez :";
	cin>>choix;
    switch(choix)
    {
    case 1 :
	{
    int gestjou=0;
    system("cls");
    do{
    	cout<<"=========================================="<<endl;
    	cout<<"\t ---GESTION DES JOUEURS--- "<<endl;
    	cout<<"Que souhaitez vous faire?"<<endl;
    	cout<<"\t 1.inscription d'un joueur. "<<endl;
    	cout<<"\t 2.inscrire plusieurs joueurs a la fois. "<<endl;
    	cout<<"\t 3.Afficher les informations d'un seul joueur. "<<endl; 	
    	cout<<"\t 4.Afficher les informations de tous les joueurs. "<<endl;
    	cout<<"\t 5.Chercher l'existance d'un joueur . "<<endl;
    	cout<<"\t 6.supprimer un joueur. "<<endl;
    	cout<<"\t 7.Afficher joueurs Elemines. "<<endl;
    	cout<<"\t 8.Afficher joueur GAGNANT. "<<endl;
    	cout<<"\t 9.Retour au menu principale. "<<endl;
    	cout<<"=========================================="<<endl;
    	cout<<"FAITES VOTRE CHOIX : ->"; cin>>gestjou;
    	switch(gestjou)
		{
    	case 1 :
    	{ 
    	    system("cls");
    	    cout<<"  {[ 1.inscription d'un joueur. ]}  "<<endl;
	    	Joueur jo;
	    	string valid;
	    	cout<<"Entrer vos donnees:"<<endl;
	    	jo.EntrerDonnee();
	    	cout<<"Valider Inscription : (Y | N) ";
	    	cin>>valid;
	    	if(valid == "Y" || valid == "y" )
	    	ajouterjoueur(jo);
	    	else
	    	cout<<"Joueur non inscrit!!!"<<endl;
			cout<<"\n \n \n \n "<<endl;
		}
	    break;
	    case 2 :
	    {
	    	system("cls");
	    	cout<<"  {[ 2.Ajouter plusieurs joueurs a la fois. ]}  \n"<<endl;
	    	
			Ajouterplusieurs();
	        
			cout<<"\n \n \n \n "<<endl;
		}
	    break;
	    case 3 :
	    {
	    	system("cls");
	    	cout<<"  {[ 3.Afficher les informations d'un seul joueur. ]}  "<<endl;
	    	string idA;
	    	cout<<"entrer l'id du joueur :";
	    	cin>>idA;
	    	afficherUnJoueur(idA);
			
			cout<<"\n \n \n \n "<<endl;
	    }
		break;
	    case 4 :
	    {
	    	system("cls");
	    	cout<<"  {[ 4.Afficher les informations de tous les joueurs. ]}  "<<endl;
			afficherJoueurs();
			
		    cout<<"\n \n \n \n "<<endl;
	    }
		break;	
	    case 5 :
	    {
	    	system("cls");
	    	cout<<"  {[ 5.Chercher l'existance d'un joueur . ]}  "<<endl;
	    	string idr;
	    	cout << "entrer l'id du joueur a rechercher:";
	    	cin>>idr;
	    	if(existeJoueur(idr)==true)
	    	cout<<"ce joueur existe"<<endl;
	    	else
	    	cout<<"ce joueur n'existe pas!"<<endl;
	    	cout<<"\n \n \n \n "<<endl;
	    }
		break;
		case 6 :
		{
			system("cls");
			cout<<"  {[ 6.supprimer un joueur. ]}  "<<endl;
			string ids;
		    cout<<"entrer l'id du joueur que vous voulez supprimer: ";
	        cin>> ids;
            supprimerjoueur(ids);
		    
			cout<<"\n \n \n \n "<<endl;
		}	
		break;
		case 7 :
		{
			system("cls");
			cout<<"  {[ 7.Afficher joueurs elimines. ]}  "<<endl;
			afficherElimines();
			cout<<"\n \n \n \n "<<endl;
		}
		break;
		case 8 :
		{
			system("cls");
			cout<<"  {[ 8.Afficher joueur GAGNANT. ]} "<<endl;
		    gagnant();
			cout<<"\n \n \n \n "<<endl;	
		}
		break;
	    }//end switch gestjou
	}while(gestjou < 9);

	}//FIN CASE 1
	break;
	
    case 2 :
	{
    int gestarb=0;
    system("cls");
    do{
    	cout<<"=========================================="<<endl;
    	cout<<"\t ---GESTION DES Arbitres--- "<<endl;
    	cout<<"Que souhaitez vous faire?"<<endl;
    	cout<<"\t 1.Ajouter un seul Arbitre. "<<endl;
    	cout<<"\t 2.Afficher les informations des arbitres. "<<endl; 	
    	cout<<"\t 3.Retour au menu principale. "<<endl;
    	cout<<"=========================================="<<endl;
    	cout<<"FAITES VOTRE CHOIX : ->"; cin>>gestarb;
    	switch(gestarb)
		{
    	case 1 :
    	{ 
    	    system("cls");
    	    cout<<"  {[ 1.Ajouter un seul Arbitre. ]}  "<<endl;
	    	Arbitre ARB;
	    	cout<<"Entrer les donnees de l'arbitre:"<<endl;
	    	ARB.EntrerDonnee();
	    	ajouterarbitre(ARB);
			cout<<"\n \n \n \n "<<endl;
		}
	    break;

	    
	    case 2 :
	    {
	    	system("cls");
	    	cout<<"  {[ 3.Afficher les informations des arbitres. ]}  "<<endl;
			afficherArbitres();
			
		    cout<<"\n \n \n \n "<<endl;
	    }
		break;	
	    
	    }//end switch gestarb
	}while(gestarb < 3);

	}//FIN CASE 2
	break;
	
	case 3 :
	{
	int gestSalle=0;
    system("cls");
	do{
    cout<<"=========================================================="<<endl;
    cout<<"\t ---GESTION DES SALLES--- "<<endl;
 	cout<<"\t 1.Ajout d'une salle"<<endl;
 	cout<<"\t 2.Ajouter plusieurs Salles a la fois"<<endl;
 	cout<<"\t 3.Afficher une salle."<<endl;
 	cout<<"\t 4.Afficher plusieurs salles"<<endl;
 	cout<<"\t 5.Supprimer salle "<<endl;
 	cout<<"\t 6.Retour au menu principale"<<endl;
 	cout<<"=========================================================="<<endl;
 	cout<<"Choisissez : -> ";  cin>>gestSalle;
 	switch(gestSalle)
 	{
 	    case 1 :
		{
			system("cls");
			cout<<"  {[ 1.Ajout d'une salle ]}  "<<endl<<endl;
			Salle sa;
			sa.DonneesSalle();
			ajouterSalle(sa);
 	        cout<<"\n \n \n \n "<<endl;
		}
		break;
		case 2 :
		{
		    system("cls");
		    cout<<"  {[ 2.Ajouter plusieurs Salles a la fois ]}  "<<endl<<endl;
		    int cp;
		    Salle sa;
		    cout<<"entrer le nbre de salle :";
		    cin>>cp;
		  
		    for(int i=0 ; i<cp ; i++)
			{
				sa.DonneesSalle();
				ajouterSalle(sa);
			}
 	        cout<<"\n \n \n \n "<<endl;
		}
		break;	
		case 3 :
		{
			system("cls");
			cout<<"  {[ 3.Afficher une salle ]}  "<<endl<<endl;
			string nom;
		    cout<<"entrer le nom de la salle :";
		    cin>>nom;
		    affichersalle(nom);
			cout<<"\n \n \n \n "<<endl;
 		}
		break;	
		case 4 :
		{
			system("cls");
			cout<<"  {[ 4.Afficher plusieurs salles ]}  "<<endl<<endl;
			affichersalles();
 	        cout<<"\n \n \n \n "<<endl;

		}
		break;	
		case 5 :
		{
			system("cls");
			cout<<"  {[ 5.Supprimer salle ]}  "<<endl<<endl;
			string nom;
			cout<<"entrer le nom de la salle :";
		    cin>>nom;
			suppSalle(nom);
			cout<<"\n \n \n \n "<<endl;
		}
		break;			
	}//fin switch gestSalle
    }while(gestSalle!=6);
	}//fin case 3
	break;
	
	
    case 4 :
    {	
    int gestP=0;
    system("cls");
	do{
    cout<<"=========================================="<<endl;
    cout<<"\t ---GESTION Des Parties--- "<<endl;
 	cout<<"\t 1.Creer premieres parties"<<endl;
 	cout<<"\t 2.Creer les parties du next round"<<endl;
 	cout<<"\t 3.Afficher les donnees de toutes les parties"<<endl;
 	cout<<"\t 4.Afficher les donnees d'une seule partie"<<endl;
 	cout<<"\t 5.Enregistrer les resultats d'une partie"<<endl;
 	cout<<"\t 6.Saisir decision en cas de litige"<<endl;
 	cout<<"\t 7.Retour au menu principale"<<endl;
 	cout<<"=========================================="<<endl;
 	cout<<"Choisissez : -> ";  cin>>gestP;
 	switch(gestP)
 	{
	    case 1 :
	    {
	    system("cls");
	    cout<<"  {[ 1.Creer premieres parties ]}  "<<endl;
	    creerParties();
		cout<<"\n \n \n \n "<<endl;
	    }
	    break;
	    case 2 :
	    {
	    system("cls");	
	 	cout<<"  {[ 2.Creer les parties du next round ]}  "<<endl;
	 	PartiesDuNextRound();
		cout<<"\n \n \n \n "<<endl;	
	    }
	    break;
	    case 3 :
	    {
	    system("cls");	
	 	cout<<"  {[ 3.Afficher les donnees de toutes les parties ]}  "<<endl;
	 	affToutesLesParties();
		cout<<"\n \n \n \n "<<endl;	
	    }
	    break;
	    case 4 :
	    {
	    system("cls");	
	 	cout<<"  {[ 4.Afficher les donnees d'une seule partie ]}  "<<endl;
	 	int m;
	 	cout<<"Entrer le num de la partie souhaitee afficher ces donnees"<<endl;
	 	cin>>m;
	 	affpartienum(m);
		cout<<"\n \n \n \n "<<endl;	
	    }
	    break;
	    case 5 :
	    {
	    system("cls");	
	 	cout<<"  {[ 5.Enregistrer les resultats d'une partie ]}  "<<endl;
	 	int f;
	 	cout<<"Entrer le num de la partie souhaitee "<<endl;
	 	cin>>f;
	 	resultats_Partie(f);
		cout<<"\n \n \n \n "<<endl;	
	    }
	    break;
	    case 6 :
	    {
	    system("cls");	
	 	cout<<"  {[ 6.Saisir decision en cas de litige ]}  "<<endl;
	 	int M;
	 	cout<<"Entrer le num de la partie "<<endl;
	 	cin>>M;
		 litige(M);
		cout<<"\n \n \n \n "<<endl;	
	    }
	    break;
	    
	}//fin switch gestParties
	
	}while(gestP <7);
    }//fin case 4
	break;
	
    case 5 :
    {
	exit(0);
	}//fin case 5
    break;
   
   	}//end switch choix
	
	}while(choix != 4);
		
	}