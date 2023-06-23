#ifndef SEMAFORO_H
#define SEMAFORO_H

#include <Arduino.h>
#include "teclas.h"

// Definir los pines utilizados para los leds
#define led_verde 2
#define led_amarillo 3
#define led_rojo 4

// Estados del semáforo
typedef enum {
  NORMAL,
  DESCONECTADO,
  ALARMA
} SemaforoState;

// Estructura para controlar el semáforo
typedef struct {
  int16_t baseTiempo;
  SemaforoState estado;
} Semaforo;

// Inicializa la MEF del semáforo
void initSemaforo(Semaforo* semaforo);

// Actualiza el estado del semáforo
void actualizarSemaforo(Semaforo* semaforo, dbn_t* dataTecla1, dbn_t* dataTecla2);

#endif
