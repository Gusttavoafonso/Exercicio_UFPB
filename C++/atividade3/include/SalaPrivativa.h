#ifndef SALAPRIVATIVA_H
#define SALAPRIVATIVA_H

#include "Sala.h"

class SalaPrivativa : public Sala {
private:
    int capacidade_maxima_de_pessoas;

public:
    // Construtor
    SalaPrivativa(int numero, int andar, int capacidade_maxima);

    // Métodos set e get para capacidade máxima de pessoas
    void set_capacidade_maxima(int capacidade);
    int get_capacidade_maxima() const;

    // Implementação do método virtual info()
    void info() const override;
};

#endif // SALAPRIVATIVA_H
