#include "Sala.h"

// Construtor
Sala::Sala(int numero, int andar)
    : numero_da_sala(numero), andar(andar) {}

// Definir o número da sala
void Sala::set_numero(int numero) {
    numero_da_sala = numero;
}

// Obter o número da sala
int Sala::get_numero() const {
    return numero_da_sala;
}

// Definir o andar
void Sala::set_andar(int andar) {
    this->andar = andar;
}

// Obter o andar
int Sala::get_andar() const {
    return andar;
}

// Obter a lista de empresas locatárias
std::vector<Empresa> Sala::get_empresas() const {
    return lista_de_empresas_locatarias;
}

// Ordenar as empresas pela idade (empresas mais antigas vêm primeiro)
void Sala::ordenar_empresas_por_idade() {
    std::sort(lista_de_empresas_locatarias.begin(), lista_de_empresas_locatarias.end());
}

// Sobrecarga do operador < para comparar salas pelo andar
bool Sala::operator<(const Sala& outra) const {
    return andar < outra.andar;
}

// Sobrecarga do operador + para adicionar uma empresa
Sala& Sala::operator+(const Empresa& empresa) {
    lista_de_empresas_locatarias.push_back(empresa);
    ordenar_empresas_por_idade(); // Ordenar empresas após adição
    return *this;
}

// Sobrecarga do operador - para remover uma empresa
Sala& Sala::operator-(const Empresa& empresa) {
    auto it = std::find(lista_de_empresas_locatarias.begin(), lista_de_empresas_locatarias.end(), empresa);
    if (it != lista_de_empresas_locatarias.end()) {
        lista_de_empresas_locatarias.erase(it);
    }
    return *this;
}
