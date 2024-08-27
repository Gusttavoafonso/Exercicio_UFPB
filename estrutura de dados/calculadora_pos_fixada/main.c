
#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int main() {

    void calc_operador(Cal*, char);
    void calc_operando(Cal*, float);

    Cal* calculadora = cria_calculadora("%f"); // Create a calculator with a float format
    calc_operando(calculadora, 5.0); // Push operand 5.0 to the calculator stack
    calc_operando(calculadora, 3.0); // Push operand 3.0 to the calculator stack
    calc_operador(calculadora, '+'); // Perform addition operation
    calc_operando(calculadora, 2.0); // Push operand 2.0 to the calculator stack
    calc_operador(calculadora, '*'); // Perform multiplication operation
    calc_operando(calculadora, 4.0); // Push operand 4.0 to the calculator stack
    calc_operador(calculadora, '/'); // Perform division operation
    calc_operando(calculadora, 1.5); // Push operand 1.5 to the calculator stack
    calc_operador(calculadora, '-'); // Perform subtraction operation
    calc_operando(calculadora, 2.0); // Push operand 2.0 to the calculator stack
    calc_operador(calculadora, '*'); // Perform multiplication operation
    calc_operando(calculadora, 3.0); // Push operand 3.0 to the calculator stack
    calc_operador(calculadora, '+'); // Perform addition operation
    calc_libera(calculadora); // Free the calculator memory
    return 0;
}