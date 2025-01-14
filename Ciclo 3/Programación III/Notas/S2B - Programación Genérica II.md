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

Ejemplo 3:
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