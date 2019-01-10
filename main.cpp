#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "main.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "tabTrajets.h"
#include "Catalogue.h"

using namespace std;

void affSaut ( )
{
	cout << endl;
	cout << "	- - - - - - - - - - - - - - - - - " << endl ;
	cout << endl;
}

void afficherOptions() 
{
	affSaut ();
	cout << "\t Menu." << endl;
	cout << " 1. Ajouter un trajet simple au catalogue." << endl;
	cout << " 2. Ajouter un trajet compose au catalogue." << endl;
	cout << " 3. Afficher le catalogue." << endl;
	cout << " 4. Rechercher un parcours (simple) dans le catalogue." << endl;
	cout << " 5. Effectuer une sauvegarde du catalogue." << endl;
	cout << " 6. Charger de nouveaux trajets dans le catalogue." << endl;
	cout << " 7. Revoir les options." << endl;
	cout << " 8. Quitter.\r\n" << endl;
	affSaut ();
}


TrajetSimple * saisieTrajetSimple() 
{

	cout << "Creation d'un Trajet Simple." << endl;

	string dep;
	string arr;
	string moy;

	cout << "- Quelle est la ville de depart ?" << endl;
	getline ( cin, dep );

	do 
	{
		cout << "- Quelle est la ville d'arrivee ?" << endl;
		getline ( cin, arr );
	} while (dep==arr);

	cout << "- Quel est le moyen de transport associe ?" << endl;
	getline ( cin, moy );

	cout << endl;
	
	TrajetSimple * ts = new TrajetSimple( dep, arr, moy );
	affSaut ( );
	return ts;
}

TrajetCompose * saisieTrajetCompose() 
{
	cout << "Création d'un Trajet Compose." << endl;

	int nbTraj;
	string nb;
	
	do {
		cout << "- Combien d'etapes intermediaires contient votre trajet ?" << endl;
		getline ( cin, nb );
		try {
  			nbTraj = stoi ( nb );
		}
		catch ( invalid_argument & e ){
  			cout << "Erreur de saisie." << endl;
  			nbTraj = -1;
		}
		
	} while (nbTraj < 0 || nbTraj > 9);


	nbTraj++;

	cout << "\n\tMerci de saisir les trajets dans l'ordre." << endl;
	cout << "\tVeuillez noter que toute etape non-conforme ne sera pas prise en compte.\n" << endl;
	affSaut ( );
	tabTrajets * t = new tabTrajets( nbTraj );

	// Création et ajout du premier trajet

	TrajetSimple * ts = saisieTrajetSimple( );
	t->Ajouter(ts);

	// Boucle pour ajouter les autres trajets

	for( int i = 1; i < nbTraj; i++ ) 
	{

		ts = saisieTrajetSimple ( );

		if( t->isCoherent(ts) ) 
		{ 
			t->Ajouter(ts);
		}
		else 
		{
			cout << "\nCe trajet ne peut être ajouté." << endl;
			delete ts;
			ts = NULL;
		}
	}

	TrajetCompose * tc = new TrajetCompose( t->getTrajet(0)->getVilleDepart(), t->getTrajet(t->getNbAct()-1)->getVilleArrivee(), t );
	affSaut ( );
	return tc;
}


void Sauvegarde (Catalogue * catalogue)
{
	cout << " 1. Choisir le chemin d'acces du fichier de sauvegarde." << endl;
	cout << " 2. Sauvegarder dans le fichier <Catalogue.txt.>" << endl;
	affSaut ( );
	string choix ;
	int selec;
	do 
	{
		cout << "Votre choix :" << endl;
		getline (cin, choix);
		try 
		{
  			selec = stoi (choix);
		}
		catch( std::invalid_argument& e )
		{
  			cout << "Erreur de saisie" << endl;
		}
		
	} while (selec < 1 || selec > 2);
	
	if (selec == 1)
	{
		cout << "Entrez le chemin d'acces du fichier." << endl;
		getline (cin, choix);
	}
	else
	{
		choix = "Catalogue.txt";
	}
	catalogue->Sauvegarder(choix);
	affSaut ( );
}
void Chargement (Catalogue * catalogue)
{
	cout << " 1. Choisir le chemin d'acces du fichier de chargement." << endl;
	cout << " 2. Charger depuis le fichier <Catalogue.txt>." << endl;
	affSaut ( );
	string choix ;
	int selec;
	do 
	{
		cout << "Votre choix :" << endl;
		getline (cin, choix);
		try 
		{
  			selec = stoi (choix);
		}
		catch(std::invalid_argument& e)
		{
  			cout << "Erreur de saisie" << endl;
		}
		
	} while (selec < 1 || selec > 2);
	
	if (selec == 1)
	{
		cout << "Entrez le chemin d'accès du fichier." << endl;
		getline (cin, choix);
	}
	else
	{
		choix = "Catalogue.txt";
	}
	catalogue->Charger(choix);
	affSaut ( );
}

int main() 
{
	afficherOptions();

	// Création du catalogue		
	Catalogue *catalogue = new Catalogue();

	string choix;
	int selec;

	do 
	{
		do 
		{
			cout << "Entrez un chiffre entre 1 et 8 :" << endl;
			getline ( cin, choix );
			try 
			{
  				selec = stoi (choix);
			}
			catch( std::invalid_argument& e )
			{
  				cout << "Erreur de saisie" << endl;
			}
			
		} while (selec < 1 || selec > 8);
		affSaut ( );
		switch (selec) {
			case 1:
			{
				TrajetSimple * ts = saisieTrajetSimple();
				catalogue->Ajouter(ts);

				cout << "Trajet ajoute." << endl;
				ts->Affichage();
				cout << endl;
			}
			break;
			case 2: 
			{
				TrajetCompose* tc = saisieTrajetCompose();
				catalogue->Ajouter(tc);	

				cout << "Trajet ajoute." << endl;
				tc->Affichage();
				cout << endl;	
			}		
			break;
			case 3: 
			{
				catalogue->Affichage();	
			}			
			break;
			case 4: 
			{
				string villeDep;
				string villeArr;

				cout << "D'ou souhaitez-vous partir ?" << endl;
				getline(cin, villeDep);

				cout << "Ou voulez-vous aller ?" << endl;
				getline(cin, villeArr);

				catalogue->rechercheVoyage(villeDep, villeArr);
			}
			break;
			case 5 : 
			{
				Sauvegarde (catalogue);
			}
			break;
			case 6 : 
			{
				Chargement (catalogue);
			}
			break;
			case 7 : 
			{
				afficherOptions();
			}
			break;
			case 8 : 
			{
				cout << "Au revoir !\r\n" << endl;
			}
			break;
			default:
			{
				cout << "Votre saisie n'est pas valide. Veuillez recommencer." << endl;
			}
			break;
		}
	} while (selec!= 8);

	delete catalogue;
}
