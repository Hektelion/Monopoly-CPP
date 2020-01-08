#ifndef CASE_HPP
#define CASE_HPP

#include <iostream>
#include <string>

#include <SDL2/SDL.h>

#include "joueur.hpp"

using namespace std;

class CASE 
{
    protected:
    
    string nom_case ;
    int id ;

    public :

    void set_id(int);
    void set_nom(string);
    int get_id() ;
    string get_nom();

    virtual void action_case() = 0;
    virtual void fenetre_action() = 0;
    virtual int get_reponse_joueur() = 0;
};

class CASE_TERRAIN : public CASE
{
    private : 

        int m_loyer_TN;
        int m_loyer_1M;
        int m_loyer_2M;
        int m_loyer_3M;
        int m_loyer_4M;
        int m_loyer_H;
        int m_prix;
        int m_val_hypotheque; 
        JOUEUR proprietaire;
        SDL_Color m_couleur;
        int m_nb_maison;
        bool m_a_hotel;
        bool m_est_hypotheque;

    public :

        void set_proprietaire(JOUEUR);
        JOUEUR get_proprietaire();
        void construire();
        int get_loyer(int);
};

class CASE_PRISON : public CASE
{
    private : 

    public :

};

class CASE_CARTE : public CASE
{
    private : 

    public :

};

class CASE_DEPART : public CASE
{
    private : 

    public :

};

class CASE_COMPAGNIE : public CASE
{
    private : 

    public :

};

class CASE_GARE : public CASE
{
    private : 

    public :

};

class CASE_IMPOT : public CASE
{
    private : 

    public :

};

class CASE_PARC_GRATUIT : public CASE
{
    private : 

    public :

};

class CASE_ALLEZ_PRISON : public CASE
{
    private : 

    public :

};

#endif