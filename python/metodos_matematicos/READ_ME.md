# Sequência Numérica - Convergência e Gráficos

Este programa calcula os valores de uma sequência numérica dada pela fórmula:

\[
a_n = \frac{4n^2 - 3n}{n^2 + 5n - 6}
\]

Além de calcular os valores da sequência, o programa gera uma tabela de valores, plota um gráfico da sequência e, caso a sequência seja convergente, permite calcular o valor de \( N(\epsilon) \) para uma tolerância dada \( \epsilon \).

## Funcionalidades

O programa oferece duas opções de execução:

1. **Opção (a)**: O usuário não sabe se a sequência é convergente para um limite \( L \).
   - O programa calcula e exibe a sequência \( a_n \) para \( n \) no intervalo fornecido, além de gerar um gráfico de dispersão da sequência.

2. **Opção (b)**: O usuário sabe que a sequência é convergente para um limite \( L \).
   - O programa calcula e exibe a sequência \( a_n \) para \( n \) no intervalo fornecido.
   - O programa exibe um gráfico com o limite \( L \), e as retas horizontais \( y = L - \epsilon \), \( y = L \), e \( y = L + \epsilon \), para verificar a convergência da sequência.
   - O programa também calcula o valor mínimo de \( N(\epsilon) \), onde \( |a_n - L| \leq \epsilon \), e retorna o menor índice \( n \) a partir do qual essa condição é atendida.

## Como Funciona

### 1. Definição da Sequência

A sequência \( a_n \) é definida pela fórmula:

\[
a_n = \frac{4n^2 - 3n}{n^2 + 5n - 6}
\]

### 2. Opções de Entrada

- **Entrada de Limites**: O usuário fornece dois números naturais \( n_{\text{min}} \) e \( n_{\text{max}} \), que definem o intervalo \( [n_{\text{min}}, n_{\text{max}}] \).
  
- **Escolha da Opção**:
  - O usuário escolhe entre a opção (a) ou (b).
  - Caso o usuário escolha a opção (b), é necessário fornecer o limite \( L \), a tolerância \( \epsilon \), e calcular o valor mínimo de \( N(\epsilon) \) tal que \( |a_n - L| \leq \epsilon \).

### 3. Saídas

- **Tabela de Resultados**: Uma tabela é gerada no console, mostrando os pares \( (n, a_n) \) para \( n \) variando de \( n_{\text{min}} \) a \( n_{\text{max}} \).
  
- **Gráfico**: Um gráfico de dispersão é gerado, onde o eixo \( x \) representa os valores de \( n \) e o eixo \( y \) representa os valores de \( a_n \).
  
- **Arquivo de Saída**: O programa gera um arquivo de texto **saida.txt** contendo a tabela \( (n, a_n) \), que pode ser usado para registrar os resultados.

- **Caso da Opção (b)**: O programa calcula o valor mínimo \( N(\epsilon) \), e inclui no gráfico as linhas horizontais \( y = L - \epsilon \), \( y = L \), e \( y = L + \epsilon \) para verificar a convergência da sequência para o limite \( L \).

## Exemplo de Execução

```plaintext
Digite o valor de nmin (natural): 1
Digite o valor de nmax (natural): 10
Escolha uma opção:
(a) Não sei se a sequência é convergente para um limite L
(b) Sei que a sequência é convergente para um limite L
Digite 'a' ou 'b': a
