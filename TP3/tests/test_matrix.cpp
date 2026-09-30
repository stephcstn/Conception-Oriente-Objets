#include <gtest/gtest.h>
#include "matrix.hpp"
#include <fstream>

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

    // indexation const
    Matrix m8(2,2,5.0);
    scal copy = m8(1,1);
    EXPECT_EQ(copy,5.0);

    // indexation
    m8(1,1) = 3.0;
    copy = m8(1,1);
    EXPECT_EQ(copy,3.0);

    // transposition
    Matrix m9(2, 2, 5.0);
    m9(0,0) = 3.0;
    m9(0,1) = 4.0;
    m9(1,1) = 6.0;

    m9.transposition(); 

    Matrix m10(2, 2, 5.0);
    m10(0,0) = 3.0;
    m10(0,1) = 5.0;
    m10(1,0) = 4.0;
    m10(1,1) = 6.0;

    EXPECT_EQ(m9, m10);
    m10.afficher();

    //ecrire fichier et fermer pour pouvoir ecrire
    {
        std::ofstream out("matrice.txt");
        out << m9;
    } 
    std::ifstream fichier("matrice.txt");
    Matrix m11;
    fichier >> m11;
    std::cout << m11;
}