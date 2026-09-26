#include "liste.hpp"
class Liste_it
{
private:
    Liste &l;
    Liste_item *items_it;
    int num_version_expected;

public:
    Liste_it(Liste &liste);
    bool hasNext();
    int *next();
};