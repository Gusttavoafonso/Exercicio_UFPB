#include "SalaPrivativa.h"
#include <iostream>

// Construtor
SalaPrivativa::SalaPrivativa(int numero, int andar, int capacidade_maxima)
    : Sala(numero, andar), capacidade_maxima_de_pessoas(capacidade_maxima) {}

// Definir a capacidade máxima de pessoas
void SalaPrivativa::set_capacidade_maxima(int capacidade) {
    capacidade_maxima_de_pessoas = capacidade;
}

// Obter a capacidade máxima de pessoas
int SalaPrivativa::get_capacidade_maxima() const {
    return capacidade_maxima_de_pessoas;
}

// Implementação do método virtual info()
void SalaPrivativa::info() const {
    std::cout << "Sala Privativa - Número: " << numero_da_sala 
              << ", Andar: " << andar 
              << ", Capacidade Máxima: " << capacidade_maxima_de_pessoas 
              << " pessoas" << std::endl;
}
