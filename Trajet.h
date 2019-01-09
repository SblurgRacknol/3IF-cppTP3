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

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

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
	// A appeller depuis un fils de la classe. 

	virtual int getType() = 0;

	// Mode d'emploi :
	// Méthode virtuelle pure forcément redéfinie dans toutes les classes héritant de Trajet. 
	// A appeller depuis un fils de la classe.

	char* getVilleDepart() const;

	// Mode d'emploi :
	// A appeller depuis un fils de la classe.

	char* getVilleArrivee() const;

	// Mode d'emploi :
	// A appeller depuis un fils de la classe.

	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur

	virtual ~Trajet();

	// Mode d'emploi :
	// A ne pas appeler directement. 
	// A appeler à la destruction d'un objet de type pointeur sur Trajet. 
	

	//------------------------------------------------------------------ PRIVE

protected:

	//----------------------------------------------------- Méthodes protégées


	//--------------------------------------------------- Constructeur protégé

	Trajet(const char* villeD, const char* villeA);

	// Mode d'emploi (constructeur standard) :
	// A appeler dans le cas où on connaître la ville de départ et d'arrivée. 

  //----------------------------------------------------- Attributs protégés

	char* villeDepart;
	char* villeArrivee;

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // Trajet_H
