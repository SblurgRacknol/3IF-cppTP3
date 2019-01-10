/*************************************************************************
 tabTrajets  -  description
-------------------
d�but                : 29/11/2018
copyright            : (C) 2018 par Ludivine K. et Lucie C.
e-mail               : kupiec.ludivine@gmail.com lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <tabTrajets> (fichier tabTrajets.h) ----------------

#if !defined (tabTrajets_H)
#define tabTrajets_H

//--------------------------------------------------- Interfaces utilis�es

#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

const int NBMAX = 2;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

// R�le de la classe <tabTrajets>
// Gestion d'un tableau de trajets pouvant �tre simples ou compos�s. Permet de :
// - Ajouter des trajets, simples ou compos�s
// - Afficher les trajets contenus dans le tableau courant
// - Rechercher un parcours via une m�thode simple
// - Rechercher un parcours via une m�thode plus complexe

//------------------------------------------------------------------------

class tabTrajets {

	//----------------------------------------------------------------- PUBLIC

	public:

	//----------------------------------------------------- M�thodes publiques
	
	/*
     * Ajoute un trajet � tabTraj	
     */
	void Ajouter(Trajet* traj);
	
	/*
     * R�alloue deux fois la m�moire allou�e actuellement. 
     * Appelle correctement le destructeur. 		
     */
	void Reallouer();
	
	/*
     * V�rifie si le trajet simple pass� en param�tre peut �tre ajout� � la fin 
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

	//----------------------------------------------------- Attributs prot�g�s

	int nbMax; // cardinalit� maximum du tableau
	int nbAct; // cardinalit� actuelle du tableau 
	Trajet **tab; // Tableau de pointeurs de Trajet

};


#endif // tabTrajets_H
