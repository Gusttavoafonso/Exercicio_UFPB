#include "MembroClube.h"
#include <iostream>

MembroClube::MembroClube() : Pessoa(), salario(0.0) {}

MembroClube::MembroClube(const std::string& nome, int idade, double salario)
    : Pessoa(nome, idade), salario(salario) {}

double MembroClube::getSalario() const {
    return salario;
}

void MembroClube::setSalario(double salario) {
    this->salario = salario;
}

// Sobrecarga do operador <<
std::ostream& operator<<(std::ostream& os, const MembroClube& membro) {
    os << "Nome: " << membro.nome << "\nIdade: " << membro.idade << "\nSalário: " << membro.salario;
    return os;
}
