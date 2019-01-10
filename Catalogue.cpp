/*************************************************************************
 Catalogue  -  description
-------------------
début                : 29/11/2018
copyright            : (C) 2018 par Ludivine K. et Lucie C.
e-mail               : kupiec.ludivine@gmail.com lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <cstring>
#include <fstream>

using namespace std;

//------------------------------------------------------ Include personnel

#include "Catalogue.h"
#include "tabTrajets.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

const char SEP = '|';

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::rechercheVoyage(char* villeD, char* villeA) {
	
	int cpt = 0;

	for (int i = 0; i < tab->getNbAct(); i++) {
		if ( villeD == tab->getTrajet(i)->getVilleDepart() ) {
			if ( villeA == tab->getTrajet(i)->getVilleArrivee() ) {
				tab->getTrajet(i)->Affichage();
				cpt++;
			}
		}
	}	

	cout << cpt << " résultats de recherche." << endl;
}

void Catalogue::Ajouter(TrajetCompose* traj) {
	tab->Ajouter(traj);
}

void Catalogue::Ajouter(TrajetSimple* traj) {
	tab->Ajouter(traj);
}


void Catalogue::Affichage() {
	cout << "Affichage du catalogue." << endl;
	tab->Affichage();
}

void Catalogue::Sauvegarder (string nomFichier)
{
	/*string fichier = "";
	do 
	{
		cout << "Entrer le chemin d'accès du fichier à charger." << endl;
		cin >> fichier ;
	}
	while ( fichier == "" );*/
	ofstream flux ( nomFichier.c_str(), ios::out | ios::trunc );
	if ( flux )
	{
		for ( int i=0 ; i<tab->getNbAct() ; i++ )
		{
			 tab->getTrajet(i)->Ecrire(flux) ; 
		}
	
	}
	else
	{
		cerr << "Erreur à l'ouverture du fichier" << endl;
	}

}
void Catalogue::Charger(string nomFichier)
{
	
	ifstream flux ( nomFichier.c_str(), ios::in );
	
	if ( flux )
	{
		tabTrajets * ajouts = new tabTrajets ( );
		string ligne;
		TrajetSimple * baseSimple = new TrajetSimple ("a","b","");
		tabTrajets  *baseTab = new tabTrajets ();
		baseTab->Ajouter (baseSimple);
		TrajetCompose * baseCompose = new TrajetCompose ( "a","b", baseTab );
		
		while ( !flux.eof() )
		{
			
			getline ( flux, ligne, SEP );

			if ( ligne == "0" )
			{
				cout << "Je passe ici, car ligne vaut " << ligne << " ! ";
				ajouts->Ajouter ( new TrajetSimple (*baseSimple) );
				ajouts->getTrajet(ajouts->getNbAct() - 1)->Lire(flux);
			}
			else if ( ligne == "1" )
			{
				cout << "Je passe ici, car ligne vaut " << ligne << " ! ";
				ajouts->Ajouter ( new TrajetCompose (*baseCompose) );
				ajouts->getTrajet(ajouts->getNbAct() - 1)->Lire(flux);
			}
			else
			{
				cout << "Je passe ici, car ligne vaut " << ligne << " ! ";
				cerr << "Erreur : le fichier n'a pas le bon format" << endl;
				flux.seekg (0, flux.end + 1) ;

				//La condition de fin de while est remplie
			}

			cout << ajouts->getNbAct() << endl;

			//si caractère = 0, on lit la ligne dans un trajet simple et on l'ajoute
			//si =1 , on ajoute un traj comp
			//sinon, message d'erreur "Erreur : le fichier n'a pas le bon format"
		}
		for (int i=0 ; i<ajouts->getNbAct() ; i++ )
		{
			tab -> Ajouter ( ajouts->getTrajet(i) );
		}

		flux.close();

		delete baseCompose;
		delete ajouts;
	}
	
	else
	{
		cerr << "Impossible d'ouvrir le fichier." << endl;
	}
}

//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue() {
	// Algorithme :
	//

#ifdef MAP
	cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

	tab = new tabTrajets();

} //----- Fin de Catalogue


Catalogue::~Catalogue() {
	// Algorithme :
	//

#ifdef MAP
	cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

	delete tab;

} //----- Fin de ~Catalogue

