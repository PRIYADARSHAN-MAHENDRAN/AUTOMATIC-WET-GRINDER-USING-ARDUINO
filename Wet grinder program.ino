// Pin assignments
const int consistencyButtonThickPin = 2;
const int consistencyButtonWateryPin = 4;
const int waterPumpRelayPin = 7;
const int wetGrinderMotorRelayPin = 8;
const int temperatureSensorPin = A0;
const int buzzerPin = 13;
int consisThick = 0;
int consisWatery = 0;

// Temperature sensor setup
const int temperatureThreshold = 48; // Adjust this value based on your requirements

// Variables
bool isConsistencySelected = false;
bool isMotorOverheated = false;
bool isPlayingBirthdayTune = false;

void setup() {
  // Set pin modes
  pinMode(consistencyButtonThickPin, INPUT_PULLUP);
  pinMode(consistencyButtonWateryPin, INPUT_PULLUP);
  pinMode(waterPumpRelayPin, OUTPUT);
  pinMode(wetGrinderMotorRelayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Start serial communication (for debugging, if needed)
  Serial.begin(9600);
}

void loop() {
  // Wait for consistency selection
  digitalWrite(waterPumpRelayPin, HIGH);
  digitalWrite(wetGrinderMotorRelayPin, HIGH);
  if (!isConsistencySelected) {
    int consistencySelection = checkConsistencySelection();
    if (consistencySelection != 0) {
      isConsistencySelected = true;
      Serial.println("Consistency selected: " + String(consistencySelection));
    }
  }
  // Only execute the rest of the code if consistency is selected
  if (isConsistencySelected) {
      checkMotorTemperature();
    
     
      startGrindingTask();
      delay(1000);
      
      digitalWrite(buzzerPin, HIGH);  
  delay(500);                       
  digitalWrite(buzzerPin, LOW);   
  delay(100);
  digitalWrite(buzzerPin, HIGH);  
  delay(100);                       
  digitalWrite(buzzerPin, LOW);   
  delay(100);
  digitalWrite(buzzerPin, HIGH);   
  delay(100);
  digitalWrite(buzzerPin, LOW);
      isConsistencySelected = false;
      consisThick=0;
      consisWatery = 0;
    }
  }
int checkConsistencySelection() {
  if (digitalRead(consistencyButtonThickPin) == LOW) {
    consisThick++;
    return 1; // Thick consistency selected
  } else if (digitalRead(consistencyButtonWateryPin) == LOW) {
    consisWatery++;
    return 2; // Watery consistency selected
  }
  return 0; // No selection yet
}

void startGrindingTask() {
  
  if(consisThick>0){
    digitalWrite(wetGrinderMotorRelayPin, LOW);
    for(int i=0;i<3;i++){
      checkMotorTemperature();
      digitalWrite(waterPumpRelayPin, LOW);
      delay(1000);
      digitalWrite(waterPumpRelayPin, HIGH);
      checkMotorTemperature();
      delay(7000);
    }
    digitalWrite(wetGrinderMotorRelayPin, HIGH);
    }
  else if(consisWatery>0){
    digitalWrite(wetGrinderMotorRelayPin, LOW);
    for(int i=0;i<5;i++){
      checkMotorTemperature();
      digitalWrite(waterPumpRelayPin, LOW);
      delay(1000);
      digitalWrite(waterPumpRelayPin, HIGH);
      checkMotorTemperature();
      delay(7000);
    }
    digitalWrite(wetGrinderMotorRelayPin, HIGH);
  }
}

void checkMotorTemperature() {
  int motorTemperature = readMotorTemperature();
  
  // Check if the motor temperature is too hot
  if(motorTemperature <= 38){
  while (motorTemperature < temperatureThreshold) {
    // Stop the motor
    digitalWrite(wetGrinderMotorRelayPin, LOW);
    Serial.println("Motor overheated! Waiting for it to cool down...");
    Serial.println("Motor temperature: " + String(motorTemperature) + " °C");
    motorTemperature = readMotorTemperature();
  }
  digitalWrite(wetGrinderMotorRelayPin, HIGH);
  }
}

int readMotorTemperature() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = voltage*100;
  Serial.println(temperature);
  return temperature;
}
