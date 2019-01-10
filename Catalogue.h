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

// Rôle de la classe <Catalogue>
// Classe générique implémentant des méthodes propres à un ensemble de Trajets
// - Recherche de trajets
// - Affichage
// - Sauvegarde
// - Chargement

//------------------------------------------------------------------------

class Catalogue {

	//----------------------------------------------------------------- PUBLIC

	public:

	//----------------------------------------------------- Méthodes publiques
	
	/*
     * Affiche dans la sortie standard le résultat d'une recherche portant sur 
     * les trajets possibles pour aller de villeD à villeA après parcours du 
     * catalogue
     */
	void rechercheVoyage(string villeD, string villeA);
	
	/*
     * Ajoute un trajet simple traj au catalogue		
     */
	void Ajouter(TrajetSimple* traj);		
	
	/*
     * Ajoute un trajet compose traj au catalogue	
     * On suppose le trajet composé conforme au format demandé	
     */
	void Ajouter(TrajetCompose* traj);
	
	/*
     * Affiche dans la sortie standard les informations du catalogue
     */
	void Affichage();
	
	/*
     * Sauvegarde le catalogue dans un fichier
     * nomFichier est le chemin d'accès au fichier de sauvegarde
     */	
	void Sauvegarder (string nomFichier);
	
	/*
     * Ajoute au catalogue les trajets présents dans un fichier de sauvegarde 
     * nomFichier est le chemin d'accès au fichier de sauvegarde
     * Contrat : on considère que le fichier est conforme au format
     */	
	void Charger (string nomFichier);


	//-------------------------------------------- Constructeurs - destructeur
	/*
     * Crée un nouveau catalogue vide
     */	
	Catalogue();
	
	virtual ~Catalogue();

	//------------------------------------------------------------------ PRIVE

	protected:

	//----------------------------------------------------- Attributs protégés

	tabTrajets *tab;

};

#endif // Catalogue_H
