/*************************************************************************
 Trajet  -  description
-------------------
d�but                : 29/11/2018
copyright            : (C) 2018 par Ludivine K. et Lucie C.
e-mail               : kupiec.ludivine@gmail.com lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------

#if !defined (Trajet_H)
#define Trajet_H

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

// R�le de la classe <Trajet>
// Classe abstraite pure et g�n�rique servant � l'impl�mentation de sous-classes plus d�taill�es.

//------------------------------------------------------------------------

class Trajet {

	//----------------------------------------------------------------- PUBLIC

public:

	//----------------------------------------------------- M�thodes publiques

	virtual void Affichage();

	// Mode d'emploi :
	// Ne peut �tre appel� directement depuis une instance de Trajet (car pas instanciable).
	// A appeller depuis un fils de la classe. 

	virtual int getType() = 0;

	// Mode d'emploi :
	// M�thode virtuelle pure forc�ment red�finie dans toutes les classes h�ritant de Trajet. 
	// A appeller depuis un fils de la classe.

	char* getVilleDepart() const;

	// Mode d'emploi :
	// A appeller depuis un fils de la classe.

	char* getVilleArrivee() const;

	// Mode d'emploi :
	// A appeller depuis un fils de la classe.

	//------------------------------------------------- Surcharge d'op�rateurs

	//-------------------------------------------- Constructeurs - destructeur

	virtual ~Trajet();

	// Mode d'emploi :
	// A ne pas appeler directement. 
	// A appeler � la destruction d'un objet de type pointeur sur Trajet. 
	

	//------------------------------------------------------------------ PRIVE

protected:

	//----------------------------------------------------- M�thodes prot�g�es


	//--------------------------------------------------- Constructeur prot�g�

	Trajet(const char* villeD, const char* villeA);

	// Mode d'emploi (constructeur standard) :
	// A appeler dans le cas o� on conna�tre la ville de d�part et d'arriv�e. 

  //----------------------------------------------------- Attributs prot�g�s

	char* villeDepart;
	char* villeArrivee;

};

//-------------------------------- Autres d�finitions d�pendantes de <Trajet>

#endif // Trajet_H
