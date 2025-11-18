
#include "Oggetto.h"

Oggetto::Oggetto(const std::string& nome, enum Categoria categoria, int quantita, const Data& data)
        : nome(nome), categoria(categoria), quantita(quantita), data(data), acquistato(false) {}

std::string Oggetto::getNome() const {
    return nome;
}
std::string Oggetto::getCategoria() const {
    switch (categoria) {
        case Categoria::Carne:      return "Carne";
        case Categoria::Pesce:      return "Pesce";
        case Categoria::Panetteria: return "Panetteria";
        case Categoria::Frutta:     return "Frutta";
        case Categoria::Verdura:    return "Verdura";
        case Categoria::Latticini:  return "Latticini";
        case Categoria::Bevande:    return "Bevande";
        case Categoria::Dolci:      return "Dolci";
        case Categoria::Alcolici:   return "Alcolici";
        case Categoria::Pasta:      return "Pasta";
    }
}
int Oggetto::getQuantita() const {
    return quantita;
}
void Oggetto::setQuantita(int quantita) {
    if (quantita > 0) {
        this->quantita = quantita;
    } else {
        throw std::invalid_argument("Quantità selezionata negativa");
    }
}
std::string Oggetto::getData() const {
    return data.getData();
}
bool Oggetto::isAcquistato() const {
    return acquistato;
}
std::string Oggetto::getState() const {
    if(acquistato)
        return "Acquistato";
    else
        return "Non Acquistato";
}
void Oggetto::setAquistato() {
    acquistato = true;
}
