
#include "gtest/gtest.h"
#include "../Lista.h"

TEST(TestLista, RimuovereOggettoNonEsistente) {
    Lista listaDellaSpesa("spesa");
    Oggetto sgombro("sgombro", Categoria::Pesce, 3, Data(30, 12, 2025));
    listaDellaSpesa.aggiungiOggetto(sgombro);
    EXPECT_EQ(listaDellaSpesa.getOggettiTotale(), 1);
    EXPECT_THROW(listaDellaSpesa.rimuoviOggetto("salmone"), std::invalid_argument);
}
TEST(TestLista, AggiungereStessoOggetto) {
    Lista listaDellaSpesa("spesa");
    Oggetto vino("vino", Categoria::Alcolici, 1, Data(13,2,2026));
    listaDellaSpesa.aggiungiOggetto(vino);
    Oggetto vino2("vino",Categoria::Alcolici, 1, Data(13,2,2026));
    EXPECT_THROW(listaDellaSpesa.aggiungiOggetto(vino2), std::invalid_argument);
}
TEST(TestLista, AggiornareOggettoNonEsistente) {
    Lista listaDellaSpesa("spesa");
    Oggetto nasello("nasello", Categoria::Pesce, 3, Data(24,1,2026));
    listaDellaSpesa.aggiungiOggetto(nasello);
    EXPECT_THROW(listaDellaSpesa.aggiornaQuantitaOggetto("salmone", 5), std::invalid_argument);
}
TEST(TestLista, SetAcquistatoOggettoNonEsistente) {
    Lista listaDellaSpesa("spesa");
    Oggetto rigatoni("rigatoni", Categoria::Pasta, 5, Data(16, 6, 2026));
    listaDellaSpesa.aggiungiOggetto(rigatoni);
    EXPECT_THROW(listaDellaSpesa.setAcquistati("penne"), std::invalid_argument);
}
TEST(TestLista, getDaAcquistareESetAcquistati) {
    Lista listaDellaSpesa("spesa");
    Oggetto manzo("manzo", Categoria::Carne, 4, Data(12,12,2025));
    listaDellaSpesa.aggiungiOggetto(manzo);
    Oggetto branzino("branziono", Categoria::Pesce, 3, Data(5,12,2025));
    listaDellaSpesa.aggiungiOggetto(branzino);
    Oggetto vodka("vodka", Categoria::Alcolici, 1, Data(19,4,2026));
    listaDellaSpesa.aggiungiOggetto(vodka);
    EXPECT_EQ(listaDellaSpesa.getDaAcquistare(),3);
    listaDellaSpesa.setAcquistati("manzo");
    EXPECT_EQ(listaDellaSpesa.getDaAcquistare(), 2);
    listaDellaSpesa.setAcquistati("branziono");
    EXPECT_EQ(listaDellaSpesa.getDaAcquistare(),1);
    listaDellaSpesa.rimuoviOggetto("vodka");
}
TEST(TestLista, CostruttoreEGetNomeLista) {
    Lista listaDellaSpesa("spesa");
    EXPECT_EQ(listaDellaSpesa.getNomeLista(), "spesa");
}
TEST(TestLista, AggiungiOggetto) {
    Lista listaDellaSpesa("spesa");
    Oggetto mandarino("mandarino", Categoria::Frutta, 16, Data(16,12,2025));
    EXPECT_EQ(listaDellaSpesa.getOggettiTotale(), 0);
    listaDellaSpesa.aggiungiOggetto(mandarino);
    EXPECT_EQ(listaDellaSpesa.getOggettiTotale(), 1);
}
TEST(TestLista, RimuoviOggetto) {
    Lista listaDellaSpesa("spesa");
    Oggetto sardina("sardina", Categoria::Pesce, 8, Data(23,1,2026));
    listaDellaSpesa.aggiungiOggetto(sardina);
    EXPECT_EQ(listaDellaSpesa.getOggettiTotale(), 1);
    listaDellaSpesa.rimuoviOggetto("sardina");
    EXPECT_EQ(listaDellaSpesa.getOggettiTotale(), 0);
}