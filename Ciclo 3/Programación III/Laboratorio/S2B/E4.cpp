class Numero {
public:
	Numero();
	Numero(Numero &&) = default;
	Numero(const Numero &) = default;
	Numero &operator=(Numero &&) = default;
	Numero &operator=(const Numero &) = default;
	~Numero();
	virtual int termino(int n){

	}
private:
	
};

Numero::Numero() {
}

Numero::~Numero() {
}
//Derivadas---------------------------------------
class Primos : public Numero{
public:
	Primos();
	Primos(Primos &&) = default;
	Primos(const Primos &) = default;
	Primos &operator=(Primos &&) = default;
	Primos &operator=(const Primos &) = default;
	~Primos();
	int termino(int n)override{
		
	}
private:
	
};

Primos::Primos() {
}

Primos::~Primos() {
}
//---
class CuadradoPerfecto : public Numero{
public:
	CuadradoPerfecto();
	CuadradoPerfecto(CuadradoPerfecto &&) = default;
	CuadradoPerfecto(const CuadradoPerfecto &) = default;
	CuadradoPerfecto &operator=(CuadradoPerfecto &&) = default;
	CuadradoPerfecto &operator=(const CuadradoPerfecto &) = default;
	~CuadradoPerfecto();

	int termino(int n)override{
		
	}
private:
	
};

CuadradoPerfecto::CuadradoPerfecto() {
}

CuadradoPerfecto::~CuadradoPerfecto() {
}
//---
class Fibonacci : public Numero{
public:
	Fibonacci();
	Fibonacci(Fibonacci &&) = default;
	Fibonacci(const Fibonacci &) = default;
	Fibonacci &operator=(Fibonacci &&) = default;
	Fibonacci &operator=(const Fibonacci &) = default;
	~Fibonacci();

	int termino(int n)override{

	}
private:
	
};

Fibonacci::Fibonacci() {
}

Fibonacci::~Fibonacci() {
}
