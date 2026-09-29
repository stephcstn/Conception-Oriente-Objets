#include "vecteur.hpp"
#include <stdexcept>

Vecteur::Vecteur() : m_donnees(new scal[2]), n_dimensions(2)
{
}

Vecteur::Vecteur(const size_t taille)
{
    m_donnees = new scal[taille];
    n_dimensions = taille;
}

Vecteur::Vecteur(const size_t taille, const scal nombreInit)
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

Vecteur &Vecteur::operator=(const Vecteur &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    scal *tab_tmp = new scal[rhs.n_dimensions];

    for (size_t i = 0; i < rhs.n_dimensions; i++)
    {
        tab_tmp[i] = rhs.m_donnees[i];
    }

    m_donnees = tab_tmp;

    n_dimensions = rhs.n_dimensions;
}

Vecteur Vecteur::operator+(const Vecteur &rhs) const
{
    if (this->n_dimensions != rhs.n_dimensions)
    {
        throw std::invalid_argument("erreur op+ = dimensions non egales");
    }

    Vecteur res(n_dimensions);

    for (size_t i = 0; i < n_dimensions; i++)
    {
        res.m_donnees[i] = this->m_donnees[i] + rhs.m_donnees[i];
    }

    return res;
}

Vecteur Vecteur::operator-(const Vecteur &rhs) const
{
    if (this->n_dimensions != rhs.n_dimensions)
    {
        throw std::invalid_argument("error op- : dimensions non egales");
    }

    Vecteur res(n_dimensions);

    for (size_t i = 0; i < n_dimensions; i++)
    {
        res.m_donnees[i] = this->m_donnees[i] - rhs.m_donnees[i];
    }

    return res;
}

scal Vecteur::operator*(const Vecteur &rhs) const
{
    if (this->n_dimensions != rhs.n_dimensions)
    {
        throw std::invalid_argument("error op* : dimensions non egales");
    }

    scal res;

    for (size_t i = 0; i < n_dimensions; i++)
    {
        res += this->m_donnees[i] * rhs.m_donnees[i];
    }

    return res;
}

Vecteur Vecteur::operator*(const double scalaire) const
{
    Vecteur v(*this);

    for (size_t i = 0; i < n_dimensions; i++)
    {
        v = v.m_donnees[i] * scalaire;
    }

    return v;
}

Vecteur Vecteur::operator*(const Vecteur rhs) const
{
}

size_t Vecteur::size() const
{
    return n_dimensions;
}
