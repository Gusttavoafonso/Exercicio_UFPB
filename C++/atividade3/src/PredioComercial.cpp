#include "PredioComercial.h"
#include "Sala.h"
#include <iostream>

// Adicionar uma sala ao prédio
void PredioComercial::adicionar_sala(Sala* sala) {
    lista_de_salas.push_back(sala);
    ordenar_salas_por_andar(); // Ordena as salas após adicionar uma nova
}

// Remover uma sala do prédio
void PredioComercial::remover_sala(Sala* sala) {
    auto it = std::find(lista_de_salas.begin(), lista_de_salas.end(), sala);
    if (it != lista_de_salas.end()) {
        lista_de_salas.erase(it);
    }
}

// Ordenar as salas pelo andar (salas de andares inferiores vêm primeiro)
void PredioComercial::ordenar_salas_por_andar() {
    std::sort(lista_de_salas.begin(), lista_de_salas.end(),
              [](Sala* a, Sala* b) { return *a < *b; });
}

// Sobrecarga do operador + para adicionar uma sala ao prédio
PredioComercial& PredioComercial::operator+(Sala* sala) {
    adicionar_sala(sala);
    return *this;
}

// Sobrecarga do operador - para remover uma sala do prédio
PredioComercial& PredioComercial::operator-(Sala* sala) {
    remover_sala(sala);
    return *this;
}

// Exibir as informações de todas as salas
void PredioComercial::listar_salas() const {
    for (const auto& sala : lista_de_salas) {
        sala->info();
    }
}

std::vector<Sala*> PredioComercial::get_salas() const {
    return lista_de_salas; // Retorna todas as salas
}

std::vector<Empresa> PredioComercial::get_empresas() const {
    std::vector<Empresa> todas_as_empresas;

    for (const auto& sala : lista_de_salas) {
        std::vector<Empresa> empresas_da_sala = sala->get_empresas();
        todas_as_empresas.insert(todas_as_empresas.end(), empresas_da_sala.begin(), empresas_da_sala.end());
    }

    return todas_as_empresas; // Retorna todas as empresas de todas as salas
}