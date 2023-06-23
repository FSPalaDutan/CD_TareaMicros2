#include "teclas.h"

// Variables para el retardo no bloqueante
unsigned long t_previo = 0;
const unsigned long intervalo = 10; // Intervalo de tiempo entre actualizaciones en milisegundos

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
}

void loop() {
  // Obtener el tiempo actual
  unsigned long t_actual = millis();
  
  //Si se presiona por más de 10ms, se actualiza el estado
  if (t_actual - t_previo >= intervalo) {
    t_previo = t_actual;
    updateButton();
  }

}