#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

class JOUEUR
{
private:

    std::string nom;
    int id;
    int position;
    int argent;
    bool est_fauche;
    bool est_en_prison;
    int tours_prison;
    bool carte_sortie_prison;
    int service_possede;
    int gare_possede;
    SDL_Color couleur;

public:

    void set_nom(std::string nom );
    void set_id(int id);
    void set_argent(int argent);
    void set_est_fauche(bool est_fauche);
    void set_est_en_prison(bool est_en_prison);
    void set_tour_en_prison(int tour_en_prison);
    void set_couleur( SDL_Color couleur);
    void set_carte_sortie_prison(bool carte_sortie_prison);
    void set_nb_gares(int nb_gare);
    void set_nb_service(int nb_service);
    std::string get_nom();
    int get_position();
    int get_argent();
    bool get_est_fauche();
    bool get_est_en_prison();
    int retirer_argent(int argent);
    int ajouter_argent(int argent); 
};

#endif