#ifndef LISTA_DELLA_SPESA_OGGETTO_H
#define LISTA_DELLA_SPESA_OGGETTO_H

#include <string>
#include "DataDiScadenza.h"

enum Category {Carne, Pesce, Panetteria, Frutta, Verdura, Latticini, Bevande, Dolci, Casa, Igene, Giardino, Cartoleria};

class Oggetto {
private:
    std::string nome;
    Category categoria;
    int quantita;
    Data data;
    bool acquistato;
public:
    Oggetto(const std::string& nome, enum Category categoria, int quantita, const Data& data);

    std::string getNome() const;
    std::string getCategory() const;
    int getQuantita() const;
    void setQuantita(int quantita);
    std::string getData() const;
    bool isAcquistato() const;
    std::string getState() const;
    void setAquistato();
};
#endif //LISTA_DELLA_SPESA_OGGETTO_H
