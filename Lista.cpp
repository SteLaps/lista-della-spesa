
#include <iostream>
#include "Lista.h"

void Lista::aggiungiOggetto(const Oggetto &oggetto) {
    if(oggetti.find(oggetto.getNome()) == oggetti.end()) {
        oggetti[oggetto.getNome()] = oggetto;
        notify();
    }
    else {
        throw std::invalid_argument("Oggetto non esistente nella lista");
    }
}
void Lista::rimuoviOggetto(const std::string &nomeOggetto) {
    if(oggetti.find(nomeOggetto) != oggetti.end()) {
        auto oggetto = oggetti.find(nomeOggetto);
        oggetti.erase(oggetto);
        notify();
    } else {
        throw std::invalid_argument("Oggetto non esistente nella lista");
    }
}
void Lista::aggiornaQuantita(const std::string &nomeOggetto, int quantita) {
    auto it = oggetti.find(nomeOggetto);
    if (it != oggetti.end()) {
        if (it ->second.getQuantita() != quantita) {
            it->second.setQuantita(quantita);
            notify();
        }
        else return;
    } else {
        throw std::invalid_argument("Oggetto non esistente nella lista");
    }
}
void Lista::listaOgggetti() const {
    std::cout << "Oggetti totali: " << getOggettiTotale() << std::endl;
    std::cout << "Oggetti non comprati: " << getDaAcquistare() << std::endl;
    for (const auto& oggetto : oggetti) {
        std::cout << "Oggetto: " << oggetto.second.getNome() << ", Categoria: " << oggetto.second.getCategory()
        << ", Quantità: " << oggetto.second.getQuantita() << ", da consumarsi entro il: " << oggetto.second.getData()
        << " " << oggetto.second.getState() << std::endl;
    }
}
std::string Lista::getNomeLista() const {
    return nome;
}
int Lista::getOggettiTotale() const {
    int count = 0;
    for(auto it : oggetti) {
        count++;
    }
    return count;
}
int Lista::getDaAcquistare() const {
    int count = 0;
    for(auto it : oggetti) {
        if(!it.second.isAcquistato()) {
            count++;
        }
    }
        return count;
}
void Lista::setAcquistati(const std::string &nomeOggetto) {
    auto it = oggetti.find(nomeOggetto);
    if (it != oggetti.end()) {
        if(!it->second.isAcquistato()) {
            it->second.setAquistato();
            notify();
        } else return;
    } else {
        throw std::invalid_argument("Oggetto non esistente nella lista");
    }
}
void Lista::attach(Observer *o) {
    observers.push_back(0);
}
void Lista::detach(Observer *o) {
    observers.remove(0);
}
void Lista::notify() {
    for(const auto& it : observers) {
        it->update(getNomeLista());
    }
}