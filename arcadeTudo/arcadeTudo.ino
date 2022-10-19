
// AeroArduino.com

/*
This is a working Trex Dinosaur with buttons Select and Enter on pins 8 and 9 

It has a score registers to save


Video on YouTube:

     https://youtu.be/8tQP66L5U7Y

     https://youtu.be/5v31BsxHwso


*/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

//bitmap array for the dino character
byte dino [8]
{ B00000,
  B00111,
  B00101,
  B10111,
  B11100,
  B11111,
  B01101,
  B01100,
};

//character for the tree
byte tree [8]
{
  B00011,
  B11011,
  B11011,
  B11011,
  B11011,
  B11111,
  B01110,
  B01110
};

const int BUTTON_ENTER = 2;
const int BUTTON_SELECT = 3;

const int MENU_SIZE = 2;
const int LCD_COLUMN = 16;

const int TREE_CHAR = 6;
const int DINO_CHAR = 7;

const String ALPHABET[26] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };

boolean isPlaying = false;
boolean isShowScore = false;
boolean isDinoOnGround = true;

int currentIndexMenu = 0;
int score = 0;
int scoreListSize = 0;
String scoreList[20];

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(DINO_CHAR, dino);
  lcd.createChar(TREE_CHAR, tree);

  Serial.begin(9600);
  pinMode(BUTTON_ENTER, INPUT_PULLUP);
  pinMode(BUTTON_SELECT, INPUT_PULLUP);
}

void loop() {
  lcd.clear();
  handleMenu();

  delay(300);
}

void handleMenu() {
  String menu[MENU_SIZE] = { "START", "MUSIC" };

  for (int i = 0; i < MENU_SIZE; i++) {
    if (i == currentIndexMenu) {
      lcd.setCursor(0, i);
      lcd.print("-> ");
    }

    lcd.setCursor(3, i);
    lcd.print(menu[i]);
  }

  if (digitalRead(BUTTON_SELECT) == LOW) {
    currentIndexMenu = currentIndexMenu == 0 ? 1 : 0;
  }

  if (digitalRead(BUTTON_ENTER) == LOW) {
    currentIndexMenu == 0 ? startGame() : showScore();
  }
}

void handleMusic() {
  String menu[MENU_SIZE] = { "SAMBA", "FUNK" };

  for (int i = 0; i < MENU_SIZE; i++) {
    if (i == currentIndexMenu) {
      lcd.setCursor(0, i);
      lcd.print("-> ");
    }

    lcd.setCursor(3, i);
    lcd.print(menu[i]);
  }

  if (digitalRead(BUTTON_SELECT) == LOW) {
    currentIndexMenu = currentIndexMenu == 0 ? 1 : 0;
  }

  if (digitalRead(BUTTON_ENTER) == LOW) {
    currentIndexMenu == 0 ? startGame() : showScore();
  }
}
void showScore () {
  isShowScore = true;
  delay(200);

  int currentIndex = 0;
  const int lastIndex = scoreListSize - 1;

  printScore(currentIndex, lastIndex);

  while (isShowScore) {
    if (digitalRead(BUTTON_SELECT) == LOW) {
      currentIndex = currentIndex < lastIndex ? currentIndex + 1 : 0;
      printScore(currentIndex, lastIndex);
    }

    if (digitalRead(BUTTON_ENTER) == LOW) {
      isShowScore = false;
    }

    delay(200);
  }
}

void printScore(int index, int lastIndex) {
  lcd.clear();

  handleMusic();
}

void startGame () {
  isPlaying = true;

  while (isPlaying) {
    handleGame();
  }
}

void handleGame() {
  lcd.clear();

  int buttonPressedTimes = 0;

  // Generate two random distances for the space between the trees
  int secondPosition = random(4, 9);
  int thirdPosition = random(4, 9);
  int firstTreePosition = LCD_COLUMN;

  const int columnValueToStopMoveTrees = -(secondPosition + thirdPosition);

  // this loop is to make the trees move, this loop waiting until
  // all the trees moved
  for (; firstTreePosition >= columnValueToStopMoveTrees; firstTreePosition--) {

    lcd.setCursor(13, 0);
    lcd.print(score);

    defineDinoPosition();

    int secondTreePosition = firstTreePosition + secondPosition;
    int thirdTreePosition = secondTreePosition + thirdPosition;

    showTree(firstTreePosition);
    showTree(secondTreePosition);
    showTree(thirdTreePosition);

    if (isDinoOnGround) {
      if (firstTreePosition == 1 || secondTreePosition == 1 || thirdTreePosition == 1) {
        handleGameOver();
        delay(5000);
        break;
      }
      buttonPressedTimes = 0;

    } else {
      if (buttonPressedTimes > 3) {
        score -= 3;
      }

      buttonPressedTimes++;
    }

    score++;
    delay(500);
  }
}

void handleGameOver () {
  lcd.clear();
  lcd.print("GAME OVER");

  lcd.setCursor(0, 1);
  lcd.print("SCORE: ");
  lcd.print(score);

  delay(2000);
  saveScore();
}

void saveScore () {
  lcd.clear();

  String nick = "";
  int nameSize = 0;
  int alphabetCurrentIndex = 0;

  lcd.print("TYPE YOUR NAME");

  while (nameSize != 3) {
    lcd.setCursor(nameSize, 1);
    lcd.print(ALPHABET[alphabetCurrentIndex]);

    if (digitalRead(BUTTON_SELECT) == LOW) {
      alphabetCurrentIndex = alphabetCurrentIndex != 25 ? alphabetCurrentIndex + 1 : 0;
    }

    if (digitalRead(BUTTON_ENTER) == LOW) {
      nick += ALPHABET[alphabetCurrentIndex];

      nameSize++;
      alphabetCurrentIndex = 0;
    }

    delay(300);
  }

  scoreList[scoreListSize] =  nick + " " + score;
  scoreListSize++;

  isPlaying = false;
  score = 0;
}

void showTree (int position) {
  lcd.setCursor(position, 1);
  lcd.write(TREE_CHAR);

  // clean the previous position
  lcd.setCursor(position + 1, 1);
  lcd.print(" ");
}

void defineDinoPosition () {
  int buttonState = digitalRead(BUTTON_ENTER);
  buttonState == HIGH ? putDinoOnGround() : putDinoOnAir();
}

void putDinoOnGround () {
  lcd.setCursor(1, 1);
  lcd.write(DINO_CHAR);
  lcd.setCursor(1, 0);
  lcd.print(" ");

  isDinoOnGround = true;
}

void putDinoOnAir () {
  lcd.setCursor(1, 0);
  lcd.write(DINO_CHAR);
  lcd.setCursor(1, 1);
  lcd.print(" ");

  isDinoOnGround = false;
}
