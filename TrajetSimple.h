/*************************************************************************
 TrajetSimple  -  description
-------------------
d�but                : 29/11/2018
copyright            : (C) 2018 par Ludivine K. et Lucie C.
e-mail               : kupiec.ludivine@gmail.com lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h)

#if ! defined (TrajetSimple_H)
#define TrajetSimple_H

//--------------------------------------------------- Interfaces utilis�es

#include "Trajet.h"
#include "TrajetSimple.h"
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

// R�le de la classe <TrajetSimple>
// Impl�mentation de trajets simples, c'est-�-dire de trajets directs 
// (en une seule �tape) ayant pour attribut un moyen de transport. 

//------------------------------------------------------------------------

class TrajetSimple : public Trajet {

	//----------------------------------------------------------------- PUBLIC

	public:

	//----------------------------------------------------- M�thodes publiques
	
	/*
     * Retourne une copie en profondeur du trajet simple
     */
    Trajet * Copie ( ) const;

	/*
     * Affiche dans la sortie standard les informations du trajet simple
     */
	virtual void Affichage();

	/*
	* Retourne 0 puisque le trajet consid�r� est simple
	*/
	virtual int getType();

	/*
	* Modifie les informations du trajet courant par celles entr�es dans le flux
	* pass� en param�tre
	*/
	void Lire ( istream & is );
	
	/*
	* Ecrit les informations du trajet courant dans le flux pass� en param�tre
	*/
	void Ecrire ( ostream & os );

	//friend class TrajetCompose;

	//-------------------------------------------- Constructeurs - destructeur

	TrajetSimple( const string villeD, const string villeA, const string moyenT );

	TrajetSimple( const TrajetSimple &t );

	virtual ~TrajetSimple( );


	//------------------------------------------------------------------ PRIVE
	protected:

	//----------------------------------------------------- Attributs prot�g�s

	string moyenTransport;

};

#endif // TrajetSimple_H
