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
	
	/*
     * Retourne une copie en profondeur du trajet simple
     */
    Trajet * Copie ( ) const;

	/*
     * Affiche dans la sortie standard les informations du trajet simple
     */
	virtual void Affichage();

	/*
	* Retourne 0 puisque le trajet considéré est simple
	*/
	virtual int getType();

	/*
	* Modifie les informations du trajet courant par celles entrées dans le flux
	* passé en paramètre
	*/
	void Lire ( istream & is );
	
	/*
	* Ecrit les informations du trajet courant dans le flux passé en paramètre
	*/
	void Ecrire ( ostream & os );

	//friend class TrajetCompose;

	//-------------------------------------------- Constructeurs - destructeur

	TrajetSimple( const string villeD, const string villeA, const string moyenT );

	TrajetSimple( const TrajetSimple &t );

	virtual ~TrajetSimple( );


	//------------------------------------------------------------------ PRIVE
	protected:

	//----------------------------------------------------- Attributs protégés

	string moyenTransport;

};

#endif // TrajetSimple_H
