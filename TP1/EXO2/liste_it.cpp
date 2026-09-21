#include "liste_it.hpp"

Liste_it::Liste_it(Liste &liste) : l(liste)
{
    items = l.getItems();
}

bool Liste_it::hasNext()
{
    return items != nullptr;
}

int Liste_it::next()
{
    if (items == nullptr)
    {
        return -1;
    }

    int val = items->getValeur();
    items = items->getSuiv();
    return val;
}