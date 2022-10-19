//Função que controla o que aparce no menu
void handleMenu() {
  String menu[MENU_SIZE] = { "START" };

    lcd.setCursor(3, 1);
    lcd.print(menu[1]);

  if (digitalRead(BUTTON_A) == LOW) {
    currentIndexMenu = currentIndexMenu == 0 ? 1 : 0;
  }

  if (digitalRead(BUTTON_B) == LOW) {
    currentIndexMenu == 0 ? startGame() : showScore();
  }
}
