Programa basado en un reto de programacion del torneo organizado por la Universidad Nacional de Villa Mercedes

![Screenshot of program](https://github.com/mateo-astudillo/darevil-game-c/blob/main/img/screen.png)

# Consigna Original

**Daredevil**, el hombre sin miedo, es un superhéroe que quedó ciego de niño
por culpa de una sustancia radiactiva. Dicha sustancia le hizo perder la
vista pero, al mismo tiempo, agudizó el resto de sus sentidos. Así,
Daredevil desarrolló un sistema de **radar** (similar a la ecolocalización)
que le permite saber en qué lugar están los villanos con los que va a
combatir.
Sin embargo, su archi-enemigo **Kingpin** le ha tendido una trampa y le ha
encerrado en una habitación cuya resonancia anula su sistema de radar.
Además, ha convocado a un montón de villanos que le esperan con rencor para darle una paliza.
Daredevil todavía no sabe lo que se le viene encima pero,
afortunadamente, tiene un gadget programable que quizá pueda ayudarle.
## Datos de Entrada
El programa deberá procesar múltiples casos de prueba. Cada uno comienza
con la descripción de la sala a la que llega Daredevil. Una sala es un
espacie rectangular organizado en **celdas**, cada una de las cuales puede
estar libre u ocupada por un villano.
La primera línea del caso de prueba contiene dos números, 1 ≤ F,C ≤ 100
indicando la cantidad de **filas** y **columnas** que tiene la sala. A
continuación vienen F líneas de C letras cada una. Las letras pueden ser
“X” para indicar que la celda está ocupada por un **villano**, o “.” para
indicar que está **vacía**.
Tras el mapa del caso de prueba aparece un número 1≤N≤100 con la cantidad
de **consultas** que se realizarán sobre ese mapa. Cada consulta es una
**posición** donde podría estar Daredevil y la **dirección** hacia la que apunta
con su gadget. La posición se indica proporcionando primero el número de
fila, y luego el número de columna. La celda (1,1) se encuentra en la
esquina superior izquierda del mapa. La dirección será IZQUIERDA,
DERECHA, ARRIBA o ABAJO. Se garantiza que no se realizará ninguna
consulta en una posición ocupada por un villano. La entrada termina con
dos ceros.
## Salida
Por cada consulta se escribirá, en una línea independiente, la **distancia**,
en número de celdas, al villano más cercano desde la posición de la
consulta en la dirección indicada. Si no hay ningún villano, se escribirá
“NINGUNO”. Al final de cada caso de prueba se escribirá “---”

