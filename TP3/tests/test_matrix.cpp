#include <gtest/gtest.h>
#include "matrix.hpp"

TEST(MatrixTest, Constructeurs) {
    Matrix m_defaut;
    EXPECT_EQ(m_defaut.nb_lignes(), 2);
    EXPECT_EQ(m_defaut.nb_col(), 2);
}