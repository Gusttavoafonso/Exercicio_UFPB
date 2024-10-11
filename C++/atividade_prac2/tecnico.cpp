#include "Tecnico.h"

Tecnico::Tecnico() : MembroClube(), experiencia(0) {}

Tecnico::Tecnico(const std::string& nome, int idade, double salario, int experiencia)
    : MembroClube(nome, idade, salario), experiencia(experiencia) {}

int Tecnico::getExperiencia() const {
    return experiencia;
}

void Tecnico::setExperiencia(int experiencia) {
    this->experiencia = experiencia;
}

double Tecnico::calcularSalario() const {
    return salario + (experiencia * 200);
}
