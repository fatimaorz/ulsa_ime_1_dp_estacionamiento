# Simulador de Acceso a Estacionamiento (versión inicial)

Punto de partida en C++ para el proyecto **Simulador de Acceso a Estacionamiento**.
Esta versión es intencionalmente limitada: no valida tipos de vehículo ni cupos.
El objetivo es que los equipos entiendan la estructura base antes de agregar las
reglas completas del proyecto (control por tipo de vehículo, capacidad máxima,
etc.).

## ¿Qué hace este programa?

Es una interfaz de una sola entrada de texto: todo lo que el usuario teclea se
interpreta según el caso:

- Si el texto **no** coincide con ningún código activo, se registra como una
  **entrada** nueva.
- Si el texto **sí** coincide con un código activo, se registra como una
  **salida**.
- Si el usuario teclea `SALIR`, el programa termina.

No hay límite de cupos ni validación de tipo de vehículo: cualquier texto es
aceptado como una entrada válida.

## Ejemplo de uso

```
=== Simulador de Acceso a Estacionamiento (version inicial) ===
- Teclea el tipo de vehiculo (ej. SUV, SEDAN, COMPACTO) para registrar una entrada.
- Teclea el codigo que recibiste al entrar para registrar una salida.
- Teclea SALIR para terminar el programa.

> suv
Entrada registrada. Tu codigo de acceso es: SUV1
> sedan
Entrada registrada. Tu codigo de acceso es: SEDAN2
> SUV1
Salida registrada para el codigo: SUV1
> salir
Programa terminado.
```

El código de acceso se forma con el texto tecleado (convertido a mayúsculas)
más un número consecutivo, por ejemplo `SUV1`, `SEDAN2`, `COMPACTO3`.

## Archivos de configuración del proyecto

- **`.clangd`**: configuración para el servidor de lenguaje `clangd`, que es
  el que le da a VSCode (y a otros editores) el autocompletado, la detección
  de errores en tiempo real y el "ir a la definición" mientras se escribe
  código. No afecta la compilación ni la ejecución del programa.
- **`.gitignore`**: le indica a Git qué archivos o carpetas no debe subir al
  repositorio (por ejemplo, la carpeta `build/` generada al compilar). Evita
  que se suban archivos temporales o binarios que no son parte del código
  fuente.
- **`Makefile`**: automatiza la compilación con el comando `make`, en lugar
  de tener que escribir el comando de `g++` completo cada vez. Define en
  dónde queda el ejecutable, con qué opciones se compila y agrega atajos
  como `make run` y `make clean`.

## Estructura del proyecto

```
proyecto-estacionamiento/
│
├── .clangd
├── .gitignore
├── Makefile
├── README.md
│
├── include/
│   ├── Lugar.h
│   ├── RegistrarEntrada.h
│   ├── RegistrarSalida.h
│   └── ImprimeReporte.h
│
├── src/
│   ├── main.cpp
│   ├── RegistrarEntrada.cpp
│   ├── RegistrarSalida.cpp
│   └── ImprimeReporte.cpp
│
└── docs/
    ├── pseudocodigo.md
    ├── pruebas.md
    └── evidencias/

Las funciones `registrarEntrada` y `registrarSalida` están separadas de
`main()` y viven cada una en su propio archivo `.h` dentro de `include/`, con
include guards para evitar inclusiones duplicadas.

## Compilar y ejecutar

Con el Makefile incluido, el ejecutable se genera en `build/gestionaEstacionamiento`:

```
make          # compila el proyecto (equivale al target "all")
make run      # compila (si hace falta) y ejecuta el programa
make clean    # borra el ejecutable generado
```

También se puede compilar manualmente con g++:

```
g++ -std=c++17 -Wall -Iinclude src/main.cpp -o build/gestionaEstacionamiento
./build/gestionaEstacionamiento
```

## Qué le falta para llegar al alcance completo del proyecto

Esta versión es solo el punto de partida. El proyecto final del parcial debe
incluir, entre otras cosas:

- Validar el tipo de vehículo (`SUV`, `SEDAN`, `COMPACTO`) en lugar de aceptar
  cualquier texto.
- Controlar el cupo disponible por tipo de vehículo.
- Cualquier otro criterio que se haya definido en la especificación del
  proyecto y en la rúbrica de evaluación.

## Buenas prácticas señaladas en el código

- Se trabaja siempre con una copia en mayúsculas del texto para comparar,
  sin modificar el texto original tecleado por el usuario.
- Se usa `find` de `<algorithm>` para buscar un código dentro de la lista de
  códigos activos, en lugar de escribir un ciclo manual.
- Los archivos `.h` usan include guards (`#ifndef` / `#define` / `#endif`)
  para evitar problemas si llegaran a incluirse más de una vez.
  # SmartPark - Simulador de Acceso a Estacionamiento

## Descripción

SmartPark es un simulador de acceso a un estacionamiento desarrollado en C++.

El programa permite registrar la entrada y salida de vehículos, asignar lugares disponibles y mostrar el estado actual del estacionamiento.

El estacionamiento cuenta con:

- 5 lugares para vehículos SUV.
- 8 lugares para vehículos SEDAN.
- 10 lugares para vehículos COMPACTO.
- 23 lugares en total.

## Integrantes y roles

| Integrante | Rol |
|---|---|
| Nathaly Valdés | Analista / Líder de diseño |
| Fatima Marisol Orrozco | Programador principal |
| Regina Murillo Arellano | Programador de módulos |
| Marian Reynoso Romo | Tester / QA |
| Lucia Anaid Tavares Espinosa | Documentador / Presentador |

## Funcionalidades

El programa permite:

1. Registrar la entrada de un vehículo.
2. Asignar automáticamente un lugar disponible.
3. Registrar la salida de un vehículo mediante su número de lugar.
4. Detectar cuando un tipo de vehículo ya no tiene lugares disponibles.
5. Detectar entradas inválidas.
6. Detectar intentos de salida de lugares inexistentes.
7. Detectar intentos de salida de lugares que ya están libres.
8. Mostrar el estado y porcentaje de ocupación del estacionamiento.
9. Finalizar la simulación utilizando el comando `SALIR`.

## Tipos de vehículos

Los tipos de vehículos aceptados son:

- `SUV`
- `SEDAN`
- `COMPACTO`

## Ejemplo de uso

Para registrar una entrada:

```text
> SUV
Vehiculo aceptado. Lugar asignado: SUV01