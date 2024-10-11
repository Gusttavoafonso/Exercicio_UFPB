#ifndef CAMPEONATO_H
#define CAMPEONATO_H

#include <string>
#include <vector>
#include "Time.h"
#include "Jogo.h"

class Campeonato {
private:
    std::string nomeCampeonato;
    std::vector<Time> times;
    std::vector<Jogo> jogos;

public:
    Campeonato();
    Campeonato(const std::string& nomeCampeonato);

    std::string getNomeCampeonato() const;
    void setNomeCampeonato(const std::string& nomeCampeonato);

    void adicionarTime(const Time& time); // Adiciona um time ao campeonato
    void adicionarJogo(const Jogo& jogo); // Adiciona um jogo ao campeonato

    void exibirClassificacao() const; // Exibe a classificação dos times pela pontuação
};

#endif // CAMPEONATO_H
