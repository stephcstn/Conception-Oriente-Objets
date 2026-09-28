#pragma once
#include <iostream>

typedef float scal;

class Vecteur
{
    size_t n_dimensions;
    float *m_donnees;

public:
    Vecteur();
    Vecteur(size_t taille);
    Vecteur(size_t taille, scal nombreInit);
    ~Vecteur();
    Vecteur(const Vecteur &rhs);
    Vecteur &operator=(const Vecteur &rhs);
    Vecteur operator+(const Vecteur &b);
    size_t size() const;
    // Vecteur operator-(const Vecteur &b);
    // double operator*(const Vecteur &b);
    // Vecteur operator*(const double scalaire);
    // Vecteur operator*(const Vecteur v);
    // Vecteur operator^(const Vecteur &b);
    // Vecteur &operator+=(const Vecteur &b);
    // Vecteur &operator-=(const Vecteur &b);
    // Vecteur &operator*=(const double scalaire);
    // Vecteur &operator^=(const Vecteur &b);
    // double &operator[](std::size_t indice);
    // const double &operator[](std::size_t index) const;
    // size_t size() const;
};