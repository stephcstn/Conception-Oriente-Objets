#pragma once
#include "vecteur.hpp"
#include <iostream>

class Matrix{
    size_t m_lignes;
    size_t m_col;
    scal **m_mat;

    public: 
    Matrix();
    Matrix(const size_t lignes, const size_t col);
    Matrix(const size_t lignes, const size_t col, const scal initVal);
    Matrix(const Vecteur &v);
    ~Matrix();
    Matrix(const Matrix &rhs);
    Matrix &operator=(const Matrix &rhs);
    bool operator==(const Matrix &rhs) const;
    bool operator==(const Vecteur &rhs) const;
    Matrix operator+(const Matrix &rhs) const;
    Matrix operator-(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs) const;
    Matrix &operator+=(const Matrix &rhs);
    Matrix &operator-=(const Matrix &rhs);
    Matrix &operator*=(const Matrix &rhs);
    scal& operator()(const size_t i, const size_t j);
    const scal& operator()(const size_t i, const size_t j) const;
    Matrix &transposition();
    size_t nb_lignes() const;
    size_t nb_col() const;
    void afficher() const;
};

const std::ostream& operator<<(std::ostream& os, const Matrix& m);
std::istream& operator>>(std::istream& is, Matrix& m);