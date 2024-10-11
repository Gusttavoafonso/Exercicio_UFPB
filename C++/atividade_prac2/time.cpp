#include "Time.h"
#include <iostream>

Time::Time() : nome("Desconhecido"), tecnico(nullptr), pontuacao(0) {}

Time::Time(const std::string& nome, Tecnico* tecnico) : nome(nome), tecnico(tecnico), pontuacao(0) {}

std::string Time::getNome() const {
    return nome;
}

void Time::setNome(const std::string& nome) {
    this->nome = nome;
}

Tecnico* Time::getTecnico() const {
    return tecnico;
}

void Time::setTecnico(Tecnico* tecnico) {
    this->tecnico = tecnico;
}

int Time::getPontuacao() const {
    return pontuacao;
}

void Time::setPontuacao(int pontuacao) {
    this->pontuacao = pontuacao;
}

void Time::adicionarJogador(const Jogador& jogador) {
    jogadores.push_back(jogador);
}

void Time::registrarResultado(char resultado) {
    if (resultado == 'V') {
        pontuacao += 3;
    } else if (resultado == 'E') {
        pontuacao += 1;
    }
    // Derrota ('D') não altera a pontuação
}

void Time::exibirInformacoes() const {
    std::cout << "Nome do time: " << nome << "\nTécnico: " << tecnico->getNome() << "\nPontuação: " << pontuacao << "\nJogadores:\n";
    for (const auto& jogador : jogadores) {
        std::cout << jogador.getNome() << " - Posição: " << jogador.getPosicao() << " - Gols Marcados: " << jogador.getGolsMarcados() << "\n";
    }
}

bool Time::operator<(const Time& outro) const {
    return this->pontuacao < outro.pontuacao;
}
