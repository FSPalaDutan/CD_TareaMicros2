#include "teclas.h"
#include "uart.h"

// Variables globales de los estados
dbn_t dataTecla1;
dbn_t dataTecla2;

// Inicializa la MEF
void initButton(void) {
  dataTecla1.tecla = Boton_1;
  dataTecla1.delay = 50;
  dataTecla1.estado = UP;

  dataTecla2.tecla = Boton_2;
  dataTecla2.delay = 50;
  dataTecla2.estado = UP;
}

// Actualiza el estado de la MEF
void actualizarMEF(dbn_t *dataTecla) {
  switch (dataTecla->estado) {
    case UP:
      // Si se presiona, cambia al estado DOWN
      if (digitalRead(dataTecla->tecla) == LOW) {
        dataTecla->estado = DOWN;
        char message[20];
        sprintf(message, "Transición en boton %d ", dataTecla->tecla);
        sendMessage(message);
        buttonPressed(dataTecla->tecla); // Llamar a la función buttonPressed
      }
      break;
    case DOWN:
      // Si se libera, cambia al estado UP
      if (digitalRead(dataTecla->tecla) == HIGH) {
        dataTecla->estado = UP;
        buttonReleased(dataTecla->tecla); // Llamar a la función buttonReleased
      } else {
        // Cambia al estado BOUNCE si hay rebote
        if (millis() - dataTecla->delay >= dataTecla->delay) {
          dataTecla->estado = BOUNCE;
        }
      }
      break;
    case BOUNCE:
      // Si se libera, cambia al estado UP
      if (digitalRead(dataTecla->tecla) == HIGH) {
        dataTecla->estado = UP;
        char message[20];
        sprintf(message, "Transición en boton %d ", dataTecla->tecla);
        sendMessage(message);
        buttonReleased(dataTecla->tecla); // Llamar a la función buttonReleased
      }
      break;
  }
}

void buttonPressed(int16_t tecla) {
  // Comunicación uart caundo se presiona el boton
  char message[20];
  sprintf(message, "Boton %d presionado", tecla);
  sendMessage(message);
}


void buttonReleased(int16_t tecla) {
  // Comunicación uart caundo se libera el boton
  char message[20];
  sprintf(message, "Boton %d liberado", tecla);
  sendMessage(message);
}
