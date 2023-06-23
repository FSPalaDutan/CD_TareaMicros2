#include "uart.h"
#include <Arduino.h>

void initUART(void) {
  // Configurar la velocidad de transmisión
  Serial.begin(9600);
}

void sendMessage(const char* message) {
  // Enviar el mensaje por UART
  Serial.println(message);
}
