#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Alterar o endereço conforme modulo I2C
LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3, POSITIVE); 

#define BotA 2
#define BotB 3
#define BotC 4
#define BotD 5

int nQuestao = 10;
int array[10];
int ponto = 0;
  
void setup(){
  pinMode(BotA, INPUT);
  pinMode(BotB, INPUT);
  pinMode(BotC, INPUT);
  pinMode(BotD, INPUT);
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  
  lcd.print("Seja Bem Vindo!");
  Serial.begin(9600);
  delay(2000);
  lcd.clear();
  
  geraSequencia();
}

void loop(){
ponto = 0;
  for (int i = 0; i < nQuestao; i++){
    SelecionaQuestao(array[i]);
  }
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Fim de Jogo!");
  
  delay(2000);
}


void SelecionaQuestao(int nQuestao){
  
  switch(nQuestao){
    case 0:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 1");
    if(AnalisaBotao()=='A'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 1:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 2");
      if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 2:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 3");
        if(AnalisaBotao()=='C'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 3:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 4");
        if(AnalisaBotao()=='D'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 4:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 5");
        if(AnalisaBotao()=='A'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 5:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 6");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 6:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 7");
        if(AnalisaBotao()=='C'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 7:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 8");
        if(AnalisaBotao()=='D'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 8:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 9");
        if(AnalisaBotao()=='A'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 9:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 10");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
  }
  
}

char AnalisaBotao(){
  bool BotaoPressionado = true;
  
  while(BotaoPressionado){
    if(digitalRead(BotA)){
      BotaoPressionado = false;
      return 'A';
    }else if(digitalRead(BotB)){
      BotaoPressionado = false;
      return 'B';
    }else if(digitalRead(BotC)){
      BotaoPressionado = false;
      return 'C';
    }else if(digitalRead(BotD)){
      BotaoPressionado = false;
      return 'D';
    }
  }
}



void geraSequencia(){
  randomSeed(random(0, 1000));
  for (int i = 0; i < nQuestao; i++){     
    array[i] = i;
  }
 
  for (int i = 0; i < nQuestao; i++) {    
    int temp = array[i];
    int novoIndice = random(nQuestao);
    array[i] = array[novoIndice];
    array[novoIndice] = temp;
  }
}
