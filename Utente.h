#ifndef LISTA_DELLA_SPESA_UTENTE_H
#define LISTA_DELLA_SPESA_UTENTE_H

#include <string>
#include <map>
#include <memory>
#include "Oggetto.h"
#include "Observer.h"

class Lista;
class Utente : public Observer {
private:
    std::string nome;
    std::map<std::string, std::shared_ptr<Lista>> liste;
public:
    Utente(const std::string& nome) : nome(nome) {}
    void creaLista(const std::string nomeLista);
    void aggiungiOggetto(const std::string& nomeLista, const Oggetto& oggetto);
    void rimuoviOggetto(const std::string& nomeLista, const std::string& nomeOggetto);
    void mostraLista() const;
    void attachToLista(Utente*self,std::shared_ptr<Lista> lista);
    void aggiornaQuantita(const std::string& nomeLIsta, const std::string& nomeOggetto, int& quantita);
    void update(const std::string& nomeLista) override;

    std::shared_ptr<Lista> getLista(const std::string& nomeLista) const;
};

#endif //LISTA_DELLA_SPESA_UTENTE_H
