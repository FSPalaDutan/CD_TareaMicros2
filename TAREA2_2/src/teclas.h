#ifndef TECLAS_H
#define TECLAS_H

#include <Arduino.h>

// Definir los pines utilizados para las teclas
#define Boton_1 5
#define Boton_2 6

// Estados de la MEF
typedef enum {
  UP,
  DOWN,
  BOUNCE
} State;

// Estructura para controlar el antirrebote
typedef struct {
  int16_t tecla;
  int16_t delay;
  State estado;
} dbn_t;

// Inicializa la MEF
void initButton(void);

// Actualiza el estado de la MEF
void actualizarMEF(dbn_t *dataTecla);

// Función al pulsar una tecla
void buttonPressed(int16_t tecla);

// Función al liberar una tecla
void buttonReleased(int16_t tecla);

#endif
