/*************************************************************************
 TrajetCompose  -  description
-------------------
début                : 29/11/2018
copyright            : (C) 2018 par Ludivine K. et Lucie C.
e-mail               : kupiec.ludivine@gmail.com lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------

#if !defined (TrajetCompose_H)
#define TrajetCompose_H

//--------------------------------------------------- Interfaces utilisées"

#include "Trajet.h"
#include "tabTrajets.h"
#include "TrajetSimple.h"
#include <string.h>

class tabTrajets;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Implémenter un Trajet qui est composé de plusieurs Trajets, simples ou
// eux-mêmes composés. Pour des raisons de facilité, ici, on aura que des 
// TrajetCompose composés de TrajetSimple.
//------------------------------------------------------------------------

class TrajetCompose : public Trajet {

	//----------------------------------------------------------------- PUBLIC

public:

	//----------------------------------------------------- Méthodes publiques

	virtual void Affichage();
	// Mode d'emploi :
	// ...

	int getType();
	// Mode d'emploi :
	// A appeler quand on veut différencier un TrajetSimple d'un TrajetCompose

	
	//------------------------------------------------- Surcharge d'opérateurs
	
	friend istream & operator >> ( istream & is, TrajetCompose & t );

	friend ostream & operator << ( ostream & os, const TrajetCompose & t );

	//-------------------------------------------- Constructeurs - destructeur

	TrajetCompose(const char* villeA, const char* villeB, tabTrajets *tab);

	// Mode d'emploi (constructeur standard) :
	// Seul constructeur de TrajetCompose.
	// Contrat :
	// Le tableau de trajets doit avoir été instancié au préalable. 

	virtual ~TrajetCompose();

	// Mode d'emploi :
	// A appeler si on a un pointeur sur Trajet* ou TrajetCompose*.
	// C'est le cas notamment dans la classe tabTrajets.

	//------------------------------------------------------------------ PRIVE

protected:

	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

	tabTrajets *tabTraj;

};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TrajetCompose_H
