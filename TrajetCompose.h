/*************************************************************************
 TrajetCompose  -  description
-------------------
d�but                : 29/11/2018
copyright            : (C) 2018 par Ludivine K. et Lucie C.
e-mail               : kupiec.ludivine@gmail.com lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------

#if !defined (TrajetCompose_H)
#define TrajetCompose_H

//--------------------------------------------------- Interfaces utilis�es

#include "Trajet.h"
#include "tabTrajets.h"
#include "TrajetSimple.h"
#include <string>
#include <iostream>
using namespace std;

class tabTrajets;

//------------------------------------------------------------------------
// R�le de la classe <TrajetCompose>
// Impl�menter un Trajet qui est compos� de plusieurs Trajets, simples ou
// eux-m�mes compos�s. Pour des raisons de facilit�, ici, on aura que des 
// TrajetCompose compos�s de TrajetSimple.
//------------------------------------------------------------------------

class TrajetCompose : public Trajet {

	//----------------------------------------------------------------- PUBLIC

	public:

	//----------------------------------------------------- M�thodes publiques

	virtual void Affichage();

	int getType();
	// Retourne 0 si le trajet est un TrajetSimple, 1 si c'est un TrajetCompose
	
	void Lire ( istream & is );
	void Ecrire ( ostream & os );
	

	//-------------------------------------------- Constructeurs - destructeur

	TrajetCompose ( const string villeA, const string villeB, tabTrajets * tab );

	// Constructeur standard
	// Le tableau de trajets doit avoir �t� instanci� au pr�alable. 
	
	TrajetCompose ( const TrajetCompose & t );
	// Constructeur de copie

	virtual ~TrajetCompose();

	// Destructeur

	//------------------------------------------------------------------ PRIVE

	protected:

	//----------------------------------------------------- Attributs prot�g�s

	tabTrajets *tabTraj;

};


#endif // TrajetCompose_H
