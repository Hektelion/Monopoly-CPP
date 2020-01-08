
#ifndef ETAT_MODIFIER_PARTIE_H
#define ETAT_MODIFIER_PARTIE_H

#include <SDL2/SDL.h>
#include "gamestate.h"

class ETAT_MODIFIER_PARTIE : public CGameState
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(CGameEngine* game);
	void Update(CGameEngine* game);
	void Draw(CGameEngine* game);

	static ETAT_MODIFIER_PARTIE* Instance() {
		return &m_ETAT_MODIFIER_PARTIE;
	}

protected:
	ETAT_MODIFIER_PARTIE() { }

private:
	static ETAT_MODIFIER_PARTIE m_ETAT_MODIFIER_PARTIE;

	SDL_Rect B_Demarrer_une_partie;
	SDL_Rect B_Ajouter_un_joueur;
	SDL_Rect B_Supprimer_un_joueur;

	SDL_Rect Z_Joueurs;
	SDL_Rect Z_Nom;
	SDL_Rect Z_Couleur;

	int largeur_interface;
	int hauteur_interface;

	SDL_Point curseur;
};

#endif

