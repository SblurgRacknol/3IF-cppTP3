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
#include <string>
using namespace std;


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

	virtual int getType() = 0;

	// Mode d'emploi :
	// M�thode virtuelle pure forc�ment red�finie dans toutes les classes h�ritant de Trajet. 
	// Retourne 0 si le trajet est un TrajetSimple, 1 si c'est un TrajetCompose

	string getVilleDepart() const;

	string getVilleArrivee() const;

	//------------------------------------------------- Surcharge d'op�rateurs

	virtual void Lire ( istream & is ) = 0;
	virtual void Ecrire ( ostream & os ) = 0;

	//-------------------------------------------- Constructeurs - destructeur
	Trajet ( const string villeD, const string villeA );
	// Constructeur standard

	virtual ~Trajet();

	// Mode d'emploi :	
	// A appeler � la destruction d'un objet de type pointeur sur Trajet. 
	

	protected :
	//----------------------------------------------------- Attributs prot�g�s

	string villeDepart;
	string villeArrivee;

};

//-------------------------------- Autres d�finitions d�pendantes de <Trajet>

#endif // Trajet_H
