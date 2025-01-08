#include <iostream>
class Pj {
public:
	Pj();
	Pj(Pj &&) = default;
	Pj(const Pj &) = default;
	Pj &operator=(Pj &&) = default;
	Pj &operator=(const Pj &) = default;
	~Pj();

private:
	
};

Pj::Pj() {
}

Pj::~Pj() {
}
int main () {
	

	return 0;
}
