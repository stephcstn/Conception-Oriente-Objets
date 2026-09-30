#include "vecteur.hpp"
#include <stdexcept>
#include <math.h>

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

bool Vecteur::operator==(const Vecteur &rhs) const{
    if (this == &rhs) {
        return true;
    }
    
    if (n_dimensions != rhs.n_dimensions){
        return false;
    }

    for (size_t i = 0 ; i < n_dimensions ; i++){
        if (m_donnees[i] != rhs.m_donnees[i]){
            return false;
        }
    }

    return true;
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

    delete[] m_donnees;
    m_donnees = nullptr;

    m_donnees = tab_tmp;

    n_dimensions = rhs.n_dimensions;

    return *this;
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

    scal res = 0;

    for (size_t i = 0; i < n_dimensions; i++)
    {
        res += m_donnees[i] * rhs.m_donnees[i];
    }

    return res;
}

Vecteur Vecteur::operator*(const double scalaire) const
{
    Vecteur v(*this);

    for (size_t i = 0; i < n_dimensions; i++)
    {
        v.m_donnees[i] = this->m_donnees[i] * scalaire;
    }

    return v;
}

Vecteur Vecteur::operator^(const Vecteur &rhs) const{
    if (n_dimensions != 3 || rhs.n_dimensions != 3){
        throw std::invalid_argument("error op^ : ce n'est pas des vecteurs 3D");
    }
    Vecteur v(*this);

    const scal &x1 = m_donnees[0];
    const scal &y1 = m_donnees[1];
    const scal &z1 = m_donnees[2];

    const scal &x2 = rhs.m_donnees[0];
    const scal &y2 = rhs.m_donnees[1];
    const scal &z2 = rhs.m_donnees[2];

    v.m_donnees[0] = y1*z2 - y2*z1;
    v.m_donnees[1] = x2*z1 - x1*z2;
    v.m_donnees[2] = x1*y2 - x2*y1;

    return v;
}

Vecteur &Vecteur::operator^=(const Vecteur &rhs){
    if (n_dimensions != 3 || rhs.n_dimensions != 3){
        throw std::invalid_argument("error op^ : ce n'est pas des vecteurs 3D");
    }

    const scal x1 = m_donnees[0];
    const scal y1 = m_donnees[1];
    const scal z1 = m_donnees[2];

    const scal &x2 = rhs.m_donnees[0];
    const scal &y2 = rhs.m_donnees[1];
    const scal &z2 = rhs.m_donnees[2];

    m_donnees[0] = y1*z2 - y2*z1;
    m_donnees[1] = x2*z1 - x1*z2;
    m_donnees[2] = x1*y2 - x2*y1;

    return *this;
}


Vecteur &Vecteur::operator+=(const Vecteur &rhs){
    if (n_dimensions != rhs.n_dimensions){
        throw std::invalid_argument("error op+= : dimensions non egales");
    }

    for (size_t i = 0 ; i < n_dimensions ; i++){
        m_donnees[i] += rhs.m_donnees[i];
    }

    return *this;
}

Vecteur &Vecteur::operator-=(const Vecteur &rhs){
    if (n_dimensions != rhs.n_dimensions){
        throw std::invalid_argument("error op-= : dimensions non egales");
    }

    for (size_t i = 0 ; i < n_dimensions ; i++){
        m_donnees[i] -= rhs.m_donnees[i];
    }

    return *this;
}
Vecteur &Vecteur::operator*=(const double scalaire){
    for (size_t i = 0 ; i < n_dimensions ; i++){
        m_donnees[i] *= scalaire;
    }

    return *this;
}

scal &Vecteur::operator[](const std::size_t index){
    return m_donnees[index];
}

const scal &Vecteur::operator[](const std::size_t index) const{
    return m_donnees[index];
}

const size_t &Vecteur::size() const
{
    return n_dimensions;
}

const scal Vecteur::norm() const{
    scal somme = 0;
    for (size_t i = 0; i < n_dimensions ; i++){
        somme += pow(m_donnees[i],2);
    }
    return sqrt(somme);
}
