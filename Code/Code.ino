/******************************************************************
*   Programador..............: (c)Tiago Machado
*   Data.....................: 13/12/2024
*   Observações..............: Semáforo
*								
******************************************************************/

//Constantes
const int BAUD_RATE = 9600;

const int PINO_LED_VERMELHO = 13;
const int PINO_LED_AMARELO = 11;
const int PINO_LED_VERDE = 9;

const int ESTADO_INICIALIZACAO_SEMAFORO = 0;
const int ESTADO_TESTE_SEMAFORO = 1;
const int ESTADO_ACENDER_VERMELHO = 2;
const int ESTADO_ACENDER_AMARELO = 3;
const int ESTADO_ACENDER_VERDE = 4;

//Variáveis
byte estadoAtual;
byte contador;

void setup(void)	{
  Serial.begin(BAUD_RATE);
  
  estadoAtual = ESTADO_INICIALIZACAO_SEMAFORO;
  
  Serial.println("Incialização dos pinos.......");
  
  pinMode(PINO_LED_VERMELHO, OUTPUT);
  pinMode(PINO_LED_AMARELO, OUTPUT);
  pinMode(PINO_LED_VERDE, OUTPUT);

	contador = 1;
}

void loop(void) {
  switch(estadoAtual)	{
    case ESTADO_INICIALIZACAO_SEMAFORO: {
      	digitalWrite(PINO_LED_VERMELHO, LOW);
      	digitalWrite(PINO_LED_AMARELO, LOW);
      	digitalWrite(PINO_LED_VERDE, LOW);

		delay(2000);
    	
    	estadoAtual = ESTADO_TESTE_SEMAFORO;
    	break;
 	}
  	case ESTADO_TESTE_SEMAFORO: {
      if(contador++ <= 3) {
      	digitalWrite(PINO_LED_VERMELHO, HIGH);
      	digitalWrite(PINO_LED_AMARELO, HIGH);
      	digitalWrite(PINO_LED_VERDE, HIGH);
      
      delay(500);
      
      digitalWrite(PINO_LED_VERMELHO, LOW);
      digitalWrite(PINO_LED_AMARELO, LOW);
      digitalWrite(PINO_LED_VERDE, LOW);
      
      delay(500);             
                   
      }
      else	{
        estadoAtual = ESTADO_ACENDER_VERMELHO;
      }
  	  break;
	}
	case ESTADO_ACENDER_VERMELHO: {
      digitalWrite(PINO_LED_VERMELHO, LOW);
      delay(5000);
      estadoAtual = ESTADO_ACENDER_AMARELO;
      break;
    }
    case ESTADO_ACENDER_AMARELO: {
      digitalWrite(PINO_LED_VERMELHO, LOW);
      digitalWrite(PINO_LED_AMARELO, HIGH);
      delay(3000);
      estadoAtual = ESTADO_ACENDER_VERDE;
      break;
    }
    case ESTADO_ACENDER_VERDE: {
      digitalWrite(PINO_LED_VERMELHO, LOW);
      digitalWrite(PINO_LED_AMARELO, HIGH);
      digitalWrite(PINO_LED_VERDE, HIGH);
      delay(10000);
      digitalWrite(PINO_LED_VERDE, LOW);
      estadoAtual = ESTADO_ACENDER_VERMELHO;
      break;
    }
  }
}		