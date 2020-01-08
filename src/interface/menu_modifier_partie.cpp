
#include <stdio.h>

#include <SDL2/SDL.h>
#include "gameengine.h"
#include "gamestate.h"
#include "menu_modifier_partie.h"

CMENU_MODIFIER_PARTIE CMENU_MODIFIER_PARTIE::m_MENU_PRINCIPAL;

void CMENU_MODIFIER_PARTIE::Init()
{
	printf("Menu principal Init\n");
}

void CMENU_MODIFIER_PARTIE::Cleanup()
{
	//LIBERATION MEMOIRE

	printf("Menu principal Cleanup\n");
}

void CMENU_MODIFIER_PARTIE::Pause()
{
	printf("Menu principal Pause\n");
}

void CMENU_MODIFIER_PARTIE::Resume()
{
	printf("Menu principal Resume\n");
}

void CMENU_MODIFIER_PARTIE::HandleEvents(CGameEngine* game)
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

void CMENU_MODIFIER_PARTIE::Update(CGameEngine* game) 
{
	//SDL_UpdateWindowSurface(game->screen);
	SDL_GetWindowSize(game->screen, &largeur_interface, &hauteur_interface);
}

void CMENU_MODIFIER_PARTIE::Draw(CGameEngine* game) 
{

}
