#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa {
protected:
    std::string nome;
    int idade;

public:
    // Construtor com parâmetros
    Pessoa(const std::string& nome, int idade);

    // Getter e Setter para nome
    std::string getNome() const;
    void setNome(const std::string& nome);

    // Getter e Setter para idade
    int getIdade() const;
    void setIdade(int idade);

    // Método virtual para exibir informações
    virtual void exibirInformacoes() const;

    // Sobrecarga do operador ==
    bool operator==(const Pessoa& outra) const;

    // Destrutor virtual
    virtual ~Pessoa();
};

#endif // PESSOA_H
