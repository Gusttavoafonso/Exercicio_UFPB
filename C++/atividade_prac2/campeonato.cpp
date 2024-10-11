#include "Campeonato.h"
#include <iostream>
#include <algorithm>

// Construtor padrão
Campeonato::Campeonato() : nomeCampeonato("Desconhecido") {}

// Construtor que inicializa o nome do campeonato
Campeonato::Campeonato(const std::string& nomeCampeonato)
    : nomeCampeonato(nomeCampeonato) {}

// Obtém o nome do campeonato
std::string Campeonato::getNomeCampeonato() const {
    return nomeCampeonato;
}

// Define o nome do campeonato
void Campeonato::setNomeCampeonato(const std::string& nomeCampeonato) {
    this->nomeCampeonato = nomeCampeonato;
}

// Adiciona um time ao campeonato
void Campeonato::adicionarTime(const Time& time) {
    times.push_back(time);
}

// Adiciona um jogo ao campeonato
void Campeonato::adicionarJogo(const Jogo& jogo) {
    jogos.push_back(jogo);
}

// Exibe a classificação dos times, ordenados pela pontuação
void Campeonato::exibirClassificacao() const {
    // Cria uma cópia do vetor de times para ordenação
    std::vector<Time> timesOrdenados = times;

    // Ordena os times pela pontuação (sobrecarga do operador < já definida na classe Time)
    std::sort(timesOrdenados.begin(), timesOrdenados.end(), [](const Time& t1, const Time& t2) {
        return t1.getPontuacao() > t2.getPontuacao(); // Ordena de forma decrescente pela pontuação
    });

    // Exibe a tabela de classificação
    std::cout << "Classificação do Campeonato: " << nomeCampeonato << std::endl;
    for (const auto& time : timesOrdenados) {
        std::cout << "Time: " << time.getNome() << " | Pontuação: " << time.getPontuacao() << std::endl;
    }
}
