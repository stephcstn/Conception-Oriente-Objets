#ifndef LISTE_ITEM_HPP
#define LISTE_ITEM_HPP

class liste_item
{
private:
    int value;
    liste_item *suiv;

public:
    liste_item(int n, liste_item *s);
    int getValue();
    liste_item *getSuiv();
    void setValue(int n);
};

#endif