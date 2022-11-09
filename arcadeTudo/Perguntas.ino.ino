#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Alterar o endereço conforme modulo I2C
LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3, POSITIVE); 

#define BotA 2
#define BotB 3
#define BotC 4
#define BotD 5

int nQuestao = 20;
int array[20];
int ponto = 0;
  
void setup(){
  pinMode(BotA, INPUT);
  pinMode(BotB, INPUT);
  pinMode(BotC, INPUT);
  pinMode(BotD, INPUT);
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  
  
  geraSequencia();
}

void loop(){
ponto = 0;
  for (int i = 0; i < nQuestao; i++){
    SelecionaQuestao(array[i]);
  }
  
  
  delay(2000);
}


void SelecionaQuestao(int nQuestao){
  
  switch(nQuestao){
    case 0:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("81-14=?  43 73 67 52");
    if(AnalisaBotao()=='C'){
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
      lcd.print("³√8=?  1,13 2 24 512");
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
      lcd.print("Qual o símbolo do hélio?  Hl He Ho H" );
        if(AnalisaBotao()=='B'){
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
      lcd.print("Medida da massa molar? g/mol mol/ml mol Kg/mol");
        if(AnalisaBotao()=='A'){
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
      lcd.print("Massa atômica de O2? (O=16) 32 45 64 26");
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
      lcd.print("Medida de pressão cm³ atm K P");
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
      lcd.print("N° de pontos em um set de vôlei 15 25 30 20");
        if(AnalisaBotao()=='B'){
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
      lcd.print("Primeiro Macintosh 1998 2002 1990 1984");
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
   case 10:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 11");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
         case 11:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 12");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
         case 13:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 14");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
         case 14:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 15");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
         case 15:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 16");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
         case 16:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 17");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
         case 17:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 18");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
         case 18:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 19");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
         case 19:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 20 case 9:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Questao 10");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
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
