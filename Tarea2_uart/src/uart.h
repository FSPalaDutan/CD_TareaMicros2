#ifndef UART_H
#define UART_H

// Inicializa la comunicación UART
void initUART(void);

// Envia un mensaje a través de la comunicación UART
void sendMessage(const char* message);

#endif
