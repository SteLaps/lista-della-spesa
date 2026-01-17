
#include "gtest/gtest.h"
#include "../Utente.h"
#include "../Lista.h"
TEST(testUtente, AggiornaStessaQuantita) {
    Utente utente ("Stefano");
    utente.creaLista("Spesa");
    utente.aggiungiOggettoAllaLista("Spesa", Oggetto("Branzino", Categoria::Pesce, 4, Data(5,1,2026)));
    utente.aggiungiOggettoAllaLista("Spesa", Oggetto("Nasello", Categoria::Pesce, 4, Data(7,1,2026)));
    utente.aggiornaQuantita("Spesa", "Branzino", 2);
}
TEST(testUtente, SetAcquistatoOggettoGiaAcquistato) {
    Utente utente ("Stefano");
    utente.creaLista("Spesa");
    utente.aggiungiOggettoAllaLista("Spesa", Oggetto("Pizzetta", Categoria::Panetteria, 3, Data(13,7,2026)));
    utente.aggiungiOggettoAllaLista("Spesa", Oggetto("Cavolo", Categoria::Verdura, 1, Data(8,8,2026)));
    utente.aggiungiOggettoAllaLista("Spesa", Oggetto("Manzo", Categoria::Carne, 2, Data(16,2,2026)));
    EXPECT_EQ(utente.getLista("Spesa")->getDaAcquistare(),3);
    utente.setAcquistatoOggetto("Spesa", "Pizzetta");
    EXPECT_EQ(utente.getLista("Spesa")->getDaAcquistare(),2);
    utente.setAcquistatoOggetto("Spesa", "Pizzetta");
    EXPECT_EQ(utente.getLista("Spesa")->getDaAcquistare(),2);
}
TEST(testUtente, AggiornareOggettoNonEsistente) {
    Utente utente("Stefano");
    utente.creaLista("Spesa");
    utente.aggiungiOggettoAllaLista("Spesa", Oggetto("Arancia", Categoria::Frutta, 5, Data(22,3,2026)));
    utente.aggiungiOggettoAllaLista("Spesa", Oggetto("Sgombro", Categoria::Pesce, 3, Data(12,1,2026)));
    utente.aggiungiOggettoAllaLista("Spesa", Oggetto("Pancake", Categoria::Dolci, 3, Data(16,2,2026)));
    EXPECT_EQ(utente.getLista("Spesa")->getDaAcquistare(),3);
    utente.setAcquistatoOggetto("Spesa", "Arancia");
    EXPECT_EQ(utente.getLista("Spesa")->getDaAcquistare(),2);
    EXPECT_THROW(utente.setAcquistatoOggetto("Spesa", "Acqua"), std::invalid_argument);
    utente.mostraLista();
}
TEST(testUtente, CondividiListaConStessoNome) {
    Utente* Stefano = new Utente("Stefano");
    Utente* Niccolo = new Utente("Niccolo");
    Stefano->creaLista("Spesa");
    Stefano->aggiungiOggettoAllaLista("Spesa", Oggetto("Pecorino", Categoria::Latticini, 1, Data(6,3,2026)));
    Niccolo->creaLista("Spesa");
    EXPECT_THROW(Stefano->condividiLista(Niccolo, "Spesa"), std::invalid_argument);
}
TEST(testUtente, AggiungereERimuovereAListeNonEsistenti) {
    Utente utente("Stefano");
    utente.creaLista("Spesa");
    Oggetto fragola("Fragola", Categoria::Frutta, 10, Data(27,1,2026));
    EXPECT_NE(utente.getLista("Spesa"), nullptr);
    utente.aggiungiOggettoAllaLista("Spesa", fragola);
    EXPECT_THROW(utente.aggiungiOggettoAllaLista("Casa", fragola), std::invalid_argument);
    EXPECT_THROW(utente.rimuoviOggettoDallaLista("Casa", "Fragola"), std::invalid_argument);
}
TEST(testUtente, CreaListaConStessoNome) {
    Utente utente("Stefano");
    utente.creaLista("Spesa");
    EXPECT_THROW(utente.creaLista("Spesa"), std::invalid_argument);
}
TEST(testUtente, CostruttoreENome) {
    Utente utente("Stefano");
    EXPECT_EQ(utente.getNome(), "Stefano");
}
TEST(testUtente, CreaLista) {
    Utente utente("Stefano");
    utente.creaLista("Spesa");
    auto lista = utente.getLista("Spesa");
    ASSERT_NE(lista, nullptr);
    EXPECT_EQ(lista->getNomeLista(), "Spesa");
}
TEST(testUtente, AggiungiOggetto) {
    Utente utente("Stefano");
    utente.creaLista("Spesa");
    Oggetto oggetto("Farfalle", Categoria::Pasta, 1, Data(16,3,2026));
    utente.aggiungiOggettoAllaLista("Spesa", oggetto);
    auto lista = utente.getLista("Spesa");
    ASSERT_NE(lista, nullptr);
    EXPECT_EQ(lista->getOggettiTotale(), 1);
}
TEST(testUtente, RimuoviOggetto) {
    Utente utente("Stefano");
    utente.creaLista("Spesa");
    Oggetto oggetto("Lattuga", Categoria::Verdura, 2,Data(7,2,2026));
    utente.aggiungiOggettoAllaLista("Spesa", oggetto);
    EXPECT_EQ(utente.getLista("Spesa")->getOggettiTotale(),1);
    utente.rimuoviOggettoDallaLista("Spesa", "Lattuga");
    ASSERT_NE(utente.getLista("Spesa"), nullptr);
    EXPECT_EQ(utente.getLista("Spesa")->getOggettiTotale(), 0);
}
TEST(testUtente, CondividiLista) {
    Utente *Stefano = new Utente("Stefano");
    Utente *Lorenzo = new Utente("Lorenzo");
    Stefano->creaLista("Spesa");
    Stefano->aggiungiOggettoAllaLista("Spesa", Oggetto("Arista", Categoria::Carne, 5,Data(7,1,2026)));
    Stefano->aggiungiOggettoAllaLista("Spesa", Oggetto("Branzino", Categoria::Pesce, 6,Data(16,1,2026)));
    Stefano->condividiLista(Lorenzo, "Spesa");
    EXPECT_NE(Lorenzo->getLista("Spesa"), nullptr);
    EXPECT_EQ(Lorenzo->getLista("Spesa")->getOggettiTotale(), 2);
    Lorenzo->aggiungiOggettoAllaLista("Spesa", Oggetto("Mandarino", Categoria::Frutta, 8,Data(22,2,2026)));
    EXPECT_EQ(Stefano->getLista("Spesa")->getOggettiTotale(), 3);
    Lorenzo->mostraLista();
    Lorenzo->rimuoviOggettoDallaLista("Spesa", "Branzino");
    EXPECT_EQ(Lorenzo->getLista("Spesa")->getOggettiTotale(), 2);
}
TEST(testUtente, MostraPiuOggetti) {
    Utente utente("Stefano");
    utente.creaLista("Spesa");
    utente.creaLista("Casa");
    Oggetto gorgonzola("Gorgonzola", Categoria::Latticini, 1, Data(24,1,2026));
    utente.aggiungiOggettoAllaLista("Spesa", gorgonzola);
    utente.aggiungiOggettoAllaLista("Casa", gorgonzola);
    utente.aggiungiOggettoAllaLista("Spesa", Oggetto("Cioccolato", Categoria::Dolci, 3, Data(13,3,2026)));
    utente.mostraLista();
    utente.setAcquistatoOggetto("Spesa", "Cioccolato");
}