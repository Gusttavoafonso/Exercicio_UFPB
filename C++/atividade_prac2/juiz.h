#ifndef JUIZ_H
#define JUIZ_H

#include "Pessoa.h"

class Juiz : public Pessoa {
private:
    int partidasArbitradas;

public:
    Juiz();
    Juiz(const std::string& nome, int idade, int partidasArbitradas);

    int getPartidasArbitradas() const;
    void setPartidasArbitradas(int partidasArbitradas);
    
    void incrementarPartidasArbitradas(); // Incrementa o número de partidas arbitradas
    void exibirInformacoes() const override; // Exibe informações do juiz
};

#endif // JUIZ_H
