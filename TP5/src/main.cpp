#include <iostream>
#include "../include/mllist.hpp"
int main()
{
    mllist<int> list1;
    mllist<int> list2(42);
    mllist<int> list3(10, list2);

    mllist<int> list4(34, list2);
    list4 + 2;
    //std::cout << "list4 : " << list4 << std::endl;

    std::cout << "list3 : " << list3 << std::endl;

    return 0;
}