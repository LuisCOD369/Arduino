const int ledPin9 = 9;
const int ledPin10 = 10;
const int ledPin11 = 11;
const int motorPin = 12; // Pin PWM para controlar el motor
const int potPin = A0;  // Pin analógico para el potenciómetro

int potValue = 0; // Variable para almacenar el valor del potenciómetro

void setup() {
  Serial.begin(9600);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin10, OUTPUT);
  pinMode(ledPin11, OUTPUT);
  pinMode(motorPin, OUTPUT); // Configura el pin del motor como salida
  
  // Menú de opciones
  Serial.println("1.- Encender LED 1");
  Serial.println("2.- Apagar LED 1");
  Serial.println("3.- Encender LED 2");
  Serial.println("4.- Apagar LED 2");
  Serial.println("5.- Encender LED 3");
  Serial.println("6.- Apagar LED 3");
  Serial.println("7.- Encender todos los LEDs");
  Serial.println("8.- Apagar todos los LEDs");
  Serial.println("9.- Encender el motor (control por potenciómetro)");
  Serial.println("10.- Apagar el motor");
  Serial.println("11.- Cerrar conexión serial");
  Serial.println("Elija una opción:");
}

void loop() {
  if (Serial.available() > 0) {
    char key = Serial.read();
    executeOption(key);
    delay(200); // Espera para evitar múltiples cambios rápidos si se mantienen presionadas las teclas
  }
  
  // Lectura del potenciómetro y control del motor
  potValue = analogRead(potPin); // Lee el valor del potenciómetro (0-1023)
  int motorSpeed = map(potValue, 0, 1023, 0, 255); // Mapea el valor a un rango adecuado para la velocidad del motor (0-255)
  analogWrite(motorPin, motorSpeed); // Controla la velocidad del motor
}

void executeOption(char option) {
  switch (option) {
    case '1':
      digitalWrite(ledPin9, HIGH);
      Serial.println("LED 1 encendido");
      break;
    case '2':
      digitalWrite(ledPin9, LOW);
      Serial.println("LED 1 apagado");
      break;
    case '3':
      digitalWrite(ledPin10, HIGH);
      Serial.println("LED 2 encendido");
      break;
    case '4':
      digitalWrite(ledPin10, LOW);
      Serial.println("LED 2 apagado");
      break;
    case '5':
      digitalWrite(ledPin11, HIGH);
      Serial.println("LED 3 encendido");
      break;
    case '6':
      digitalWrite(ledPin11, LOW);
      Serial.println("LED 3 apagado");
      break;
    case '7':
      digitalWrite(ledPin9, HIGH);
      digitalWrite(ledPin10, HIGH);
      digitalWrite(ledPin11, HIGH);
      Serial.println("Todos los LEDs encendidos");
      break;
    case '8':
      digitalWrite(ledPin9, LOW);
      digitalWrite(ledPin10, LOW);
      digitalWrite(ledPin11, LOW);
      Serial.println("Todos los LEDs apagados");
      break;
    case '9':
      digitalWrite(motorPin, HIGH);
      Serial.println("Encender el motor (control por potenciómetro)");
      
      //digitalWrite(motorPin, LOW);
      //Serial.println("Encender el motor (control por potenciómetro)");
      break;
    case '10':
      digitalWrite(motorPin, LOW);
      Serial.println("Apagar el motor (control por potenciómetro)");
      break;
    case '11':
      Serial.println("Cerrando conexión serial");
      Serial.end();
      break;
    default:
      Serial.println("Opción no válida");
      break;
  }
}
