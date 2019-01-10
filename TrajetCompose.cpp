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
Trajet * TrajetCompose::Copie ( ) const
{
    return new TrajetCompose ( * this );
}  //----- Fin de Copie

void TrajetCompose::Affichage ( )
 {
	cout << "Trajet compose de " << tabTraj->getNbAct() << " trajets, ";
	Trajet::Affichage( );
	cout << ".\n";
	tabTraj->Affichage( );
	cout << endl;
}

void TrajetCompose::Lire ( istream & is )
{
	int taille = 0;
	string ligne = "";
	getline ( is, ligne, SEP );
	try 
	{
  		taille = stoi ( ligne ); 
	}
	catch( std::invalid_argument& e )
	{
  		cout << "Erreur de saisie" << endl;
	}
	getline ( is, ligne );
	
	TrajetSimple base = TrajetSimple ("a","b","");
	delete tabTraj;
	tabTraj = new tabTrajets (taille);
	
	for (int i = 0 ; i < taille ; i++ )
	{
		tabTraj->Ajouter ( new TrajetSimple (base) );
		getline ( is, ligne, SEP ); // on ne lit pas le caractère 0 
		tabTraj->getTrajet(i)->Lire (is);
	}
	
	villeDepart = tabTraj->getTrajet ( 0 )->getVilleDepart( );
	villeArrivee = tabTraj->getTrajet ( taille-1 )->getVilleArrivee( );
}

void TrajetCompose::Ecrire ( ostream & os )
{
	os << "1" << SEP << tabTraj->getNbAct()<< SEP << endl;
	for ( int i = 0 ; i < tabTraj->getNbAct() ; i++ )
	{
		tabTraj->getTrajet ( i ) ->Ecrire(os) ; 
	}
}

int TrajetCompose::getType() 
{
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
	tabTraj = new tabTrajets (0);
	for ( int i=0 ; i<t.tabTraj->getNbAct() ; i++ )
	{
		tabTraj->Ajouter( t.tabTraj->getTrajet (i)-> Copie() );
	
	}
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose()
{
#ifdef MAP
	cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

	delete tabTraj;

} //----- Fin de ~TrajetCompose

