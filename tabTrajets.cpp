/*************************************************************************
 tabTrajets  -  description
-------------------
début                : 29/11/2018
copyright            : (C) 2018 par Ludivine K. et Lucie C.
e-mail               : kupiec.ludivine@gmail.com lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
#include <cstring>

using namespace std;

//------------------------------------------------------ Include personnel

#include "tabTrajets.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// type TrajetCompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

	void tabTrajets::Reallouer() {
		Trajet **temp = new Trajet*[nbMax * 2];

		// On fait pointer chaque case du tableau temp sur l'instance de Trajet pointée par tab au même indice

		for (int i = 0; i < this->nbAct; i++) {
			temp[i] = tab[i];
		}

		// Définition du reste des pointeurs à NULL

		for (int i = nbAct; i < nbMax * 2; i++) {
			temp[i] = NULL;
		}

		// On supprime le tableau tab, mais pas les instances de Trajet qu'il contient !

		delete[] tab;

		// On change la valeur max de l'instance de tableau de trajets courante

		this->nbMax = 2 * nbMax;

		// On fait pointer l'attribut tab vers temp.

		tab = temp;
	}

	void tabTrajets::Ajouter(Trajet *traj) {
		if(!(nbAct < nbMax)) {
			Reallouer();
		}

		tab[nbAct] = traj;
		nbAct++;
	}

	bool tabTrajets::isCoherent(TrajetSimple *ts) 
	{
		bool res = false;
		if ( tab[nbAct - 1]->getVilleArrivee() == ts->getVilleDepart() )
		{
			res = true;
		}
		return res;
	}

	void tabTrajets::Affichage() {
		for (int i = 0; i < nbAct; i++) {
			tab[i]->Affichage();
		}
	}

	//----------------------------------------------------- Getters & Setteurs

	int tabTrajets::getNbAct() const {
		return nbAct;
	}

	int tabTrajets::getNbMax() const {
		return nbMax;
	}

	int tabTrajets::getType(int i) const {
		return tab[i] -> getType();
	}

	Trajet* tabTrajets::getTrajet(int i) const  {
		return tab[i];
	}

	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur

	tabTrajets::tabTrajets() : nbMax(NBMAX), nbAct(0)

		// Algorithme :
		// Créé un tableau de trajets dans le tas

	{

#ifdef MAP
		cout << "Appel au constructeur par défaut de <tabTrajets>" << endl;
#endif

		tab = new Trajet*[NBMAX];

		// Initialisation des pointeurs à NULL 

		for (int i = 0; i < nbMax; i++) {
			tab[i] = NULL;
		}

	} //----- Fin de TrajetCompose

tabTrajets::tabTrajets(int nbTraj) : nbMax(nbTraj + (5 - nbTraj % 5)), nbAct(0)

		// Algorithme :
		// Créé un tableau de trajets dans le tas

	{

#ifdef MAP
		cout << "Appel au constructeur standard de <tabTrajets>" << endl;
#endif

		tab = new Trajet*[nbMax];

		// Initialisation des pointeurs à NULL 

		for (int i = 0; i < nbMax; i++) {
			tab[i] = NULL;
		}

	} //----- Fin de TrajetCompose

	tabTrajets::tabTrajets(const tabTrajets &unTabTrajets)

		// Algorithme :
		// Créé un tableau de trajets dans le tas

	{

#ifdef MAP
		cout << "Appel au constructeur de copie de <tabTrajets>" << endl;
#endif

		nbAct = unTabTrajets.getNbAct();
		nbMax = unTabTrajets.getNbMax();

		for (int i = 0; i < nbMax; i++) {

		}
	} //----- Fin de TrajetCompose

	tabTrajets::~tabTrajets() {

		// Algorithme :
		//

#ifdef MAP
		cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

		for (int i = 0; i < nbMax; i++) {
			delete tab[i];
		}

		delete[] tab;

	} //----- Fin de ~TrajetCompose


	//------------------------------------------------------------------ PRIVE

	//----------------------------------------------------- Méthodes protégées

