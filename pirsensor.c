// Sketch for Particle Photon - PIR Sensor / Motion Detection
// By Anton
int inputPin = D6;              // choose the input pin (for PIR sensor)
int ledPin = D7;                // LED Pin
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

int calibrateTime = 5000;      // wait for the thingy to calibrate

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(inputPin, INPUT);     // declare sensor as input
}

void loop() {

  // if the sensor is calibrated
  if (calibrated()) 
  {
  // get the data from the sensor
    readTheSensor();

    // report it out, if the state has changed
    reportTheData();
    
    }
}
void readTheSensor() {
    val = digitalRead(inputPin);
}

bool calibrated() {
    return millis() - calibrateTime > 0;
}

void setLED(int state) {
    digitalWrite(ledPin, state);
}

void reportTheData() {
  
if (val == LOW) {   
       if (pirState = HIGH){
          Particle.publish("Photon2Motion", "OFF", PRIVATE);
        delay(1000);
        pirState = LOW;
       }
        val == LOW;
}
if (val == HIGH) {
          if (pirState = LOW){
          Particle.publish("Photon2Motion", "Motion Detected", PRIVATE);
        delay(1000);
    pirState = LOW;
          }

}
}
