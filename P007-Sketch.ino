#define pin1Vm 2
#define pin1Am 3
#define pin1Vd 4

#define pinB 16 //Botão de "acessibilidade"

#define pin2Vm 5
#define pin2Am 6
#define pin2Vd 7

#define pinB2 19 //Botão de "acessibilidade"

void setup() {
  
  pinMode(pin1Vm, OUTPUT); //Pino Vermelho  - Semaforo 1
  pinMode(pin1Am, OUTPUT); //Pino Amarelo   - Semaforo 1
  pinMode(pin1Vd, OUTPUT); //Pino Verde     - Semaforo 1

  pinMode(pinB, INPUT_PULLUP); //Pino Botão - Semaforo 1

  pinMode(pin2Vm, OUTPUT); //Pino Vermelho - Semaforo 2
  pinMode(pin2Am, OUTPUT); //Pino Amarelo  - Semaforo 2
  pinMode(pin2Vd, OUTPUT); //Pino Verde    - Semaforo 2

  pinMode(pinB2, INPUT_PULLUP); //Pino Botão - Semaforo 2

  Serial.begin(9600);
}
void estadoSemaforo(){
  for(int i=1; i<5; i++){
    if(digitalRead(pinB) == HIGH or digitalRead(pinB2) == HIGH){
      i = 0;
    }
    switch (i) {
      case 0:
        break;
      case 1: //1Vd - 2Vm
          digitalWrite(pin1Vm, LOW); //vm1
          digitalWrite(pin1Am, LOW); //am1
          digitalWrite(pin2Vd, LOW); //vd2
          digitalWrite(pin2Am, LOW); //am2
        
          digitalWrite(pin1Vd, HIGH); //VD1
          Serial.println("Verde 1"); 

          digitalWrite(pin2Vm, HIGH); //VM2             
          Serial.print("/ Vermelho 2");

          delay(3000);
          break;
      case 2: //1Am - 2Vm
          digitalWrite(pin1Vm, LOW);
          digitalWrite(pin1Vd, LOW);
          digitalWrite(pin2Vd, LOW);
          digitalWrite(pin2Am, LOW);

          digitalWrite(pin1Am, HIGH);
          Serial.println("Amarelo 1");

          digitalWrite(pin2Vm, HIGH);
          Serial.print("/ Vermelho 2");                 
          delay(1500);
          break;
      case 3: //1Vm - 2Vd
          digitalWrite(pin1Vd, LOW);
          digitalWrite(pin1Am, LOW);
          digitalWrite(pin2Am, LOW);
          digitalWrite(pin2Vm, LOW);

          digitalWrite(pin1Vm, HIGH);
          Serial.println("Vermelho 1");                 
          digitalWrite(pin2Vd, HIGH);                 
          Serial.print("/ Verde 2");
          delay(3000);
          break;
      case 4: //1Vm - 2Am
          digitalWrite(pin1Vd, LOW);
          digitalWrite(pin1Am, LOW);
          digitalWrite(pin2Vd, LOW);
          digitalWrite(pin2Vm, LOW);

          digitalWrite(pin1Vm, HIGH);
          Serial.println("Vermelho 1");                 
          digitalWrite(pin2Am, HIGH);
          Serial.print("/ Amarelo 2");                 
          delay(1500);
          break;
        if (i == 4){
          i = 1;
        }
    }
  }      
}

void mudancaButton(){
    if (digitalRead(pinB) == HIGH) {
      if(pin1Vm == HIGH and pin2Am == HIGH){
        digitalWrite(pin1Vd, HIGH);
        digitalWrite(pin1Vm, LOW);
        digitalWrite(pin1Am, LOW);
        digitalWrite(pin2Vd, LOW);
        digitalWrite(pin2Vm, LOW);
        digitalWrite(pin2Am, HIGH);        
      }
  }
      if (digitalRead(pinB2) == HIGH) {
      if(pin2Vm == HIGH and pin1Am == HIGH){
        digitalWrite(pin2Vd, HIGH);
        digitalWrite(pin2Vm, LOW);
        digitalWrite(pin2Am, LOW);
        digitalWrite(pin1Vd, LOW);
        digitalWrite(pin1Vm, LOW);
        digitalWrite(pin1Am, HIGH);    
      }
  }
}

void loop() {
  estadoSemaforo();
  mudancaButton();

}
