#ifndef PREDIOCOMERCIAL_H
#define PREDIOCOMERCIAL_H

#include <vector>
#include <algorithm>  // Para std::sort
#include "Sala.h"

class PredioComercial {
private:
    std::vector<Sala*> lista_de_salas;

public:
    // Construtor padrão
    PredioComercial() {}

    // Adicionar e remover sala
    void adicionar_sala(Sala* sala);
    void remover_sala(Sala* sala);

    // Ordenar salas por andar
    void ordenar_salas_por_andar();

    // Sobrecarga dos operadores + e -
    PredioComercial& operator+(Sala* sala);
    PredioComercial& operator-(Sala* sala);

    // Exibir informações das salas
    void listar_salas() const;

    std::vector<Sala*> get_salas() const; // Método para retornar as salas
    std::vector<Empresa> get_empresas() const; // Método para retornar todas as empresas
};

#endif // PREDIOCOMERCIAL_H
