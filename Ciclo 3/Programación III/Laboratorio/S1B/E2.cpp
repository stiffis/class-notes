#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>
class Dados {
public:
	Dados(int n);
	Dados(Dados& d);
	Dados(Dados&& d);
	void lanzar(){
		for (int i = 0; i < cant; ++i) {
			data[i]=(rand()%6)+1;
			suma += data[i];
		}
	}
	double promedio(){
		double prom = (suma*1.0)/cant;
		for (int i = 0; i < cant; ++i) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Promedio de dado: " << prom << std::endl;
		if (prom > 3.0) {
			std::cout << "Jugador Gana!" << std::endl;
		}else { 
			std::cout << "Jugador Pierde!" << std::endl;
		}
		return prom;
	}
	~Dados();

private:
	int cant;
	int suma=0;
	int* data;
};

Dados::Dados(int n) : cant(n){
	data = new int[cant];
}

Dados::Dados(Dados& d){
	this->cant=d.cant;
	this->suma=d.suma;
	this->data=d.data;
	this->lanzar();
}


Dados::Dados(Dados&& d) : data(d.data), cant(d.cant), suma(d.suma){
	d.data=nullptr;
	d.cant=0;
	d.suma=0;
}

Dados::~Dados() {
	delete[] data;
}


int main () {
	std::srand(std::time(NULL));
	Dados d1(4);
	d1.lanzar();
	d1.promedio();
	return 0;
}
