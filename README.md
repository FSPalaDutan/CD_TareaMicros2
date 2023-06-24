# CD_TareaMicros2
## Integrantes:
## Lourdes Gutiérrez
## Felipe Palaguachi
###
###
###
###
#
## La carpeta "CD_Tarea2" contiene los archivos necesarios para correr el programa correspondiente al punto 1 de la Tarea 2, desde el software Visual Code Studio. 
#### En este punto se implementa una MEF que resuelve el antirrebote por software con dos funciones asociadas, una para inicializar la MEF (initButton) y otra para actualizar el estado de la MEF (actualizarMEF).
#### Los estados de la MEF son los siguientes: UP, DOWN, BOUNCE. Entonces, cuando se encuentra en el estado UP, si se presiona el botón, cambia al estado DOWN. Luego, cuando se encuentra en el estado DOWN, si se libera el botón, cambia al estado DOWN; pero, si no se ha liberado el botón, cambia al estado BOUNCE si verifica que se ha producido un rebote, con los tiempos. Ahora, si están en el estado BOUNCE, y si se libera el botón, cambia al estado UP.
#### Finalmente, con la función buttonPressed se indica qué tecla se presionó. Así mismo, con la función buttonReleased se indica qué tecla se liberó. 
#### La carpeta contiene los siguientes archivos:
##### -main.ino: Necesario para comprobar el funcionamiento en Arduino.
##### -teclas.cpp: Aquí se encuentran las funciones asociadas a la MEF del botón.
##### -teclas.h: Aquí se definen las funciones asociadas a la MEF, las variables, y las librerías.
#### Los pines que se deben conectar son los siguientes:
##### -Boton 1: pin 5
#
###
###
###
###
#
## La carpeta "TAREA2_2" contiene los archivos necesarios para correr el programa correspondiente al punto 2 de la Tarea 2, desde el software Visual Code Studio.
#### En este punto se implementa una única MEF que permite controlar las dos teclas de forma independiente. Entonces, la función de actualización de la MEF recibe como argumento una estructura con los campos: numero de tecla, delay no bloqueante, estado de la MEF.
#### En este contexto, se han definido las variables globales dataTecla1 y dataTecla2 para los dos botones.
#### En cuanto a la máquina de estados, se recibe el argumento dataTecla, que engloba a ambas teclas.
#### La carpeta contiene los siguientes archivos:
##### -main.ino: Necesario para comprobar el funcionamiento en Arduino.
##### -teclas.cpp: Aquí se encuentran las funciones asociadas a la MEF del botón. (Funciones)
##### -teclas.h: Aquí se definen las funciones asociadas a la MEF, las variables, y las librerías. (Prototipo de Funciones)
#### Los pines que se deben conectar son los siguientes:
##### -Boton 1: pin 5
##### -Boton 2: pin 6
#
###
###
###
###
#
## La carpeta "Tarea2_semaforo" contiene los archivos necesarios para correr el programa correspondiente al punto 3 de la Tarea 2, desde el software Visual Code Studio.
#### En este punto, el semáforo tiene los siguientes modos de operación: 
##### -Normal:Secuencia de leds: verde 3 s, verde y amarillo 500 ms, rojo 2 s, verde nuevamente....
##### -Desconectado: Led amarillo intermitente cada 500 ms.
##### -Alarma: Led rojo intermitente cada 1 s.
#### Luego, el botón 1 cambia la base de tiempo de la condición de operación normal (0.5x, 1x, 2x). También, el botón 2 cambia el modo de operación del semáforo a normal. Entonces, cada vez que se libera el botón, cambia el modo en el siguiente orden: normal, desconectado, alarma, normal, etc.
#### En cuanto a la máquina de estados de los botones, se usa la misma que se encuentra en el punto 2 de la Tarea 2.
#### La carpeta contiene los siguientes archivos:
##### -main.ino: Necesario para comprobar el funcionamiento en Arduino.
##### -teclas.cpp: Aquí se encuentran las funciones asociadas a la MEF del botón. (Funciones)
##### -teclas.h: Aquí se definen las funciones asociadas a la MEF, las variables, y las librerías. (Prototipo de Funciones)
##### -semaforo.cpp: Aquí se encuentran las funciones asociadas a la MEF del semáforo. (Funciones)
##### -semaforo.h: Aquí se definen las funciones asociadas a la MEF, las variables, y las librerías. (Prototipo de Funciones)
#### Los pines que se deben conectar son los siguientes:
##### -Boton 1: pin 5
##### -Boton 2: pin 6
##### -Led Verde: pin 4
##### -Led Amarillo: pin 3
##### -Led Rojo: pin 2
#
###
###
###
###
#
## La carpeta "Tarea2_uart" contiene los archivos necesarios para correr el programa correspondiente al punto 4 de la Tarea 2, desde el software Visual Code Studio.
#### En este punto, se implenta una función que imprime los cambios en la MEF antirrebote (qué tecla y en qué estado está la MEF), y los cambios en la MEF del controlador de semáforos (modo de funcionamiento). 
#### La carpeta contiene los siguientes archivos:
##### -main.ino: Necesario para comprobar el funcionamiento en Arduino.
##### -teclas.cpp: Aquí se encuentran las funciones asociadas a la MEF del botón. (Funciones)
##### -teclas.h: Aquí se definen las funciones asociadas a la MEF, las variables, y las librerías. (Prototipo de Funciones)
##### -semaforo.cpp: Aquí se encuentran las funciones asociadas a la MEF del semáforo. (Funciones)
##### -semaforo.h: Aquí se definen las funciones asociadas a la MEF, las variables, y las librerías. (Prototipo de Funciones)
##### -uart.cpp: Aquí se encuentran las funciones asociadas al UART. (Funciones)
##### -uart.h: Aquí se definen las funciones asociadas al UART, las variables, y las librerías. (Prototipo de Funciones)
#### Los pines que se deben conectar son los siguientes:
##### -Boton 1: pin 5
##### -Boton 2: pin 6
##### -Led Verde: pin 2
##### -Led Amarillo: pin 3
##### -Led Rojo: pin 4
#
