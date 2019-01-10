/*************************************************************************
 tabTrajets  -  description
-------------------
début                : 29/11/2018
copyright            : (C) 2018 par Ludivine K. et Lucie C.
e-mail               : kupiec.ludivine@gmail.com lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <tabTrajets> (fichier tabTrajets.h) ----------------

#if !defined (tabTrajets_H)
#define tabTrajets_H

//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

const int NBMAX = 2;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

// Rôle de la classe <tabTrajets>
// Gestion d'un tableau de trajets pouvant être simples ou composés. Permet de :
// - Ajouter des trajets, simples ou composés
// - Afficher les trajets contenus dans le tableau courant
// - Rechercher un parcours via une méthode simple
// - Rechercher un parcours via une méthode plus complexe

//------------------------------------------------------------------------

class tabTrajets {

	//----------------------------------------------------------------- PUBLIC

	public:

	//----------------------------------------------------- Méthodes publiques
	
	/*
     * Ajoute un trajet à tabTraj	
     */
	void Ajouter(Trajet* traj);
	
	/*
     * Réalloue deux fois la mémoire allouée actuellement. 
     * Appelle correctement le destructeur. 		
     */
	void Reallouer();
	
	/*
     * Vérifie si le trajet simple passé en paramètre peut être ajouté à la fin 
     * de l'instance actuelle
     */	
	bool isCoherent(TrajetSimple *ts);
	
	/*
     * Affiche dans la sortie standard les informations du tabTrajets
     */
	void Affichage();


	//---------------------------------------------------- Getters & Setters

	int getNbAct() const;

	Trajet* getTrajet(int i) const;

	int getType(int i) const;

	int getNbMax() const;


	//-------------------------------------------- Constructeurs - destructeur

	tabTrajets();

	tabTrajets(const tabTrajets &unTabTrajets);

	tabTrajets(int nbTraj);

	virtual ~tabTrajets();
	//------------------------------------------------------------------ PRIVE

	protected:

	//----------------------------------------------------- Attributs protégés

	int nbMax; // cardinalité maximum du tableau
	int nbAct; // cardinalité actuelle du tableau 
	Trajet **tab; // Tableau de pointeurs de Trajet

};


#endif // tabTrajets_H
