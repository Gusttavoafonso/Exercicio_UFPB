# Sistema de Controle de Locação para Salas Comerciais

Este projeto é um sistema de controle de locação para gerenciar salas comerciais em um prédio. Ele permite que empresas locatárias sejam associadas a salas, que podem ser salas privativas ou compartilhadas. O sistema usa conceitos de herança, composição e polimorfismo, além da sobrecarga de operadores para adicionar e remover elementos.

## Funcionalidades
Adicionar Salas:

Sala Privativa: Adiciona uma sala privativa com capacidade máxima de pessoas.
Sala Compartilhada: Adiciona uma sala compartilhada com número de estações de trabalho disponíveis.
Remover Sala: Remove uma sala do prédio, utilizando seu número como referência.

Adicionar Empresa a uma Sala: Adiciona uma empresa à lista de locatários de uma sala específica.

Remover Empresa de uma Sala: Remove uma empresa da lista de locatários de uma sala.

Listar Salas e Empresas: Exibe todas as salas e as empresas locatárias associadas, ordenadas pelo andar e pela idade das empresas.

## Estrutura do Projeto
Empresa.h e Empresa.cpp: Implementa a classe Empresa, que representa uma empresa locatária.
Sala.h e Sala.cpp: Implementa a classe abstrata Sala, que serve de base para os tipos de sala (privativa e compartilhada).
SalaPrivativa.h e SalaPrivativa.cpp: Implementa a classe SalaPrivativa, derivada de Sala, com um atributo adicional para capacidade máxima.
SalaCompartilhada.h e SalaCompartilhada.cpp: Implementa a classe SalaCompartilhada, derivada de Sala, com um atributo adicional para o número de estações de trabalho disponíveis.
PredioComercial.h e PredioComercial.cpp: Implementa a classe PredioComercial, que gerencia as salas dentro de um prédio.
main.cpp: Implementa o menu interativo para o usuário, permitindo a adição e remoção de salas e empresas, além da listagem das salas e empresas de forma ordenada.
Como Compilar e Executar
Requisitos
Um compilador C++ (GCC, Clang, etc.)
CMake (opcional, mas recomendado para grandes projetos)


## Executando o Programa
Após compilar e executar o programa, você verá um menu interativo com as seguintes opções:

Adicionar Sala Privativa: Insira o número da sala, andar e capacidade máxima de pessoas.
Adicionar Sala Compartilhada: Insira o número da sala, andar e o número de estações de trabalho disponíveis.
Remover Sala: Insira o número da sala que deseja remover.
Adicionar Empresa a uma Sala: Insira o número da sala, nome da empresa e idade (anos de mercado).
Remover Empresa de uma Sala: Insira o número da sala e o nome da empresa que deseja remover.
Listar Salas e Empresas: Exibe a lista de todas as salas e as empresas associadas a cada uma, ordenadas por andar.