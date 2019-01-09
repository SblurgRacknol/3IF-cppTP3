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

//--------------------------------------------------- Interfaces utilis�es"

#include "Trajet.h"
#include "tabTrajets.h"
#include "TrajetSimple.h"
#include <string.h>

class tabTrajets;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

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
	// Mode d'emploi :
	// ...

	int getType();
	// Mode d'emploi :
	// A appeler quand on veut diff�rencier un TrajetSimple d'un TrajetCompose

	
	//------------------------------------------------- Surcharge d'op�rateurs
	
	friend istream & operator >> ( istream & is, TrajetCompose & t );

	friend ostream & operator << ( ostream & os, const TrajetCompose & t );

	//-------------------------------------------- Constructeurs - destructeur

	TrajetCompose(const char* villeA, const char* villeB, tabTrajets *tab);

	// Mode d'emploi (constructeur standard) :
	// Seul constructeur de TrajetCompose.
	// Contrat :
	// Le tableau de trajets doit avoir �t� instanci� au pr�alable. 

	virtual ~TrajetCompose();

	// Mode d'emploi :
	// A appeler si on a un pointeur sur Trajet* ou TrajetCompose*.
	// C'est le cas notamment dans la classe tabTrajets.

	//------------------------------------------------------------------ PRIVE

protected:

	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

	tabTrajets *tabTraj;

};

//-------------------------------- Autres d�finitions d�pendantes de <TrajetCompose>

#endif // TrajetCompose_H
