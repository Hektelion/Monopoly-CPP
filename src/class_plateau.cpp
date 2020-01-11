#include <iostream>

#include "class_plateau.hpp"
#include "class_joueur.hpp"

PLATEAU::PLATEAU()
{
    this->id_joueur_actif = 0;
    this->nombre_cases = 40;
    this->nombre_tours = 0;
    this->nb_maison = 32;
    this->nb_hotel = 12;

    this->nombre_joueur = 0;
    this->joueurs = new JOUEUR[8];

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
    this->id_joueur_actif = (id_joueur_actif + 1) % (this->nombre_joueur);
}

int PLATEAU::get_nombre_joueur()
{
    return this->nombre_joueur;
}

JOUEUR *PLATEAU::get_joueur(int id)
{

    if(id < 0 || id > 8)
    {
        cerr << "id invalide : " << id << endl;
        exit(EXIT_FAILURE);
    }

    if(id > nombre_joueur)
    {
        cerr << "id inexistant : " << id << endl;
        exit(EXIT_FAILURE);
    }

    return &joueurs[id];
}

void PLATEAU::set_case(CASE *c, int id)
{

}

void PLATEAU::set_carte(CARTE *c, int id)
{

}

int PLATEAU::ajouter_joueur()
{
    if(this->nombre_joueur == 8)
    {
        cerr << "nombre de joueurs maximum atteint : " << this->nombre_joueur << endl;
        return 1;
    }

    JOUEUR nouveau_joueur;
    this->joueurs[this->nombre_joueur] = nouveau_joueur; 
    this->nombre_joueur++;

    return 0;
}

int PLATEAU::get_id_joueur_actif()
{
    return this->id_joueur_actif;
} 

int PLATEAU::get_vanqueur()
{
    //il ne doit rester qu'un joueur en ligne sinon renvoi -1
    int nombre_joueur_encore_en_jeu = 0;
    int id_vainqueur;
    for(int i=0 ; i<this->nombre_joueur ; i++)
    {
        if(this->joueurs[i].get_est_fauche() == false)
        {
            id_vainqueur = this->joueurs[i].get_id();
            nombre_joueur_encore_en_jeu++;
        }
    }

    if(nombre_joueur_encore_en_jeu == 0) //tous les joueurs sont éliminé ERREUR
    {
        cerr << "ERREUR : tout les joueur sont éliminé" << endl;
        exit(EXIT_FAILURE);
    }
    else if(nombre_joueur_encore_en_jeu == 1)
    {
        cout << "le vainqueur a pour id : " << id_vainqueur << endl;
        return id_vainqueur;
    }
    else
    {
        cout << "pas de vainqueur" << endl;
        return -1;
    }
}

bool PLATEAU::partie_termine()
{
    //si il ne reste qu'un joueur en jeu renvoi true sinon false
    int nombre_joueur_encore_en_jeu = 0;

    for(int i=0 ; i<this->nombre_joueur ; i++)
    {
        if(this->joueurs[i].get_est_fauche() == false)
        {
            nombre_joueur_encore_en_jeu++;
        }
    }

    if(nombre_joueur_encore_en_jeu == 0) //tous les joueurs sont éliminé ERREUR
    {
        cerr << "ERREUR : tout les joueur sont éliminé" << endl;
        exit(EXIT_FAILURE);
    }
    else if(nombre_joueur_encore_en_jeu == 1)
    {
        cout << "partie terminé" << endl;
        return true;
    }
    else
    {
        cout << "la partie continue" << endl;
        return false;
    }
}

CASE *PLATEAU::get_case(int id)
{
    if(id < 0 || id > this->nombre_cases)
    {
        cout << "Cette case n'existe pas : " << id << endl;
        return NULL;
    }
    else if(cases[id] == NULL)
    {
        cerr << "ERREUR : case non initialisées : " << id << endl;
        return NULL;
    }
    else
    {
        return this->cases[id];
    }
}

CARTE *PLATEAU::get_carte(int id, bool type)
{
        if(id < 0 || id > this->nombre_carte)
    {
        cout << "Cette carte n'existe pas : " << id << endl;
        return NULL;
    }
    else if(cases[id] == NULL)
    {
        cerr << "ERREUR : carte non initialisées : " << id << endl;
        return NULL;
    }
    else
    {
        if(type == true)
        {
            return this->carte_chance[id];
        }
        else
        {
            return this->carte_caisse_com[id];
        }
        
    }
}