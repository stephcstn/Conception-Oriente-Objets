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