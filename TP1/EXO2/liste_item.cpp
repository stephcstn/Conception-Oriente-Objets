#include "liste_item.hpp"

Liste_item::Liste_item(int n)
{
    valeur = n;
    suiv = nullptr;
}

int Liste_item::getValeur()
{
    return valeur;
}

Liste_item *Liste_item::getSuiv()
{
    return suiv;
}

void Liste_item::setSuiv(Liste_item *suivant)
{
    suiv = suivant;
}