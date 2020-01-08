#include <des.hpp>

#include <random>
#include <iostream>

using namespace std;

DES::DES()
{
    d1 = 0;
    d2 = 0;
    tot = 0;
}

DES::~DES()
{
    cout << "suppression dés" << endl;
}

void DES::lancer()
{
    random_device rd{};
 
    d1 = rd()%7;
    d2 = rd()%7;
}

int DES::get_tot()
{
    return tot;
}

int DES::get_d1()
{
    return d1;
}

int DES::get_d2()
{
    return d2;
}

bool DES::is_double()
{
    if(d1 == d2)
    {
        return true;
    }
    else
    {
        return false;

    }
    
}