#ifndef SALA_H
#define SALA_H

#include <vector>
#include <algorithm> // Para std::sort
#include "Empresa.h"

class Sala {
protected:
    int numero_da_sala;
    int andar;
    std::vector<Empresa> lista_de_empresas_locatarias;

public:
    // Construtor
    Sala(int numero = 0, int andar = 0);

    // Métodos set e get para número e andar
    void set_numero(int numero);
    int get_numero() const;

    void set_andar(int andar);
    int get_andar() const;

    // Método para obter a lista de empresas
    std::vector<Empresa> get_empresas() const;

    // Método para ordenar as empresas por idade
    void ordenar_empresas_por_idade();

    // Sobrecarga do operador < para comparação de salas por andar
    bool operator<(const Sala& outra) const;

    // Sobrecarga dos operadores + e - para adicionar/remover empresas
    Sala& operator+(const Empresa& empresa);
    Sala& operator-(const Empresa& empresa);

    // Método virtual puro para garantir que a classe é abstrata
    virtual void info() const = 0;
};

#endif // SALA_H
