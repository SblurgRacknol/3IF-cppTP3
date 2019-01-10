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

	virtual void Affichage();

	// Mode d'emploi :
	// Ne peut être appelé directement depuis une instance de Trajet (car pas instanciable).

	virtual int getType() = 0;

	// Mode d'emploi :
	// Méthode virtuelle pure forcément redéfinie dans toutes les classes héritant de Trajet. 
	// Retourne 0 si le trajet est un TrajetSimple, 1 si c'est un TrajetCompose

	string getVilleDepart() const;

	string getVilleArrivee() const;

	//------------------------------------------------- Surcharge d'opérateurs

	virtual void Lire ( istream & is ) = 0;
	virtual void Ecrire ( ostream & os ) = 0;

	//-------------------------------------------- Constructeurs - destructeur
	Trajet ( const string villeD, const string villeA );
	// Constructeur standard

	virtual ~Trajet();

	// Mode d'emploi :	
	// A appeler à la destruction d'un objet de type pointeur sur Trajet. 
	

	protected :
	//----------------------------------------------------- Attributs protégés

	string villeDepart;
	string villeArrivee;

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // Trajet_H
