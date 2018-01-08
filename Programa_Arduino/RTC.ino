void RTC_DS () {
  DateTime now = rtc.now();
  int s = 0;
  int m = 0;
  int h = 0;
  int D = 0;
  int M = 0;
  static int vell_segond = now.second();
  static int vell_minut = now.minute();
  static int vell_hora = now.hour();
  static int vell_dia = now.day();
  static int vell_diaSetmana = now.dayOfTheWeek();
  char diaSetmana[7][10] = {"Diumenge", "Dilluns", "Dimarts", "Dimecres", "Dijous", "Divendres", "Dissabte"};

  const int posX_hora = 5;
  const int posY_hora = 220;
  const int posX_data = 220;
  const int posY_data = 220;
  const int MidaLletres = 2;

  if (vell_diaSetmana != now.dayOfTheWeek()) {
    vell_diaSetmana = now.dayOfTheWeek();
    tft.fillRect(103, 218, 110, 20, BLACK);
  }
  texto(diaSetmana[now.dayOfTheWeek()], 105, 220, 2, GREEN);

  if (vell_segond != now.second()) {
    vell_segond = now.second();
    tft.fillRect((posX_hora - 1 + 35 + 35), posY_hora - 1, 25, 16, BLACK);
  }

  if (vell_minut != now.minute()) {
    vell_minut = now.minute();
    tft.fillRect((posX_hora - 1 + 35), posY_hora - 1, 25, 16, BLACK);
  }

  if (vell_hora != now.hour()) {
    vell_hora = now.hour();
    tft.fillRect(posX_hora - 1, posY_hora - 1, 25, 16, BLACK);
  }

  if (vell_dia != now.day()) {
    vell_dia = now.day();
    tft.fillRect(posX_data - 1, posY_data - 1, 95, 16, BLACK);
  }
  //**********************************************************************
  if (now.day() < 10) {
    texto("0", posX_data, posY_data, MidaLletres, WHITE);
    D = 12;
  }
  variableI(now.day(), posX_data + D, posY_data, MidaLletres, WHITE);

  texto("/", posX_data + 25, posY_data, MidaLletres, WHITE);
  if (now.month() < 10) {
    texto("0", posX_data + 35, posY_data, MidaLletres, WHITE);
    M = 12;
  }
  variableI(now.month(), (posX_data + 35) + M, posY_data, MidaLletres, WHITE);

  texto("/", (posX_data + 25 + 35), posY_data, MidaLletres, WHITE);
  variableI(now.year() - 2000, (posX_data + 35 + 35), posY_data, MidaLletres, WHITE);
  //*******************************************************************

  if (now.hour() < 10) {
    texto("0", posX_hora, posY_hora, MidaLletres, WHITE);
    h = 12;
  }
  variableI(now.hour(), (posX_hora) + h, posY_hora, MidaLletres, WHITE);

  texto(":", posX_hora + 23, posY_hora, MidaLletres, WHITE);
  if (now.minute() < 10) {
    texto("0", posX_hora + 35, posY_hora, MidaLletres, WHITE);
    m = 12;
  }
  variableI(now.minute(), (posX_hora + 35) + m, posY_hora, MidaLletres, WHITE);

  texto(":", posX_hora + 23 + 35, posY_hora, MidaLletres, WHITE);
  if (now.second() < 10) {
    texto("0", posX_hora + 35 + 35, posY_hora, MidaLletres, WHITE);
    s = 12;
  }
  variableI(now.second(), (posX_hora + 35 + 35) + s, posY_hora, MidaLletres, WHITE);

}
