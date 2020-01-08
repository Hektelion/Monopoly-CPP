
#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <SDL2/SDL.h>
#include "gamestate.h"

class CMENU_PRINCIPAL : public CGameState
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(CGameEngine* game);
	void Update(CGameEngine* game);
	void Draw(CGameEngine* game);

	static CMENU_PRINCIPAL* Instance() {
		return &m_MENU_PRINCIPAL;
	}

protected:
	CMENU_PRINCIPAL() { }

private:
	static CMENU_PRINCIPAL m_MENU_PRINCIPAL;

	SDL_Color C_fond;
	SDL_Color C_bouton;

	SDL_Rect B_modifier_partie;
	SDL_Rect B_quitter;

	int largeur_interface;
	int hauteur_interface;

	SDL_Point curseur;
};

#endif

