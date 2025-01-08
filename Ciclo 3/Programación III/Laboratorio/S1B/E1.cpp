#include <string>
#include <iostream>
class Personaje {
public:
	Personaje(std::string _name, int _life, int _attack, int _defense);
	void set_name(std::string _name) {
		name = _name;
	}
	void mostrar(){
		std::cout << "------------------" << std::endl
		<< "Nombre: " << name << std::endl << "Vida: " << life << std::endl << "Ataque: " << attack << std::endl << "Defensa: " << defense << std::endl;

	}
	Personaje(Personaje& per);
	~Personaje();

private:
	std::string name;
	int life;
	int attack;
	int defense;
};

Personaje::Personaje(std::string _name, int _life, int _attack, int _defense) 
	: name(_name), life(_life), attack(_attack), defense(_defense){
}
Personaje::Personaje(Personaje& per){
	this->life = per.life;
	this->attack = per.attack;
	this->defense = per.defense;
}
Personaje::~Personaje() {
}


int main () {
	Personaje p1("Per1", 100, 50, 30);
	Personaje p2(p1);
	p2.set_name("Per2");
	p1.mostrar();
	p2.mostrar();
	return 0;
}
