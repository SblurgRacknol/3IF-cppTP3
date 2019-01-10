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
	cout << " 5. Rechercher un parcours (complexe) dans le catalogue." << endl;
	cout << " 6. Revoir les options." << endl;
	cout << " 7. Quitter.\r\n" << endl;
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

int main() {

	cout << "Bienvenue dans ce logiciel de gestion de voyages. \r\n" << endl;
	afficherOptions();

	// Création du catalogue
		
	Catalogue *catalogue = new Catalogue();

	// Variables nécessaires aux choix de l'utilisateur

	char caractere;
	int choix;

	do {
		do {
			cout << "Quelle action souhaitez-vous realiser ?" << endl;
			scanf("%c", &caractere);
			cout << endl;
			choix = caractere - 48;
			viderBuffer();
		} while (choix < 1 || choix > 7);

		/* switch */

		switch (choix) {
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
			case 6 : {
				afficherOptions();
			} break;
			case 7 : {
				cout << "Au revoir !\r\n" << endl;

			} break;
			default:
				cout << "Votre saisie n'est pas valide. Veuillez recommencer." << endl;
			break;
		}
	} while (choix != 7);


	///// On affiche ces trajets simples.

	//t1.verifier();
	//t1.afficher();

	//t5.verifier();
	//t5.afficher();

	///// On crée différents tableau de trajets simples qui serviront pour des trajets complexes.

	//tabTrajet tabT1 = new tabTrajet();
	//tabT1.ajouter(t2);
	//tabT1.ajouter(t1);

	//tabTrajet tabT2 = new tabTrajet();
	//tabT2.ajouter(t3);
	//tabT2.ajouter(t1);

	///// On crée différents trajets complexes.

	//TrajetComplexe tC1 = new TrajetComplexe(londres, new_york, tabT1);//Fonctionne
	//TrajetComplexe tC2 = new TrajetComplexe(paris, new_york, tabT1);//Pas la bonne ville de départ
	//TrajetComplexe tC3 = new TrajetComplexe(londres, atlanta, tabT1);//Pas la bonne ville d'arrivée
	//TrajetComplexe tC4 = new TrajetComplexe(los_angeles, new_york, tabT2);//Trajet impossible.

	///// On les vérife et on les affiche.

	//tC1.verifier();
	//tC1.afficher();
	//tC2.verifier();
	//tC2.afficher();
	//tC3.verifier();
	//tC3.afficher();
	//tC4.verifier();
	//tC4.afficher();

	///// On crée des tableaux de trajets contenant des trajets complexes.

	//tabTrajet tabT4 = new tabTrajet();
	//tabT4.ajouter(tabT1);
	//tabT4.ajouter(t4);

	//tabTrajet tabT5 = new tabTrajet();
	//tabT5.ajouter(tabT1);
	//tabT5.ajouter(t3);

	///// On crée un trajetComplexe avec ce tableau.

	//TrajetComplexe tC5 = new TrajetComplexe(londres, los_angeles, tabT4);//Fonctionne.
	//tC5.verifier();
	//tC5.afficher();
	//TrajetComplexe tC6 = new TrajetComplexe(atlanta, los_angeles, tabT4);//Pas la bonne ville de départ.
	//tC6.verifier();
	//tC6.afficher();
	//TrajetComplexe tC7 = new TrajetComplexe(londres, paris, tabT4);//Pas la bonne ville d'arrivée.
	//tC7.verifier();
	//tC7.afficher();
	//TrajetComplexe tC8 = new TrajetComplexe(londres, atlanta, tabT5);//Trajet impossible.
	//tC8.verifier();
	//tC8.afficher();

	delete catalogue;
}
