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

void Catalogue::rechercheVoyage( string villeD, string villeA ) 
{
	
	int cpt = 0;

	for (int i = 0; i < tab->getNbAct( ); i++) 
	{
		if ( villeD == tab->getTrajet(i)->getVilleDepart( ) ) 
		{
			if ( villeA == tab->getTrajet(i)->getVilleArrivee( ) ) 
			{
				tab->getTrajet(i)->Affichage( );
				cpt++;
			}
		}
	}	

	cout << cpt << " résultats de recherche." << endl;
}

void Catalogue::Ajouter(TrajetCompose* traj) 
{
	tab->Ajouter(traj);
}

void Catalogue::Ajouter(TrajetSimple* traj) 
{
	tab->Ajouter(traj);
}


void Catalogue::Affichage( ) 
{
	cout << "Affichage du catalogue." << endl;
	tab->Affichage();
}

void Catalogue::Sauvegarder (string nomFichier)
{
		ofstream flux ( nomFichier.c_str(), ios::out | ios::trunc );

	if ( flux )
	{
		for ( int i=0 ; i<tab->getNbAct(); i++ )
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
		string ligne;
		TrajetSimple * baseSimple = new TrajetSimple ("a","b","");
		tabTrajets * baseTab = new tabTrajets ();
		baseTab->Ajouter (baseSimple);
		TrajetCompose * baseCompose = new TrajetCompose ( "a","b", baseTab );
		
		while ( !flux.eof() )
		{
			getline ( flux, ligne, SEP );

			if ( ligne == "0" )
			{
				tab->Ajouter ( new TrajetSimple (*baseSimple) );
				tab->getTrajet( tab->getNbAct()-1 )->Lire(flux);
			}
			else if ( ligne == "1" )
			{
				tab->Ajouter ( new TrajetCompose (*baseCompose) );
				tab->getTrajet(tab->getNbAct() - 1)->Lire(flux);
			}

			//si la ligne commence par 0, on ajoute un trajet simple.
			//sinon, si la ligne commence par 1, on ajoute un trajet composé
			//on considère que le fichier a forcément le bon format
		}
		flux.close();

		delete baseCompose;
	}
	
	else
	{
		cerr << "Impossible d'ouvrir le fichier." << endl;
	}
}

//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue() 
{
#ifdef MAP
	cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

	tab = new tabTrajets();

} //----- Fin de Catalogue


Catalogue::~Catalogue() 
{
#ifdef MAP
	cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

	delete tab;

} //----- Fin de ~Catalogue

