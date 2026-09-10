#ifndef LISTE_IT_EXO3_HPP
#define LISTE_IT_EXO3_HPP

class liste_it
{
private:
    liste_item *items;
    int count;

public:
    bool hasNext();
    void next();
};

#endif