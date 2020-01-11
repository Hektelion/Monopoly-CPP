 
#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H

#include <SDL2/SDL.h>
#include "gamestate.h"
#include "constant.h"

class ETAT_JEU : public CGameState
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(CGameEngine* game);
	void Update(CGameEngine* game);
	void Draw(CGameEngine* game);

	static ETAT_JEU* Instance() {
		return &m_ETAT_JEU;
	}

protected:
	ETAT_JEU() { }

private:
	static ETAT_JEU m_ETAT_JEU;

	//ZONE PRINCIPAL
    SDL_Rect Z_plateau;
    SDL_Rect Z_joueurs;
    SDL_Rect Z_panneau_control;

	//ZONE PANNEAU_CONTROL
	SDL_Rect Z_info_joueur_actuel;
	SDL_Rect Z_actions;
	SDL_Rect Z_console;

	//ACTION
	SDL_Rect B_passer_tour;
	SDL_Rect B_lancer_des;
	SDL_Rect B_payer_loyer;
	SDL_Rect B_abandonner;

	SDL_Rect C_monopoly[NB_CASE];

	int largeur_interface;
	int hauteur_interface;

	SDL_Point curseur;
};

#endif

