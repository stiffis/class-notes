#include <iostream>
#include <istream>
class Complejo {
public:
	Complejo();
	Complejo(double a, double b);
	~Complejo();
friend std::ostream &operator<<(std::ostream &os, const  Complejo& item){
	os << "q: " << item.real << " + " << item.img<<"i" << std::endl;
	return os;
}
Complejo operator+(Complejo& otro){
	Complejo result(this->real+otro.real,this->img+otro.img);
	return result;
}
Complejo operator-(Complejo& otro){
	Complejo result(this->real-otro.real,this->img-otro.img);
	return result;
}
Complejo operator*(Complejo& otro){
	double c = (this->real*otro.real) - (this->img*otro.img);
	double d = (this->img*otro.real) + (this->real*otro.img);
	Complejo result(c,d);
	return result;
}
Complejo& operator++() {
	this->img+=1;
	this->real+=1;
	return *this;
}

//Complejo operator++(){
//	Complejo temp = *this;

//}
bool operator==(Complejo& otro){
	return (this->real==otro.real)&&(this->img==otro.img);
}

// TODO: TERMINAR EL >>
friend std::istream &operator>>(std::istream &is,  Complejo& item){
	double x,y;
	std::cout << "Ingrese la parte real: ";
	is>>item.real;
	std::cout << "Ingrese la parte img: ";
	is>>item.img;
	return is;

}

private:
	double real;
	double img;
};
Complejo::Complejo(){}
Complejo::Complejo(double a, double b) : real(a), img(b){

}

Complejo::~Complejo() {
}


int main () {
	Complejo c1(1,2);
	Complejo c2(3,4);
	Complejo c3;
	std::cout << c1 << std::endl;
	std::cout << c2 << std::endl;
	std::cout << c1+c2 << std::endl;
	std::cin >> c3;
	std::cout << c3 << std::endl;
	++c3;
	std::cout << c3 << std::endl;
	return 0;
}
