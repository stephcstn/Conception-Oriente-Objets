#ifndef LISTE_HPP
#define LISTE_HPP

#include "liste_item.hpp"

class liste
{

private:
    liste_item *items;
    int count;

public:
    liste();
    void add(int n);
    int size();
    void clear();
    int get(int index);
};

#endif