#include <iostream>
#include "liste_item.cpp"
#include "liste.cpp"

int main()
{
    liste_item i2(2, nullptr);
    liste_item i1(1, &i2);
    std::cout << i1.getValue() << std::endl;
    std::cout << i1.getSuiv()->getValue() << std::endl;
    i2.setValue(3);
    std::cout << i1.getSuiv()->getValue() << std::endl;

    liste myList;
    myList.add(1);
    myList.add(2);
    myList.add(3);

    std::cout << "Size of list: " << myList.size() << std::endl;

    std::cout << "Value at index 0: " << myList.get(0) << std::endl;

    myList.clear();
    std::cout << "Size of list after clear: " << myList.size() << std::endl;

    return 0;
}