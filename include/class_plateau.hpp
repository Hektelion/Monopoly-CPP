#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <iostream>
#include <string>

#include "class_case.hpp"
#include "class_des.hpp"
#include "class_carte.hpp"
#include "class_joueur.hpp"
#include "class_carte.hpp"

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
        void set_case(CASE*, int);
        CASE *get_case(int);
        void set_carte(CARTE*, int);
        int ajouter_joueur();
        CARTE *get_carte(int, bool);
        int get_id_joueur_actif();
        int get_vanqueur();
        bool partie_termine();
        int get_nombre_joueur();
        JOUEUR *get_joueur(int);
};

#endif