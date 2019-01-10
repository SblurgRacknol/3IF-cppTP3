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

//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"
#include "tabTrajets.h"
#include "TrajetSimple.h"
#include <string>
#include <iostream>
using namespace std;

class tabTrajets;

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

	int getType();
	// Retourne 0 si le trajet est un TrajetSimple, 1 si c'est un TrajetCompose
	
	void Lire ( istream & is );
	void Ecrire ( ostream & os );
	

	//-------------------------------------------- Constructeurs - destructeur

	TrajetCompose ( const string villeA, const string villeB, tabTrajets * tab );

	// Constructeur standard
	// Le tableau de trajets doit avoir été instancié au préalable. 
	
	TrajetCompose ( const TrajetCompose & t );
	// Constructeur de copie

	virtual ~TrajetCompose();

	// Destructeur

	//------------------------------------------------------------------ PRIVE

	protected:

	//----------------------------------------------------- Attributs protégés

	tabTrajets *tabTraj;

};


#endif // TrajetCompose_H
