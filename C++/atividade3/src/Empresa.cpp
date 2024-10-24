#include "Empresa.h"

// Construtor
Empresa::Empresa(std::string nome, int idade)
    : nome_da_empresa(nome), idade_da_empresa(idade) {}

// Definir o nome da empresa
void Empresa::set_nome(const std::string& nome) {
    nome_da_empresa = nome;
}

// Obter o nome da empresa
std::string Empresa::get_nome() const {
    return nome_da_empresa;
}

// Definir a idade da empresa
void Empresa::set_idade(int idade) {
    idade_da_empresa = idade;
}

// Obter a idade da empresa
int Empresa::get_idade() const {
    return idade_da_empresa;
}

// Sobrecarga do operador < para comparar empresas pela idade
bool Empresa::operator<(const Empresa& outra) const {
    return idade_da_empresa < outra.idade_da_empresa;

}

    // Implementação do operador ==
bool Empresa::operator==(const Empresa &outra) const {
    return nome_da_empresa == outra.nome_da_empresa && 
        idade_da_empresa == outra.idade_da_empresa;
}
