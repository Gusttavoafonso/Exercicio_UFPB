#ifndef TECNICO_H
#define TECNICO_H

#include "MembroClube.h"

class Tecnico : public MembroClube {
private:
    int experiencia;

public:
    Tecnico();
    Tecnico(const std::string& nome, int idade, double salario, int experiencia);

    int getExperiencia() const;
    void setExperiencia(int experiencia);

    double calcularSalario() const override; // Implementação de calcular_salario
};

#endif // TECNICO_H
