int led = 12;

void setup() {  
  // put your setup code here, to run once:  
  pinMode(led, OUTPUT); 
  
  Serial.begin(9600);  
  Serial.setTimeout(100); //100ms
}

int v;
void loop() {

  if(Serial.available()>0){ //Checa si existe información que leer en el buffer
      v = Serial.readString().toInt();

      digitalWrite(led, v); //0 o 1
      Serial.println("Acción Realizada");
  }
  delay(100); //ms
}
