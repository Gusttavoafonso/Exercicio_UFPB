#ifndef JOGO_H
#define JOGO_H

#include "Time.h"
#include "Juiz.h"

class Jogo {
private:
    Time* timeCasa;
    Time* timeVisitante;
    Juiz* juizPrincipal;
    int golsTimeCasa;
    int golsTimeVisitante;

public:
    Jogo();
    Jogo(Time* timeCasa, Time* timeVisitante, Juiz* juizPrincipal);

    Time* getTimeCasa() const;
    void setTimeCasa(Time* timeCasa);

    Time* getTimeVisitante() const;
    void setTimeVisitante(Time* timeVisitante);

    Juiz* getJuizPrincipal() const;
    void setJuizPrincipal(Juiz* juizPrincipal);

    int getGolsTimeCasa() const;
    void setGolsTimeCasa(int gols);

    int getGolsTimeVisitante() const;
    void setGolsTimeVisitante(int gols);

    void registrarResultado(int golsCasa, int golsVisitante); // Atualiza o resultado do jogo

    void exibirInformacoes() const; // Exibe o resultado do jogo
};

#endif // JOGO_H
