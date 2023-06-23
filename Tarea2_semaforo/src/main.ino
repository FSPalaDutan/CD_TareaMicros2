#include "teclas.h"

// Variables para el retardo no bloqueante
unsigned long t_previo = 0;
const unsigned long intervalo = 10; // Intervalo de tiempo entre actualizaciones en milisegundos
extern dbn_t dataTecla1;
extern dbn_t dataTecla2;

// Declarar la estructura del semáforo
Semaforo semaforo;

void setup() {
  // Inicializar el módulo de los botones
  initButton();

  // Configurar los botones como entradas
  pinMode(Boton_1, INPUT);
  pinMode(Boton_2, INPUT);

  // Configurar resistencias de pull-up para los botones
  digitalWrite(Boton_1, HIGH);
  digitalWrite(Boton_2, HIGH);

  // Iniciar la comunicación serial
  Serial.begin(9600);

  // Inicializar el semáforo
  initSemaforo(&semaforo);

  // Configurar los pines de los leds como salidas
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarillo, OUTPUT);
  pinMode(led_rojo, OUTPUT);
}

void loop() {
  // Obtener el tiempo actual
  unsigned long t_actual = millis();

  // Si se presiona por más de 10ms, se actualiza el estado
  if (t_actual - t_previo >= intervalo) {
    t_previo = t_actual;
    actualizarMEF(&dataTecla1);
    actualizarMEF(&dataTecla2);

    // Actualizar el estado del semáforo
    actualizarSemaforo(&semaforo, &dataTecla1, &dataTecla2);
    t_previo = t_actual;
  }
}
