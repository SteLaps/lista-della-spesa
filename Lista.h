#ifndef LISTA_DELLA_SPESA_LISTA_H
#define LISTA_DELLA_SPESA_LISTA_H

#include <list>
#include <map>
#include <memory>
#include "Oggetto.h"
#include "Subject.h"
#include "Observer.h"

class Lista : public Subject {
private:
    std::map<std::string, Oggetto> oggetti;
    std::string nome;
    std::list<Observer*> observers;
public:
    Lista(const std::string& NomeLista) : nome(NomeLista) {}

    void aggiungiOggetto(const Oggetto& oggetto);
    void rimuoviOggetto(const std::string& nomeOggetto);
    void aggiornaQuantita(const std::string& nomeOggetto, int quantita);
    void listaOgggetti() const;
    std::string getNomeLista() const;
    int getOggettiTotale() const;
    int getDaAcquistare() const;
    void setAcquistati(const std::string& nomeOggetto);

    void attach(Observer* o) override;
    void detach(Observer* o) override;
    void notify() override;
};

#endif //LISTA_DELLA_SPESA_LISTA_H
