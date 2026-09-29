#include <gtest/gtest.h>
#include "vecteur.hpp"

TEST(VecteurTest, Constructeurs) {
    Vecteur v_defaut;
    EXPECT_EQ(v_defaut.size(), 2);

    Vecteur v_taille(5);
    EXPECT_EQ(v_taille.size(), 5);

    Vecteur v_init(3, 4.5);
    EXPECT_EQ(v_init.size(), 3);
}

// Test de l'indépendance de la copie (constructeur et affectation)
TEST(VecteurTest, CopieEtAffectation) {
    Vecteur v1(3, 2.0);
    
    // Constructeur par copie
    Vecteur v2(v1);
    EXPECT_EQ(v2, v1);

    // Opérateur d'affectation
    Vecteur v3(1, 0.0);
    v3 = v1;
    EXPECT_EQ(v3, v1);

    // Auto-affectation (ne doit pas planter ni vider les données)
    EXPECT_NO_THROW({
        v3 = v3;
    });
    EXPECT_EQ(v3, v1);
}

TEST(VecteurTest, OperationsArithmetiques) {
    Vecteur a(2, 5.0);
    Vecteur b(2, 2.0);

    EXPECT_EQ(a == a, true);

    // 1. Addition (5.0 + 2.0 = 7.0)
    Vecteur attendu_somme(2, 7.0);
    EXPECT_EQ(a + b, attendu_somme);

    // 2. Soustraction (5.0 - 2.0 = 3.0)
    Vecteur attendu_diff(2, 3.0);
    EXPECT_EQ(a - b, attendu_diff);

    // 3. Produit scalaire (5*2 + 5*2 = 20)
    EXPECT_DOUBLE_EQ(a * b, 20.0);

    // 4. Multiplication par un scalaire (5.0 * 2.0 = 10.0)
    Vecteur attendu_mult(2, 10.0);
    EXPECT_EQ(a * 2.0, attendu_mult);

    Vecteur v1(3,3.0);
    Vecteur v2(3,6.0);

    // produit vectoriel 
    Vecteur attendu_vectoriel(3,0.0);
    EXPECT_EQ(v1^v2,attendu_vectoriel);

    // produit vectoriel avec affectation
    v1 ^= v2;
    EXPECT_EQ(v1,attendu_vectoriel);

    // somme avec affectation
    a += b; // a devient (2, 7.0)
    EXPECT_EQ(a,attendu_somme);

    // soustraction avec affectation
    Vecteur v3(2, 10.0);
    Vecteur v4(2, 5.0);
    Vecteur attendu_diff_aff(2, 5.0);
    v3 -= v4;
    EXPECT_EQ(v3,attendu_diff_aff);

    // multiplication avec affectation
    Vecteur attendu_mult_aff(2, 25.0);
    v4 *= 5;
    EXPECT_EQ(v4,attendu_mult_aff);

    // indexation const
    Vecteur v5(2, 5.0);
    scal indice3 = v5[1];
    EXPECT_EQ(indice3,5.0);

    // indexation
    v5[1] = 3.0;
    EXPECT_EQ(v5[1],3.0);

    // normalisation d'un vecteur
    Vecteur v6(2,2.0);
    EXPECT_NEAR(v6.norm(), 2.8284, 2.8285);
}