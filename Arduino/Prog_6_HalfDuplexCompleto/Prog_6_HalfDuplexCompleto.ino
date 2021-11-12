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

String temporal;
int vSensor1, vSensor2, vSensor3;
int vActuador1, vActuador2, vActuador3;
void loop() {
  //leer el valor de todos los sensores
  //enviar la información al EV en una única trama

  vSensor1 = analogRead(Sensor1); //0 - 1023
  vSensor2 = analogRead(Sensor2);
  vSensor3 = analogRead(Sensor3);

  //Serial.print("E" + String(vSensor1) +"S"+ String(vSensor2) +"S"+ String(vSensor3) + "T");

  //////////////////////////////////////////////////////////////////////////////////

  //leer datos recibidos del EV para el control de los actuadores
  if (Serial.available() > 0) { //si hay informacion que leer, entonces se lee
    temporal = Serial.readString();
    temporal.replace("\n", "");
    temporal.replace("\r", "");
    Serial.print(temporal);

    //String aux[] = temporal.Split("S");
    String aux = "";
    int actuador = 11;
    for (int i = 1; i < temporal.length() - 1; i++){
      if (temporal.charAt(i) == 'S') {
        analogWrite(actuador++, aux.toInt());
        Serial.println(aux);
        aux = "";
      }
      else {
        aux += temporal.charAt(i);
      }
    }
    analogWrite(actuador, aux.toInt());
    Serial.println(aux);
    
  }
  
  // E3S50S255T
  //////////////////////////////////////////////////////////////////////////////////
  delay(100);
}
