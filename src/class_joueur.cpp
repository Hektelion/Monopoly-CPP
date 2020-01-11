#include <iostream>
#include <string>

#include "class_joueur.hpp"

using  namespace std ;

JOUEUR::JOUEUR()
{

}

JOUEUR::~JOUEUR()
{
    
}

void JOUEUR::set_nom(string nom)
{
    this->nom = nom ;
}

int JOUEUR::get_id()
{
    return this->id;
}

void JOUEUR::set_id(int id)
{ 
    this->id += 1 ; 
}

void JOUEUR::set_argent(int argent)
{
    this->argent = argent ;
}

void JOUEUR::set_est_fauche(bool est_fauche)
{
    this->est_fauche = est_fauche ;
}

void JOUEUR::set_est_en_prison(bool est_en_prison)
{
    this->est_en_prison = est_en_prison ;
}

void JOUEUR::set_tour_en_prison(int tour_en_prison )
{
    this->tours_prison = tour_en_prison ;
}

void JOUEUR::set_couleur (SDL_Color couleur)
{
    this->couleur = couleur ;
}

void JOUEUR::set_carte_sortie_prison(bool carte_sortie_prison)
{
    this->carte_sortie_prison = carte_sortie_prison;
}

void JOUEUR::set_nb_gares(int nb_gare)
{
    this->gare_possede = nb_gare ;
}
void JOUEUR::set_nb_service(int nb_service)
{
    this->service_possede = nb_service ;
}

string JOUEUR::get_nom()
{
    return this->nom ;
}

int JOUEUR::get_position()
{
    return this->position ;
}

int JOUEUR::get_argent()
{
    return this->argent ;
}

bool JOUEUR::get_est_fauche()
{
    return this->est_fauche ;
}

bool JOUEUR::get_est_en_prison()
{
    return this->est_en_prison ;
}

int JOUEUR::retirer_argent(int argent )
{
    this->argent -= argent ;
}

int JOUEUR::ajouter_argent(int argent)
{
    this->argent += argent ;
}
