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

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Trajet::Affichage() 
{
	cout << "de " << villeDepart << " à " << villeArrivee;
}

//--------------------------------------------------- Getteurs et Setteurs

char* Trajet::getVilleDepart() const
// Retourne la ville de départ
{
	return villeDepart;
}

char* Trajet::getVilleArrivee() const
// Retourne la ville d'arrivée
{
	return villeArrivee;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet(const char* villeD, const char* villeA)
// Algorithme :
// - Allocation de mémoire pour villeDepart et villeArrive
// Allocation de la longueur des paramètres, +1 pour le caractère de fin \0
// - Copie des arguments passés en paramètres dans les attributs de la classe
{

#ifdef MAP
	cout << "Appel au constructeur de <Trajet>" << endl;
#endif

	villeDepart = new char[strlen(villeD) + 1]; 
	villeArrivee = new char[strlen(villeA) + 1];

	strcpy(villeDepart, villeD); 
	strcpy(villeArrivee, villeA);

} //----- Fin de Trajet

Trajet::~Trajet()
// Algorithme :
// Destruction de villeDepart et villeArrivee.
// Les crochets permettent au compilateur de savoir que ce sont des pointeurs.
{
#ifdef MAP
	cout << "Appel au destructeur de <Trajet>" << endl;
#endif

	delete[] villeDepart;
	delete[] villeArrivee;

} //----- Fin de ~Trajet

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
