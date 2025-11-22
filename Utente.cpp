
#include <iostream>
#include "Utente.h"
#include "Lista.h"

void Utente::creaLista(const std::string& nomeLista) {
    if (liste.find(nomeLista) != liste.end()) {
        throw std::invalid_argument("Lista già esistente");
    } else {
        auto lista = std::make_shared<Lista>(nomeLista);
        liste[nomeLista] = lista;
        lista->attach(this);
    }
}
void Utente::aggiungiOggetto(const std::string& nomeLista, const Oggetto& oggetto) {
    if (liste.find(nomeLista) != liste.end()) {
        liste[nomeLista]->aggiungiOggetto(oggetto);
    } else {
        throw std::invalid_argument("Lista non trovata");
    }
}
void Utente::rimuoviOggetto(const std::string& nomeLista, const std::string& nomeOggetto) {
    if (liste.find(nomeLista) != liste.end()) {
        liste[nomeLista]->rimuoviOggetto(nomeOggetto);
    } else {
        throw std::invalid_argument("Lista non trovata");
    }
}
void Utente::mostraLista() const {
    std::cout << "Utente: " << nome << "gestisce le liste: " << std::endl;
    for (const auto& it : liste) {
        std::cout << "- " << it.first << std::endl;
        it.second->listaOgggetti();
    }
}
void Utente::attachToLista(Utente *self, std::shared_ptr<Lista> lista) {
    auto nomeLista = lista->getNomeLista();
    if (liste.find(nomeLista) == liste.end()) {
        liste[nomeLista] = lista;
        lista->attach(self);
    } else {
        throw std::invalid_argument("Lista già esistente");
    }
}
void Utente::aggiornaQuantita(const std::string& nomeLista, const std::string& nomeOggetto,const int& quantita) {
    auto lista = getLista(nomeLista);
    lista->aggiornaQuantitaOggetto(nomeOggetto, quantita);
}
void Utente::update(const std::string& nomeLista) {
    auto lista = getLista(nomeLista);
    std::cout << "La lista: " << lista->getNomeLista() << " è stata modificata, ora è: " << std::endl;
    lista->listaOgggetti();
}
std::string Utente::getNome() const {
    return nome;
}
void Utente::condividiLista(Utente *utente, const std::string &nomeLista) {
    auto lista = getLista(nomeLista);
    utente->attachToLista(utente, lista);
    std::cout << "Lista: " << lista->getNomeLista() << " , condivisa con " << utente->getNome() << std::endl;
}
void Utente::setAcquistatoOggetto(const std::string &nomeLista, const std::string &nomeOggetto) {
    auto lista = getLista(nomeLista);
    lista->setAcquistati(nomeOggetto);
}
std::shared_ptr<Lista> Utente::getLista(const std::string& nomeLista) const {
    auto it = liste.find(nomeLista);
    if (it != liste.end()) {
        return it->second;
    } else {
        throw std::invalid_argument("Non esiste questa lista");
    }
}