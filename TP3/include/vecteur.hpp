#pragma once
#include <iostream>

typedef float scal;

class Vecteur{
    size_t n_dimensions;
    float *m_donnees;
    public:
    Vecteur(std::size_t taille = 1, float valInit = 0.0);
    ~Vecteur();
    Vecteur(const Vecteur& rhs);
    Vecteur operator+(const Vecteur& b);
    Vecteur operator-(const Vecteur& b);
    double operator*(const Vecteur& b);
    VecteurD operator*(const double scalaire);
    VecteurD operator*(const VecteurD v);
    Vecteur operator^(const VecteurD& b);
    VecteurD& operator+=(const VecteurD& b);
    VecteurD& operator-=(const VecteurD& b);
    VecteurD& operator*=(const double scalaire);
    VecteurD& operator^=(const VecteurD& b);
    double& operator[](std::size_t indice);
    const double& operator[](std::size_t index) const;
    size_t size() const;
}