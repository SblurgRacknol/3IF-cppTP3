/*************************************************************************
 TrajetSimple  -  description
-------------------
d�but                : 29/11/2018
copyright            : (C) 2018 par Ludivine K.
e-mail               : kupiec.ludivine@gmail.com
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h)

#if ! defined (TrajetSimple_H)
#define TrajetSimple_H

//--------------------------------------------------- Interfaces utilis�es

#include "Trajet.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

// R�le de la classe <TrajetSimple>
// Impl�mentation de trajets simples, c'est-�-dire de trajets directs 
// (en une seule �tape) ayant pour attribut un moyen de transport. 

//------------------------------------------------------------------------

class TrajetSimple : public Trajet {

//----------------------------------------------------------------- PUBLIC

public:

//----------------------------------------------------- M�thodes publiques
	
virtual void Affichage();
// Mode d'emploi :
// ...

virtual int getType();

// Mode d'emploi :
// Appel� dans d'autres classes pour savoir si les pointeurs sur Trajet sont 
// des trajets simples ou compos�s.

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple(const char* villeD, const char* villeA, const char* moyenT);

// Mode d'emploi (constructeur standard) :
// Appel� pour cr�er une instance de TrajetSimple si on conna�t :
// - Sa ville de d�part
// - Sa ville d'arriv�e
// - Son moyen de transport

// TrajetSimple(const TrajetSimple &unTrajet);

// Mode d'emploi (constructeur de copie) :
// 
// Contrat :
//

virtual ~TrajetSimple();

// Mode d'emploi :
//
// Contrat :
//

//------------------------------------------------------------------ PRIVE

protected:

//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s

char* moyenTransport;

};

//-------------------------------- Autres d�finitions d�pendantes de <TrajetSimple>

#endif // TrajetSimple_H
