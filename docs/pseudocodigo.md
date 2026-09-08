# Pseudocódigo del Simulador de Estacionamiento

## Inicio

Crear una lista llamada estacionamiento.

Crear 5 lugares de tipo SUV.
Crear 8 lugares de tipo SEDAN.
Crear 10 lugares de tipo COMPACTO.

Mostrar mensaje de bienvenida.

Mostrar las opciones:
- COMPACTO
- SEDAN
- SUV
- Lugar para salida
- SALIR

Mientras la opción no sea SALIR:

    Leer entrada del usuario.

    Si la entrada es "SUV", "SEDAN" o "COMPACTO":

        Buscar el primer lugar disponible
        del tipo de vehículo.

        Si existe un lugar disponible:

            Marcar el lugar como ocupado.

            Mostrar el lugar asignado.

        Si no existe:

            Mostrar "Estacionamiento lleno".

        Mostrar el estado del estacionamiento.

    Si no:

        Intentar identificar el tipo y número del lugar.

        Si el lugar no existe:

            Mostrar "Salida invalida".

        Si el lugar está libre:

            Mostrar "El lugar ya está libre".

        Si el lugar está ocupado:

            Marcar el lugar como libre.

            Mostrar que el vehículo salió.

            Mostrar el estado del estacionamiento.

Fin mientras

Mostrar "Simulación finalizada".

Fin