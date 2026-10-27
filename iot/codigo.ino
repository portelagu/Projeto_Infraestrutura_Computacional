int pinSensor = A0;
int ledVerde = 8;
int ledAmarelo = 9;
int ledVermelho = 10;

void setup() {
  Serial.begin(9600);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  int leituraAnaloga = analogRead(pinSensor);
  float tensao = leituraAnaloga * 5.0 / 1024.0;
  float temperaturaC = (tensao - 0.5) * 100.0;
  
  Serial.print("Temperatura atual: ");
  Serial.print(temperaturaC);
  Serial.println(" C");
  
  if (temperaturaC < 28.0) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  } else if (temperaturaC >= 28.0 && temperaturaC < 32.0) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
  } else {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
  }
  delay(1000);
}