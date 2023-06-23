#include "teclas.h"

// Variables globales de los estados
State e_actual;
State e_siguiente;
unsigned long t_antirebote = 50; // Tiempo de antirebore en milisegundos

// Inicializa la MEF
void initButton(void) {
  e_actual = UP;
  e_siguiente = UP;
}

// Actualiza el estado de la MEF
void updateButton(void) {
  switch (e_actual) {
    case UP:
      // Si se presiona, cambia al estado DOWN
      if (digitalRead(Boton_1) == LOW) {
        e_siguiente = DOWN;
        buttonPressed(1); // Llamar a la funcion buttonPressed (1 o 2)
      }
      break;
    case DOWN:
      // Si se libera, cambia al estado UP
      if (digitalRead(Boton_1) == HIGH) {
        e_siguiente = UP;
        buttonReleased(1); // Llamar a la funcion buttonReleased 
      } else {
        // Cambia al estado BOUNCE si hay rebote
        if (millis() - t_antirebote >= t_antirebote) {
          e_siguiente = BOUNCE;
        }
      }
      break;
    case BOUNCE:
      // Si se libera, cambia al estado UP
      if (digitalRead(Boton_1) == HIGH) {
        e_siguiente = UP;
        buttonReleased(1); // Llamar a la funcion buttonReleased
      }
      break;
  }

  e_actual = e_siguiente;
}

void buttonPressed(int16_t tecla) {
  // Imprimir cuando se presiona la tecla
  Serial.print("Boton ");
  Serial.print(tecla);
  Serial.println(" presionado");
}

void buttonReleased(int16_t tecla) {
  // Imprimir cuando se libera la tecla
  Serial.print("Boton ");
  Serial.print(tecla);
  Serial.println(" liberado");
}