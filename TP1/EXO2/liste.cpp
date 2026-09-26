#include <iostream>
#include "liste.hpp"

Liste::Liste()
{
    items = nullptr;
    num_version = 0;
}

void Liste::add(int n)
{
    Liste_item *newItems = new Liste_item(n);
    if (items == nullptr)
    {
        items = newItems;
        return;
    }
    Liste_item *current = items;
    while (current->suiv != nullptr)
    {
        current = current->suiv;
    }
    current->suiv = newItems;
    num_version++;
}

int Liste::size()
{
    Liste_item *current = items;
    int count = 0;
    while (current != nullptr)
    {
        count++;
        current = current->suiv;
    }
    return count;
}

void Liste::print()
{
    if (items == nullptr)
    {
        std::cout << "liste vide" << std::endl;
        return;
    }
    Liste_item *current = items;
    while (current->suiv != nullptr)
    {
        std::cout << current->valeur << "->";
        current = current->suiv;
    }
    std::cout << current->valeur << std::endl;
}

int Liste::get(int n)
{
    if (n < 0 || n >= this->size())
    {
        std::cerr << "error : index hors limites" << std::endl;
        return -1;
    }

    Liste_item *current = items;
    int count = 0;

    while (count < n && current != nullptr)
    {
        current = current->suiv;
        count++;
    }

    return current->valeur;
}

void Liste::clear()
{
    Liste_item *current = items;
    while (current != nullptr)
    {
        Liste_item *temp = current;
        current = current->suiv;
        delete temp;
    }
    items = nullptr;
    num_version++;
}