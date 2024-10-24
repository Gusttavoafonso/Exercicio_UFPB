#ifndef SALACOMPARTILHADA_H
#define SALACOMPARTILHADA_H

#include "Sala.h"

class SalaCompartilhada : public Sala {
private:
    int numero_de_estacoes_de_trabalho_disponiveis;

public:
    // Construtor
    SalaCompartilhada(int numero, int andar, int numero_estacoes);

    // Métodos set e get para o número de estações de trabalho
    void set_numero_estacoes(int numero_estacoes);
    int get_numero_estacoes() const;

    // Implementação do método virtual info()
    void info() const override;
};

#endif // SALACOMPARTILHADA_H
