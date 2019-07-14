

//Motor A
int inputPin1  = 0;    // Pin 2 of L293D IC, D1 Pin of NodeMCU
int ENABLE_1 = 5;     // Pin 1 of L293D IC, D6 Pin of NodeMCU

//Motor B
int inputPin3  = 2;    // Pin 12 of L293D IC, D2 Pin of NodeMCU
int ENABLE_2 = 4;      // Pin 11 of L293D IC, D5 Pin of NodeMCU

int speed = 50;
int deadBand = 50;

void setup() {
    pinMode(ENABLE_1, OUTPUT);   // where the motor is connected to
    pinMode(ENABLE_2, OUTPUT);   // where the motor is connected to
    pinMode(inputPin1, OUTPUT);
    pinMode(inputPin3, OUTPUT);
    
    digitalWrite(ENABLE_1, LOW);
    digitalWrite(ENABLE_2, LOW);
    
    Serial.begin(115200);
    Serial.print("Enter integer value : ");
    Serial.print("> FORWARD  [           0 :  511 - dband ]");
    Serial.print("> BACKWARD [ 513 + dband :         1023 ]\n");
    Serial.print("DeadBand = ");
    Serial.println(deadBand);
}

void loop() {
  delay(100);
  if(Serial.available())
    { 
      speed = Serial.parseInt();
      
      analogWrite(inputPin1, speed);//sets the motors speed
      analogWrite(inputPin3, speed);//sets the motors speed
      if ((abs(speed-512) < deadBand ) ) {
        Serial.print("Motors stopped speed < ");
        Serial.println(deadBand);
        digitalWrite(ENABLE_1, LOW);
        digitalWrite(ENABLE_2, LOW);
      }
      else {
       Serial.print("Motors running speed = ");
       Serial.println(speed);
       digitalWrite(ENABLE_1, HIGH);
       digitalWrite(ENABLE_2, HIGH);
       }
    }
    
}
