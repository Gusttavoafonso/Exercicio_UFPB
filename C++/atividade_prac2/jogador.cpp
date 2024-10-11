#include "Jogador.h"

Jogador::Jogador() : MembroClube(), posicao("Desconhecida"), golsMarcados(0) {}

Jogador::Jogador(const std::string& nome, int idade, double salario, const std::string& posicao, int golsMarcados)
    : MembroClube(nome, idade, salario), posicao(posicao), golsMarcados(golsMarcados) {}

std::string Jogador::getPosicao() const {
    return posicao;
}

void Jogador::setPosicao(const std::string& posicao) {
    this->posicao = posicao;
}

int Jogador::getGolsMarcados() const {
    return golsMarcados;
}

void Jogador::setGolsMarcados(int golsMarcados) {
    this->golsMarcados = golsMarcados;
}

double Jogador::calcularSalario() const {
    return salario + (golsMarcados * 100);
}

bool Jogador::operator<(const Jogador& outro) const {
    return this->golsMarcados < outro.golsMarcados;
}
