# ¿Por qué la POO?:
Entre las principales ventajas de usar POO:
	- **Modularidad**: Dividir el problema en partes pequeñas, facilita y agiliza la resolución de problemas.
	- **Mantenimiento**: Permite añadir, modificar o eliminar de una manera sencilla.
	- **Reutilización de código**: La _Herencia_ permite heredar características de una Superclase en una sub-clase.
	- **Flexibilidad**: Utilizando _Polimorfismo_, podemos hacer que una función se adapte y cambia, a cualquier clase.
	- **Encapsulación**: Al igual que con los enteros, en un **tipo de dato abstracto** las operaciones de definen únicamente con las entradas y las salidas. No se especifica cómo se ha implementado el tipo de dato, todos los detalles se esconden del usuario.

Una clase otorgará o denegará el acceso a datos del objeto utilizando los especificadores de acceso **público** o **privado**.

Los miembros públicos definen una interfaz entre una clase y los usuarios de esa clase. Se puede acceder a los miembros públicos el cualquier parte del programa. 

Los miembros privados solo los conoce el objeto y no se puede acceder a ellos mediante una interfaz.

En una base de datos orientada a objetos se puede trabajar con datos de cualquier tipo, no solo los que vienen con C++.
- En los enteros tenemos los valores: -3,1,0,2...
	- Una variable de tipo **int** sería un _tipo de dato_. La suma, resta son ejemplos de operaciones.
Del mismo modo, un tipo de dato _Abstracto_ se debería definir como el tipo y las operaciones que lo manipulan.

---
# Tipos de datos abstractos:
Al crear las distintas clases de un programa, creamos un ADT, que abarca no solo el conjunto de valores sino de las funciones que esta nuevo objeto representa.

---
# Creando un ADT: 
```cpp
struct Alumno{};
// Coloca todos los miembros por defecto publicos
class Alumno{};
// Coloca todos los miembros por defecto privados
```

---
# Constructores: 
- Constructores por defecto
- Constructores de copia
```cpp
class Alumno{
public:
    Alumno() = default;
    Alumno(const Alumno&);
    ...
};

Alumno::Alumno(const Alumno& item){
    nombre = item.nombre; 
    notas = item.notas;
}

```
---
# Constructores de movimiento:
## Lvalue:
Es un objeto que tiene una ubicación en memoria y el identificable. Por ejemplo:
```cpp
int i = 7,
int *p = &i;
i = 10;
// MODIFICABLE
```
## Rvalues:
Es un objeto no identificable en memoria. Podemos detectar un R value rápidamente cuando el objeto *no tiene nombre*. Por ejemplo:
```cpp
int i = 7;           // i en un lvalue
int k = i+3;
int *pi = &(i+3);    // ERROR
i + 3 = 10;          // ERROR
3 = i;               // ERROR
```

Una referencia de Rvalue es aquella que se **vincula** únicamente a un Rvalue, es decir a objetos temporales en memoria. Se obtiene utilizando &&, en lugar de &. Por ejemplo:
```cpp
int i = 42;
int &&c1 = 8;
int &&d1 = i * 42;
const int &d2 = i * 42;
```

## Función "move"
Esta se usa para asignar únicamente el valor una variable cualquier al otra, obviamente compatibles y eliminando la variable inicial y conservando la variable final con los datos.
```cpp
int &&i = 7;
int &&j = move(i);
```

Si queremos construir un nuevo objeto a partir de una variable (Lvalue) no podríamos hacerlo. La función move nos permite convertir el Lvalue en un Rvalue y para poder copiar sus miembros.

El constructor o cualquier función que capture tu variable casteada a Rvalue actuará como un destructor de la variable.

## Definiendo el constructor de movimiento

```cpp
class Foo{
public:
    Foo(int x){ ptr = new int(x);}
    Foo(const Foo& item): ptr(item.ptr){
        cout << "Constructor de Copia" << endl;
    }
    Foo(Foo&& item): ptr(item.ptr){
        item.ptr = NULL;
        cout << "Constructor de Movimiento" << endl;
    }
    void print(){cout << *ptr << endl;}
    ~Foo(){
        delete ptr;
    }
private:
    int* ptr;
};

//  INTERFAZ

int main(){
    Foo p1(7);
    
    Foo p2 = p1;
    Foo p3 = move(p1);
}

//Resultado:

//Constructor de Copia
//Constructor de Movimiento
```
---