# ¿Por qué la POO?:
Entre las principales ventajas de usar POO:
	- **Modularidad**: Dividir el problema en partes pequeñas, facilita y agiliza la resolución de problemas.
	- **Mantenimiento**: Permite añadir, modificar o eliminar de una manera sencilla.
	- **Reutilización de código**: La _Herencia_ permite heredar características de una Superclase en una sub-clase.
	- **Flexibilidad**: Utilizando _Polimorfismo_, podemos hacer que una función se adapte y cambia, a cualquier clase.
	- **Encapsulación**: Al igual que con los enteros, en un **tipo de dato abstracto** las operaciones de definen únicamente con las entradas y las salidas. No se especifica cómo se ha implementado el tipo de dato, todos los detalles se esconden del usuario.

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
Es un objeto no identificable en memoria. Podemos detercar un R value rapidamente cuando el objeto *no tiene nombre*. Por ejemplo:
```cpp
int i = 7;           // i en un lvalue
int k = i+3;
int *pi = &(i+3);
i + 3 = 10;
3 = i;
```

Una referencia de Rvalue es aquella que se **vincula** únicamente a un Rvalue, es decir a objetos temporales en memoria. Se obtiene utilizando &&, en lugar de &. Por ejemplo:
```cpp
int i = 42;
int &&c1 = 8;
int &&d1 = i * 42;
const int &d2 = i * 42;
```

---