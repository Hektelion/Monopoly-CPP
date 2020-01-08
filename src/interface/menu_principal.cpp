
#include <stdio.h>

#include <SDL2/SDL.h>
#include "gameengine.h"
#include "gamestate.h"
#include "menu_principal.h"

CMENU_PRINCIPAL CMENU_PRINCIPAL::m_MENU_PRINCIPAL;

void CMENU_PRINCIPAL::Init()
{
	C_fond.r = 255;
	C_fond.b = 255;
	C_fond.g = 255;

	C_bouton.r = 0;
	C_bouton.b = 0;
	C_bouton.g = 0;

	printf("Menu principal Init\n");
}

void CMENU_PRINCIPAL::Cleanup()
{
	//LIBERATION MEMOIRE

	printf("Menu principal Cleanup\n");
}

void CMENU_PRINCIPAL::Pause()
{
	printf("Menu principal Pause\n");
}

void CMENU_PRINCIPAL::Resume()
{
	printf("Menu principal Resume\n");
}

void CMENU_PRINCIPAL::HandleEvents(CGameEngine* game)
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
				}
				else if(SDL_PointInRect(&curseur, &B_quitter))
				{
					//CLIC SUR LE BOUTON QUITTER
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

void CMENU_PRINCIPAL::Update(CGameEngine* game) 
{
	//SDL_UpdateWindowSurface(game->screen);
	SDL_GetWindowSize(game->screen, &largeur_interface, &hauteur_interface);

	B_modifier_partie.w = 200;
	B_modifier_partie.h = 50;
	B_modifier_partie.x = largeur_interface/2 - B_modifier_partie.w/2;
	B_modifier_partie.y = hauteur_interface - B_modifier_partie.h*4;

	B_quitter.w = 200;
	B_quitter.h = 50;
	B_quitter.x = largeur_interface/2 - B_modifier_partie.w/2;
	B_quitter.y = hauteur_interface - B_modifier_partie.h*2;
}

void CMENU_PRINCIPAL::Draw(CGameEngine* game) 
{
	SDL_SetRenderDrawColor(game->renderer, C_fond.r, C_fond.g, C_fond.g, 255);
	SDL_RenderClear(game->renderer);

	SDL_SetRenderDrawColor(game->renderer, C_bouton.r, C_bouton.g, C_bouton.g, 255);
	SDL_RenderDrawRect(game->renderer, &B_modifier_partie);
	SDL_RenderDrawRect(game->renderer, &B_quitter);
	SDL_RenderPresent(game->renderer);
}
