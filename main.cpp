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

// Définition d'une constante maximum pour les chaînes de caractères

const int TAILLE = 30;

// Permet de vider le buffer pour éviter les erreurs de saisie

void viderBuffer() {
	int c;

	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

//

void afficherOptions() {
	cout << "\t Menu." << endl;
	cout << " 1. Ajouter un trajet simple au catalogue." << endl;
	cout << " 2. Ajouter un trajet composé au catalogue." << endl;
	cout << " 3. Afficher le catalogue." << endl;
	cout << " 4. Rechercher un parcours (simple) dans le catalogue." << endl;
	cout << " 5. Effectuer une sauvegarde du catalogue." << endl;
	cout << " 6. Charger de nouveaux trajets dans le catalogue." << endl;
	cout << " 7. Revoir les options." << endl;
	cout << " 8. Quitter.\r\n" << endl;
}

//

TrajetSimple* saisieTrajetSimple() {

	cout << "Création d'un Trajet Simple." << endl;

	// Chaînes de caractères

	/*char* depart = new char[TAILLE];
	char* arrivee = new char[TAILLE];
	char* moyDeTransp = new char[TAILLE];*/
	
	string dep;
	string arr;
	string moy;

	cout << "- Quelle est la ville de depart ?" << endl;
	getline ( cin, dep );

	do {
		cout << "- Quelle est la ville d'arrivee ?" << endl;
		getline ( cin, arr );
	} while (dep==arr);

	cout << "- Quel est le moyen de transport associe ?" << endl;
	getline ( cin, moy );

	cout << endl;
	
	TrajetSimple *ts = new TrajetSimple(dep, arr, moy);

	/*delete[] depart;
	delete[] arrivee;
	delete[] moyDeTransp;*/

	return ts;
}

TrajetCompose* saisieTrajetCompose() {

	cout << "Création d'un Trajet Compose." << endl;

	int nbTraj;
	string nb;

	// Saisie du nombre de trajets simples dont sera composé le trajet composé

	do {
		cout << "- Combien d'étapes intermédiaires contient votre trajet ?" << endl;
		getline ( cin, nb );
		nbTraj = stoi ( nb );
	} while (nbTraj < 0 || nbTraj > 9);


	nbTraj++;

	// Affichage

	cout << "\n\tMerci de saisir les trajets dans l'ordre." << endl;
	cout << "\tVeuillez noter que toute etape non-conforme ne sera pas prise en compte.\n" << endl;

	// Création d'un tableau de trajets

	tabTrajets *t = new tabTrajets(nbTraj);

	// Création et ajout du premier trajet

	TrajetSimple *ts = saisieTrajetSimple();
	t->Ajouter(ts);

	// Boucle pour ajouter les autres trajets

	for(int i = 1; i < nbTraj; i++) {

		ts = saisieTrajetSimple();

		if(t->isCoherent(ts)) { 
			t->Ajouter(ts);
		}
		else {
			cout << "\nCe trajet ne peut être ajouté." << endl;
			delete ts;
			ts = NULL;
		}
	}

	TrajetCompose *tc = new TrajetCompose(t->getTrajet(0)->getVilleDepart(), t->getTrajet(t->getNbAct()-1)->getVilleArrivee(), t);

	return tc;
}

// Fonction main

void Sauvegarde (Catalogue * catalogue)
{
	cout << " 1. Choisir le chemin d'accès du fichier de sauvegarde." << endl;
	cout << " 2. Sauvegarder dans le fichier <Catalogue.txt.>" << endl;
	string choix ;
	int selec;
	do {
		cout << "Votre choix :" << endl;
		getline (cin, choix);
		selec = stoi (choix);
		
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
	catalogue->Sauvegarder(choix);
}
void Chargement (Catalogue * catalogue)
{
	cout << " 1. Choisir le chemin d'accès du fichier de chargement." << endl;
	cout << " 2. Charger depuis le fichier <Catalogue.txt>." << endl;
	
	string choix ;
	int selec;
	do {
		cout << "Votre choix :" << endl;
		getline (cin, choix);
		selec = stoi (choix);
		
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
}

int main() {

	afficherOptions();

	// Création du catalogue
		
	Catalogue *catalogue = new Catalogue();

	// Variables nécessaires aux choix de l'utilisateur

	string choix;
	int selec;

	do {
		do {
			cout << "Entrez un chiffre entre 1 et 8 :" << endl;
			getline (cin, choix);
			selec = stoi (choix);
			
		} while (selec < 1 || selec > 8);

		switch (selec) {
			case 1: {
				TrajetSimple* ts = saisieTrajetSimple();
				catalogue->Ajouter(ts);

				cout << "Trajet ajoute." << endl;
				ts->Affichage();
				cout << endl;
			} break;
			case 2: {
				TrajetCompose* tc = saisieTrajetCompose();
				catalogue->Ajouter(tc);	

				cout << "Trajet ajoute." << endl;
				tc->Affichage();
				cout << endl;			
			} break;
			case 3: {
				catalogue->Affichage();				
			} break;
			case 4: {
				char* villeDep = new char[TAILLE];
				char* villeArr = new char[TAILLE];

				cout << "D'où souhaitez-vous partir ?" << endl;
				scanf("%s", villeDep);
				viderBuffer();

				cout << "Où voulez-vous aller ?" << endl;
				scanf("%s", villeArr);
				viderBuffer();

				catalogue->rechercheVoyage(villeDep, villeArr);
			} break;
			case 5 : {
				Sauvegarde (catalogue);
			} break;
			case 6 : {
				Chargement (catalogue);
			} break;
			case 7 : {
				afficherOptions();
			} break;
			case 8 : {
				cout << "Au revoir !\r\n" << endl;
			} break;
			default:
				cout << "Votre saisie n'est pas valide. Veuillez recommencer." << endl;
			break;
		}
	} while (selec!= 8);

	delete catalogue;
}
