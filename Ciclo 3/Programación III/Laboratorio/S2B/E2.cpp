#include <iostream>
using namespace std;
class Forma{
public:
	Forma();
	Forma(Forma &&) = default;
	Forma(const Forma &) = default;
	Forma &operator=(Forma &&) = default;
	Forma &operator=(const Forma &) = default;
	virtual void calcular_area() {
	
	}
	virtual ~Forma();

friend std::ostream& operator<<(std::ostream& os, Forma& p){
	os << "Area de a figura es: " << p.area<< "u²"<<std::endl;
	return os;
}
private:
protected:
	double area;
};

Forma::Forma() {
}

Forma::~Forma() {
}
// Derivadas
class Cuadrado : public Forma{
public:
	Cuadrado(double n);
	Cuadrado(Cuadrado &&) = default;
	Cuadrado(const Cuadrado &) = default;
	Cuadrado &operator=(Cuadrado &&) = default;
	Cuadrado &operator=(const Cuadrado &) = default;
	~Cuadrado();
	void calcular_area() override {
		area=lado*lado;
	}
private:
	double lado;
};

Cuadrado::Cuadrado(double n) : lado(n){
}

Cuadrado::~Cuadrado() {
}
//----------------------------------------------------------
class Circulo : public Forma{
public:
	Circulo(double r);
	Circulo(Circulo &&) = default;
	Circulo(const Circulo &) = default;
	Circulo &operator=(Circulo &&) = default;
	Circulo &operator=(const Circulo &) = default;
	~Circulo();

	void calcular_area() override {
		area=3.14*radio*radio;
	}
private:
	double radio;
};

Circulo::Circulo(double r) : radio(r){
}

Circulo::~Circulo() {
}
//----------------------------------------------------------
class Triangulo :public Forma{
public:
	Triangulo(double b, double h);
	Triangulo(Triangulo &&) = default;
	Triangulo(const Triangulo &) = default;
	Triangulo &operator=(Triangulo &&) = default;
	Triangulo &operator=(const Triangulo &) = default;
	~Triangulo();

	void calcular_area() override {
		area=base*h*0.5;
	}
private:
	double base;
	double h;
};

Triangulo::Triangulo(double b, double h) : base(b), h(h){
}

Triangulo::~Triangulo() {
}
int main(){
    Forma* forma;

    forma = new Cuadrado(2);
    forma->calcular_area();
    std::cout << *forma << std::endl;

    forma = new Circulo(1);
    forma->calcular_area();
    cout << *forma << endl;

    forma = new Triangulo(2,3);
    forma->calcular_area();
    cout << *forma << endl;
}
