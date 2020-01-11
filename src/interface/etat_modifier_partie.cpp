
#include <iostream>

#include <SDL2/SDL.h>
#include "gameengine.h"
#include "gamestate.h"
#include "etat_modifier_partie.h"
#include "etat_jeu.h"
#include "constant.h"

using namespace std;

ETAT_MODIFIER_PARTIE ETAT_MODIFIER_PARTIE::m_ETAT_MODIFIER_PARTIE;

void ETAT_MODIFIER_PARTIE::Init()
{
	cout << "Menu principal Init" << endl;
}

void ETAT_MODIFIER_PARTIE::Cleanup()
{
	//LIBERATION MEMOIRE

	cout << "Menu principal Cleanup" << endl;
}

void ETAT_MODIFIER_PARTIE::Pause()
{
	cout << "Menu principal Pause" << endl;
}

void ETAT_MODIFIER_PARTIE::Resume()
{
	cout << "Menu principal Resume" << endl;
}

void ETAT_MODIFIER_PARTIE::HandleEvents(CGameEngine* game)
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				game->Quit();
				break;

			case SDL_MOUSEMOTION:
				SDL_GetMouseState(&curseur.x, &curseur.y);
				break;

			case SDL_MOUSEBUTTONDOWN:
				if(SDL_PointInRect(&curseur, &B_Demarrer_une_partie))
				{
					//CLIC SUR LE BOUTON DEMARRER UNE PARTIE
					cout << "Appui bouton demarrer une partie" << endl;
					cout << "#######################################################" << endl;
					cout << "# AJOUTER LA CONDITION MINIMUM 2 JOUEURS DANS LE CODE #" << endl;
					cout << "#######################################################" << endl;
					game->ChangeState( ETAT_JEU::Instance() );
				}
				else if(SDL_PointInRect(&curseur, &B_Ajouter_un_joueur))
				{
					///CLIC SUR LE BOUTON AJOUTER UN JOUEUR
					cout << "Appui bouton ajouter un joueur" << endl;
				}
				else if(SDL_PointInRect(&curseur, &B_Supprimer_un_joueur))
				{
					//CLIC SUR LE BOUTON SUPPRIMER UN JOUEUR
					cout << "Appui bouton supprimer un joueur" << endl;
				}
				else if(SDL_PointInRect(&curseur, &Z_Joueurs))
				{
					//CLIC SUR LA ZONE DES JOUEURS
					cout << "Appui sur la zone des joueurs" << endl;
				}
				else if(SDL_PointInRect(&curseur, &Z_Nom))
				{
					//CLIC SUR LA ZONE NOM DU JOUEURS SELECTIONNE
					cout << "Appui la zone nom du joueur selectionné" << endl;
				}
				else if(SDL_PointInRect(&curseur, &Z_Couleur))
				{
					//CLIC SUR LA ZONE COULEUR DU JOUEUR SELECTIONNE
					cout << "Appui la zone couleur du joueur selectionné" << endl;
				} 
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
						game->Quit();
						break;
				}
				break;
		}
	}
}

void ETAT_MODIFIER_PARTIE::Update(CGameEngine* game) 
{
	//SDL_UpdateWindowSurface(game->screen);
	SDL_GetWindowSize(game->screen, &largeur_interface, &hauteur_interface);

	B_Demarrer_une_partie.w = 200;
	B_Demarrer_une_partie.h = 50;
	B_Demarrer_une_partie.x = (largeur_interface/4)*3 - B_Demarrer_une_partie.w/2;
	B_Demarrer_une_partie.y = (hauteur_interface/3) + 20;

	B_Ajouter_un_joueur.w = 200;
	B_Ajouter_un_joueur.h = 50;
	B_Ajouter_un_joueur.x = (largeur_interface/4)*3 - B_Ajouter_un_joueur.w/2;
	B_Ajouter_un_joueur.y = (hauteur_interface/3) + 20 + hauteur_interface/5;

	B_Supprimer_un_joueur.w = 200;
	B_Supprimer_un_joueur.h = 50;
	B_Supprimer_un_joueur.x = (largeur_interface/4)*3 - B_Supprimer_un_joueur.w/2;
	B_Supprimer_un_joueur.y = (hauteur_interface/3) + 20 + (hauteur_interface/5)*2;

	Z_Joueurs.w = largeur_interface/2 - 40;
	Z_Joueurs.h = hauteur_interface - hauteur_interface/5 - 40;
	Z_Joueurs.x = 20;
	Z_Joueurs.y = (hauteur_interface/5) + 20;

	Z_Nom.w = 300;
	Z_Nom.h = 50;
	Z_Nom.x = largeur_interface/2 - Z_Nom.w/2;
	Z_Nom.y = (hauteur_interface/10) - Z_Nom.h/2;

	Z_Couleur.w = 50;
	Z_Couleur.h = 50;
	Z_Couleur.x = largeur_interface/2 + Z_Nom.w/2 + 20;
	Z_Couleur.y = (hauteur_interface/10) - Z_Couleur.h/2;
}

void ETAT_MODIFIER_PARTIE::Draw(CGameEngine* game) 
{
	SDL_SetRenderDrawColor(game->renderer, C_fond.r, C_fond.g, C_fond.g, 255);
	SDL_RenderClear(game->renderer);

	SDL_SetRenderDrawColor(game->renderer, C_arriere_plan.r, C_arriere_plan.g, C_arriere_plan.g, 255);
	SDL_RenderFillRect(game->renderer, &Z_Joueurs);
	SDL_RenderFillRect(game->renderer, &Z_Nom);
	SDL_RenderFillRect(game->renderer, &Z_Couleur);

	SDL_SetRenderDrawColor(game->renderer, C_bouton.r, C_bouton.g, C_bouton.g, 255);
	SDL_RenderFillRect(game->renderer, &B_Demarrer_une_partie);
	SDL_RenderFillRect(game->renderer, &B_Ajouter_un_joueur);
	SDL_RenderFillRect(game->renderer, &B_Supprimer_un_joueur);

	SDL_RenderPresent(game->renderer);
}
