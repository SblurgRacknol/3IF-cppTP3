/*************************************************************************
 TrajetSimple  -  description
-------------------
début                : 29/11/2018
copyright            : (C) 2018 par Ludivine K.
e-mail               : kupiec.ludivine@gmail.com
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h)

#if ! defined (TrajetSimple_H)
#define TrajetSimple_H

//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

// Rôle de la classe <TrajetSimple>
// Implémentation de trajets simples, c'est-à-dire de trajets directs 
// (en une seule étape) ayant pour attribut un moyen de transport. 

//------------------------------------------------------------------------

class TrajetSimple : public Trajet {

//----------------------------------------------------------------- PUBLIC

public:

//----------------------------------------------------- Méthodes publiques
	
virtual void Affichage();
// Mode d'emploi :
// ...

virtual int getType();

// Mode d'emploi :
// Appelé dans d'autres classes pour savoir si les pointeurs sur Trajet sont 
// des trajets simples ou composés.

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple(const char* villeD, const char* villeA, const char* moyenT);

// Mode d'emploi (constructeur standard) :
// Appelé pour créer une instance de TrajetSimple si on connaît :
// - Sa ville de départ
// - Sa ville d'arrivée
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

//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

char* moyenTransport;

};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TrajetSimple_H
