
// Pin.
#define relay  2

bool RelayIsOn;

void setup() {
  Serial.begin(9600);

  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH); // Set relay off. HIGH = off; LOW = ON.
  RelayIsOn = false;
}

void loop() {
  if (Serial.available() > 0) {
    char data = Serial.read();
    
    Serial.write("R:");
    Serial.write(data);
    Serial.write("\r\n");
    
    switch (data) {
      // Off.
      case '0':
        digitalWrite(relay, HIGH);
        RelayIsOn = false;
        break;

      // On.
      case '1':
        digitalWrite(relay, LOW);
        RelayIsOn = true;
        break;
        
      // Toggle.
      case '2':
        if (RelayIsOn)
          digitalWrite(relay, HIGH);
        else
          digitalWrite(relay, LOW);
        RelayIsOn = !RelayIsOn;
        break;
        
      default:
        digitalWrite(relay, HIGH);
        RelayIsOn = false;
        break;
    }
    delay(50);
  }
}
