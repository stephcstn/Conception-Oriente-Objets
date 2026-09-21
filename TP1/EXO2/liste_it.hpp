#include "liste.hpp"
class Liste_it
{
private:
    Liste &l;
    Liste_item *items;

public:
    Liste_it(Liste &liste);
    bool hasNext();
    int next();
};