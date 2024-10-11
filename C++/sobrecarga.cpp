#include <iostream>

using std::cout;
using std::cin;
using std::endl;

using std::ostream;
using std::istream;

class retangulo {
	double base;
	double altura;
public:
	retangulo(double b = 0, double a = 0):base(b), altura(a) {}

	void print_info() {
		cout << "retangulo(" << base << ", " << altura << ")" << endl;
	}

	retangulo operator+(const retangulo& outro) {
		return retangulo(base + outro.base, altura + outro.altura);
	}

	friend retangulo operator-(const retangulo& a, const retangulo& b) {
		return retangulo(a.base - b.base, a.altura - b.altura);
	}

	bool operator==(const retangulo& outro) {
		return (base == outro.base)&&(altura == outro.altura);
	}

	bool operator>(const retangulo& outro) {
		return (base*altura)>(outro.base*outro.altura);
	}

	friend bool operator<(const retangulo& a, const retangulo& b) {
		return (a.base*a.altura)<(b.base*b.altura);
	}

	friend ostream& operator<<(ostream& out, const retangulo& r) {
		out << "retangulo(" << r.base << ", " << r.altura << ") ";
		return out;
	}

	friend istream& operator>>(istream& in, retangulo& r) {
		in >> r.base >> r.altura;
		return in;
	}

	operator double() const {
		return base*altura;
	}

	operator int() const {
		return (int)base*altura;
	}
};

int main(void) {
	retangulo r1(10, 2);
	retangulo r2(5, 10);

	retangulo r3 = r1 + r2;

	retangulo r4 = r1 - r2;

	retangulo r5(10, 2);

	retangulo r6(8, 14);

	retangulo r7;

	cout << "r6: " << r6 << endl;

	cout << "Digite dois numeros reais: " << endl;

	cin >> r7;

	cout << "r7: " << r7 << endl;

	double area_r7 = r7;

	cout << "area_r7 = " << area_r7 << endl; 

	r1.print_info();
	r2.print_info();
	cout << "-----" << endl;
	r3.print_info();
	r4.print_info();
	r5.print_info();
	cout << "-----" << endl;

	if (r1 > r2) {
		cout << "r1 > r2" << endl;
	} else {
		cout << "r2 >= r1" << endl;
	}

	if (r1 == r5) {
		cout << "r1 == r5" << endl;
	} else {
		cout << "r1 != r5" << endl;
	}

	if (r4 < r2) {
		cout << "r4 < r2" << endl;
	} else {
		cout << "r2 >= r4" << endl;
	}

	return 0;
}
