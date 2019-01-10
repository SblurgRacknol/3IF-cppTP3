/*************************************************************************
 TrajetSimple  -  description
-------------------
début                : 29/11/2018
copyright            : (C) 2018 par Ludivine K. et Lucie C.
e-mail               : kupiec.ludivine@gmail.com lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>

using namespace std;

//------------------------------------------------------ Include personnel

#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes
const char SEP = '|';
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Trajet * TrajetSimple::Copie ( ) const
{
    return new TrajetSimple ( * this );
} //----- Fin de Copie

void TrajetSimple::Affichage( ) 
{
	cout << "Trajet simple, ";
	Trajet::Affichage();
	cout << " - en " << moyenTransport << endl;
}

int TrajetSimple::getType( ) {
	return 0;
}

void TrajetSimple::Lire ( istream & is )
{
	// Lecture des informations
	
	getline ( is, villeDepart, SEP );
	getline ( is, villeArrivee, SEP );
	getline ( is, moyenTransport, SEP );
	string s ;
	getline ( is, s );
	
}

void TrajetSimple::Ecrire ( ostream & os )
{
	os << "0" << SEP << villeDepart << SEP << villeArrivee << SEP;
	os << moyenTransport << SEP << endl;

}


//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple( const string VilleD, const string VilleA, const string moyTransport ) : Trajet( VilleD, VilleA )
{
#ifdef MAP
	cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif

	moyenTransport = moyTransport;

} //----- Fin de TrajetSimple

TrajetSimple::TrajetSimple(const TrajetSimple &t) : Trajet ( t )
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif

	moyenTransport = t.moyenTransport;

} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple()
{

#ifdef MAP
	cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif

} //----- Fin de ~TrajetSimple


