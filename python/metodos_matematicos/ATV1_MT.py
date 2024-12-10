

import math
import numpy as np
import matplotlib.pyplot as plt

def main():
    # Define a função geral da sequência
    '''def a(n):
        denominador = (n**2) + (5*n) - 6
        if denominador == 0:
            raise ZeroDivisionError(f"Divisão por zero para n = {n}")
        return (4 * (n**2) - (3 * n)) / denominador'''
    def a(n):
        return (2 ** n) / math.factorial(n)
    '''def a(n):
        return 2 ** (1 - 1 / (2 ** n))'''


    # Entrada dos limites do intervalo
    nmin = int(input("Digite o valor de nmin (natural): "))
    nmax = int(input("Digite o valor de nmax (natural): "))
    if nmin > nmax:
        raise ValueError("nmin deve ser menor ou igual a nmax.")

    # Opções de execução
    print("Escolha uma opção:")
    print("(a) Não sei se a sequência é convergente para um limite L")
    print("(b) Sei que a sequência é convergente para um limite L")
    opcao = input("Digite 'a' ou 'b': ").strip().lower()

    # Preparar os valores da sequência
    n_values = np.arange(nmin, nmax + 1)
    a_values = np.array([a(n) for n in n_values])

    if opcao == 'a':
        # Exibir tabela
        print("\nTabela de valores:")
        print("n\t a(n)")
        for n, an in zip(n_values, a_values):
            print(f"{n}\t {an:.6f}")

        # Plotar gráfico
        plt.figure(figsize=(10, 6))
        plt.scatter(n_values, a_values, color='blue', label='a(n)', zorder=2)
        plt.title("Gráfico da sequência a(n)")
        plt.xlabel("n")
        plt.ylabel("a(n)")
        plt.grid(True, linestyle='--', alpha=0.7, zorder=1)
        plt.legend()
        plt.show()



    elif opcao == 'b':
        L = float(input("Digite o valor do limite L: "))
        epsilon = float(input("Digite o valor da tolerância ε: "))
        
        # Encontrar o menor N(ε)
        N_epsilon = None
        for n in n_values:
            if abs(a(n) - L) <= epsilon:
                N_epsilon = n
                break

        # Exibir tabela
        print("\nTabela de valores:")
        print("n\t a(n)\t |a(n) - L|")
        for n, an in zip(n_values, a_values):
            diff = abs(an - L)
            print(f"{n}\t {an:.6f}\t {diff:.6f}")

        # Gráfico
        plt.figure(figsize=(10, 6))
        plt.scatter(n_values, a_values, color='blue', label='a(n)', zorder=2)
        plt.axhline(L, color='green', linestyle='--', label=f'L = {L}')
        plt.axhline(L + epsilon, color='red', linestyle='--', label=f'L + ε')
        plt.axhline(L - epsilon, color='red', linestyle='--', label=f'L - ε')
        if N_epsilon:
            plt.axvline(N_epsilon, color='purple', linestyle='--', label=f'N(ε) = {N_epsilon}')
        plt.title("Gráfico da sequência a(n) com limite L")
        plt.xlabel("n")
        plt.ylabel("a(n)")
        plt.grid(True, linestyle='--', alpha=0.7, zorder=1)
        plt.legend()
        plt.show()

    else:
        print("Opção inválida. Escolha 'a' ou 'b'.")

if __name__ == "__main__":
    main()
