Esta es una es una rama de la informática que hace uso de principios de la _mecánica cuántica_ para realizar cálculos de manera más eficiente. La mecánica cuántica ayuda a describir el comportamiento de las partículas subatómicas, como electrones y fotones. Donde tienen propiedades únicas, como la **superposición** y el **entrelazamiento**.

Pero, ¿qué diferencia a la computación clásica de la cuántica?

Las diferencias principales entre estos dos tipos de computación se encuentran en la representación de datos, principios físicos, el procesamiento de información, los tipos de problemas que resuelven, y el hardware usado.

## Representación de datos
La computación clásica hace uso de bits, estos representan valores como 0 y 1, que se interpretan a menudo como _sin paso de corriente_ y _paso de corriente_ respectivamente. Sin embargo; en la computación cuántica se utiliza _bits cuánticos_ o _qubits_ que tienen más de un estado, no se limitan a 1's y 0's, además no sabemos su "valor" hasta que este sea medido u observado.

![[Pasted image 20241213000115.png|450]]

## Principios Físicos
Para la computación cuántica las operaciones con _bits_ pueden ser predecibles, osea tiene un comportamiento _determinista_, por lo tanto se basan en las leyes de la física clásica. Mientras que la computación cuántica hace uso de conceptos como la _superposición cuántica_, multiples estados al mismo tiempo, _entrelazamiento_, correlación entre varios qubits, si algo afectara a uno, también afectará al otro, sin importar la distancia, _interferencia_, son patrones de interferencia usados para reforzar las soluciones correctas y desechar las incorrectas.

## Procesamiento de Información
La principal diferencia en esta área es la posibilidad de poder realizar cálculos simultáneos por parte de la computación cuántica y cálculos secuenciales por parte de la computación clásica, de esta manera los propósitos entre estos dos tipo de computación son distintos.
- $\text{Computación clásica: suma de }A=10_2 \text{ y }B=01_2$
$$\begin{array}{}
  & 1  0_2 & \quad (A)  \\
  + & 0  1_2 & \quad  (B) \\
\hline 
  & 1  1_2 & \quad (\text{suma})
\end{array}$$

$\text{Aquí el resultado es }11_2\text{ equivalente a }3_{10}.$
- $\text{Computación cuántica: }$
$$|A\rangle = |10\rangle, \quad |B\rangle = |01\rangle$$
$$|A\rangle |B\rangle |0\rangle = |10\rangle |01\rangle |0\rangle$$
$$\text{Haciendo uso de puertas cuánticas el sistema evoluciona a:}$$
$$|A\rangle |B\rangle |S\rangle = |10\rangle |01\rangle |11\rangle$$
	$\text{Aquí el resultado es }|11\rangle.$

## Tipos de problemas que resuelven
La computación clásica es indicada para problemas que requieren un cálculo numérico y científico **estándar**, como simulación de fenómenos físicos, procesamiento de señales y análisis de datos. Un ejemplo es el reconocimiento de dígitos escritos en un hoja o digital. O la gestión de bases de datos y transacciones.

![[Pasted image 20241213010509.png|440]]

En cambio la computación cuántica es excelente para resolución de problemas NP-completos y NP-difíciles, como el _viajante del comercio_, optimización de rutas y más importante la descomposición en factores primos, como el _algoritmo de Shor_.

![[Pasted image 20241213011305.png|440]]

## Hardware usado
