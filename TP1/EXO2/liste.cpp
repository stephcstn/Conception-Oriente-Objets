#include <iostream>
#include "liste_item.cpp"

class liste
{

private:
    liste_item *items;
    int count;

public:
    liste();
    void add(int n, int index, liste_item *items);
    int size();
    void clear();
    int get(int index, liste_item *items);
};

liste::liste()
{
    items = nullptr;
    count = 0;
}

void liste::add(int n, int index, liste_item *items)
{
    items->setSuiv(items->getSuiv());
    items[index] = *items;
}

// a refaire plus tard add est faux

int liste::size()
{
    return count;
}

int liste::get(int index, liste_item *items)
{
    return items[index].getValue();
}

void liste::clear()
{
    items = nullptr;
    count = 0;
}