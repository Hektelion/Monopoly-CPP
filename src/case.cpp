#include "case.hpp"

using namespace std;

void CASE::set_id(int id)
{
    id = id;
}

void CASE::set_nom(string nom)
{
    nom_case = nom;
}

int CASE::get_id()
{
    return id;
}

string CASE::get_nom()
{
    return nom_case;
}







void CASE_TERRAIN::set_proprietaire(JOUEUR proprietaire)
{
    this->proprietaire = proprietaire;
}

JOUEUR CASE_TERRAIN::get_proprietaire()
{
    return this->proprietaire;
}

void CASE_TERRAIN::construire()
{

}

int CASE_TERRAIN::get_loyer( int nb_loyer)
{

}

