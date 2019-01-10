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
// Implémenter un Trajet qui est composé de plusieurs trajets simples.
//------------------------------------------------------------------------

class TrajetCompose : public Trajet 
{

	//----------------------------------------------------------------- PUBLIC
	public:

	//----------------------------------------------------- Méthodes publiques
	
	/*
     * Retourne une copie en profondeur du trajet composé
     */
    Trajet * Copie ( ) const ;
    
    /*
     * Affiche dans la sortie standard les informations du trajet composé
     */
	virtual void Affichage();
	
	/*
	* Retourne 1 puisque le trajet considéré est composé
	*/
	int getType();
	
	/*
	* Modifie les informations du trajet courant par celles entrées dans le flux
	* passé en paramètre
	*/
	void Lire ( istream & is );
	
	/*
	* Ecrit les informations du trajet courant dans le flux passé en paramètre
	*/
	void Ecrire ( ostream & os );
	

	//-------------------------------------------- Constructeurs - destructeur

	TrajetCompose ( const string villeA, const string villeB, tabTrajets * tab );
	TrajetCompose ( const TrajetCompose & t );

	virtual ~TrajetCompose();

	//------------------------------------------------------------------ PRIVE

	protected:

	//----------------------------------------------------- Attributs protégés

	tabTrajets *tabTraj;

};


#endif // TrajetCompose_H
