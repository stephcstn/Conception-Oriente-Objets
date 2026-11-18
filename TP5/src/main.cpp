#include <iostream>
#include "../include/mllist.hpp"
int main()
{
    mllist<int> list1;
    mllist<int> list2(42);
    mllist<int> list3(10, list2);

    std::cout << "list3 : " << list3 << std::endl;

    return 0;
}