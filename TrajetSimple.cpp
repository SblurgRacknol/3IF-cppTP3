/*************************************************************************
 TrajetSimple  -  description
-------------------
début                : 29/11/2018
copyright            : (C) 2018 par Ludivine K.
e-mail               : kupiec.ludivine@gmail.com
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

//------------------------------------------------------ Include personnel

#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// type TrajetSimple::Méthode (liste des paramètres)
// Algorithme :
//
// {
// } //----- Fin de Méthode

void TrajetSimple::Affichage() 
{
	cout << "Trajet simple, ";
	Trajet::Affichage();
	cout << " - en " << moyenTransport << endl;
}

// type TrajetSimple::Méthode(liste des paramètres)
// Algorithme :
//
//{
//} //----- Fin de Méthode

int TrajetSimple::getType() {
	return 0;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple(const char* VilleD, const char* VilleA, const char* moyTransport) : Trajet(VilleD, VilleA)
// Algorithme :
// - Appel au constructeur de la classe parent
// - Allocation de mémoire pour la chaîne de caractères stockant le moyen de transport
// - Copie du paramètre d'entrée dans la variable
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

//----------------------------------------------------- Méthodes protégées

