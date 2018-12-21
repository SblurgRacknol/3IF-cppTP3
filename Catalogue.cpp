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

// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Catalogue::Affichage() {
	cout << "Affichage du catalogue." << endl;
	tab->Affichage();
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

