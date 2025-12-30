#include <iostream>
#include "Utente.h"
#include "Lista.h"
#include "Oggetto.h"

int main() {
    try {
        // Creazione utenti
        Utente stefano("Stefano");
        Utente lorenzo("Lorenzo");

        // Crea una lista
        stefano.creaLista("Spesa Settimanale");

        // Condivisione lista
        std::cout << "---  condividi la lista  ---" << std::endl;
        stefano.condividiLista(&lorenzo, "Spesa Settimanale");

        // Creazione oggetti
        Oggetto latte("Latte", Categoria::Latticini, 2, Data(10, 2, 2025));
        Oggetto pane("Pane", Categoria::Panetteria, 4, Data(5, 2, 2025));
        Oggetto pasta("Pasta", Categoria::Pasta, 3, Data(30, 6, 2025));
        Oggetto mele("Mele", Categoria::Frutta, 6, Data(15, 2, 2025));
        Oggetto arista("Arista", Categoria::Carne, 3, Data(18, 1, 2025));
        Oggetto focaccia("Focaccia", Categoria::Panetteria, 1, Data(25, 4, 2025));

        // Aggiunta oggetti alla lista
        stefano.aggiungiOggetto("Spesa Settimanale", latte);
        stefano.aggiungiOggetto("Spesa Settimanale", pane);
        stefano.aggiungiOggetto("Spesa Settimanale", pasta);
        stefano.aggiungiOggetto("Spesa Settimanale", mele);
        stefano.aggiungiOggetto("Spesa Settimanale", arista);
        stefano.aggiungiOggetto("Spesa Settimanale", focaccia);

        // Mostra stato lista
        std::cout << "--- Liste  ---" << std::endl;
        stefano.mostraLista();

        // Aggiorna quantità
        std::cout << "---  aggiorna la quantità  ---" << std::endl;
        stefano.aggiornaQuantita("Spesa Settimanale", "Pasta", 5);
        stefano.aggiornaQuantita("Spesa Settimanale", "Mele", 6);
        stefano.aggiornaQuantita("Spesa Settimanale", "Arista", 5);
        stefano.aggiornaQuantita("Spesa Settimanale", "Focaccia", 3);

        // Segna come acquistato
        std::cout << "---  segna come acquistato  ---" << std::endl;
        stefano.setAcquistatoOggetto("Spesa Settimanale", "Pane");
        stefano.setAcquistatoOggetto("Spesa Settimanale", "Latte");


        // Modifica la lista condivisa
        std::cout << "---  modifica lista condivisa  ---" << std::endl;
        lorenzo.rimuoviOggetto("Spesa Settimanale", "Mele");
        lorenzo.mostraLista();
        stefano.mostraLista();

    }
    catch (const std::exception& e) {
        std::cerr << "Errore: " << e.what() << std::endl;
    }

    return 0;
}