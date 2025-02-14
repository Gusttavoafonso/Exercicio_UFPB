import numpy as np
import math
import matplotlib.pyplot as plt

def calcular_serie(a_n, n0, kmim, kmax, opcao, S=None, epsilon=None):
    k_values = np.arange(kmim, kmax + 1)
    a_values = np.array([a_n(k) for k in k_values])
    S_values = np.cumsum(a_values)  # Soma parcial da série
    
    # Exibir tabela
    print(" k | a(k) | S(k)")
    print("-" * 25)
    for k, a_k, S_k in zip(k_values, a_values, S_values):
        print(f"{k:2d} | {a_k:.5f} | {S_k:.5f}")
    
    # Gerar gráfico
    plt.figure(figsize=(8, 5))
    plt.scatter(k_values, a_values, color='red', label='a(k)', marker='o')
    plt.scatter(k_values, S_values, color='blue', label='S(k)', marker='x')
    plt.xlabel("Índice k")
    plt.ylabel("Valores")
    plt.legend()
    plt.grid()
    
    # Se a opção (a) foi escolhida, desenhar linhas horizontais
    if opcao == 'a' and S is not None and epsilon is not None:
        plt.axhline(S, color='green', linestyle='--', label='S')
        plt.axhline(S - epsilon, color='orange', linestyle='--', label='S - ε')
        plt.axhline(S + epsilon, color='orange', linestyle='--', label='S + ε')
        plt.legend()
    
    plt.show()

# Exemplo de uso
def main():

    #a) o usu´aro sabe que a s´erie ´e convergente para a soma S

    #b)o usu´ario n˜ao sabe se a s´erie ´e convergente.
    opcao = input("Escolha a opção (a/b): ")
    n0 = int(input("Digite n0: "))
    kmim = int(input("Digite kmim: "))
    kmax = int(input("Digite kmax (> kmim): "))
    
    def a_n(n):  
       # return 1 / (n**2)
       # return 1 + (-1)**n
       # return 1/2*n - (1/2*n+3)
       # return (-1)**n * np.sin(1/n)
       # return 1 / (n**4 + n**2 + 1)
       return (-1)**n * math.cos(n) / (n**2)
       
    if opcao == 'a':
        S = float(input("Digite o valor de S: "))
        epsilon = float(input("Digite a tolerância ε: "))
        calcular_serie(a_n, n0, kmim, kmax, opcao, S, epsilon)
    else:
        calcular_serie(a_n, n0, kmim, kmax, opcao)

if __name__ == "__main__":
    main()
