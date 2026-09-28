#include "vecteur.hpp"
#include <stdexcept>

Vecteur::Vecteur() : m_donnees(new scal[2]), n_dimensions(2)
{
}

Vecteur::Vecteur(size_t taille)
{
    m_donnees = new scal[taille];
    n_dimensions = taille;
}

Vecteur::Vecteur(size_t taille, scal nombreInit)
{
    m_donnees = new scal[taille];
    for (size_t i = 0; i < taille; i++)
    {
        m_donnees[i] = nombreInit;
    }
    n_dimensions = taille;
}

Vecteur::~Vecteur()
{
    delete[] m_donnees;
    m_donnees = nullptr;
    n_dimensions = 0;
}

Vecteur::Vecteur(const Vecteur &rhs)
{
    m_donnees = new scal[rhs.n_dimensions];

    for (size_t i = 0; i < rhs.n_dimensions; i++)
    {
        m_donnees[i] = rhs.m_donnees[i];
    }

    n_dimensions = rhs.n_dimensions;
}

size_t Vecteur::size() const
{
    return n_dimensions;
}
