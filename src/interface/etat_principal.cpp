#include <iostream>

#include <SDL2/SDL.h>

#include "constant.h"
#include "gameengine.h"
#include "gamestate.h"
#include "etat_principal.h"
#include "etat_modifier_partie.h"

using namespace std;

ETAT_PRINCIPAL ETAT_PRINCIPAL::m_ETAT_PRINCIPAL;

void ETAT_PRINCIPAL::Init()
{
	cout << "Menu principal Init" << endl;
} 

void ETAT_PRINCIPAL::Cleanup()
{
	//LIBERATION MEMOIRE

	cout << "Menu principal Cleanup" << endl;
}

void ETAT_PRINCIPAL::Pause()
{
	cout << "Menu principal Pause" << endl;
}

void ETAT_PRINCIPAL::Resume()
{
	cout << "Menu principal Resume" << endl;
}

void ETAT_PRINCIPAL::HandleEvents(CGameEngine* game)
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
				if(SDL_PointInRect(&curseur, &B_modifier_partie))
				{
					//CLIC SUR LE BOUTON MODIFIER UNE PARTIE
					cout << "Appui bouton modifier partie" << endl;
					game->ChangeState( ETAT_MODIFIER_PARTIE::Instance() );
				}
				else if(SDL_PointInRect(&curseur, &B_quitter))
				{
					//CLIC SUR LE BOUTON QUITTER
					cout << "Appui bouton quitter" << endl;
					game->Quit();
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

void ETAT_PRINCIPAL::Update(CGameEngine* game) 
{
	//SDL_UpdateWindowSurface(game->screen);
	SDL_GetWindowSize(game->screen, &largeur_interface, &hauteur_interface);

	B_modifier_partie.w = 300;
	B_modifier_partie.h = 50;
	B_modifier_partie.x = largeur_interface/2 - B_modifier_partie.w/2;
	B_modifier_partie.y = hauteur_interface - B_modifier_partie.h*4;

	B_quitter.w = 300;
	B_quitter.h = 50;
	B_quitter.x = largeur_interface/2 - B_modifier_partie.w/2;
	B_quitter.y = hauteur_interface - B_modifier_partie.h*2;
}

void ETAT_PRINCIPAL::Draw(CGameEngine* game) 
{
	SDL_SetRenderDrawColor(game->renderer, C_fond.r, C_fond.g, C_fond.g, 255);
	SDL_RenderClear(game->renderer);

	SDL_SetRenderDrawColor(game->renderer, C_bouton.r, C_bouton.g, C_bouton.g, 255);
	SDL_RenderFillRect(game->renderer, &B_modifier_partie);
	SDL_RenderFillRect(game->renderer, &B_quitter);
	SDL_RenderPresent(game->renderer);
}
