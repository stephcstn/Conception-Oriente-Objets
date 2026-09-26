#ifndef LISTE_HPP
#define LISTE_HPP

#include "liste_item.hpp"
class Liste
{
private:
    Liste_item *items;
    int num_version;

    friend class Liste_it;

public:
    Liste();
    void add(int n);
    int size();
    void print();
    int get(int n);
    void clear();
};

#endif