#include "SalaCompartilhada.h"
#include <iostream>

// Construtor
SalaCompartilhada::SalaCompartilhada(int numero, int andar, int numero_estacoes)
    : Sala(numero, andar), numero_de_estacoes_de_trabalho_disponiveis(numero_estacoes) {}

// Definir o número de estações de trabalho disponíveis
void SalaCompartilhada::set_numero_estacoes(int numero_estacoes) {
    numero_de_estacoes_de_trabalho_disponiveis = numero_estacoes;
}

// Obter o número de estações de trabalho disponíveis
int SalaCompartilhada::get_numero_estacoes() const {
    return numero_de_estacoes_de_trabalho_disponiveis;
}

// Implementação do método virtual info()
void SalaCompartilhada::info() const {
    std::cout << "Sala Compartilhada - Número: " << numero_da_sala 
              << ", Andar: " << andar 
              << ", Estaçoes de Trabalho Disponíveis: " 
              << numero_de_estacoes_de_trabalho_disponiveis << std::endl;
}
