void pan_param_E12_L1() {

  int m_E1 = 0, h_E1 = 0, m_E2 = 0, h_E2 = 0;

  static int vell_minuts_E1 = minuts_E1, vell_hora_E1 = hora_E1;
  static int vell_minuts_E2 = minuts_E2, vell_hora_E2 = hora_E2;

  texto("Parametres L1 1", 25, 5, 3, ORANGE);
  dibuLinea(0, 33, 350, 33, 3, true, VIOLETA);

  texto("Hora", 30, 40, 2, BLUE);
  hora_E1 = num_inputI(hora_E1_inicial, 5, 85, 2, WHITE, BLUE, 0, 23, 1);
  hora_E1_inicial = hora_E1;

  texto("Minuts", 125, 40, 2, BLUE);
  minuts_E1 = num_inputI(minuts_E1_inicial, 115, 85, 2, WHITE, BLUE, 0, 59, 1);
  minuts_E1_inicial = minuts_E1;

  texto("Hora", 30, 130, 2, BLAU);
  hora_E2 = num_inputI(hora_E2_inicial, 5, 175, 2, WHITE, BLAU, 0, 23, 1);
  hora_E2_inicial = hora_E2;

  texto("Minuts", 125, 130, 2, BLAU);
  minuts_E2 = num_inputI(minuts_E2_inicial, 115, 175, 2, WHITE, BLAU, 0, 59, 1);
  minuts_E2_inicial = minuts_E2;


  if (vell_hora_E1 != hora_E1) {
    vell_hora_E1 = hora_E1;
    tft.fillRect(240 - 1, 85 - 1, 25, 16, BLACK);
  }

  if (vell_minuts_E1 != minuts_E1) {
    vell_minuts_E1 = minuts_E1;
    tft.fillRect(270 - 1, 85 - 1, 25, 16, BLACK);
  }

  if (vell_hora_E2 != hora_E2) {
    vell_hora_E2 = hora_E2;
    tft.fillRect(240 - 1, 175 - 1, 25, 16, BLACK);
  }

  if (vell_minuts_E2 != minuts_E2) {
    vell_minuts_E2 = minuts_E2;
    tft.fillRect(270 - 1, 175 - 1, 25, 16, BLACK);
  }

  texto("ON", 255, 60, 2, BLUE);
  texto("OFF", 250, 150, 2, BLAU);

  if (hora_E1 < 10) {
    texto("0", 240, 85, 2, WHITE);
    h_E1 = 12;
  }
  variableI(hora_E1, 240 + h_E1, 85, 2, WHITE);

  texto(":", 260, 85, 2, WHITE);

  if (minuts_E1 < 10) {
    texto("0", 270, 85, 2, WHITE);
    m_E1 = 12;
  }
  variableI(minuts_E1, 270 + m_E1, 85, 2, WHITE);

  if (hora_E2 < 10) {
    texto("0", 240, 175, 2, WHITE);
    h_E2 = 12;
  }
  variableI(hora_E2, 240 + h_E2, 175, 2, WHITE);

  texto(":", 260, 175, 2, WHITE);

  if (minuts_E2 < 10) {
    texto("0", 270, 175, 2, WHITE);
    m_E2 = 12;
  }
  variableI(minuts_E2, 270 + m_E2, 175, 2, WHITE);

  EEPROM.update(10, hora_E1);
  EEPROM.update(12, minuts_E1);
  EEPROM.update(14, hora_E2);
  EEPROM.update(16, minuts_E2);

}

void pan_param_E34_L1() {

  int m_E3 = 0, h_E3 = 0, m_E4 = 0, h_E4 = 0;

  static int vell_minuts_E3 = minuts_E3, vell_hora_E3 = hora_E3;
  static int vell_minuts_E4 = minuts_E4, vell_hora_E4 = hora_E4;

  texto("Parametres L1 2", 25, 5, 3, ORANGE);
  dibuLinea(0, 33, 350, 33, 3, true, VIOLETA);

  texto("Hora", 30, 40, 2, VERD);
  hora_E3 = num_inputI(hora_E3_inicial, 5, 85, 2, WHITE, VERD, 0, 23, 1);
  hora_E3_inicial = hora_E3;

  texto("Minuts", 125, 40, 2, VERD);
  minuts_E3 = num_inputI(minuts_E3_inicial, 115, 85, 2, WHITE, VERD, 0, 59, 1);
  minuts_E3_inicial = minuts_E3;

  texto("Hora", 30, 130, 2, GREEN);
  hora_E4 = num_inputI(hora_E4_inicial, 5, 175, 2, WHITE, GREEN, 0, 23, 1);
  hora_E4_inicial = hora_E4;

  texto("Minuts", 125, 130, 2, GREEN);
  minuts_E4 = num_inputI(minuts_E4_inicial, 115, 175, 2, WHITE, GREEN, 0, 59, 1);
  minuts_E4_inicial = minuts_E4;

  if (vell_hora_E3 != hora_E3) {
    vell_hora_E3 = hora_E3;
    tft.fillRect(240 - 1, 85 - 1, 25, 16, BLACK);
  }

  if (vell_minuts_E3 != minuts_E3) {
    vell_minuts_E3 = minuts_E3;
    tft.fillRect(270 - 1, 85 - 1, 25, 16, BLACK);
  }

  if (vell_hora_E4 != hora_E4) {
    vell_hora_E4 = hora_E4;
    tft.fillRect(240 - 1, 175 - 1, 25, 16, BLACK);
  }

  if (vell_minuts_E4 != minuts_E4) {
    vell_minuts_E4 = minuts_E4;
    tft.fillRect(270 - 1, 175 - 1, 25, 16, BLACK);
  }

  texto("ON", 255, 60, 2, VERD);
  texto("OFF", 250, 150, 2, GREEN);

  if (hora_E3 < 10) {
    texto("0", 240, 85, 2, WHITE);
    h_E3 = 12;
  }
  variableI(hora_E3, 240 + h_E3, 85, 2, WHITE);

  texto(":", 260, 85, 2, WHITE);

  if (minuts_E3 < 10) {
    texto("0", 270, 85, 2, WHITE);
    m_E3 = 12;
  }
  variableI(minuts_E3, 270 + m_E3, 85, 2, WHITE);

  if (hora_E4 < 10) {
    texto("0", 240, 175, 2, WHITE);
    h_E4 = 12;
  }
  variableI(hora_E4, 240 + h_E4, 175, 2, WHITE);

  texto(":", 260, 175, 2, WHITE);

  if (minuts_E4 < 10) {
    texto("0", 270, 175, 2, WHITE);
    m_E4 = 12;
  }
  variableI(minuts_E4, 270 + m_E4, 175, 2, WHITE);

  EEPROM.update(18, hora_E3);
  EEPROM.update(20, minuts_E3);
  EEPROM.update(22, hora_E4);
  EEPROM.update(24, minuts_E4);

}

void pan_param_E56_L2() {

  int m_E5 = 0, h_E5 = 0, m_E6 = 0, h_E6 = 0;

  static int vell_minuts_E5 = minuts_E5, vell_hora_E5 = hora_E5;
  static int vell_minuts_E6 = minuts_E6, vell_hora_E6 = hora_E6;

  texto("Parametres L2", 30, 5, 3, ORANGE);
  dibuLinea(0, 33, 350, 33, 3, true, VIOLETA);

  texto("Hora", 30, 40, 2, VIOLET);
  hora_E5 = num_inputI(hora_E5_inicial, 5, 85, 2, WHITE, VIOLET, 0, 23, 1);
  hora_E5_inicial = hora_E5;

  texto("Minuts", 125, 40, 2, VIOLET);
  minuts_E5 = num_inputI(minuts_E5_inicial, 115, 85, 2, WHITE, VIOLET, 0, 59, 1);
  minuts_E5_inicial = minuts_E5;

  texto("Hora", 30, 130, 2, ROSA);
  hora_E6 = num_inputI(hora_E6_inicial, 5, 175, 2, WHITE, ROSA, 0, 23, 1);
  hora_E6_inicial = hora_E6;

  texto("Minuts", 125, 130, 2, ROSA);
  minuts_E6 = num_inputI(minuts_E6_inicial, 115, 175, 2, WHITE, ROSA, 0, 59, 1);
  minuts_E6_inicial = minuts_E6;

  if (vell_hora_E5 != hora_E5) {
    vell_hora_E5 = hora_E5;
    tft.fillRect(240 - 1, 85 - 1, 25, 16, BLACK);
  }

  if (vell_minuts_E5 != minuts_E5) {
    vell_minuts_E5 = minuts_E5;
    tft.fillRect(270 - 1, 85 - 1, 25, 16, BLACK);
  }

  if (vell_hora_E6 != hora_E6) {
    vell_hora_E6 = hora_E6;
    tft.fillRect(240 - 1, 175 - 1, 25, 16, BLACK);
  }

  if (vell_minuts_E6 != minuts_E6) {
    vell_minuts_E6 = minuts_E6;
    tft.fillRect(270 - 1, 175 - 1, 25, 16, BLACK);
  }

  texto("ON", 255, 60, 2, VIOLET);
  texto("OFF", 250, 150, 2, ROSA);

  if (hora_E5 < 10) {
    texto("0", 240, 85, 2, WHITE);
    h_E5 = 12;
  }
  variableI(hora_E5, 240 + h_E5, 85, 2, WHITE);

  texto(":", 260, 85, 2, WHITE);

  if (minuts_E5 < 10) {
    texto("0", 270, 85, 2, WHITE);
    m_E5 = 12;
  }
  variableI(minuts_E5, 270 + m_E5, 85, 2, WHITE);

  if (hora_E6 < 10) {
    texto("0", 240, 175, 2, WHITE);
    h_E6 = 12;
  }
  variableI(hora_E6, 240 + h_E6, 175, 2, WHITE);

  texto(":", 260, 175, 2, WHITE);

  if (minuts_E6 < 10) {
    texto("0", 270, 175, 2, WHITE);
    m_E6 = 12;
  }
  variableI(minuts_E6, 270 + m_E6, 175, 2, WHITE);

  EEPROM.update(26, hora_E5);
  EEPROM.update(28, minuts_E5);
  EEPROM.update(30, hora_E6);
  EEPROM.update(32, minuts_E6);


}

