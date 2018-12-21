/*************************************************************************
                           Gestionnaire  -  description
                             -------------------
    début                : 21/12/2018
    copyright            : (C) 2018 par KUPIEC Ludivine et CLEMENCEAU Lucie
    e-mail               : ludivine.kupiec@insa-lyon.fr lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Gestionnaire> (fichier Gestionnaire.h) ----------------
#if ! defined ( GESTIONNAIRE_H )
#include <fstream.h>
#include <string.h>
#define GESTIONNAIRE_H


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Gestionnaire>
//
//
//------------------------------------------------------------------------

class Gestionnaire
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	bool lisible( const string & unFichier );
    void sauvegarder ( string & unFichier ); 
    void charger ( const string & unFichier );


//------------------------------------------------- Surcharge d'opérateurs
    Gestionnaire & operator = ( const Gestionnaire & unGestionnaire );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Gestionnaire ( const Gestionnaire & unGestionnaire );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Gestionnaire ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Gestionnaire ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	fstream monFichier;

};

//-------------------------------- Autres définitions dépendantes de <Gestionnaire>

#endif // GESTIONNAIRE_H
