#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x, y;  // Coordenadas privadas do ponto

public:
    // Construtor para inicializar as coordenadas do ponto
    Point(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // Declarando a função friend que pode acessar membros privados
    friend Point operator+(const Point &p1, const Point &p2);  // Somando dois pontos
    friend double distance(const Point &p1, const Point &p2);  // Calculando a distância entre dois pontos

    // Método para exibir as coordenadas do ponto
    void display() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

class Line {
private:
    Point p1, p2;  // Dois pontos privados que definem a linha

public:
    // Construtor que inicializa os pontos da linha
    Line(const Point &point1, const Point &point2) : p1(point1), p2(point2) {}

    // Função friend que pode acessar os pontos privados da linha
    friend double length(const Line &l);  // Calculando o comprimento da linha
};

// Definindo a função friend que sobrecarrega o operador + para somar dois pontos
Point operator+(const Point &p1, const Point &p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);  // Acessando diretamente os membros privados de Point
}

// Definindo a função friend que calcula a distância entre dois pontos
double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));  // Acessando diretamente os membros privados
}

// Definindo a função friend que calcula o comprimento de uma linha
double length(const Line &l) {
    return distance(l.p1, l.p2);  // Acessa os membros privados da linha (pontos p1 e p2)
}

int main() {
    // Criando dois pontos
    Point p1(3.0, 4.0);
    Point p2(6.0, 8.0);

    // Somando dois pontos usando o operador sobrecarregado
    Point p3 = p1 + p2;
    p3.display();  // Exibe: Point(9, 12)

    // Calculando a distância entre p1 e p2 usando a função friend
    cout << "Distance between p1 and p2: " << distance(p1, p2) << endl;  // Exibe a distância

    // Criando uma linha entre p1 e p2
    Line line(p1, p2);

    // Calculando o comprimento da linha usando a função friend
    cout << "Length of the line: " << length(line) << endl;  // Exibe o comprimento da linha

    return 0;
}
