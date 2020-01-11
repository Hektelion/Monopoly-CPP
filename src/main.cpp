#include <cstdlib>

#include "class_plateau.hpp"
#include "gameengine.h"
#include "etat_principal.h"
#include "etat_jeu.h"

int main ( int argc, char *argv[] )
{
	CGameEngine game;

	// initialize the engine
	game.Init( "Monopoly", 1080, 820, 0, true );

	// load the intro
	game.ChangeState( ETAT_PRINCIPAL::Instance() );

	// main loop
	while ( game.Running() )
	{
		game.HandleEvents();
		game.Update();
		game.Draw();
	} 

	// cleanup the engine
	game.Cleanup();

	return 0;
}