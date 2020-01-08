#include "plateau.hpp"
#include "joueur.hpp"

PLATEAU::PLATEAU()
{
    this->id_joueur_actif = 0;
    this->nombre_cases = 40;
    this->nombre_tours = 0;
    this->nb_maison = 32;
    this->nb_hotel = 12;

    this->nombre_joueur = 2;
    this->joueurs = new JOUEUR[this->nombre_joueur];

    this->cases = new CASE*[this->nombre_cases];
    this->carte_chance = new CARTE*[this->nombre_carte];
    this->carte_caisse_com = new CARTE*[this->nombre_carte];

    for(int i=0 ; i<this->nombre_cases ; i++)
    {
        //init case
    }

    for(int i=0 ; i<this->nombre_carte ; i++)
    {
        //init carte chance i

        //init carte caisse de communauté i
    }
}

PLATEAU::~PLATEAU()
{
    delete cases;
    delete carte_chance;
    delete carte_caisse_com;
}

void PLATEAU::set_joueur_suivant()
{
    this->id_joueur_actif = (id_joueur_actif++)%this->nombre_joueur;
}

void PLATEAU::set_case(CASE *c)
{

}

void PLATEAU::set_carte(CARTE *c)
{

}

int PLATEAU::ajouter_joueur()
{

}

JOUEUR PLATEAU::get_vanqueur()
{

}

bool PLATEAU::partie_termine()
{

}

CASE *PLATEAU::get_case()
{

}

CARTE *PLATEAU::get_carte()
{

}