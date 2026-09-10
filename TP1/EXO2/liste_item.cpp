#include <iostream>
#include "liste_item.hpp"

liste_item::liste_item(int n, liste_item *s)
{
    value = n;
    suiv = s;
}

int liste_item::getValue()
{
    return value;
}

void liste_item::setValue(int n)
{
    value = n;
}

liste_item *liste_item::getSuiv()
{
    return suiv;
}
