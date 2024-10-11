#include "Pessoa.h"
#include <iostream>

// Construtor padrão
Pessoa::Pessoa() : nome("Desconhecido"), idade(0) {}

// Construtor com parâmetros
Pessoa::Pessoa(const std::string& nome, int idade) : nome(nome), idade(idade) {}

// Getter para nome
std::string Pessoa::getNome() const {
    return nome;
}

// Setter para nome
void Pessoa::setNome(const std::string& nome) {
    this->nome = nome;
}

// Getter para idade
int Pessoa::getIdade() const {
    return idade;
}

// Setter para idade
void Pessoa::setIdade(int idade) {
    this->idade = idade;
}

// Método virtual para exibir informações
void Pessoa::exibirInformacoes() const {
    std::cout << "Nome: " << nome << "\nIdade: " << idade << std::endl;
}

// Sobrecarga do operador ==
bool Pessoa::operator==(const Pessoa& outra) const {
    return (this->nome == outra.nome) && (this->idade == outra.idade);
}

// Destrutor virtual
Pessoa::~Pessoa() {}

