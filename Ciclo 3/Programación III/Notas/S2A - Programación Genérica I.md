## Programación Genérica
Cuando se usa P.G., se escribe código independiente del tipo de datos.

Imaginemos que requerimos sumar dos números

```cpp
bool comparar(int x, int y) {
	return x < y;
}

bool comparar(float x, float y) {
	return x < y;
}

// CON CLASE PLANTILLA
template<class T>
bool comparar(T x, T y) {
	return x < y;
}
```

---

## Funciones Plantilla
Este tipo de funciones nos permiten generar distintas versiones de sí misma dependiendo del tipo de dato que necesitemos:

```cpp
template<class T>
bool comparar(T x, T y) {
	return x < y;
}


int main() {
	cout << comparar(3.4,7.6) << endl;
	cout << comparar(3,4) << endl;
	return 0;
}
```

En caso queramos usar más de dos tipos de datos o clases de datos, añadimos:

```cpp
template<typename T1, typename T2>
```

---

## Clases Plantilla
Similar a una función plantilla, una clase plantilla permite generar distintos tipos de clase con una única máscara.

La gran diferencia con una función plantilla es que el compilados no puede deducir el parámetro template.
```cpp
template<typename T>
class Pair{
	T _a, T _b;
public:
	Pair(T a, T b){
		_a = a;
		_b = b;
	}
	T Max();
};

template <class T>
T Pair<T>::Max () {
	return(_a > _b)? _a : _b;
}

int main () {
	Pair<float> obj(1.3, 6.2);
	cout << obj.Max() << endl;
	return 0;
}
```

## Funciones Friend y Estáticas

### Funciones _friend_
Cuando una clase tiene una declaración _friend_, la clase y la función/clase amiga pueden ser template o no.
- Una clase template da acceso a la función/clase amiga de todas sus instancias.
- Si además de la declaración amiga es también _template_, el acceso es a todas sus instancias.
```cpp
template<typename T>
struct A;

template<typename T>
void print(A<T> a){
	cout << "print<T>" << endl;
}

template<typename T>
struct A {
	friend void print<T>(A<T>);
};

int main() {
	A<int> a;
	print(a);
}

// A<int> y print <int>
// son _friend_
```