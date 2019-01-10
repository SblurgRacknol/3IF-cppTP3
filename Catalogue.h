/*************************************************************************
 Catalogue  -  description
-------------------
d�but                : 29/11/2018
copyright            : (C) 2018 par Ludivine K. et Lucie C.
e-mail               : kupiec.ludivine@gmail.com lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------

#if !defined (Catalogue_H)
#define Catalogue_H

//--------------------------------------------------- Interfaces utilis�es

#include "Trajet.h"
#include "tabTrajets.h"
#include <string>
#include <iostream>
using namespace std;

// R�le de la classe <Catalogue>
// Classe g�n�rique impl�mentant des m�thodes propres � un ensemble de Trajets
// - Recherche de trajets
// - Affichage
// - Sauvegarde
// - Chargement

//------------------------------------------------------------------------

class Catalogue {

	//----------------------------------------------------------------- PUBLIC

	public:

	//----------------------------------------------------- M�thodes publiques
	
	/*
     * Affiche dans la sortie standard le r�sultat d'une recherche portant sur 
     * les trajets possibles pour aller de villeD � villeA apr�s parcours du 
     * catalogue
     */
	void rechercheVoyage(string villeD, string villeA);
	
	/*
     * Ajoute un trajet simple traj au catalogue		
     */
	void Ajouter(TrajetSimple* traj);		
	
	/*
     * Ajoute un trajet compose traj au catalogue	
     * On suppose le trajet compos� conforme au format demand�	
     */
	void Ajouter(TrajetCompose* traj);
	
	/*
     * Affiche dans la sortie standard les informations du catalogue
     */
	void Affichage();
	
	/*
     * Sauvegarde le catalogue dans un fichier
     * nomFichier est le chemin d'acc�s au fichier de sauvegarde
     */	
	void Sauvegarder (string nomFichier);
	
	/*
     * Ajoute au catalogue les trajets pr�sents dans un fichier de sauvegarde 
     * nomFichier est le chemin d'acc�s au fichier de sauvegarde
     * Contrat : on consid�re que le fichier est conforme au format
     */	
	void Charger (string nomFichier);


	//-------------------------------------------- Constructeurs - destructeur
	/*
     * Cr�e un nouveau catalogue vide
     */	
	Catalogue();
	
	virtual ~Catalogue();

	//------------------------------------------------------------------ PRIVE

	protected:

	//----------------------------------------------------- Attributs prot�g�s

	tabTrajets *tab;

};

#endif // Catalogue_H
