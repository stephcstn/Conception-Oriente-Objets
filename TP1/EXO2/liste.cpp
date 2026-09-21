#include <iostream>
#include "liste.hpp"

Liste::Liste()
{
    items = nullptr;
}

Liste_item *Liste::getItems()
{
    return items;
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
    while (current->getSuiv() != nullptr)
    {
        current = current->getSuiv();
    }
    current->setSuiv(newItems);
}

int Liste::size()
{
    Liste_item *current = items;
    int count = 0;
    while (current != nullptr)
    {
        count++;
        current = current->getSuiv();
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
    while (current->getSuiv() != nullptr)
    {
        std::cout << current->getValeur() << "->";
        current = current->getSuiv();
    }
    std::cout << current->getValeur() << std::endl;
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
        current = current->getSuiv();
        count++;
    }

    return current->getValeur();
}

void Liste::clear()
{
    Liste_item *current = items;
    while (current != nullptr)
    {
        Liste_item *temp = current;
        current = current->getSuiv();
        delete temp;
    }
    items = nullptr;
}