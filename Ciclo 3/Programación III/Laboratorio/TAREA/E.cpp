#include <iostream>
#include <utility>
#include <vector>
class Foo {
public:
	Foo(int n);
	Foo(Foo& foo);
	Foo(Foo&& foo);
	~Foo();
private:
	int* _num;
};

Foo::Foo(int n) {
	_num = new int (n);
	std::cout << "Clase Foo: Constructor -> " << *_num;
	std::cout << std::endl;
}

Foo::Foo(Foo& foo) {
	_num = new int(*foo._num);
	std::cout << "Clase Foo: Constructor Copia -> " << *_num;
	std::cout << std::endl;
}


Foo::Foo(Foo&& foo) {
	_num = new int(*foo._num);
	std::cout << "Clase Foo: Constructor Mov -> " << *_num;
	std::cout << std::endl;
	foo._num = nullptr;
}



Foo::~Foo() {
	if (_num==nullptr) {
		std::cout << "Clase Foo: Destructor -> nullptr" << std::endl;
	}else {	
		std::cout << "Clase Foo: Destructor -> " << *_num << std::endl;
	}
	delete _num;
}


void test1(){
	Foo f1(3);
}
void test2(){
	Foo f1(3);
	Foo f2(f1);
}
void test3(){
	std::vector<Foo> v;
	v.push_back(Foo(4));
}
void test4(){
	Foo f1(3);
	Foo f2(std::move(f1));
}


int main () {
	test1();
	std::cout << "----------------------" << std::endl;
	test2();
	std::cout << "----------------------" << std::endl;
	test3();
	std::cout << "----------------------" << std::endl;
	test4();
	return 0;
}
