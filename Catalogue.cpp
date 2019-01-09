/*************************************************************************
 Catalogue  -  description
-------------------
d�but                : 29/11/2018
copyright            : (C) 2018 par Ludivine K. et Lucie C.
e-mail               : kupiec.ludivine@gmail.com lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//------------------------------------------------------ Include personnel

#include "Catalogue.h"
#include "tabTrajets.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

final char SEP = '|';

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

void Catalogue::rechercheVoyage(char* villeD, char* villeA) {
	
	int cpt = 0;

	for (int i = 0; i < tab->getNbAct(); i++) {
		if (0 == strcmp(villeD, tab->getTrajet(i)->getVilleDepart())) {
			if (0 == strcmp(villeA, tab->getTrajet(i)->getVilleArrivee())) {
				tab->getTrajet(i)->Affichage();
				cpt++;
			}
		}
	}	

	cout << cpt << " r�sultats de recherche." << endl;
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


int compterTrajets (string nomFichier)
{
	int nbTraj = 0;
	ifstream flux ( nomFichier, ios::in );
	if ( flux )
	{
		string ligne;
		int taille = 0;
		
		// Parcours du fichier en comptant les trajets
		while ( !flux.eof() )
		{
			getline ( flux, ligne, SEP );
			if ( ligne == "0" )
			{
				nbTraj++;
				// D�placement � la ligne suivante
				getline ( flux, ligne );
			}
			else if ( ligne == "1" )
			{
				nbTraj++;
				getline ( flux, ligne, SEP ); 
				taille = atoi ( ligne ); // A RAJOUTER : v�rification du format
				
				// D�placement � la ligne suivante autant de fois qu'il y a de 
				// trajets simples dans le trajet compos�
				for ( int i=0 ; i<=taille ; i++ ) 
				{
					getline ( flux, ligne );
				}
				// QUESTION : est-ce que le curseur est au bon endroit ? </<=  
				taille = 0;
			}
			else
			{
				cerr << "Le fichier n'a pas le bon format." << endl;
			}
			
		}
		
		flux.close();
	}
	else
	{
		cerr << "Impossible d'ouvrir le fichier." << endl;
	}
	return nbTraj;
}


void Catalogue::Sauvegarder (string nomFichier)
{
	

}
void Catalogue::Charger (string nomFichier)
{
	string fichier = "";
	do 
	{
		cout << "Entrer le chemin d'acc�s du fichier � charger." << endl;
		cin >> fichier ;
	}
	while ( fichier == "" );
	ifstream flux ( fichier, ios::in );
	
	
	if ( flux )
	{
		tabTrajets ajouts = new tabTrajets ( compterTrajets ( nomFichier ) );
		string ligne;
		while ( !flux.eof() )
		{
			getline ( flux, ligne, SEP );
			if ( ligne == "0" )
			{
				TrajetSimple t;
				flux >> t; // Est-il besoin de mettre un new ? + plusieurs instances de t si on repasse par l�...
				ajouts->Ajouter(&t);
			}
			else if ( ligne == "1" )
			{
				TrajetCompose t;
				flux >> t; // Est-il besoin de mettre un new ?
				ajouts->Ajouter(&t);
			}
			else
			{
				cerr << "Erreur : le fichier n'a pas le bon format" << endl;
				flux.seekg (0, ios::end+1 ) ; 
				//La condition de fin de while est remplie
			}
			//si caract�re = 0, on lit la ligne dans un trajet simple et on l'ajoute
			//si =1 , on ajoute un traj comp
			//sinon, message d'erreur "Erreur : le fichier n'a pas le bon format"
		}
		for (int i=0 ; i<ajouts.nbAct ; i++ )
		{
			tab -> Ajouter ( ajouts[i] );
		}
		ajouts.delete();
		flux.close();
	}
	
	else
	{
		cerr << "Impossible d'ouvrir le fichier." << endl;
	}
		
}


//------------------------------------------------- Surcharge d'op�rateurs

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


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

