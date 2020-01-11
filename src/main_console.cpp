#include <cstdlib>

#include "class_plateau.hpp"

void menu_principal();
void modifier_partie();
void jeu();

using namespace std;

PLATEAU plateau_monopoly;

int main ()
{
	menu_principal();

	return 0;
}

void menu_principal()
{
	char choix;

	do
	{
		cout << "Application test permettant de developpez l'interface indépendement du jeu" << endl << endl;
		cout << "######################################" << endl;
		cout << "#              MONOPOLY              #" << endl;
		cout << "######################################" << endl;
		cout << "# 1 # INSCRIRE JOUEUR                #" << endl;
		cout << "# Q # QUITER LE JEU                  #" << endl;
		cout << "######################################" << endl;
        cout << "choix : ";
		cin >> choix;

		switch (choix)
		{
		case '1':
			modifier_partie();
			break;

		case 'Q':
		case 'q':
			cout << "Le jeu quitte" << endl;
			break;
		
		default:
			cout << "Choix incorrect" << endl;
			break;
		}

	} while (choix != 'q' && choix != 'Q');
}

void modifier_partie()
{
	char choix;
    string tmp_name;
    JOUEUR *tmp_joueur;

	do
	{
		cout << "######################################" << endl;
		cout << "#           MODIFIER PARTIE          #" << endl;
		cout << "######################################" << endl;
		cout << "# 1 # AJOUTER JOUEUR                 #" << endl;
		cout << "# 2 # LANCER LA PARTIE               #" << endl;
		cout << "# Q # RETOUR                         #" << endl;
		cout << "######################################" << endl;
        cout << "# NOMBRES JOUEURS INSCRIT : " << plateau_monopoly.get_nombre_joueur() << "        #" << endl;
        cout << "######################################" << endl;
        cout << "choix : ";
		cin >> choix;

		switch (choix)
		{
		case '1':
			if(!plateau_monopoly.ajouter_joueur())
            {
                cout << "entrez un nom pour leur joueur : " << endl;
                cin >> tmp_name;
                tmp_joueur = plateau_monopoly.get_joueur(plateau_monopoly.get_nombre_joueur()-1);
                tmp_joueur->set_nom(tmp_name);
            }
			break;

		case '2':
			jeu();
			break;

		case 'Q':
		case 'q':
			cout << "Retour menu précédent" << endl;
			break;
		
		default:
			cout << "Choix incorrect" << endl;
			break;
		}

	} while (choix != 'q' && choix != 'Q');
}

void jeu()
{
	char choix;
    string tmp_name;
    JOUEUR *joueur_actuel;

	if(plateau_monopoly.get_nombre_joueur() >= 2)
	{
		do
		{
			joueur_actuel = plateau_monopoly.get_joueur(plateau_monopoly.get_id_joueur_actif());

			do
			{

				//debut tour
				cout << "######################################" << endl;
				cout << "#           TOUR DU JOUEUR " << plateau_monopoly.get_id_joueur_actif() <<"          #" << endl;
				cout << "######################################" << endl;

				if(1) //AJOUTER OPERATION
				{
					cout << "# L # LANCER LES DES                 #" << endl;
				}

				if(1) //AJOUTER OPERATION
				{
					cout << "# A # ABANDONNER                     #" << endl;
				}

				if(1) //AJOUTER OPERATION
				{
					cout << "# T # TERMINER TOUR                 #" << endl;
				} 

				cout << "######################################" << endl;
				cin >> choix;

				switch (choix)
				{
					case 'L':
					case 'l':
						cout << "non implémentée" << endl;
						break;

					case 'A':
					case 'a':
						cout << "non implémentée" << endl;
						break;

					case 'T':
					case 't':
						cout << "fin du tour" << endl;
						break;
					
					default:
						cout << "Choix incorrect" << endl;
						break;
				}

				//lancer de dés

				//deplacement joueur

				//action case

				//passer son tour

				//joueur suivant
			} while (choix != 'T' && choix != 't');

			//passer au joueur suivant

		} while (!plateau_monopoly.partie_termine());
		
		cout << "le joueur : " << plateau_monopoly.get_vanqueur() << " remporte la partie.";
	}
	else
	{
		cout << "nombre de joueur insuffisant" << endl;
	}
	
}