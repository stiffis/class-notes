class Complejo {
public:
	Complejo(double a, double b);
	~Complejo();

private:
	double real;
	double img;
};

Complejo::Complejo(double a, double b) : real(a), img(b){

}

Complejo::~Complejo() {
}
