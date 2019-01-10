/*************************************************************************
 TrajetCompose  -  description
-------------------
début                : 29/11/2018
copyright            : (C) 2018 par Ludivine K. et Lucie C.
e-mail               : kupiec.ludivine@gmail.com lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp)

//---------------------------------------------------------------- INCLUDE


//------------------------------------------------------ Include personnel

#include "TrajetCompose.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "tabTrajets.h"

using namespace std;

//------------------------------------------------------------- Constantes
const char SEP = '|';
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetCompose::Affichage ( )
 {
	cout << "Trajet composé de " << tabTraj->getNbAct() << " trajets, ";
	Trajet::Affichage();
	cout << ".\n";
	tabTraj->Affichage();
	cout << endl;
}

void TrajetCompose::Lire ( istream & is )
{
	int taille = 0;
	int position = is.tellg ( );
	string ligne = "";
	// Incrémentation de la position de 2
	position += 2;
	is.seekg ( position, is.beg );
	getline ( is, ligne, SEP );
	taille = stoi ( ligne ); // A RAJOUTER : vérification du format
	
	TrajetSimple base = TrajetSimple ("a","b","");
	delete tabTraj;
	tabTraj = new tabTrajets (taille);
	
	// Lecture des lignes
	for (int i = 0 ; i < taille ; i++ )
	{
		tabTraj->Ajouter ( new TrajetSimple (base) );
		tabTraj->getTrajet(i)->Lire (is);
	}
	villeDepart = tabTraj->getTrajet ( 0 )->getVilleDepart();
	villeArrivee = tabTraj->getTrajet ( taille-1 )->getVilleArrivee();
}

void TrajetCompose::Ecrire ( ostream & os )
{
	os << "1" << SEP << tabTraj->getNbAct()<< SEP << endl;
	for ( int i = 0 ; i < tabTraj->getNbAct() ; i++ )
	{
		tabTraj->getTrajet ( i ) ->Ecrire(os) ; //MARCHE PAS
	}
}

int TrajetCompose::getType() {
	return 1;
}


//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose(const string villeD, const string villeA, tabTrajets *tT) : Trajet(villeD, villeA)
{
#ifdef MAP
	cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif

	tabTraj = tT;

} //----- Fin de TrajetCompose

TrajetCompose::TrajetCompose ( const TrajetCompose & t ) : Trajet ( t )
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
	tabTraj = new tabTrajets (*t.tabTraj); 
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose()
{
#ifdef MAP
	cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

	delete tabTraj;

} //----- Fin de ~TrajetCompose

