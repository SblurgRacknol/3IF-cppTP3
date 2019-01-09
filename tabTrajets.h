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

	void Ajouter(Trajet* traj);
	// Mode d'emploi :
	// Ajoute traj à son tableau de pointeur
	// Contrat :
	// La réallocation n'est appellée nul part ailleurs


	void Reallouer();
	// Mode d'emploi :
	// Est appelé uniquement par Ajouter(Trajet* traj). Réalloue deux fois la mémoire
	// allouée actuellement. Appelle correctement le destructeur. 

	bool isCoherent(TrajetSimple *ts);
	// Mode d'emploi :
	// Vérifie si le trajet passé en paramètre peut être ajouté à la fin de l'instance
	// actuelle
	// Contrat :
	// Comme spécifié dans le main, les trajets composant un trajet composé doivent être
	// entrés dans l'ordre

	void Affichage();
	// Mode d'emploi :
	// ...


	//---------------------------------------------------- Getteurs & Setteurs

	int getNbAct() const;
	// Mode d'emploi :
	// Retourn nbAct

	Trajet* getTrajet(int i) const;
	// Mode d'emploi :
	// Retourne le pointeur sur Trajet d'indice i

	int getType(int i) const;
	// Mode d'emploi :
	// Retourne le type de Trajet du pointeur d'indice i

	int getNbMax() const;

	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur

	tabTrajets();

	// Mode d'emploi : constructeur par défaut
	// 

	tabTrajets(const tabTrajets &unTabTrajets);

	tabTrajets(int nbTraj);

	virtual ~tabTrajets();

	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE

protected:

	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

	int nbMax; // cardinalité maximum du tableau
	int nbAct; // cardinalité actuelle du tableau (nombre d'éléments actuellement contenus)
	Trajet **tab; // Tableau de pointeurs de Trajet

};

//-------------------------------- Autres définitions dépendantes de <tabTrajets>

#endif // tabTrajets_H
