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

	void Ajouter(Trajet* traj);
	// Mode d'emploi :
	// Ajoute traj � son tableau de pointeur
	// Contrat :
	// La r�allocation n'est appell�e nul part ailleurs


	void Reallouer();
	// Mode d'emploi :
	// Est appel� uniquement par Ajouter(Trajet* traj). R�alloue deux fois la m�moire
	// allou�e actuellement. Appelle correctement le destructeur. 

	bool isCoherent(TrajetSimple *ts);
	// Mode d'emploi :
	// V�rifie si le trajet pass� en param�tre peut �tre ajout� � la fin de l'instance
	// actuelle
	// Contrat :
	// Comme sp�cifi� dans le main, les trajets composant un trajet compos� doivent �tre
	// entr�s dans l'ordre

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

	//------------------------------------------------- Surcharge d'op�rateurs

	//-------------------------------------------- Constructeurs - destructeur

	tabTrajets();

	// Mode d'emploi : constructeur par d�faut
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

	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

	int nbMax; // cardinalit� maximum du tableau
	int nbAct; // cardinalit� actuelle du tableau (nombre d'�l�ments actuellement contenus)
	Trajet **tab; // Tableau de pointeurs de Trajet

};

//-------------------------------- Autres d�finitions d�pendantes de <tabTrajets>

#endif // tabTrajets_H
