#include "Juiz.h"
#include <iostream>

Juiz::Juiz() : Pessoa(), partidasArbitradas(0) {}

Juiz::Juiz(const std::string& nome, int idade, int partidasArbitradas)
    : Pessoa(nome, idade), partidasArbitradas(partidasArbitradas) {}

int Juiz::getPartidasArbitradas() const {
    return partidasArbitradas;
}

void Juiz::setPartidasArbitradas(int partidasArbitradas) {
    this->partidasArbitradas = partidasArbitradas;
}

void Juiz::incrementarPartidasArbitradas() {
    partidasArbitradas++;
}

void Juiz::exibirInformacoes() const {
    std::cout << "Nome: " << nome << "\nIdade: " << idade << "\nPartidas Arbitradas: " << partidasArbitradas << std::endl;
}
