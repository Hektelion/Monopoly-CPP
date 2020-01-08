#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <iostream>
#include <string>

#include "case.hpp"
#include "des.hpp"
#include "carte.hpp"
#include "joueur.hpp"
#include "carte.hpp"

class PLATEAU
{
    private : 

        int id_joueur_actif;
        int nombre_joueur;
        int nombre_cases;
        int nombre_carte;
        int nombre_tours;
        CASE **cases;
        DES les_des;
        CARTE **carte_chance;
        CARTE **carte_caisse_com;
        JOUEUR *joueurs;
        int nb_maison;
        int nb_hotel;

    public : 
        PLATEAU();
        ~PLATEAU();

        void set_joueur_suivant();
        void set_case(CASE*);
        CASE *get_case();
        void set_carte(CARTE*);
        int ajouter_joueur();
        CARTE *get_carte();
        JOUEUR get_vanqueur();
        bool partie_termine();

};

#endif