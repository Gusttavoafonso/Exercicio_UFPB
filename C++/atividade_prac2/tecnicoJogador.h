#ifndef TECNICOJOGADOR_H
#define TECNICOJOGADOR_H

#include "Jogador.h"
#include "Tecnico.h"

class TecnicoJogador : public Jogador, public Tecnico {
private:
    double bonusDuploPapel;

public:
    TecnicoJogador();
    TecnicoJogador(const std::string& nome, int idade, double salario, const std::string& posicao, int golsMarcados, int experiencia, double bonusDuploPapel);

    double getBonusDuploPapel() const;
    void setBonusDuploPapel(double bonus);

    double calcularSalario() const override; // Implementação de calcular_salario

    friend std::ostream& operator<<(std::ostream& os, const TecnicoJogador& tecnicoJogador); // Sobrecarga do operador <<
};

#endif // TECNICOJOGADOR_H
