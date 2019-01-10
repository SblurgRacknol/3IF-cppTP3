/*************************************************************************
 TrajetSimple  -  description
-------------------
début                : 29/11/2018
copyright            : (C) 2018 par Ludivine K. et Lucie C.
e-mail               : kupiec.ludivine@gmail.com lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h)

#if ! defined (TrajetSimple_H)
#define TrajetSimple_H

//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"
#include "TrajetSimple.h"
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

// Rôle de la classe <TrajetSimple>
// Implémentation de trajets simples, c'est-à-dire de trajets directs 
// (en une seule étape) ayant pour attribut un moyen de transport. 

//------------------------------------------------------------------------

class TrajetSimple : public Trajet {

	//----------------------------------------------------------------- PUBLIC

	public:

	//----------------------------------------------------- Méthodes publiques
	
	virtual void Affichage();

	virtual int getType();
	// Retourne 0 si le trajet est un TrajetSimple, 1 si c'est un TrajetCompose

	void Lire ( istream & is );
	void Ecrire ( ostream & os );

	friend class TrajetCompose; //A MODIFIER SI NECESSAIRE

	//-------------------------------------------- Constructeurs - destructeur

	TrajetSimple(const string villeD, const string villeA, const string moyenT);
	// Constructeur standard

	TrajetSimple(const TrajetSimple &t);
	// Constructeur de copie

	virtual ~TrajetSimple();
	// Destructeur


	//------------------------------------------------------------------ PRIVE
	protected:

	//----------------------------------------------------- Attributs protégés

	string moyenTransport;

};


#endif // TrajetSimple_H
