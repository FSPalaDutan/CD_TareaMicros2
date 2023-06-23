#include "semaforo.h"
#include "teclas.h"

void initSemaforo(Semaforo* semaforo) {
  semaforo->baseTiempo = 500;
  semaforo->estado = NORMAL;
}

void actualizarSemaforo(Semaforo* semaforo, dbn_t* dataTecla1, dbn_t* dataTecla2) {
  // Verificar si se ha presionado la primera tecla
  if (dataTecla1->estado == DOWN) {
    switch (semaforo->baseTiempo) {
      case 500:
        semaforo->baseTiempo = 1000;
        break;
      case 1000:
        semaforo->baseTiempo = 2000;
        break;
      case 2000:
        semaforo->baseTiempo = 500;
        break;
    }
  }

  // Verificar si se ha presionado la segunda tecla
  if (dataTecla2->estado == DOWN) {
    switch (semaforo->estado) {
      case NORMAL:
        semaforo->estado = DESCONECTADO;
        break;
      case DESCONECTADO:
        semaforo->estado = ALARMA;
        break;
      case ALARMA:
        semaforo->estado = NORMAL;
        break;
    }
  }

  // Estado del semáforo
  switch (semaforo->estado) {
    case NORMAL:
    // Semaforo normal
      if (millis() % (semaforo->baseTiempo * 6) < semaforo->baseTiempo * 3) {
        digitalWrite(led_verde, HIGH);
        digitalWrite(led_amarillo, LOW);
        digitalWrite(led_rojo, LOW);
      } else if (millis() % (semaforo->baseTiempo * 6) < semaforo->baseTiempo * 3 + semaforo->baseTiempo / 2) {
        digitalWrite(led_verde, HIGH);
        digitalWrite(led_amarillo, HIGH);
        digitalWrite(led_rojo, LOW);
      } else if (millis() % (semaforo->baseTiempo * 6) < semaforo->baseTiempo * 5) {
        digitalWrite(led_verde, LOW);
        digitalWrite(led_amarillo, LOW);
        digitalWrite(led_rojo, HIGH);
      } else {
        digitalWrite(led_verde, HIGH);
        digitalWrite(led_amarillo, LOW);
        digitalWrite(led_rojo, LOW);
      }
      break;
    case DESCONECTADO:
      // Led amarillo intermitente cada 500 ms
      if (millis() % semaforo->baseTiempo < semaforo->baseTiempo / 2) {
        digitalWrite(led_verde, LOW);
        digitalWrite(led_amarillo, HIGH);
        digitalWrite(led_rojo, LOW);
      } else {
        digitalWrite(led_verde, LOW);
        digitalWrite(led_amarillo, LOW);
        digitalWrite(led_rojo, LOW);
      }
      break;
    case ALARMA:
      // Led rojo intermitente cada 1 s
      if (millis() % semaforo->baseTiempo < semaforo->baseTiempo / 2) {
        digitalWrite(led_verde, LOW);
        digitalWrite(led_amarillo, LOW);
        digitalWrite(led_rojo, HIGH);
      } else {
        digitalWrite(led_verde, LOW);
        digitalWrite(led_amarillo, LOW);
        digitalWrite(led_rojo, LOW);
      }
      break;
  }
}
