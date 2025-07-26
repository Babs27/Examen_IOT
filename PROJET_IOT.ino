#define IR_SENSOR_PIN D5   
#define LED_PIN       D0   

int compteur = 0;                  
bool ancienEtat = HIGH;           

void setup() {
  Serial.begin(9600);             
  pinMode(IR_SENSOR_PIN, INPUT);  
  pinMode(LED_PIN, OUTPUT);       
  digitalWrite(LED_PIN, LOW);     
}

void loop() {
  int sensorValue = digitalRead(IR_SENSOR_PIN); 

  
  if (ancienEtat == HIGH && sensorValue == LOW) {
    if (compteur < 20) {
      compteur++; 
      Serial.print("Personne détecté ! Nombre total : ");
      Serial.println(compteur);
      digitalWrite(LED_PIN, HIGH); 

      if (compteur == 20) {
        Serial.println("Nombre de passages maximal atteint !");
      }
    }
  } else if (sensorValue == HIGH) {
    Serial.println("Pas de personne détecté.");
    digitalWrite(LED_PIN, LOW); 
  }

  ancienEtat = sensorValue; 
  delay(100); 
}