# Carrera de Algoritmos | Proyecto U3 Algoritmos y Estructuras de Datos

Este es un programa en C++ que simula una carrera entre diferentes algoritmos de ordenamiento para determinar cuál es el más rápido en diferentes escenarios de entrada. El programa implementa varios algoritmos de ordenamiento, como Bubble Sort, Heap Sort, Quick Sort, Merge Sort, Selection Sort, Insertion Sort y Shell Sort.

Para ver video explicativo, haga click [Aquí](https://drive.google.com/file/d/1cjAYx4FvvX7pInPPpxrNJ0IDzxeMRPu0/view?usp=sharing)
## Aspectos generales

El programa se enfoca en comparar el rendimiento de los algoritmos de ordenamiento en cuatro modos diferentes de entrada:

1. Datos ordenados.
2. Datos ordenados de manera inversa.
3. Datos aleatorios sin elementos duplicados.
4. Datos aleatorios con posibilidad de elementos duplicados.

En cada carrera, se selecciona un tamaño de datos aleatorio dentro de un rango específico. Luego, se ejecutan los algoritmos de ordenamiento en los datos generados para cada modo y se mide el tiempo de ejecución de cada algoritmo.

El ganador de cada carrera es el algoritmo que termina primero en términos de tiempo de ejecución.

### Función de Generación de Conjuntos de Datos

La función `generateDataSet` se utiliza para crear conjuntos de datos para la carrera. Puede generar conjuntos de datos ordenados, inversamente ordenados, aleatorios sin repeticiones y aleatorios con posibilidad de elementos duplicados, según el modo proporcionado.

### Función de Medición de Tiempo de Ejecución

La función `getExecutionTime` se encarga de medir el tiempo de ejecución de cada algoritmo en un conjunto de datos específico. También permite ordenar los datos en orden ascendente o descendente según la configuración proporcionada.

### Requisitos del Sistema
- Sistema operativo compatible (Windows)
- Compilador C++ compatible

### Configuración e Instalación
1. Clona o descarga este repositorio en tu máquina local.
2. Asegúrate de tener un compilador C++ instalado y configurado correctamente en tu sistema.
3. Abre el archivo del programa principal `ProyectoU3.cpp` en tu entorno de desarrollo o editor de código preferido.

### Compilación y Ejecución
1. Compila el código fuente del programa utilizando tu compilador C++. Esto puede variar dependiendo del sistema operativo y del compilador utilizado.
   - Ejemplo de compilación en línea de comandos con g++ 
     ```shell
     g++ ProyectoU3.cpp -o ProyectoU3
     ```
2. Una vez compilado correctamente, ejecuta el programa resultante.
   - Ejemplo de ejecución en línea de comandos 
     ```shell
     ./ProyectoU3
     ```

