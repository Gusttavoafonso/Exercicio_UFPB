#include "TecnicoJogador.h"

TecnicoJogador::TecnicoJogador() : Jogador(), Tecnico(), bonusDuploPapel(0.0) {}

TecnicoJogador::TecnicoJogador(const std::string& nome, int idade, double salario, const std::string& posicao, int golsMarcados, int experiencia, double bonusDuploPapel)
    : Jogador(nome, idade, salario, posicao, golsMarcados), Tecnico(nome, idade, salario, experiencia), bonusDuploPapel(bonusDuploPapel) {}

double TecnicoJogador::getBonusDuploPapel() const {
    return bonusDuploPapel;
}

void TecnicoJogador::setBonusDuploPapel(double bonus) {
    this->bonusDuploPapel = bonus;
}

double TecnicoJogador::calcularSalario() const {
    return Jogador::calcularSalario() + Tecnico::calcularSalario() + bonusDuploPapel;
}

std::ostream& operator<<(std::ostream& os, const TecnicoJogador& tecnicoJogador) {
    os << "Nome: " << tecnicoJogador.getNome() << "\nIdade: " << tecnicoJogador.getIdade()
       << "\nSalário: " << tecnicoJogador.calcularSalario()
       << "\nPosição: " << tecnicoJogador.getPosicao()
       << "\nGols Marcados: " << tecnicoJogador.getGolsMarcados()
       << "\nExperiência: " << tecnicoJogador.getExperiencia()
       << "\nBônus Duplo Papel: " << tecnicoJogador.getBonusDuploPapel();
    return os;
}
