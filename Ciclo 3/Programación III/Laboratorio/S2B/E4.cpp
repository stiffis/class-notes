class Numero {
public:
	Numero();
	Numero(Numero &&) = default;
	Numero(const Numero &) = default;
	Numero &operator=(Numero &&) = default;
	Numero &operator=(const Numero &) = default;
	~Numero();

private:
	
};

Numero::Numero() {
}

Numero::~Numero() {
}
