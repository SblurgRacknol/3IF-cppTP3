/*************************************************************************
 TrajetCompose  -  description
-------------------
d�but                : 29/11/2018
copyright            : (C) 2018 par Ludivine K.
e-mail               : kupiec.ludivine@gmail.com
*************************************************************************/

//---------- R�alisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel

#include "TrajetCompose.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "tabTrajets.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

void TrajetCompose::Affichage()
// Algorithme :
// - Affiche le nombre de 
 {
	cout << "Trajet compos� de " << tabTraj->getNbAct() << " trajets, ";
	Trajet::Affichage();
	cout << ".\n";
	tabTraj->Affichage();
	cout << endl;
}
//
//bool TrajetCompose::isValid() {
//	return tabTraj.isCoherent();
//}

int TrajetCompose::getType() {
	return 1;
}

//------------------------------------------------- Surcharge d'op�rateurs
const char SEP = '|';
friend istream & operator >> ( istream & is, TrajetCompose & t )
{
	

}

friend ostream & operator << ( ostream & os, const TrajetCompose & t )
{
	os << "1" << SEP << tabTraj.nbAct << endl;
	for ( int i = 0 ; i < tabTraj.nbAct ; i++ )
	{
		os << tabTraj[i] ;
	}
}
//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose(const char* villeD, const char* villeA, tabTrajets *tT) : Trajet(villeD, villeA)
// Algorithme :
//
{

#ifdef MAP
	cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif

	tabTraj = tT;

} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

	delete tabTraj;

} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

