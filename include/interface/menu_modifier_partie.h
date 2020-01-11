 
#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <SDL2/SDL.h>
#include "gamestate.h"

class CMENU_MODIFIER_PARTIE : public CGameState
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(CGameEngine* game);
	void Update(CGameEngine* game);
	void Draw(CGameEngine* game);

	static CMENU_MODIFIER_PARTIE* Instance() {
		return &m_MENU_PRINCIPAL;
	}

protected:
	CMENU_MODIFIER_PARTIE() { }

private:
	static CMENU_MODIFIER_PARTIE m_MENU_PRINCIPAL;

	SDL_Color C_fond;
	SDL_Color C_bouton;

	SDL_Rect B_modifier_partie;
	SDL_Rect B_quitter;

	int largeur_interface;
	int hauteur_interface;

	SDL_Point curseur;
};

#endif

