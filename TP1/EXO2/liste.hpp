#ifndef LISTE_HPP
#define LISTE_HPP

#include "liste_item.hpp"
class Liste
{
private:
    Liste_item *items;

public:
    Liste();
    Liste_item *getItems();
    void add(int n);
    int size();
    void print();
    int get(int n);
    void clear();
};

#endif