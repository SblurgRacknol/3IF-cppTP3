/*************************************************************************
 tabTrajets  -  description
-------------------
d�but                : 29/11/2018
copyright            : (C) 2018 par Ludivine K. et Lucie C.
e-mail               : kupiec.ludivine@gmail.com lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

#include <iostream>
#include <cstring>

using namespace std;

//------------------------------------------------------ Include personnel

#include "tabTrajets.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques


void tabTrajets::Reallouer( ) 
{
	Trajet **temp = new Trajet*[nbMax * 2];

	for (int i = 0; i < this->nbAct; i++) 
	{
		temp[i] = tab[i];
	}
	for (int i = nbAct; i < nbMax * 2; i++) 
	{
		temp[i] = NULL;
	}
	delete[] tab;
	this->nbMax = 2 * nbMax;
	tab = temp;
}

void tabTrajets::Ajouter( Trajet *traj ) 
{
	if( !(nbAct < nbMax) ) 
	{
		Reallouer( );
	}
	tab [ nbAct ] = traj;
	nbAct++;
}

bool tabTrajets::isCoherent( TrajetSimple *ts ) 
{
	bool res = false;
	if ( tab[nbAct - 1]->getVilleArrivee() == ts->getVilleDepart() )
	{
		res = true;
	}
	return res;
}

void tabTrajets::Affichage() 
{
	for (int i = 0; i < nbAct; i++) 
	{
		tab[i]->Affichage();
	}
}

//----------------------------------------------------- Getters & Setters

int tabTrajets::getNbAct( ) const 
{
	return nbAct;
}

int tabTrajets::getNbMax( ) const 
{
	return nbMax;
}

int tabTrajets::getType(int i) const 
{
	return tab[i] -> getType( );
}

Trajet* tabTrajets::getTrajet(int i) const  
{
	return tab[i];
}


//-------------------------------------------- Constructeurs - destructeur

tabTrajets::tabTrajets( ) : nbMax( NBMAX ), nbAct(0)
{

#ifdef MAP
		cout << "Appel au constructeur par d�faut de <tabTrajets>" << endl;
#endif
	tab = new Trajet*[NBMAX];
	for (int i = 0; i < nbMax; i++) 
	{
		tab[i] = NULL;
	}
} //----- Fin de TrajetCompose


tabTrajets::tabTrajets(const tabTrajets &unTabTrajets)
{
#ifdef MAP
		cout << "Appel au constructeur de copie de <tabTrajets>" << endl;
#endif

	nbAct = unTabTrajets.getNbAct();
	nbMax = unTabTrajets.getNbMax();

	for (int i = 0; i < nbAct; i++) 
	{
		tab [i] =  unTabTrajets.getTrajet(i)->Copie ( );
	}
	for (int i = nbAct; i < nbMax; i++) 
	{
		tab[i] = NULL;
	}	
	
} //----- Fin de tabTrajets

tabTrajets::tabTrajets(int nbTraj) : nbMax(nbTraj + (5 - nbTraj % 5)), nbAct(0) 
{
#ifdef MAP
		cout << "Appel au constructeur standard de <tabTrajets>" << endl;
#endif

	tab = new Trajet*[nbMax];
	// Initialisation des pointeurs � NULL 
	for (int i = 0; i < nbMax; i++) {
		tab[i] = NULL;
	}

} //----- Fin de tabTrajets

tabTrajets::~tabTrajets() 
{
#ifdef MAP
		cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

	for (int i = 0; i < nbMax; i++) {
		delete tab[i];
	}

	delete[] tab;

} //----- Fin de ~tabTrajets


