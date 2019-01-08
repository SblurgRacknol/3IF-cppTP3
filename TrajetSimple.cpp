/*************************************************************************
 TrajetSimple  -  description
-------------------
d�but                : 29/11/2018
copyright            : (C) 2018 par Ludivine K.
e-mail               : kupiec.ludivine@gmail.com
*************************************************************************/

//---------- R�alisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

//------------------------------------------------------ Include personnel

#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

// type TrajetSimple::M�thode (liste des param�tres)
// Algorithme :
//
// {
// } //----- Fin de M�thode

void TrajetSimple::Affichage() 
{
	cout << "Trajet simple, ";
	Trajet::Affichage();
	cout << " - en " << moyenTransport << endl;
}

// type TrajetSimple::M�thode(liste des param�tres)
// Algorithme :
//
//{
//} //----- Fin de M�thode

int TrajetSimple::getType() {
	return 0;
}

//------------------------------------------------- Surcharge d'op�rateurs
const char SEP = '|';
istream & operator >> ( istream & is, TrajetSimple & t )
{
	// avanc�e du curseur de 2
	
	int position = is.tellg();
	position+=2;
	is.seekg(position, is.beg);
	
	// Lecture des lignes
	getline ( is, t.villeDepart, SEP );
	getline ( is, t.villeArrivee, SEP );
	getline ( is, t.moyenTransport, SEP );
}

ostream & operator << ( ostream & os, const TrajetSimple & t )
{
	os << "0" << SEP << t.villeDepart << SEP << t.villeArrivee << SEP;
	os << t.moyenTransport << endl;
}

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple(const char* VilleD, const char* VilleA, const char* moyTransport) : Trajet(VilleD, VilleA)
// Algorithme :
// - Appel au constructeur de la classe parent
// - Allocation de m�moire pour la cha�ne de caract�res stockant le moyen de transport
// - Copie du param�tre d'entr�e dans la variable
{

#ifdef MAP
	cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif

	moyenTransport = new char[strlen(moyTransport) + 1];
	strcpy(moyenTransport, moyTransport);

} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple()
// Algorithme :
//
{

#ifdef MAP
	cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif

	delete[] moyenTransport;

} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

