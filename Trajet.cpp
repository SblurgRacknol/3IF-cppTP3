/*************************************************************************
 Trajet  -  description
-------------------
début                : 29/11/2018
copyright            : (C) 2018 par Ludivine K. et Lucie C.
e-mail               : kupiec.ludivine@gmail.com lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#define _CRT_SECURE_NO_WARNINGS // Pour les scanf.

#include <iostream>
#include <cstring>

using namespace std;

//------------------------------------------------------ Include personnel

#include"Trajet.h"


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Trajet::Affichage() 
{
	cout << "de " << villeDepart << " a " << villeArrivee;
}

//--------------------------------------------------- Getters et Setters

string Trajet::getVilleDepart() const
{
	return villeDepart;
}

string Trajet::getVilleArrivee() const
{
	return villeArrivee;
}


//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet(const string villeD, const string villeA)
{

#ifdef MAP
	cout << "Appel au constructeur de <Trajet>" << endl;
#endif

	villeDepart = villeD; 
	villeArrivee = villeA;


} //----- Fin de Trajet


Trajet::~Trajet()
{
#ifdef MAP
	cout << "Appel au destructeur de <Trajet>" << endl;
#endif

} //----- Fin de ~Trajet

