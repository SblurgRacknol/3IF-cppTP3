/*************************************************************************
 Trajet  -  description
-------------------
début                : 29/11/2018
copyright            : (C) 2018 par Ludivine K. et Lucie C.
e-mail               : kupiec.ludivine@gmail.com lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------

#if !defined (Trajet_H)
#define Trajet_H
#include <string>
using namespace std;


// Rôle de la classe <Trajet>
// Classe abstraite pure et générique servant à l'implémentation de sous-classes plus détaillées.

//------------------------------------------------------------------------

class Trajet {

	//----------------------------------------------------------------- PUBLIC

	public:

	//----------------------------------------------------- Méthodes publiques
	
	/*
     * Renvoie un pointeur vers une copie du trajet
     */
	virtual Trajet * Copie ( ) const = 0;
	
	/*
     * Affiche dans la sortie standard les informations du trajet
     */
	virtual void Affichage();

	/*
	* Retourne 0 si le trajet est un TrajetSimple, 1 si c'est un TrajetCompose
	*/
	virtual int getType() = 0;
	
	/*
	* Modifie les informations du trajet courant par celles entrées dans le flux
	* passé en paramètre
	*/
	virtual void Lire ( istream & is ) = 0;
	
	/*
	* Ecrit les informations du trajet courant dans le flux passé en paramètre
	*/
	virtual void Ecrire ( ostream & os ) = 0;
	
	//--------------------------------------------------------------- Getters
	string getVilleDepart() const;
	string getVilleArrivee() const;
	//-------------------------------------------- Constructeurs - destructeur
	
	Trajet ( const string villeD, const string villeA );

	virtual ~Trajet();	
	
	//------------------------------------------------------------------ PRIVE
	protected :
	//----------------------------------------------------- Attributs protégés

	string villeDepart;
	string villeArrivee;

};

#endif // Trajet_H
