#ifndef LISTE_ITEM_HPP
#define LISTE_ITEM_HPP

class Liste_item
{
private:
    int valeur;
    Liste_item *suiv;

public:
    Liste_item(int n);
    int getValeur();
    Liste_item *getSuiv();
    void setSuiv(Liste_item *suivant);
};

#endif