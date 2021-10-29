int led = 12;

void setup() {  
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  
  Serial.begin(9600);
  Serial.setTimeout(100);//ms
}

int v;
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){    
      v = Serial.readString().toInt();

      digitalWrite(led, v); // 1 = HIGH --- 0 = LOW
    }
}
