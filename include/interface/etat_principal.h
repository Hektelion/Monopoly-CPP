 
#ifndef ETAT_PRINCIPAL_H
#define ETAT_PRINCIPAL_H

#include <SDL2/SDL.h>
#include "gamestate.h"

class ETAT_PRINCIPAL : public CGameState
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(CGameEngine* game);
	void Update(CGameEngine* game);
	void Draw(CGameEngine* game);

	static ETAT_PRINCIPAL* Instance() {
		return &m_ETAT_PRINCIPAL;
	}

protected:
	ETAT_PRINCIPAL() { }

private:
	static ETAT_PRINCIPAL m_ETAT_PRINCIPAL;

	SDL_Rect B_modifier_partie;
	SDL_Rect B_quitter;

	int largeur_interface;
	int hauteur_interface;

	SDL_Point curseur;
};

#endif

