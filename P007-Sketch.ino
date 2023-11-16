#define pin1Vm 2
#define pin1Am 3
#define pin1Vd 4

#define pinB 8 //Botão de "acessibilidade"

#define pin2Vm 5
#define pin2Am 6
#define pin2Vd 7

#define pinB2 9 //Botão de "acessibilidade"

int d = 2000;
void setup() {

  pinMode(pin1Vm, OUTPUT); //Pino Vermelho  - Semaforo 1
  pinMode(pin1Am, OUTPUT); //Pino Amarelo   - Semaforo 1
  pinMode(pin1Vd, OUTPUT); //Pino Verde     - Semaforo 1
  digitalWrite(pin1Vm, HIGH);
  digitalWrite(pin1Am, HIGH);
  digitalWrite(pin1Vd, HIGH);
  pinMode(pinB, INPUT_PULLUP); //Pino Botão - Semaforo 1

  pinMode(pin2Vm, OUTPUT); //Pino Vermelho - Semaforo 2
  pinMode(pin2Am, OUTPUT); //Pino Amarelo  - Semaforo 2
  pinMode(pin2Vd, OUTPUT); //Pino Verde    - Semaforo 2
  digitalWrite(pin2Vm, HIGH);
  digitalWrite(pin2Am, HIGH);
  digitalWrite(pin2Vd, HIGH);
  pinMode(pinB2, INPUT_PULLUP); //Pino Botão - Semaforo 2

  Serial.begin(9600);
  acessibilityButton();
  delay(d/2);
}

void acessibilityButton(){
  int button = digitalRead(pinB);
  int button2 = digitalRead(pinB2);
  if(button == HIGH and button2 == LOW){
    delay(d/2);
    digitalWrite(pin1Vm, HIGH);
    digitalWrite(pin1Vd, LOW);
    digitalWrite(pin1Am, LOW);
    digitalWrite(pin2Vm, LOW);
    digitalWrite(pin2Vd, HIGH);
    digitalWrite(pin2Am, LOW);  
    Serial.println("Button HIGH");
    delay(d*2);
    estadoSemaforo();      
  }
  if (button2 == HIGH and button == LOW) {
    delay(d/2);
    digitalWrite(pin2Vm, HIGH);
    digitalWrite(pin2Vd, LOW);
    digitalWrite(pin2Am, LOW);
    digitalWrite(pin1Vm, LOW);
    digitalWrite(pin1Vd, HIGH);
    digitalWrite(pin1Am, LOW); 
    Serial.println("Button2 HIGH");
    delay(d*2); 
    estadoSemaforo();
  }
}

void estadoSemaforo(){
  acessibilityButton();
  //1Vd - 2Vm
  digitalWrite(pin1Vm, LOW); //vm1
  digitalWrite(pin1Am, LOW); //am1
  digitalWrite(pin2Vd, LOW); //vd2
  digitalWrite(pin2Am, LOW); //am2

  digitalWrite(pin1Vd, HIGH); //VD1
  Serial.print("Verde 1"); 

  digitalWrite(pin2Vm, HIGH); //VM2             
  Serial.println(" / Vermelho 2");

  delay(d*2);

  acessibilityButton();
   //1Am - 2Vm
  digitalWrite(pin1Vm, LOW);
  digitalWrite(pin1Vd, LOW);
  digitalWrite(pin2Vd, LOW);
  digitalWrite(pin2Am, LOW);

  digitalWrite(pin1Am, HIGH);
  Serial.print("Amarelo 1");

  digitalWrite(pin2Vm, HIGH);
  Serial.println(" / Vermelho 2");                 
  delay(d);

  acessibilityButton();
   //1Vm - 2Vd
  digitalWrite(pin1Vd, LOW);
  digitalWrite(pin1Am, LOW);
  digitalWrite(pin2Am, LOW);
  digitalWrite(pin2Vm, LOW);

  digitalWrite(pin1Vm, HIGH);
  Serial.print("Vermelho 1");                 
  digitalWrite(pin2Vd, HIGH);                 
  Serial.println(" / Verde 2");
  delay(d*2);

  acessibilityButton();
   //1Vm - 2Am
  digitalWrite(pin1Vd, LOW);
  digitalWrite(pin1Am, LOW);
  digitalWrite(pin2Vd, LOW);
  digitalWrite(pin2Vm, LOW);

  digitalWrite(pin1Vm, HIGH);
  Serial.print("Vermelho 1");                 
  digitalWrite(pin2Am, HIGH);
  Serial.println(" / Amarelo 2");                 
  delay(d);

}

void loop() {
  estadoSemaforo();
  
}
