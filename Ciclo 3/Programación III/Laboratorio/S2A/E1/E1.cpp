#include <iostream>
#include <string>
class Pj {
public:
	Pj(std::string _name, std::string _raza, double _vida, double _ataque);
	~Pj();
/*
// NOTE: : << Print atrobutos, + Recuperar vida de un personaje, >> Para atacar
// al atacar a uno, recuperamos la vida de ese.
*/

friend std::ostream& operator<<(std::ostream& os, Pj& p){
	os << "Atributos de personaje: " << std::endl;
	os << "Nombre: " << p.name << std::endl;
	os << "Raza: " << p.raza << std::endl;
	os << "Vida: " << p.vida << std::endl;
	os << "Ataque: " << p.ataque << std::endl;
	return os;
}

void operator>>(Pj& pjRight){
	pjRight.vida-=(this->ataque);
}

void operator+(int plus){
	this->vida+=plus;
}
/*
friend std::ostream& print(std::ostream& os, ){
	std::cout << vec.dim;
	for (int i = 0; i < vec.dim; ++i) {
	os << vec.Coordinates[i] << " ";
	}
	return os;
}
*/
private:
	std::string name;
	std::string raza;
	double vida;
	double ataque;
};

Pj::Pj(std::string _name, std::string _raza, double _vida, double _ataque) : name(_name), raza(_raza), ataque(_ataque){
	std::cout << "Creando Pj" << std::endl;
}

Pj::~Pj() {
	std::cout << "Destruyendo Pj" << std::endl;
}
int main () {
	Pj p1("Orgrim", "Orco", 100, 25);
	Pj p2("Steve", "Humano", 80, 20);
	Pj p3("Elfin", "Elfo", 70, 40);
	std::cout << p2;
	p1 >> p2;
	std::cout << p2;
	return 0;
}
