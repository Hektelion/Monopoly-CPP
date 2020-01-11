
#include <stdio.h>
#include <cstdlib>

#include <SDL2/SDL.h>
#include "gameengine.h"
#include "gamestate.h"

void CGameEngine::Init(const char* title, int width, int height, int bpp, bool fullscreen)
{
	int flags = 0;

	// initialize SDL
	if( SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0 ){
        fprintf(stderr, "Erreur SDL_Init : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

	if ( fullscreen ) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	screen = SDL_CreateWindow(title,
                                  0,
                                  0,
						   	  width,
                          	 height,
                   SDL_WINDOW_RESIZABLE);
	
	if(screen == NULL)
	{
        fprintf(stderr, "Erreur SDL_CreateWindow : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
	else
	{
		printf("Fenetre initialisée\n");
	}
	

	renderer = SDL_CreateRenderer(screen,	//Fenetre cible du moteur de rendu
                                      -1,		//Index
                SDL_RENDERER_ACCELERATED);

	if( renderer == NULL){
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s\n", SDL_GetError());  //LOG
        exit(EXIT_FAILURE);
    }
	else
	{
		printf("Moteur de rendu initialisé\n");
	} 
	
	m_fullscreen = fullscreen;
	m_running = true;

	printf("INITIALISATION DU MOTEUR\n");
}

void CGameEngine::Cleanup()
{
	// cleanup the all states
	while ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	printf("NETTOYAGE DU MOTEUR\n");

	SDL_Quit();
}

void CGameEngine::ChangeState(CGameState* state) 
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void CGameEngine::PushState(CGameState* state)
{
	// pause current state
	if ( !states.empty() ) {
		states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void CGameEngine::PopState()
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// resume previous state
	if ( !states.empty() ) {
		states.back()->Resume();
	}
}

void CGameEngine::HandleEvents() 
{
	// let the state handle events
	states.back()->HandleEvents(this);
}

void CGameEngine::Update() 
{
	// let the state update the game
	states.back()->Update(this);
}

void CGameEngine::Draw() 
{
	// let the state draw the screen
	states.back()->Draw(this);
}
