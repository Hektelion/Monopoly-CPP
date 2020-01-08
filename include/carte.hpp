#ifndef CARTE_HPP
#define CARTE_HPP

#include <string>

using namespace std;

class CARTE 
{
    protected:
        string description;
        string titre;

    public :
        virtual void effet_carte() = 0; 
};

class CARTE_PAYER_ARGENT
{
    private:
        int montant;

    public:
        CARTE_PAYER_ARGENT();
        ~CARTE_PAYER_ARGENT();
};

class CARTE_ALLEZ_EN_PRISON
{
    private:

    public:
        CARTE_ALLEZ_EN_PRISON();
        ~CARTE_ALLEZ_EN_PRISON();
};

class CARTE_GAGNER_ARGENT
{
    private:
        int montant;

    public:
        CARTE_GAGNER_ARGENT();
        ~CARTE_GAGNER_ARGENT();
};

class CARTE_DEPLACEMENT
{
    private:
        int position;
        bool deplacement_relatif;

    public:
        CARTE_DEPLACEMENT();
        ~CARTE_DEPLACEMENT();
};

class CARTE_SORTIE_DE_PRISON
{
    private:

    public:
        CARTE_SORTIE_DE_PRISON();
        ~CARTE_SORTIE_DE_PRISON();
};

#endif