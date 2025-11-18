
#include "gtest/gtest.h"
#include "../Oggetto.h"

TEST(TestOggetto, GirnoNonValido) {
    EXPECT_THROW(Oggetto latte("latte", Categoria::Latticini, 2, Data(50,10,2025)), std::invalid_argument);
}
TEST(TestOggetto, MeseNonValido) {
    EXPECT_THROW(Oggetto arista("arista", Categoria::Carne, 3, Data(18, 20, 2026)), std::invalid_argument);
}
TEST(TestOggetto, AnnoNonValido) {
    EXPECT_THROW(Oggetto focaccia("focaccia", Categoria::Panetteria, 1, Data(25, 4, 1996)), std::invalid_argument);
}
TEST(TestOggetto, Creazione) {
    Data data(16, 11, 2025);
    Oggetto CocaCola("CocaCola", Categoria::Bevande, 2, data);
    EXPECT_EQ(CocaCola.getNome(), "CocaCola");
    EXPECT_EQ(CocaCola.getCategoria(), "Bevande");
    EXPECT_EQ(CocaCola.getQuantita(), 2);
    EXPECT_EQ(CocaCola.getData(), "16/11/2025");
}
TEST(TestOggetto, setAcquistato) {
    Oggetto carota("carota", Categoria::Verdura, 8, Data(2, 12, 2025));
    EXPECT_EQ(carota.isAcquistato(), false);
    carota.setAquistato();
    EXPECT_EQ(carota.isAcquistato(), true);
}
TEST(TestOggetto, AggiornaQuantita) {
    Data data(16, 11, 2025);
    Oggetto bigne("bigne", Categoria::Dolci, 3, data);
    EXPECT_EQ(bigne.getQuantita(), 3);
    bigne.setQuantita(5);
    EXPECT_EQ(bigne.getQuantita(), 5);
}
TEST(TestOggetto, AggiornaQuantitaSbagliata) {
    Data data(16, 11, 2025);
    Oggetto birra("birra", Categoria::Alcolici, 6, data);
    EXPECT_EQ(birra.getQuantita(), 2);
    EXPECT_THROW(birra.setQuantita(-2), std::invalid_argument);
}
TEST(TestOggetto, getCategoria) {
    Data data(16, 11, 2025);
    Oggetto spaghetti("spaghetti", Categoria::Pasta, 5, data);
    EXPECT_EQ(spaghetti.getCategoria(), "Pasta");
}
TEST(TestOggetto, getData) {
    Data data(6, 5, 2026);
    Oggetto anguria("anguria", Categoria::Frutta, 2, data);
    EXPECT_EQ(anguria.getData(), "6/5/2026");
}
TEST(TestOggetto, PiuOggetti) {
    Data data1(4,12,2025);
    Data data2(9,12,2025);
    Oggetto arancia("arancia", Categoria::Frutta, 5, data1);
    Oggetto uva("uva", Categoria::Frutta, 7, data2);
    EXPECT_EQ(arancia.getNome(), "arancia");
    EXPECT_EQ(uva.getNome(), "uva");
    EXPECT_EQ(arancia.getCategoria(), "Frutta");
    EXPECT_EQ(uva.getCategoria(), "Frutta");
    EXPECT_EQ(arancia.getQuantita(), 5);
    EXPECT_EQ(uva.getQuantita(), 7);
    EXPECT_EQ(arancia.getData(), "4/12/2025");
    EXPECT_EQ(uva.getData(), "9/12/2025");
}