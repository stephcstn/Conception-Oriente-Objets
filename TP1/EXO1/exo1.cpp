#include <iostream>

int main()
{
    int a = 239;
    int *p;

    std::cout << "Hello, World!" << std::endl;
    std::cout << "La valeur de a est: " << a << std::endl;
    std::cout << "Adresse mémoire de a: " << &a << std::endl;
    std::cout << std::endl;

    std::cout << "La valeur de p est: " << p << std::endl;
    std::cout << "Adresse mémoire de p: " << &p << std::endl;
    std::cout << "La valeur pointée par p est: " << *p << std::endl;
    std::cout << std::endl;

    p = NULL;

    std::cout << "La valeur de p est: " << p << std::endl;
    std::cout << "Adresse mémoire de p: " << &p << std::endl;
    std::cout << std::endl;

    p = &a;

    std::cout << "La valeur de p est: " << p << std::endl;
    std::cout << "Adresse mémoire de p: " << &p << std::endl;
    std::cout << "La valeur pointée par p est: " << *p << std::endl;
    std::cout << std::endl;

    int &r = a;

    std::cout << "La valeur de r est: " << r << std::endl;
    std::cout << "Adresse mémoire de r: " << &r << std::endl;
    std::cout << std::endl;

    std::cout << "La taille de a est: " << sizeof(a) << " octets" << std::endl;
    std::cout << "La taille de p est: " << sizeof(p) << " octets" << std::endl;
    std::cout << "La taille de r est: " << sizeof(r) << " octets" << std::endl;
    std::cout << std::endl;

    std::cout << "La taille de int est: " << sizeof(int) << " octets" << std::endl;
    std::cout << "La taille de int* est: " << sizeof(int *) << " octets" << std::endl;
    std::cout << std::endl;

    std::cout << "La taille de float est: " << sizeof(float) << " octets" << std::endl;
    std::cout << "La taille de float* est: " << sizeof(float *) << " octets" << std::endl;
    std::cout << std::endl;

    std::cout << "La taille de double est: " << sizeof(double) << " octets" << std::endl;
    std::cout << "La taille de double* est: " << sizeof(double *) << " octets" << std::endl;
    std::cout << std::endl;

    std::cout << "La taille de char est: " << sizeof(char) << " octets" << std::endl;
    std::cout << "La taille de char* est: " << sizeof(char *) << " octets" << std::endl;
    std::cout << std::endl;

    std::cout << "La taille de bool est: " << sizeof(bool) << " octets" << std::endl;
    std::cout << "La taille de bool* est: " << sizeof(bool *) << " octets" << std::endl;
    std::cout << std::endl;

    std::cout << "La taille de long est: " << sizeof(long) << " octets" << std::endl;
    std::cout << "La taille de long* est: " << sizeof(long *) << " octets" << std::endl;
    std::cout << std::endl;

    std::cout << "La taille de short est: " << sizeof(short) << " octets" << std::endl;
    std::cout << "La taille de short* est: " << sizeof(short *) << " octets" << std::endl;
    std::cout << std::endl;

    return 0;
}