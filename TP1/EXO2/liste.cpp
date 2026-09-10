#include <iostream>
#include "liste.hpp"

liste::liste()
{
    items = nullptr;
    count = 0;
}

void liste::add(int n)
{
    liste_item *newItem = new liste_item(n, items);
    items = newItem;
    count++;
}

int liste::size()
{
    return count;
}

int liste::get(int index)
{
    liste_item *current = items;
    if (index < 0 || index >= count)
    {
        std::cerr << "Index out of bounds" << std::endl;
        return -1; // or throw an exception
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            current = current->getSuiv();
        }
    }
    return current->getValue();
}

void liste::clear()
{
    for (int i = 0; i < count; i++)
    {
        liste_item *current = items;
        items = items->getSuiv();
        delete current;
    }
    count = 0;
}
