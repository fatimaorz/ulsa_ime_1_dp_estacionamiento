# Pruebas del Simulador de Estacionamiento

## Objetivo

Verificar que el simulador permita registrar entradas y salidas de vehículos
y que muestre correctamente el estado del estacionamiento.

## Prueba 1: Entrada de SUV

### Entrada
SUV

### Resultado esperado
El sistema debe aceptar el vehículo y asignarle el primer lugar disponible:

SUV01

### Resultado obtenido
El vehículo fue aceptado y se asignó el lugar SUV01.

---

## Prueba 2: Entrada de SEDAN

### Entrada
SEDAN

### Resultado esperado
El sistema debe aceptar el vehículo y asignar:

SEDAN01

### Resultado obtenido
El vehículo fue aceptado y se asignó el lugar SEDAN01.

---

## Prueba 3: Entrada de COMPACTO

### Entrada
COMPACTO

### Resultado esperado
El sistema debe aceptar el vehículo y asignar:

COMPACTO01

### Resultado obtenido
El vehículo fue aceptado y se asignó el lugar COMPACTO01.

---

## Prueba 4: Registrar salida

### Entrada
SUV01

### Resultado esperado
El sistema debe liberar el lugar SUV01.

### Resultado obtenido
El vehículo salió correctamente y el lugar quedó disponible.

---

## Prueba 5: Salida de un lugar libre

### Entrada
SUV01

### Resultado esperado
El sistema debe indicar que el lugar ya está libre.

### Resultado obtenido
El sistema indicó que el lugar ya está libre.

---

## Prueba 6: Comando SALIR

### Entrada
SALIR

### Resultado esperado
El sistema debe finalizar la simulación.

### Resultado obtenido
La simulación finalizó correctamente.

---

## Conclusión

Las pruebas realizadas permitieron comprobar el funcionamiento de las
entradas, salidas, validaciones y visualización del estado del estacionamiento.