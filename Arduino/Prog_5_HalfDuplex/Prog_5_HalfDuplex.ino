int Actuador1 = 11;
int Actuador2 = 12;
int Actuador3 = 13;

int Sensor1 = A0;
int Sensor2 = A1;
int Sensor3 = A2;

void setup() {  
  // put your setup code here, to run once:  
  pinMode(Actuador1, OUTPUT); 
  pinMode(Actuador2, OUTPUT); 
  pinMode(Actuador3, OUTPUT); 
  
  Serial.begin(9600);  
  Serial.setTimeout(100); //100ms
}

int vSensor1, vSensor2, vSensor3;
void loop() {
  //leer el valor de todos los sensores
  //enviar la información al EV en una única trama

  vSensor1 = analogRead(Sensor1); //0 - 1023
  vSensor2 = analogRead(Sensor2);
  vSensor3 = analogRead(Sensor3);

  Serial.print("E" + String(vSensor1) +"S"+ String(vSensor2) +"S"+ String(vSensor3) + "T");

  delay(100);
}
