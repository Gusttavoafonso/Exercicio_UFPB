#include "Jogo.h"
#include <iostream>

Jogo::Jogo() : timeCasa(nullptr), timeVisitante(nullptr), juizPrincipal(nullptr), golsTimeCasa(0), golsTimeVisitante(0) {}

Jogo::Jogo(Time* timeCasa, Time* timeVisitante, Juiz* juizPrincipal)
    : timeCasa(timeCasa), timeVisitante(timeVisitante), juizPrincipal(juizPrincipal), golsTimeCasa(0), golsTimeVisitante(0) {}

Time* Jogo::getTimeCasa() const {
    return timeCasa;
}

void Jogo::setTimeCasa(Time* timeCasa) {
    this->timeCasa = timeCasa;
}

Time* Jogo::getTimeVisitante() const {
    return timeVisitante;
}

void Jogo::setTimeVisitante(Time* timeVisitante) {
    this->timeVisitante = timeVisitante;
}

Juiz* Jogo::getJuizPrincipal() const {
    return juizPrincipal;
}

void Jogo::setJuizPrincipal(Juiz* juizPrincipal) {
    this->juizPrincipal = juizPrincipal;
}

int Jogo::getGolsTimeCasa() const {
    return golsTimeCasa;
}

void Jogo::setGolsTimeCasa(int gols) {
    this->golsTimeCasa = gols;
}

int Jogo::getGolsTimeVisitante() const {
    return golsTimeVisitante;
}

void Jogo::setGolsTimeVisitante(int gols) {
    this->golsTimeVisitante = gols;
}

void Jogo::registrarResultado(int golsCasa, int golsVisitante) {
    golsTimeCasa = golsCasa;
    golsTimeVisitante = golsVisitante;

    if (golsCasa > golsVisitante) {
        timeCasa->registrarResultado('V');
        timeVisitante->registrarResultado('D');
    } else if (golsCasa < golsVisitante) {
        timeCasa->registrarResultado('D');
        timeVisitante->registrarResultado('V');
    } else {
        timeCasa->registrarResultado('E');
        timeVisitante->registrarResultado('E');
    }
}

void Jogo::exibirInformacoes() const {
    std::cout << "Resultado do Jogo:\n" << timeCasa->getNome() << " " << golsTimeCasa << " x " << golsTimeVisitante << " " << timeVisitante->getNome() << std::endl;
}
