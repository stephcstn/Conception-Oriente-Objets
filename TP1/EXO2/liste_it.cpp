#include "iostream"
#include "liste_it.hpp"

Liste_it::Liste_it(Liste &liste) : l(liste)
{
    items_it = l.items;
    num_version_expected = l.num_version;
}

bool Liste_it::hasNext()
{
    if (l.num_version != num_version_expected){
        std::cerr << "Erreur : modification concurrente de la liste detectee !" << std::endl;
        return false;
    }
    return items_it != nullptr;
}

int *Liste_it::next()
{
    if (l.num_version != num_version_expected){
        std::cerr << "Erreur : modification concurrente de la liste detectee !" << std::endl;
        return nullptr;
    }
    if (items_it == nullptr){
        return nullptr;
    }
    int* valeur = &(items_it->valeur);
    items_it = items_it->suiv;
    return valeur;
    
}