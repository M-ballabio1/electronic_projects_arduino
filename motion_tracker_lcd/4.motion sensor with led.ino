#define PIR_PIN 7
#define LED_PIN 13
#define BUZZER_PIN 8

bool state = false;

void setup(){
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

}

void loop() {
  if(digitalRead(PIR_PIN) == HIGH){
    if(!state){
      digitalWrite(LED_PIN, HIGH);
      state = true;
    }
    digitalWrite(LED_PIN, millis()/100%2);
    tone(BUZZER_PIN, millis()%1000+200);
  }else{
    if(state){
      digitalWrite(LED_PIN, LOW);
      noTone(BUZZER_PIN);
      state = false;
    }
  }
  delay(1);
}
