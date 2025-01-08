#include <iostream>
class Cartas {
public:
	Cartas();
	Cartas(Cartas &&) = default;
	
	std::istream &operator>>(Cartas& item){
		item.estrella;
	}

	Cartas(const Cartas &) = default;
	Cartas &operator=(Cartas &&) = default;
	Cartas &operator=(const Cartas &) = default;
	~Cartas();
	void baraja(Cartas& item){
		
	}
private:
	int* estrella;
	int* trebol;
	int* espada;
	int* corazones;
};

Cartas::Cartas() {
	//Separar memoria
	estrella = new int[13];
	
	for (int i = 0; i < 13; ++i) {
		estrella[i]=i;
	}
	trebol = new int[13];
	
	for (int i = 0; i < 13; ++i) {
		trebol[i]=i;
	}
	espada = new int[13];
	
	for (int i = 0; i < 13; ++i) {
		espada[i]=i;
	}
	corazones = new int[13];
	
	for (int i = 0; i < 13; ++i) {
		corazones[i]=i;
	}
}

Cartas::~Cartas() {
	delete[] estrella;
	delete[] espada;
	delete[] trebol;
	delete[] corazones;
}
// NOTE: 3 PRIMEROS 
// USAR UN ARRAY DE 1D
int main(){
	Cartas cartas;

	int barajar;
	cout << “Barajar? (> 1): ”;
	cin >> barajar;

	if (barajar > 1){
		cartas >> barajar;
		cout << deck;
}
}

