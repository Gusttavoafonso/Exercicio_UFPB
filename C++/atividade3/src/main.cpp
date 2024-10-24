#include <iostream>
#include "PredioComercial.h"
#include "SalaPrivativa.h"
#include "SalaCompartilhada.h"

void mostrar_menu() {
    std::cout << "\n--- Menu ---\n";
    std::cout << "1. Adicionar Sala Privativa\n";
    std::cout << "2. Adicionar Sala Compartilhada\n";
    std::cout << "3. Remover Sala\n";
    std::cout << "4. Adicionar Empresa a uma Sala\n";
    std::cout << "5. Remover Empresa de uma Sala\n";
    std::cout << "6. Listar Salas e Empresas\n";
    std::cout << "0. Sair\n";
    std::cout << "Escolha uma opcao: ";
}

int main() {
    PredioComercial predio;
    int opcao;
    
    do {
        mostrar_menu();
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                int numero, andar, capacidade;
                std::cout << "Número da sala: ";
                std::cin >> numero;
                std::cout << "Andar: ";
                std::cin >> andar;
                std::cout << "Capacidade máxima de pessoas: ";
                std::cin >> capacidade;

                SalaPrivativa* salaPrivativa = new SalaPrivativa(numero, andar, capacidade);
                predio + salaPrivativa;
                std::cout << "Sala Privativa adicionada com sucesso.\n";
                break;
            }
            case 2: {
                int numero, andar, estacoes;
                std::cout << "Número da sala: ";
                std::cin >> numero;
                std::cout << "Andar: ";
                std::cin >> andar;
                std::cout << "Número de estações de trabalho: ";
                std::cin >> estacoes;

                SalaCompartilhada* salaCompartilhada = new SalaCompartilhada(numero, andar, estacoes);
                predio + salaCompartilhada;
                std::cout << "Sala Compartilhada adicionada com sucesso.\n";
                break;
            }
            case 3: {
                int numero;
                std::cout << "Número da sala a ser removida: ";
                std::cin >> numero;

                // Procura a sala pelo número e remove
                for (auto sala : predio.get_empresas()) {  // Necessário um método adicional para retornar todas as salas
                    if (sala->get_numero() == numero) {
                        predio - sala;
                        std::cout << "Sala removida com sucesso.\n";
                        break;
                    }
                }
                break;
            }
            case 4: {
                int numero;
                std::string nome_empresa;
                int idade_empresa;

                std::cout << "Número da sala para adicionar a empresa: ";
                std::cin >> numero;
                std::cout << "Nome da empresa: ";
                std::cin.ignore();  // Ignora o \n remanescente
                std::getline(std::cin, nome_empresa);
                std::cout << "Idade da empresa: ";
                std::cin >> idade_empresa;

                Empresa novaEmpresa(nome_empresa, idade_empresa);

                // Encontra a sala e adiciona a empresa
                for (auto sala : predio.get_empresas()) {
                    if (sala->get_numero() == numero) {
                        *sala + novaEmpresa;  // Adiciona a empresa à sala
                        std::cout << "Empresa adicionada com sucesso.\n";
                        break;
                    }
                }
                break;
            }
            case 5: {
                int numero;
                std::string nome_empresa;

                std::cout << "Número da sala para remover a empresa: ";
                std::cin >> numero;
                std::cout << "Nome da empresa: ";
                std::cin.ignore();
                std::getline(std::cin, nome_empresa);

                // Encontra a sala e remove a empresa
                for (auto sala : predio.get_empresas()) {
                    if (sala->get_numero() == numero) {
                        for (auto empresa : sala->get_empresas()) {
                            if (empresa.get_nome() == nome_empresa) {
                                *sala - empresa;  // Remove a empresa da sala
                                std::cout << "Empresa removida com sucesso.\n";
                                break;
                            }
                        }
                    }
                }
                break;
            }
            case 6: {
                std::cout << "\nListando todas as salas e empresas:\n";
                predio.listar_salas();
                break;
            }
            case 0:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opcao invalida. Tente novamente.\n";
                break;
        }

    } while (opcao != 0);

    return 0;
}
