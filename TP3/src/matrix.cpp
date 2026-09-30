#include <iostream>
#include "matrix.hpp"

Matrix::Matrix()
{
    m_mat = new scal*[2];
    for (size_t i = 0; i < 2 ; i++){
        m_mat[i] = new scal[2];
    }
    m_lignes = 2;
    m_col = 2;
}

Matrix::Matrix(const size_t lignes, const size_t col){
    m_mat = new scal*[lignes];
    for (size_t i = 0 ; i < lignes ; i++){
        m_mat[i] = new scal[col];
    }
    m_lignes = lignes;
    m_col = col;
}

Matrix::Matrix(const size_t lignes, const size_t col, const scal initVal){
    m_mat = new scal*[lignes];
    for (size_t i = 0 ; i < lignes ; i++){
        m_mat[i] = new scal[col];
        for (size_t j = 0 ; j < col ; j++){
            m_mat[i][j] = initVal;
        }
    }
    m_lignes = lignes;
    m_col = col;
}

Matrix::Matrix(const Vecteur &v){
    if (v.size() == 0){
        return;
    }

    m_mat = new scal*[1];
    m_mat[0] = new scal[v.size()];

    for (size_t j = 0 ; j < v.size() ; j++){
        m_mat[0][j] = v[j];
    }

    m_lignes = 1;
    m_col = v.size();
}

Matrix::~Matrix(){
    for (size_t i = 0 ; i < m_lignes ; i++){
        delete[] m_mat[i];
    }
    delete[] m_mat;
    m_mat = nullptr;
    m_lignes = 0;
    m_col = 0;
}

Matrix::Matrix(const Matrix &rhs){
    m_mat = new scal*[rhs.m_lignes];
    for (size_t i = 0 ; i < rhs.m_lignes ; i++){
        m_mat[i] = new scal[rhs.m_col];
        for (size_t j = 0 ; j < rhs.m_col ; j++){
            m_mat[i][j] = rhs.m_mat[i][j];
        }
    }

    m_lignes = rhs.m_lignes;
    m_col = rhs.m_col;
}

Matrix &Matrix::operator=(const Matrix &rhs){
    if (this == &rhs) {
        return *this;
    }

    scal **mat_tmp = new scal*[rhs.m_lignes];

    for (size_t i = 0; i < rhs.m_lignes; i++)
    {
        mat_tmp[i] = new scal[rhs.m_col];
        for (size_t j = 0 ; j < rhs.m_col ; j++){
            mat_tmp[i][j] = rhs.m_mat[i][j];
        }
    }

    for (size_t i = 0 ; i < m_lignes ; i++){
        delete[] m_mat[i];
    }

    delete[] m_mat;
    m_mat = mat_tmp;
    m_lignes = rhs.m_lignes;
    m_col = rhs.m_col;

    return *this;
}

bool Matrix::operator==(const Matrix &rhs) const{
    if (this == &rhs) {
        return true;
    }

    if (m_lignes != rhs.m_lignes || m_col != rhs.m_col){
        return false;
    }

    for (size_t i = 0 ; i < m_lignes ; i++){
        for (size_t j = 0 ; j < m_col ; j++){
            if (m_mat[i][j] != rhs.m_mat[i][j]){
                return false;
            }
        }
    }

    return true;
}

bool Matrix::operator==(const Vecteur &rhs) const{
    if (m_lignes != 1 || m_col != rhs.size()){
        return false;
    }
    for (size_t j = 0 ; j < m_col ; j++){
        if (m_mat[0][j] != rhs[j]){
            return false;
        }
    }

    return true;
}

Matrix Matrix::operator+(const Matrix &rhs) const{
    if (m_lignes != rhs.m_lignes || m_col != rhs.m_col){
        throw std::invalid_argument("Erreur d'addition : les matrices doivent avoir les memes dimensions.");
    }
    Matrix res(rhs);

    for (size_t i = 0 ; i < m_lignes ; i++){
        for (size_t j = 0 ; j < m_col ; j++){
            res.m_mat[i][j] = this->m_mat[i][j] + rhs.m_mat[i][j];
        }
    }

    return res;
}

Matrix Matrix::operator-(const Matrix &rhs) const{
    if (m_lignes != rhs.m_lignes || m_col != rhs.m_col){
        throw std::invalid_argument("Erreur de soustraction : les matrices doivent avoir les memes dimensions.");
    }
    Matrix res(rhs);

    for (size_t i = 0 ; i < m_lignes ; i++){
        for (size_t j = 0 ; j < m_col ; j++){
            res.m_mat[i][j] = this->m_mat[i][j] - rhs.m_mat[i][j];
        }
    }

    return res;
}

Matrix Matrix::operator*(const Matrix &rhs) const{
    if (m_lignes != rhs.m_lignes || m_col != rhs.m_col){
        throw std::invalid_argument("Erreur de multiplication : les matrices doivent avoir les memes dimensions.");
    }
    Matrix res(rhs);

    for (size_t i = 0 ; i < m_lignes ; i++){
        for (size_t j = 0 ; j < m_col ; j++){
            res.m_mat[i][j] = this->m_mat[i][j] * rhs.m_mat[i][j];
        }
    }

    return res;
}

Matrix &Matrix::operator+=(const Matrix &rhs){
    if (m_lignes != rhs.m_lignes || m_col != rhs.m_col){
        throw std::invalid_argument("Erreur d'addition : les matrices doivent avoir les memes dimensions.");
    }

    for (size_t i = 0 ; i < m_lignes ; i++){
        for (size_t j = 0 ; j < m_col ; j++){
            m_mat[i][j] += rhs.m_mat[i][j];
        }
    }

    return *this;
}

Matrix &Matrix::operator-=(const Matrix &rhs){
    if (m_lignes != rhs.m_lignes || m_col != rhs.m_col){
        throw std::invalid_argument("Erreur de soustraction : les matrices doivent avoir les memes dimensions.");
    }

    for (size_t i = 0 ; i < m_lignes ; i++){
        for (size_t j = 0 ; j < m_col ; j++){
            m_mat[i][j] -= rhs.m_mat[i][j];
        }
    }

    return *this;
}

Matrix &Matrix::operator*=(const Matrix &rhs){
    if (m_lignes != rhs.m_lignes || m_col != rhs.m_col){
        throw std::invalid_argument("Erreur de multiplication : les matrices doivent avoir les memes dimensions.");
    }

    for (size_t i = 0 ; i < m_lignes ; i++){
        for (size_t j = 0 ; j < m_col ; j++){
            m_mat[i][j] *= rhs.m_mat[i][j];
        }
    }

    return *this;
}

size_t Matrix::nb_lignes() const{
    return m_lignes;
}

size_t Matrix::nb_col() const{
    return m_col;
}