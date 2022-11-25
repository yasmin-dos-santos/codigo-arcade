#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Alterar o endereço conforme modulo I2C
LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3, POSITIVE); 

#define BotA 2
#define BotB 3
#define BotC 4
#define BotD 5

int nQuestao = 10;
int array[20];
int ponto = 0;
  
void setup(){
  pinMode(BotA, INPUT_PULLUP);
  pinMode(BotB, INPUT_PULLUP);
  pinMode(BotC, INPUT_PULLUP);
  pinMode(BotD, INPUT_PULLUP);
  
  lcd.begin(20, 4);
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
      lcd.print("81-14=?");
      lcd.setCursor(0,1);
      lcd.print("a)43 b)73 c)67 d)52");
    if(AnalisaBotao()=='C'){
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Correto!");
          delay(500);
        }else{
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Errado!");
           delay(500);
        }
    break;
    case 1:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("169/13=?");
      lcd.setCursor(0,1);
      lcd.print("a)15 b)13 c)9 d)12");
      if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Correto!");
          delay(500);
        }else{
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Errado!");
           delay(500);
        }
    break;
    case 2:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Primeiro Macintosh");
      lcd.setCursor(0,1);
      lcd.print("a)02 b)84 c)96 d)92");
        if(AnalisaBotao()=='C'){
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Correto!");
          delay(500);
        }else{
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Errado!");
          delay(500);
        }
    break;
    case 3:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Tri do Brasil");
      lcd.setCursor(0,1);
      lcd.print("a)02 b)06 c)94 d)70");
        if(AnalisaBotao()=='D'){
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Correto!");
          delay(500);
        }else{
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Errado!");
          delay(500);
        }
    break;
    case 4:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("O que e Monaco");
      lcd.setCursor(0,1);
      lcd.print("a)pais b)principado");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Correto!");
          delay(500);
        }else{
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Errado!");
          delay(500);
        }
    break;
    case 5:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Copa de 98 foi na");
      lcd.setCursor(0,1);
      lcd.print("a)Brasil b)Franca c)EUA");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Correto!");
          delay(500);
        }else{
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Errado!");
          delay(500);
        }
    break;
    case 6:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Quantos países Asia");
      lcd.setCursor(0,1);
      lcd.print("a)62 b)49 c)22 d)42");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Correto!");
          delay(500);
        }else{
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Errado!");
          delay(500);
        }
    break;
    case 7:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Vasco era");
      lcd.setCursor(0,1);
      lcd.print("a)clube b)nada c)SAF");
        if(AnalisaBotao()=='A'){
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Correto!");
          delay(500);
        }else{
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Errado!");
          delay(500);
        }
    break;
    case 8:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Primeira Copa");
      lcd.setCursor(0,1);
      lcd.print("a)30 b)58 c)62 d)38");
        if(AnalisaBotao()=='A'){
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Correto!");
          delay(500);
        }else{
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Errado!");
          delay(500);
        }
    break;
    case 9:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Ultimo Campeao Copa");
      lcd.setCursor(0,1);
      lcd.print("a)Vasco b)Alemanha");
      lcd.setCursor(0,2);
      lcd.print("c)Franca d)Portugal");
        if(AnalisaBotao()=='C'){
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Correto!");
          delay(500);
        }else{
          lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("Errado!");
          delay(500);
        }
    break;
  }
  
}

char AnalisaBotao(){
  bool BotaoPressionado = true;
  
  while(BotaoPressionado){
    if(!digitalRead(BotA)){
      BotaoPressionado = false;
      delay(700);
      return 'A';
    }else if(!digitalRead(BotB)){
      BotaoPressionado = false;
       delay(700);
      return 'B';
    }else if(!digitalRead(BotC)){
      BotaoPressionado = false; 
       delay(700);
      return 'C';
    }else if(!digitalRead(BotD)){
      BotaoPressionado = false;
       delay(700);
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
