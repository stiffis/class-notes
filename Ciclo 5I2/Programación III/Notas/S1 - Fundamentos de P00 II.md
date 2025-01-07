# Sobrecarga de operadores
Un operador sobrecargado es una función (o método). Tiene la palabra  _operator_ seguida del símbolo del operador.
- Puede hacer que nuestro código se pueda escribir y leer mejor.
- Un operador sobrecargado tiene la misma cantidad de parámetros que los operandos de operador.
- Cuando un operador sobrecargado es un método, _this_ está vinculado al operando de la izquierda.
- En una sobrecarga de operador al menor un parámetro debe ser distinto a los tipos de datos integrados en C++.

+ - * / % & ^ | ~ ! , = < > <= >= ++ -- += -= /= %= ^= &= |= = <<= >>=
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

---
# Polimorfismo
## Tipos de Polimorfismo:
- Polimorfismo Estático: Es conseguido utilizando **sobrecarga de funciones** o **sobrecarga de operadores**.
- Polimorfismo Dinámico: Es conseguido a través de la anulación de funciones.


---