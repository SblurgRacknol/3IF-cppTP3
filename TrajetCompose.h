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
// Impl�menter un Trajet qui est compos� de plusieurs trajets simples.
//------------------------------------------------------------------------

class TrajetCompose : public Trajet 
{

	//----------------------------------------------------------------- PUBLIC
	public:

	//----------------------------------------------------- M�thodes publiques
	
	/*
     * Retourne une copie en profondeur du trajet compos�
     */
    Trajet * Copie ( ) const ;
    
    /*
     * Affiche dans la sortie standard les informations du trajet compos�
     */
	virtual void Affichage();
	
	/*
	* Retourne 1 puisque le trajet consid�r� est compos�
	*/
	int getType();
	
	/*
	* Modifie les informations du trajet courant par celles entr�es dans le flux
	* pass� en param�tre
	*/
	void Lire ( istream & is );
	
	/*
	* Ecrit les informations du trajet courant dans le flux pass� en param�tre
	*/
	void Ecrire ( ostream & os );
	

	//-------------------------------------------- Constructeurs - destructeur

	TrajetCompose ( const string villeA, const string villeB, tabTrajets * tab );
	TrajetCompose ( const TrajetCompose & t );

	virtual ~TrajetCompose();

	//------------------------------------------------------------------ PRIVE

	protected:

	//----------------------------------------------------- Attributs prot�g�s

	tabTrajets *tabTraj;

};


#endif // TrajetCompose_H
