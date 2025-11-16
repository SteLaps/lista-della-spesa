#ifndef LISTA_DELLA_SPESA_OGGETTO_H
#define LISTA_DELLA_SPESA_OGGETTO_H

#include <string>
#include "DataDiScadenza.h"

enum Categoria {Carne, Pesce, Panetteria, Frutta, Verdura, Latticini, Bevande, Dolci, Casa, Igene, Giardino, Cartoleria};

class Oggetto {
private:
    std::string nome;
    Categoria categoria;
    int quantita;
    Data data;
    bool acquistato;
public:
    Oggetto(const std::string& nome, enum Categoria categoria, int quantita, const Data& data);
    Oggetto() : nome(""), categoria(Categoria::Carne), quantita(0), data(Data(1, 1, 2026)), acquistato(false) {};

    std::string getNome() const;
    std::string getCategoria() const;
    int getQuantita() const;
    void setQuantita(int quantita);
    std::string getData() const;
    bool isAcquistato() const;
    std::string getState() const;
    void setAquistato();
};
#endif //LISTA_DELLA_SPESA_OGGETTO_H
