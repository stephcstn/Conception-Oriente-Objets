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
    void setSuiv(liste_item *s);
};

liste_item::liste_item(int n, liste_item *s)
{
    value = n;
    suiv = s;
}

int liste_item::getValue()
{
    return value;
}

void liste_item::setSuiv(liste_item *s)
{
    suiv = s;
}

void liste_item::setValue(int n)
{
    value = n;
}

liste_item *liste_item::getSuiv()
{
    return suiv;
}