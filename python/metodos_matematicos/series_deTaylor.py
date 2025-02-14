import numpy as np
import sympy as sp
import matplotlib.pyplot as plt

# Função para calcular a soma parcial da série de Taylor de f em torno de a até a ordem k
def taylor_series(f, x, a, k):
    return f.series(x, a, k + 1).removeO()  # Retorna a série de Taylor diretamente

# Função para plotar a função original e suas aproximações de Taylor
def plot_taylor_series(f_expr, a, Kmin, Kmax, xmin, xmax):
    x = sp.Symbol('x')  # Definição do símbolo para a variável x
    f = sp.sympify(f_expr)  # Conversão da expressão string para uma função simbólica
    
    # Aproximação do raio de convergência da série de Taylor
    R = sp.limit(abs(f / (sp.diff(f, x) + 1e-6)), x, a)
    delta = 0.1  # Pequeno deslocamento para evitar singularidade
    
    # Certifique-se de que R seja positivo
    R = float(R) if R.is_real else 1.0  # Use 1.0 como fallback se R não for real
    R = max(R, 0)  # Garante que R não seja negativo
    
    # Geração dos valores de x para plotagem
    x_vals = np.linspace(xmin, xmax, 400)
    
    # Conversão da função simbólica para uma função numérica utilizável no matplotlib
    f_lambdified = sp.lambdify(x, f, 'numpy')
    
    plt.figure(figsize=(10, 6))
    
    # Plot da função original
    plt.plot(x_vals, f_lambdified(x_vals), label='f(x)', linewidth=2, color='black')
    
    # Loop para calcular e plotar os polinômios de Taylor de ordem Kmin até Kmax
    for k in range(Kmin, Kmax + 1):
        Pk = taylor_series(f, x, a, k)  # Cálculo do polinômio de Taylor de ordem k
        Pk_lambdified = sp.lambdify(x, Pk, 'numpy')  # Conversão para função numérica
        
        # Avalia o polinômio de Taylor
        Pk_vals = Pk_lambdified(x_vals)  # Avalia o polinômio de Taylor
        
        # Verifica se Pk_vals é um array
        if isinstance(Pk_vals, (np.ndarray, list)):
            plt.plot(x_vals, Pk_vals, linestyle='--', label=f'P{k}(x)', alpha=0.7)
        else:
            print(f"Aviso: Pk retornou um valor não-array para k={k}. Valor: {Pk_vals}.")
    
    # Linha vertical indicando o centro da série de Taylor
    plt.axvline(a, color='gray', linestyle=':')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title(f'Gráfico de f(x) e suas somas parciais de Taylor')
    plt.legend()
    plt.grid()
    plt.show()

# Exemplo de uso da função
f_expr = '(1 + x)**(3/2)'  # Expressão da função a ser aproximada
a = 0  # Centro da série de Taylor
Kmin = 0  # Ordem mínima das somas parciais
Kmax = 4  # Ordem máxima das somas parciais
xmin = -1  # Limite inferior do intervalo de plotagem
xmax = 1   # Limite superior do intervalo de plotagem

# Chamada da função para exibição do gráfico
plot_taylor_series(f_expr, a, Kmin, Kmax, xmin, xmax)
