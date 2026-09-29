#pragma once
#include <iostream>

typedef float scal;

class Vecteur
{
    size_t n_dimensions;
    float *m_donnees;

public:
    Vecteur();
    Vecteur(const size_t taille);
    Vecteur(const size_t taille, const scal nombreInit);
    ~Vecteur();
    Vecteur(const Vecteur &rhs);
    Vecteur &operator=(const Vecteur &rhs);
    Vecteur operator+(const Vecteur &rhs) const;
    Vecteur operator-(const Vecteur &rhs) const;
    scal operator*(const Vecteur &rhs) const;
    Vecteur operator*(const double scalaire) const;
    Vecteur operator*(const Vecteur rhs) const;
    Vecteur operator^(const Vecteur &rhs) const;
    size_t size() const;

    // Vecteur &operator+=(const Vecteur &rhs);
    // Vecteur &operator-=(const Vecteur &rhs);
    // Vecteur &operator*=(const double scalaire);
    // Vecteur &operator^=(const Vecteur &rhs);
    // double &operator[](const std::size_t indice);
    // double &operator[](const std::size_t index) const;
};