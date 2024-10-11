#ifndef JOGADOR_H
#define JOGADOR_H

#include "MembroClube.h"
#include <string>

class Jogador : public MembroClube {
private:
    std::string posicao;
    int golsMarcados;

public:
    Jogador();
    Jogador(const std::string& nome, int idade, double salario, const std::string& posicao, int golsMarcados);

    std::string getPosicao() const;
    void setPosicao(const std::string& posicao);

    int getGolsMarcados() const;
    void setGolsMarcados(int golsMarcados);

    double calcularSalario() const override; // Implementação de calcular_salario

    bool operator<(const Jogador& outro) const; // Sobrecarga do operador <
};

#endif // JOGADOR_H
