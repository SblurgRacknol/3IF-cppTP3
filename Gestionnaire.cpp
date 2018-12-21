/*************************************************************************
                           Gestionnaire  -  description
                             -------------------
    début                : 21/12/2018
    copyright            : (C) 2018 par KUPIEC Ludivine et CLEMENCEAU Lucie
    e-mail               : ludivine.kupiec@insa-lyon.fr lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Gestionnaire> (fichier Gestionnaire.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Gestionnaire.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool lisible( const string & unFichier )  
{  
    ifstream fichier( unFichier.c_str() );  
    return !fichier.fail();  
}  //----- Fin de lisible

void sauvegarder ( string & unFichier )
{
	

}

void charger ( const string & unFichier )
{
	if (lisible (unFichier) )
	{
		
		
		cout << "Chargement réussi" << endl ;
	}
	else 
	{
		cout << "Echec du chargement : le fichier n'est pas lisible" << endl ;
	}
}


//------------------------------------------------- Surcharge d'opérateurs
Gestionnaire & Gestionnaire::operator = ( const Gestionnaire & unXxx )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Gestionnaire::Gestionnaire ( const Gestionnaire & unXxx )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Gestionnaire>" << endl;
#endif
} //----- Fin de Gestionnaire (constructeur de copie)


Gestionnaire::Gestionnaire ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Gestionnaire>" << endl;
#endif
} //----- Fin de Gestionnaire


Gestionnaire::~Gestionnaire ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Gestionnaire>" << endl;
#endif
} //----- Fin de ~Gestionnaire


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

