## Variadic Templates
### Pack de parámetros
```cpp
void foo();
void foo(int x1);
void foo(int x1, float x2);
void foo(int x1, float x2, double x3.....);
```
$\downarrow$
```cpp
template <typename... Ts>
void foo(Ts... xs);
```

```ad-info
Un variadic template es una función plantilla o clase plantilla que acepta un pack de parámetros(xs).
```

```cpp
// Para obtener la cantidad de parámetros ingresados
template <typename... Ts>
void foo(Ts... xs){
	cout << sizeof...(xs);
}
```

Además no es posible iterar sobre estos parámetros!!!

Entonces:
- Los Variadic Templates permite escribir funciones con número variable de argumentos. O clases.

---
## Fold Expressions
Un Fold Expressions es na forma de evaluar expresiones con un número variable de argumentos.
```ad-warning
Finish notes
```
Estos se utilizan en los Variadic Templates para reducir el pack de parámetros con operadores binarios.

```cpp
(pack op ...)
(... op pack)
(pack op ... op init)
(init op ... op pack)
//LEYENDA
//op: 
//pack: 
//init: 
```

Expansión(pack op ...)
$$

xs = {a_1,a_2,a_3};
(xs + \ldots);
(a_1+(a_2+a_3))
$$
//faltaaaaaaaaaaaaaaaaaaaaaaaaaaa
Expansión(pack op ...)
$$

xs = {a_1,a_2,a_3};
(xs + \ldots);
(a_1+(a_2+a_3))
$$


Ejemplo 1:
```cpp
template <class... Ts>
auto suma(Ts... args){
	return (args+...);
}

int main(){
	cout << "Utilizando suma" << endl;
	cout << suma(1) << endl;
	cout << suma(1,2) << endl;
	cout << suma(1,2,3.5,0.5,5) << endl;

	return 0;
}
```

```cpp
template<typename... Ts>
void print(Ts... args){
	(cout << ... << args) << endl;
}
int main(){
	print();
	print(1,2,3,4,5);
	print("Hola", 1 "Mundo");
	return 0;
}
```

Ejemplo 3(Recursivo):
En este ejemplo no se usan los Folds Expression, ya que se desempaqueta y no estamos operando con el pack completo sino con el primer elemento del pack cada vez que se llama.
```cpp
void print(){cout<<endl;}

template<typename T, typename... Ts>
void print(T arg, Ts... args){
	cout << arg << ' ';
	print(args...);// args... desempaquetado!!
}

int main(){
	print();
	print(1,2,3,4,5);
	print("Hola",1,"Mundo");
	return 0;
}
```
---
## Variadic Alias Template
Es una plantilla que es un alias para una familia de tipos con un numero variable de parámetros templates:

```cpp
template <typename T, typename... Ts>
struct foo{

...
};

template <typename... Ts>
using int_foo = foo<int, Ts...>;
```

int_foo es una alias para la clase template foo, con el primer argument de tipo int y los demás templates.

## Especialización
La especialización y la sobrecarga son dos mecanismos distintos para resolver la instanciación de plantillas de C++.

```cpp
template<class T>
T Max(T a, T b){}

template<> //especializacion cuando quiero q para una instancia especifica se haga algo especifico
char Max(char a, char b){}

int max(char a, int b){} //sobrecarga
```

La especialización es una extension de la plantilla, donde los argumentos deben ser de la misma forma que de la plantilla. En otras palabras, es una instancia de una clase o función plantilla.

```cpp
template<typename T> T max_value();

template<> constexpr int max_value<int>() {return INT_MAX;}

template<> constexpr int max_value<char>() {return CHAR_MAX;}

```

La palabra _constexpr_ permite la evaluación de una función en tiempo de compilación. Reduciendo la cantidad de código por ejecutar en tiempo de ejecución.

### Sobrecarga
La sobrecarga en funciones plantilla permite crear múltiples funciones con el mismo nombre pero con cantidad o tipo distinto de parámetros. Sirve para definir funciones de propósito general.

```cpp
template<typename T>
T max(T const& a, T)
```

## Conclusiones

- Los parámetros de pack se usan con Fold Expressions para crear Variadic Templates.
- Entre las ventajas de utilizar Variadic Templates tenemo