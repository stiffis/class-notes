#include <iostream>
class Complejo {
public:
	Complejo(double a, double b);
	~Complejo();
//bool operator==(const Coor &item1, const Coor &item2){
//	return (item1.x == item2.x) && (item 1.y == item2.y);
//}
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
private:
	double real;
	double img;
};

Complejo::Complejo(double a, double b) : real(a), img(b){

}

Complejo::~Complejo() {
}


int main () {
	

	return 0;
}
