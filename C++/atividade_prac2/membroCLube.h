#ifndef MEMBROCLUBE_H
#define MEMBROCLUBE_H

#include "Pessoa.h"

class MembroClube : public virtual Pessoa {
protected:
    double salario;

public:
    MembroClube();
    MembroClube(const std::string& nome, int idade, double salario);

    double getSalario() const;
    void setSalario(double salario);

    virtual double calcularSalario() const = 0; // Método puramente virtual

    friend std::ostream& operator<<(std::ostream& os, const MembroClube& membro); // Sobrecarga do operador <<
};

#endif // MEMBROCLUBE_H
