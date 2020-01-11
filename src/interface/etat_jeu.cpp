 
#include <iostream>

#include <SDL2/SDL.h>
#include "gameengine.h"
#include "gamestate.h"
#include "etat_jeu.h"
#include "constant.h"

using namespace std;

ETAT_JEU ETAT_JEU::m_ETAT_JEU;

void ETAT_JEU::Init()
{
	cout << "Etat Jeu Init" << endl;
}

void ETAT_JEU::Cleanup()
{
	//LIBERATION MEMOIRE

	cout << "Etat Jeu Cleanup" << endl;
}

void ETAT_JEU::Pause()
{
	cout << "Etat Jeu Pause" << endl;
}

void ETAT_JEU::Resume()
{
	cout << "Etat Jeu Resume" << endl;
}

void ETAT_JEU::HandleEvents(CGameEngine* game)
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

void ETAT_JEU::Update(CGameEngine* game) 
{
	SDL_GetWindowSize(game->screen, &largeur_interface, &hauteur_interface);

	Z_plateau.w = largeur_interface/2 - 20;
	Z_plateau.h = largeur_interface/2 - 20;
	Z_plateau.x = 10;
	Z_plateau.y = 10;

	Z_joueurs.w = largeur_interface/2 - 20;
	Z_joueurs.h = hauteur_interface - Z_plateau.h - 30;
	Z_joueurs.x = 10;
	Z_joueurs.y = Z_plateau.y + Z_plateau.h + 10;

	Z_panneau_control.w = largeur_interface - Z_plateau.w - 30;
	Z_panneau_control.h = hauteur_interface - 20;
	Z_panneau_control.x = Z_plateau.x + Z_plateau.w + 10;
	Z_panneau_control.y = 10;

	Z_info_joueur_actuel.w = Z_panneau_control.w - 20;
	Z_info_joueur_actuel.h = (hauteur_interface - 20)/3 - 13;
	Z_info_joueur_actuel.x = Z_panneau_control.x + 10;
	Z_info_joueur_actuel.y = Z_panneau_control.y + 10;

	Z_actions.w = Z_panneau_control.w - 20;
	Z_actions.h = (hauteur_interface - 20)/3 - 13;
	Z_actions.x = Z_panneau_control.x + 10;
	Z_actions.y = Z_info_joueur_actuel.y + Z_info_joueur_actuel.h + 10;

	Z_console.w = Z_panneau_control.w - 20;
	Z_console.h = (hauteur_interface - 20)/3 - 13;
	Z_console.x = Z_panneau_control.x + 10;
	Z_console.y = Z_actions.y + Z_actions.h + 10;

	B_passer_tour.w = 200;
	B_passer_tour.h = 50;
	B_passer_tour.x = Z_actions.x + Z_actions.w/2 - B_passer_tour.w/2;
	B_passer_tour.y = Z_actions.y + (Z_actions.h - 200)/5;

	B_lancer_des.w = 200;
	B_lancer_des.h = 50;
	B_lancer_des.x = Z_actions.x + Z_actions.w/2 - B_passer_tour.w/2;
	B_lancer_des.y = B_passer_tour.y + B_passer_tour.h + (Z_actions.h - 200)/5;

	B_payer_loyer.w = 200;
	B_payer_loyer.h = 50;
	B_payer_loyer.x = Z_actions.x + Z_actions.w/2 - B_passer_tour.w/2;
	B_payer_loyer.y = B_lancer_des.y + B_lancer_des.h + (Z_actions.h - 200)/5;

	B_abandonner.w = 200;
	B_abandonner.h = 50;
	B_abandonner.x = Z_actions.x + Z_actions.w/2 - B_passer_tour.w/2;
	B_abandonner.y = B_payer_loyer.y + B_payer_loyer.h + (Z_actions.h - 200)/5;
	
}

void ETAT_JEU::Draw(CGameEngine* game) 
{
    SDL_SetRenderDrawColor(game->renderer, C_fond.r, C_fond.g, C_fond.g, 255);
	SDL_RenderClear(game->renderer);

	SDL_SetRenderDrawColor(game->renderer, C_arriere_plan.r, C_arriere_plan.g, C_arriere_plan.g, 255);
	SDL_RenderFillRect(game->renderer, &Z_plateau);
	SDL_RenderFillRect(game->renderer, &Z_joueurs);
	SDL_RenderFillRect(game->renderer, &Z_panneau_control);

	SDL_SetRenderDrawColor(game->renderer, C_fond.r, C_fond.g, C_fond.g, 255);
	SDL_RenderFillRect(game->renderer, &Z_info_joueur_actuel);
	SDL_RenderFillRect(game->renderer, &Z_actions);
	SDL_RenderFillRect(game->renderer, &Z_console);

	SDL_SetRenderDrawColor(game->renderer, C_bouton.r, C_bouton.g, C_bouton.g, 255);
	SDL_RenderFillRect(game->renderer, &B_passer_tour);
	SDL_RenderFillRect(game->renderer, &B_lancer_des);
	SDL_RenderFillRect(game->renderer, &B_payer_loyer);
	SDL_RenderFillRect(game->renderer, &B_abandonner);

	SDL_RenderFillRects(game->renderer, C_monopoly, 30);

    SDL_RenderPresent(game->renderer);
}
