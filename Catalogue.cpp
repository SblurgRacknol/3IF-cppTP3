/*************************************************************************
 Catalogue  -  description
-------------------
début                : 29/11/2018
copyright            : (C) 2018 par Ludivine K.
e-mail               : kupiec.ludivine@gmail.com
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//------------------------------------------------------ Include personnel

#include "Catalogue.h"
#include "tabTrajets.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

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
	

}
void Catalogue::Charger (string nomFichier)
{
	string fichier = "";
	do 
	{
		cout << "Entrer le chemin d'accès du fichier à charger." << endl;
		cin >> fichier ;
	}
	while ( fichier == "" );
	ifstream flux ( fichier, ios::in );
	
	final char SEP = '|';
	
	if ( flux )
	{
		tabTrajets ajouts = new tabTrajets();
		char pos;
		while ( !flux.eof() )
		{
			getline ( flux, pos, SEP );
			if ( pos == '0' )
			{
				TrajetSimple t;
				flux >> t; // Est-il besoin de mettre un new ? + plusieurs instances de t si on repasse par là...
				ajouts->Ajouter(&t);
			}
			else if ( pos == '1' )
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
			//si caractère = 0, on lit la ligne dans un trajet simple et on l'ajoute
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

//------------------------------------------------- Surcharge d'opérateurs

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

//----------------------------------------------------- Méthodes protégées

