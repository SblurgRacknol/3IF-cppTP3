/*************************************************************************
 Catalogue  -  description
-------------------
début                : 29/11/2018
copyright            : (C) 2018 par Ludivine K. et Lucie C.
e-mail               : kupiec.ludivine@gmail.com lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------

#if !defined (Catalogue_H)
#define Catalogue_H

//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"
#include "tabTrajets.h"
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

// Rôle de la classe <Catalogue>
// Classe générique implémentant des méthodes propres à un ensemble de Trajets
// - Recherche de trajets
// - Affichage

//------------------------------------------------------------------------

class Catalogue {

	//----------------------------------------------------------------- PUBLIC

	public:

	//----------------------------------------------------- Méthodes publiques

	void rechercheVoyage(char* villeD, char* villeA);
	// Mode d'emploi :
	// Affiche les trajets possibles pour aller de villeD à villeA

	void Ajouter(TrajetSimple* traj);
	// Mode d'emploi :
	// Ajoute un trajet simple au catalogue		

	void Ajouter(TrajetCompose* traj);
	// Mode d'emploi :
	// Ajoute un trajet composé au catalogue
	// Contrat : 
	// On suppose le trajet composé conforme (vérifié dans le main)	
	void Affichage();
	// Mode d'emploi :
	// ...
		
	void Sauvegarder (string nomFichier);
	void Charger (string nomFichier);
	/*
     * Compte le nombre de trajets (simples et composés) dans un fichier
     * Retourne le nombre de trajets.
     */
	int compterTrajets (string nomFichier);

	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur

	Catalogue();

	// Mode d'emploi : constructeur par défaut
	// A appeler en début de fonction
	// tabTrajets a une taille maximale mais une cardinalité actuelle nulle

	virtual ~Catalogue();

	// Mode d'emploi : destructeur
	// Si catalogue est de type pointeur, à appeler avant la fin du bloc
	// où catalogue a été instancié

	//------------------------------------------------------------------ PRIVE

	protected:

	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

	tabTrajets *tab;

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H
