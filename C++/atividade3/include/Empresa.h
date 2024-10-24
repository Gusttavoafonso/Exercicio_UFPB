#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>

class Empresa {
private:
    std::string nome_da_empresa;
    int idade_da_empresa; // em anos de mercado

public:
    // Construtor
    Empresa(std::string nome = "", int idade = 0);

    // Métodos set e get para o nome
    void set_nome(const std::string& nome);
    std::string get_nome() const;

    // Métodos set e get para a idade
    void set_idade(int idade);
    int get_idade() const;

    // Sobrecarga do operador < para comparação
    bool operator<(const Empresa& outra) const;
    
    // Sobrecarga do operador ==
    bool operator==(const Empresa &outra) const;
};

#endif // EMPRESA_H
