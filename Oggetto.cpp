
#include "Oggetto.h"

Oggetto::Oggetto(const std::string& nome, enum Category categoria, int quantita, const Data& data)
        : nome(nome), categoria(categoria), quantita(quantita), data(data), acquistato(false) {}

std::string Oggetto::getNome() const {
    return nome;
}
std::string Oggetto::getCategory() const {
    switch (categoria) {
        case Category::Carne:      return "Carne";
        case Category::Pesce:      return "Pesce";
        case Category::Panetteria: return "Panetteria";
        case Category::Frutta:     return "Frutta";
        case Category::Verdura:    return "Verdura";
        case Category::Latticini:  return "Latticini";
        case Category::Bevande:    return "Bevande";
        case Category::Dolci:      return "Dolci";
        case Category::Casa:       return "Casa";
        case Category::Igene:      return "Igene";
        case Category::Giardino:   return "Giardino";
        case Category::Cartoleria: return "Cartoleria";
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
