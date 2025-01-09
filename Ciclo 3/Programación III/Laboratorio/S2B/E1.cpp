#include <iostream>
#include <string>
class Item {
public:
	Item(int n, std::string m);
	Item(Item &&) = default;
	Item(const Item &) = default;
	Item &operator=(Item &&) = default;
	Item &operator=(const Item &) = default;
	~Item();
friend class Pj;
private:
	double num;
	std::string name;
};

Item::Item(int n, std::string m) : num(n), name(m){
}

Item::~Item() {
}
////////////////////////////////////////////////////////
class Carne : public Item{
public:
	Carne();
	Carne(Carne &&) = default;
	Carne(const Carne &) = default;
	Carne &operator=(Carne &&) = default;
	Carne &operator=(const Carne &) = default;
	~Carne();

private:
	
};

Carne::Carne() : Item(20,"Carne"){
}

Carne::~Carne() {
}
////////////////////////////////////////////////////////
class Agua : public Item{
public:
	Agua();
	Agua(Agua &&) = default;
	Agua(const Agua &) = default;
	Agua &operator=(Agua &&) = default;
	Agua &operator=(const Agua &) = default;
	~Agua();

private:
	
};

Agua::Agua() : Item(10,"Agua"){
}

Agua::~Agua() {
}
////////////////////////////////////////////////////////
class Magia : public Item{
public:
	Magia();
	Magia(Magia &&) = default;
	Magia(const Magia &) = default;
	Magia &operator=(Magia &&) = default;
	Magia &operator=(const Magia &) = default;
	~Magia();

private:
	
};

Magia::Magia() : Item(12, "Magia"){
}

Magia::~Magia() {
}
//////////////////////////////////////////////////77777
class Arma {
public:
	Arma(int n);
	Arma(Arma &&) = default;
	Arma(const Arma &) = default;
	Arma &operator=(Arma &&) = default;
	Arma &operator=(const Arma &) = default;
	~Arma();
friend class Pj;
private:
	double num;
};

Arma::Arma(int n) : num(n){
}

Arma::~Arma() {
}
//////////////////////////////////////////////////////
class Hacha : public Arma{
public:
	Hacha();
	Hacha(Hacha &&) = default;
	Hacha(const Hacha &) = default;
	Hacha &operator=(Hacha &&) = default;
	Hacha &operator=(const Hacha &) = default;
	~Hacha();

private:
	
};

Hacha::Hacha() : Arma(5){
}

Hacha::~Hacha() {
}
///////////////////////////////////////////////////////
class Espada : public Arma{
public:
	Espada();
	Espada(Espada &&) = default;
	Espada(const Espada &) = default;
	Espada &operator=(Espada &&) = default;
	Espada &operator=(const Espada &) = default;
	~Espada();

private:
	
};

Espada::Espada() : Arma(10){
}

Espada::~Espada() {
}
///////////////////////////////////////////////////////
class Arco : public Arma{
public:
	Arco();
	Arco(Arco &&) = default;
	Arco(const Arco &) = default;
	Arco &operator=(Arco &&) = default;
	Arco &operator=(const Arco &) = default;
	~Arco();

private:
	
};

Arco::Arco() : Arma(15){
}

Arco::~Arco() {
}
////////////////////////////////////////////////////////
class Pj {
public:
	Pj(std::string name, std::string raza, double n, double m);
	Pj(Pj &&) = default;
	Pj(const Pj &) = default;
	Pj &operator=(Pj &&) = default;
	Pj &operator=(const Pj &) = default;
	void curar(Item m){
		vida+=m.num;
	}
	void atacar(Arma n, Pj& m) {
		double daño = m.ataque + n.num;
		m.vida-=daño;
	}
	~Pj();
friend std::ostream& operator<<(std::ostream& os, Pj& p){
	os << "Atributos de personaje: " << std::endl;
	os << "Nombre: " << p.name << std::endl;
	os << "Raza: " << p.raza << std::endl;
	os << "Vida: " << p.vida << std::endl;
	os << "Ataque: " << p.ataque << std::endl;
	os << "---------------------------------" << std::endl;
	return os;
}
private:
	std::string name;
	std::string raza;
	double vida;
	double ataque;
};

Pj::Pj(std::string name, std::string raza, double n, double m) : name(name), raza(raza), vida(n), ataque(m){
}

Pj::~Pj() {
}
////////////////////////////////////////////////////////////
int main(){
    Pj pj1("Orgrim","Orco",100,20); // Se cura con Carne
    Pj pj2("Legolas","Elfo",60,35); // Se cura con Magia
    Pj pj3("Aragorn","Humano",80,25); // Se cura con Agua

    Hacha hacha;
    Arco arco;
    pj1.atacar(hacha, pj2);
    pj2.atacar(arco, pj3);

    std::cout << pj1 << pj2 << pj3;
}
