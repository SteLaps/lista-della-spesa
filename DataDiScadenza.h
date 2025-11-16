#ifndef LISTA_DELLA_SPESA_DATADISCADENZA_H
#define LISTA_DELLA_SPESA_DATADISCADENZA_H

#include <vector>
#include <stdexcept>
class Data {
private:
    int giorno, mese, anno;
    std::vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //numero di giorni in ciascun mese
public:
    Data(int g, int m, int a) {
        if(a > 2024) {
            if(m > 12 or m < 0) {
                throw std::invalid_argument("Mese non valido");
            }
            if(g < 0 or g > days[m-1]) { //se il giorno è maggiore del numero di giorni validi in quel mese
                throw std::invalid_argument("Giorno non valido");
            }
            giorno = g;
            mese = m;
            anno = a;
        }
        else
            throw std::invalid_argument("Anno non valido");
    }

    std::string getData() const {
        return std::to_string(giorno) + "/" + std::to_string(mese) + "/" + std::to_string(anno);
    }
};
#endif //LISTA_DELLA_SPESA_DATADISCADENZA_H
