#include<iostrem>

/*Uma classe é uma estrutura
 que define um tipo de dado personalizado.
 Um objeto é uma instância de uma classe. Quando 
 você cria um objeto,
 você está criando uma "cópia" ou "exemplar" 
da classe*/ 

class conta{
    int numero_da_conta;
    int saldo;
    char tipo;

public:
    conta(int num, int s, char t):numero_da_conta(num), saldo(s),tipo(t){}
        std::cout <<"contrutor acionado" << std::endl;

    int depositar(double valor);
    int sacar(double valor);

};

class transacao{
    int valor;
    conta& conta_origem;
    conta& conta_destino;

public:
    transacao(int num, conta& origem, conta& destino):valor(num), conta_origem(origem),conta_destino(destino){}


    void exetucar(){
        conta_origem.sacar(valor);
        conta_destino.depositar(valor);

    }

};

/*questao 2
Agregação é um tipo de relacionamento onde uma classe (o todo) 
contém referências a objetos de outra(s) classe(s) 
(as partes), mas as partes podem existir independentemente do todo.

Composição é um tipo mais forte de relacionamento onde uma 
classe (o todo) contém instâncias de outra(s) classe(s) (as partes), 
mas as partes não podem existir independentemente do todo. 

Agregação: Use quando o ciclo de vida dos objetos "parte" 
não depende do ciclo de vida do objeto "todo". Se as partes podem ou 
devem existir 
independentemente do todo, a agregação é a escolha certa.

Composição: Use quando o ciclo de vida dos objetos "parte" 
depende completamente do ciclo de vida do objeto "todo". 
Se as partes não 
devem existir sem o todo, a composição é mais apropriada.
*/


/*questao 3
Um construtor é um método especial de uma classe que 
é automaticamente chamado quando um objeto dessa classe é criado. 
Ele serve para inicializar o objeto, definindo 
valores iniciais para seus atributos e alocando recursos necessário


Um destrutor é um método especial que é chamado automaticamente 
quando um objeto está sendo destruído, ou seja, quando ele sai
 de escopo ou é explicitamente deletado. O destrutor é usado para 
 liberar recursos que o objeto possa ter alocado durante sua vida,
 como memória dinâmica ou conexões de banco de dados.

*/

/*questao 4
encapsulamento significa que os dados (atributos) de um objeto e 
os métodos que operam sobre esses dados estão 
agrupados em uma única unidade, e o acesso a esses dados é controlado.*/



