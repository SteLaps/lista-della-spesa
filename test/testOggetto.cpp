
#include "gtest/gtest.h"
#include "../Oggetto.h"

TEST(TestOggetto, GirnoNonValido) {
    EXPECT_THROW(Oggetto latte("latte", Category::Latticini, 1, Data(50,10,2025)), std::invalid_argument);
}

TEST(TestOggetto, Creazione) {
    Data data(16, 11, 2025);
    Oggetto CocaCola("CocaCola", Category::Bevande, 2, data);
    EXPECT_EQ(CocaCola.getNome(), "CocaCola");
    EXPECT_EQ(CocaCola.getCategory(), "Bevande");
    EXPECT_EQ(CocaCola.getQuantita(), 2);
    EXPECT_EQ(CocaCola.getData(), "16/11/2025");
}