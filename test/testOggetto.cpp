
#include "gtest/gtest.h"
#include "../Oggetto.h"

TEST(TestOggetto, GirnoNonValido) {
    EXPECT_THROW(Oggetto latte("latte", Category::Latticini, 1, Data(50,10,2025)), std::invalid_argument);
}
