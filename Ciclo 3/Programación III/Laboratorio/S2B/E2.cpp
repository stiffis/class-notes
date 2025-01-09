class Forma{
public:
	Forma();
	Forma(Forma &&) = default;
	Forma(const Forma &) = default;
	Forma &operator=(Forma &&) = default;
	Forma &operator=(const Forma &) = default;
	virtual void calcular_area(){
	
	}
	~Forma();

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
	Cuadrado();
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

Cuadrado::Cuadrado() {
}

Cuadrado::~Cuadrado() {
}
//----------------------------------------------------------
class Circulo {
public:
	Circulo();
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

Circulo::Circulo() {
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

private:
	
};

Triangulo::Triangulo() {
}

Triangulo::~Triangulo() {
}
