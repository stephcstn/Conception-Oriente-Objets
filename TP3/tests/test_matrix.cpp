#include <gtest/gtest.h>
#include "matrix.hpp"

TEST(MatrixTest, Constructeurs) {
    Matrix m_defaut;
    EXPECT_EQ(m_defaut.nb_lignes(), 2);
    EXPECT_EQ(m_defaut.nb_col(), 2);

    Matrix m_taille(3,3);
    EXPECT_EQ(m_taille.nb_lignes(), 3);
    EXPECT_EQ(m_taille.nb_col(), 3);

    Matrix m_init(3,3,2.0);
    EXPECT_EQ(m_init.nb_lignes(), 3);
    EXPECT_EQ(m_init.nb_col(), 3);

    Vecteur v1(2,2.0);
    Matrix m_vec(v1);
    EXPECT_EQ(m_vec, v1);
}

// Test de l'indépendance de la copie (constructeur et affectation)
TEST(MatrixTest, CopieEtAffectation) {
    Matrix m1(3, 2, 2.0);
    
    // Constructeur par copie
    Matrix m2(m1);
    EXPECT_EQ(m2, m1);

    // Opérateur d'affectation
    Matrix m3(1, 1, 2.0);
    m3 = m1;
    EXPECT_EQ(m3, m1);

    // Auto-affectation (ne doit pas planter ni vider les données)
    EXPECT_NO_THROW({
        m3 = m3;
    });
    EXPECT_EQ(m3, m1);
}

TEST(VecteurTest, OperationsArithmetiques) {
    Matrix m1(2, 2, 3.0);
    Matrix m2(2, 2 , 5.0);
    Matrix m3(1,2,2.0);
    Vecteur v(2,2.0);

    // operateur egalité matrice et matrice
    EXPECT_TRUE(m1 == m1);

    // operateur egalité matrice et vecteur
    EXPECT_TRUE(m3 == v);
    
    // operateur addition
    Matrix attendu_somme(2, 2 , 8.0);
    EXPECT_EQ(m1 + m2, attendu_somme);

    // operateur soustraction
    Matrix attendu_soustraction(2, 2 , 2.0);
    EXPECT_EQ(m2 - m1, attendu_soustraction);

    // operateur multiplication
    Matrix attendu_mult(2, 2, 15.0);
    EXPECT_EQ(m1 * m2, attendu_mult);

    //operateur d'affectation addition
    Matrix m4(2, 2, 3.0);
    Matrix m5(2, 2, 5.0);
    m4 += m5;
    EXPECT_EQ(m4, attendu_somme);

    //operateur d'affectation soustraction
    Matrix m6(2, 2, 3.0);
    m5 -= m6;
    EXPECT_EQ(m5, attendu_soustraction);

    //operateur d'affectation multiplication
    Matrix m7(2, 2, 5.0);
    m6 *= m7;
    EXPECT_EQ(m6, attendu_mult);
}