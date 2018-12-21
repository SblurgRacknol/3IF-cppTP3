/*************************************************************************
 Catalogue  -  description
-------------------
d�but                : 29/11/2018
copyright            : (C) 2018 par Ludivine K.
e-mail               : kupiec.ludivine@gmail.com
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------

#if !defined (Catalogue_H)
#define Catalogue_H

//--------------------------------------------------- Interfaces utilis�es

#include "Trajet.h"
#include "tabTrajets.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

// R�le de la classe <Catalogue>
// Classe g�n�rique impl�mentant des m�thodes propres � un ensemble de Trajets
// - Recherche de trajets
// - Affichage

//------------------------------------------------------------------------

class Catalogue {

	//----------------------------------------------------------------- PUBLIC

	public:

		//----------------------------------------------------- M�thodes publiques

		void rechercheVoyage(char* villeD, char* villeA);
		// Mode d'emploi :
		// Affiche les trajets possibles pour aller de villeD � villeA

		void Ajouter(TrajetSimple* traj);
		// Mode d'emploi :
		// Ajoute un trajet simple au catalogue		

		void Ajouter(TrajetCompose* traj);
		// Mode d'emploi :
		// Ajoute un trajet compos� au catalogue
		// Contrat : 
		// On suppose le trajet compos� conforme (v�rifi� dans le main)	

		void Affichage();
		// Mode d'emploi :
		// ...

		//------------------------------------------------- Surcharge d'op�rateurs

		//-------------------------------------------- Constructeurs - destructeur

		Catalogue();

		// Mode d'emploi : constructeur par d�faut
		// A appeller en d�but de fonction
		// tabTrajets a une taille maximale mais une cardinalit� actuelle nulle

		virtual ~Catalogue();

		// Mode d'emploi : destructeur
		// Si catalogue est de type pointeur, � appeler avant la fin du bloc
		// o� catalogue a �t� instanci�

		//------------------------------------------------------------------ PRIVE

	protected:

		//----------------------------------------------------- M�thodes prot�g�es

		//----------------------------------------------------- Attributs prot�g�s

		tabTrajets *tab;

};

//-------------------------------- Autres d�finitions d�pendantes de <Catalogue>

#endif // Catalogue_H