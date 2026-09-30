#pragma once
#include <iostream>

typedef float scal;

class Vecteur
{
    size_t n_dimensions;
    scal *m_donnees;

public:
    Vecteur();
    Vecteur(const size_t taille);
    Vecteur(const size_t taille, const scal nombreInit);
    ~Vecteur();
    Vecteur(const Vecteur &rhs);
    bool operator==(const Vecteur &rhs) const;
    Vecteur &operator=(const Vecteur &rhs);

    Vecteur operator+(const Vecteur &rhs) const;
    Vecteur operator-(const Vecteur &rhs) const;
    scal operator*(const Vecteur &rhs) const;
    Vecteur operator*(const double scalaire) const;
    Vecteur operator^(const Vecteur &rhs) const;

    Vecteur &operator^=(const Vecteur &rhs);
    Vecteur &operator+=(const Vecteur &rhs);
    Vecteur &operator-=(const Vecteur &rhs);
    Vecteur &operator*=(const double scalaire);
    scal &operator[](const std::size_t index);
    const scal &operator[](const std::size_t index) const;
    const size_t &size() const;
    const scal norm() const;
};