#ifndef TIME_H
#define TIME_H

#include <string>
#include <vector>
#include "Jogador.h"
#include "Tecnico.h"

class Time {
private:
    std::string nome;
    Tecnico* tecnico;
    std::vector<Jogador> jogadores;
    int pontuacao;

public:
    Time();
    Time(const std::string& nome, Tecnico* tecnico);

    std::string getNome() const;
    void setNome(const std::string& nome);

    Tecnico* getTecnico() const;
    void setTecnico(Tecnico* tecnico);

    int getPontuacao() const;
    void setPontuacao(int pontuacao);

    void adicionarJogador(const Jogador& jogador); // Adiciona um jogador ao time
    void registrarResultado(char resultado); // Atualiza a pontuação com base no resultado

    void exibirInformacoes() const; // Exibe as informações completas do time
    bool operator<(const Time& outro) const; // Sobrecarga do operador < para comparar pela pontuação
};

#endif // TIME_H
