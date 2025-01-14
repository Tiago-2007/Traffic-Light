/******************************************************************
*   Programador..............: (c)Tiago Machado
*   Data.....................: 6/01/2025
*   Observações..............: Led a piscar
*								
******************************************************************/


const int LedPin = 7;

void setup() {
  // Configurando o pino como saída
  pinMode(LedPin, OUTPUT);
}

void loop() {
  
  // Liga o LED
  digitalWrite(LedPin, HIGH);
  delay(500);
  digitalWrite(LedPin, LOW);
  delay(500);
}