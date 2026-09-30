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
    }
    m_lignes = lignes;
    m_col = col;
}

size_t Matrix::nb_lignes() const{
    return m_lignes;
}

size_t Matrix::nb_col() const{
    return m_col;
}