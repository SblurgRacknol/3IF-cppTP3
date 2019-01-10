/*************************************************************************
 Trajet  -  description
-------------------
d�but                : 29/11/2018
copyright            : (C) 2018 par Ludivine K. et Lucie C.
e-mail               : kupiec.ludivine@gmail.com lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

#define _CRT_SECURE_NO_WARNINGS // Pour les scanf.

#include <iostream>
#include <cstring>

using namespace std;

//------------------------------------------------------ Include personnel

#include"Trajet.h"


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

void Trajet::Affichage() 
{
	cout << "de " << villeDepart << " � " << villeArrivee;
}

//--------------------------------------------------- Getteurs et Setteurs

string Trajet::getVilleDepart() const
// Retourne la ville de d�part
{
	return villeDepart;
}

string Trajet::getVilleArrivee() const
// Retourne la ville d'arriv�e
{
	return villeArrivee;
}


//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet(const string villeD, const string villeA)
// Algorithme :
// - Allocation de m�moire pour villeDepart et villeArrive
// Allocation de la longueur des param�tres, +1 pour le caract�re de fin \0
// - Copie des arguments pass�s en param�tres dans les attributs de la classe
{

#ifdef MAP
	cout << "Appel au constructeur de <Trajet>" << endl;
#endif

	villeDepart = villeD; 
	villeArrivee = villeA;


} //----- Fin de Trajet


Trajet::~Trajet()
// Algorithme :
// Destruction de villeDepart et villeArrivee.
// Les crochets permettent au compilateur de savoir que ce sont des pointeurs.
{
#ifdef MAP
	cout << "Appel au destructeur de <Trajet>" << endl;
#endif

} //----- Fin de ~Trajet

