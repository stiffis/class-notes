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
	Cuadrado(int n);
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

Cuadrado::Cuadrado(int n) : lado(n){
}

Cuadrado::~Cuadrado() {
}
//----------------------------------------------------------
class Circulo {
public:
	Circulo(int r);
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

Circulo::Circulo(int r) : radio(r){
}

Circulo::~Circulo() {
}
//----------------------------------------------------------
class Triangulo {
public:
	Triangulo();
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

Triangulo::Triangulo() {
}

Triangulo::~Triangulo() {
}
int main(){
    Forma* forma;

    forma = new Cuadrado(2);
    forma->calcularArea();
    cout << *forma << endl;

    forma = new Circulo(1);
    forma->calcularArea();
    cout << *forma << endl;

    forma = new Triangulo(2,3);
    forma->calcularArea();
    cout << *forma << endl;
}
