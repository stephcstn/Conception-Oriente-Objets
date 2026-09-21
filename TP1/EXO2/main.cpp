#include <iostream>
#include "liste.hpp"
#include "liste_item.hpp"

int main()
{
    Liste liste1 = Liste();
    liste1.add(4);
    liste1.add(7);
    liste1.add(10);

    liste1.print();

    std::cout << liste1.get(2) << std::endl;

    std::cout << "la taille de la liste est : " << liste1.size() << std::endl;

    liste1.clear();
    liste1.print();

    return 0;
}