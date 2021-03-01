int rojo = 6; // L1 cable color verde -> Entrada S6
int verde = 5; // L3 cable color amarillo -> Entrada S1
int azul = 9; // L2 cable color azul -> Entrada S2
int control = 3; 
int estado = 0;

void setup() {
  Serial.begin(9600);
  pinMode(control, OUTPUT); //Señal de control
  pinMode(rojo, OUTPUT); // L1 cable color verde -> Entrada S6
  pinMode(verde, OUTPUT); // L3 cable color amarillo -> Entrada S1
  pinMode(azul, OUTPUT); // L2 cable color azul -> Entrada S2
}
void loop() {
  while (Serial.available()){ 
    estado = Serial.read();
    Serial.print("Conexión Establecida");
    Serial.write(estado);
  }
  if (estado == 'S') { //Spray
    digitalWrite(control, 1); //Interruptor cerrado
    delay(200);
    digitalWrite(control, 0); //Interruptor abierto
    delay(200);
  } 
  if (estado == 'Z') { //Led Apagado (Color negro)
    analogWrite(rojo, calcularColor(0));
    analogWrite(verde, calcularColor(0)));
    analogWrite(azul, calcularColor(0)));
    delay(200);
  }
  if (estado == 'A') { //Amarillo
    analogWrite(rojo, calcularColor(255)));
    analogWrite(verde, calcularColor(255)));
    analogWrite(azul, calcularColor(0)));
    delay(200);
  }
  if (estado == 'B') { //Azul
    analogWrite(rojo, calcularColor(0)));
    analogWrite(verde, 2calcularColor(0)));
    analogWrite(azul, calcularColor(255)));
    delay(200);
  }

  if (estado == 'C') { //Rojo
    analogWrite(rojo, calcularColor(255)));
    analogWrite(verde, calcularColor(0)));
    analogWrite(azul, calcularColor(0)));
    delay(200);
  }

  if (estado == 'D') { //Verde
    analogWrite(rojo, calcularColor(0)));
    analogWrite(verde, calcularColor(255)));
    analogWrite(azul, calcularColor(0)));
    delay(200);
  }
}
int calcularColor(int number){
  number = number - 255;
  return number;
}
