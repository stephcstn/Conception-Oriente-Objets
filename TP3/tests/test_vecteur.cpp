#include <gtest/gtest.h>
#include "vecteur.hpp"

TEST(VecteurTest, consParDefNoThrow)
{
    EXPECT_NO_THROW(Vecteur());
}

TEST(VecteurTest, Cons1ArgNoThrow)
{
    EXPECT_NO_THROW(Vecteur(3));
}

TEST(VecteurTest, Cons1ArgThrow)
{
    EXPECT_THROW(Vecteur(-1), std::bad_array_new_length);
}

TEST(VecteurTest, cons2argNoThrow)
{
    EXPECT_NO_THROW(Vecteur(3, 2.0));
}

TEST(VecteurTest, cons2argThrow1)
{
    EXPECT_THROW(Vecteur(-3, 2.0), std::bad_array_new_length);
}

TEST(VecteurTest, consRecopieNoThrow)
{
    Vecteur v1(3, 2.0);
    EXPECT_NO_THROW(Vecteur(v1));
}
