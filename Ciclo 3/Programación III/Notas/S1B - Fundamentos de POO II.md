# Sobrecarga de operadores
Un operador sobrecargado es una función (o método). Tiene la palabra  _operator_ seguida del símbolo del operador.
- Puede hacer que nuestro código se pueda escribir y leer mejor.
- Un operador sobrecargado tiene la misma cantidad de parámetros que los operandos de operador.
- Cuando un operador sobrecargado es un método, _this_ está vinculado al operando de la izquierda.
- En una sobrecarga de operador al menor un parámetro debe ser distinto a los tipos de datos integrados en C++.
![[Pasted image 20250106215453.png]]
## Operador de Salida:
```cpp
ostream &operator<<(ostream &os, const Coordenada &item){
	os << "(" << item.x << ", ";
	os << item.y << ")";
return os;
}

// INTERFAZ
```

```ad-note
El operador de salida no puede ser miembro de la clase.
```

## Operador de Entrada:
```cpp
istream &operator>>(istream 6is, Coordenada &item){
	is >> item.x >> item.y;
	return is;
}

// INTERFAZ
```

```ad-note
- El operador de entrada no puede ser miembro de la clase.
- Si existen errores de sobrecarga debería resolverlos.
```

## Operadores Aritméticos
```cpp
Coor operator+(const Coor &item1, const Coor &item2){
	Coor obj;
	obj.x = item1.x + item2.x;
	obj.y = item1.y + item2.y;
	return obj;
}
```

```ad-note
Para demás operadores aritmeticos se usa la misma sintaxis
```

## Operadores de Relación
```cpp
bool operator==(const Coor &item1, const Coor &item2){
	return (item1.x == item2.x) && (item 1.y == item2.y);
}
```
```ad-note
Misma sintaxis para los demás operadores relacionales
```

Se pueden realizar sobrecarga a más tipo de operadores:
- Operadores de asignación.
- Operador de subíndice.
- Operador de incremento y decremento.
- Functores.

---
# Herencia
Las clases relacionadas por _Herencia_ construyen una jerarquía. En esta jerarquía existen dos tipos de clases:
- La _Clase Base_ o _Super Clase_: Esta clase está en la raíz de la jerarquía, desde donde las demás clases heredan sus miembros.
- La _Clase Derivada_ o _Sub Clase_. Estas son las que heredan los miembros de la Clase Base.  

```cpp
class A{
public: 
void f() {cout << "A::f()" << endl; }
void g() {cout << "A::g()" << endl; }
};
class B : public A {
public:
	void f() {cout << "B::f()" << endl; }
}
```

```cpp
int main(){
	A a;
	B b;
	a.f(); a.g();
	b.f(); b.g();
}

/*SALIDA
A::f()
A::g()
B::f()
A::g()
*/
```

Existen 3 tipos de herencia:
- **Herencia pública**: En esta herencia, todos los miembros públicos y protegidos de la clase base conservan esos mismos niveles de acceso respectivamente en las clases derivadas. Un miembro con acceso protegido se hereda en las clases derivadas. Es decir, cualquier clase derivada puede acceder a este miembro.
- **Herencia privada**: Todos los miembros públicos y protegidos de la clase base adquieren el nivel de acceso privado en las clases derivadas. Toda clase derivada que haya heredado mediante herencia privada no puede heredar a otras clases los miembros que ha heredado de otras clases. 
- **Herencia protegida**: Todos los miembros públicos de la clase base adquieren el nivel de acceso protegido en las clases derivadas. Los miembros protegidos conservan su nivel de acceso. Una clase derivada puede heredar a otra clase los miembros protegidos que heredó de su clase base.

---
# Polimorfismo
## Tipos de Polimorfismo:
- Polimorfismo Estático: Es conseguido utilizando **sobrecarga de funciones** o **sobrecarga de operadores**.
- Polimorfismo Dinámico: Es conseguido a través de la anulación de funciones. _Se logra con métodos virtuales_.

## Métodos Virtuales: 
El Polimorfismo Dinámico se da en la etapa de ejecución. Esto no puede lograrse únicamente con Herencia:

```cpp
struct A {
    void f() { cout << "A::f()" << endl; }
};
struct B : public A {
    void f() { cout << "B::f()" << endl; }
};

void g(A& arg){
	arg.f();
}

int main() {
	B b;
	g(b);
}

//SAlida:
//A::f()
```

```ad-note
El compilador solo sabe que el argumento de la función g es de tipo A, no sabe si es un objeto de alguna clase derivada (B). 
```

Esto se puede determinar en tiempo de ejecución utilizando la palabra virtual :

```cpp
struct A {
    virtual void f() { cout << "A::f()" << endl; }
};
struct B : public A {
    void f() override { cout << "B::f()" << endl; }
};

void g(A& arg){
	arg.f();
}

```

Como A::f() y B::f() tienen la misma lista de parámetros, ambos son virtuales.

La palabra "virtual" le dice al compilador que debe escoger la función correcta para el argumento de g().
 ```cpp
 int main() {
	 B b;
	 g(b);
 }
//Salida

//B::f()
 ```
La definición de f se realiza ahora mediante el objetivo al que apunta arg en la función g. 

$\therefore$

- Un método virtual es un miembro de la clase que se puede redefinir en las clases derivadas.
- El método virtual puede asegurarse  de que el compilador llamará a la función virtual redefinada para un objeto de clase derivada que sobrescribió al método, incluso si llama a esa función con un puntero o referencia a una clase baja del objeto.
```cpp
int main() {
A *a;
a = new B(1);
a->f();
a = new C(1,’hola’);
a->f();
}
```

## Reglas en los método virtuales
- Se puede invocar a las funciones virtuales con punteros a la clase base.
- Uno puede re-definir (o no) una función virtual con la clase derivada.
- Una clase no puede tener un constructor virtual, pero si un destructor virtual, el cual de podrá redefinir en las clases derivadas.
- Este tipo de funciones no pueden ser declaradas como static. 


---