//********** Extriu text a la possició, amb el gruix i amb el color indicat
void texto(char *text, int posx, int posy, byte gruix, char *color) {
  tft.setTextColor(color);
  tft.setTextSize(gruix);
  tft.setCursor(posx, posy);
  tft.print(text);
}

//********** Escriu una variable flotant a la possició, amb el gruix i amb el color indicat
void variableF(float var, int posx, int posy, byte gruix, char *color) {
  tft.setTextColor(color);
  tft.setTextSize(gruix);
  tft.setCursor(posx, posy);
  tft.print(var);
}

//********** Escriu una variable entera a la possició, amb el gruix i amb el color indicat
void variableI(int var, int posx, int posy, byte gruix, char *color) {
  tft.setTextColor(color);
  tft.setTextSize(gruix);
  tft.setCursor(posx, posy);
  tft.print(var);
}

//********** Escriu una variable Byte a la possició, amb el gruix i amb el color indicat
void variableB(byte var, int posx, int posy, byte gruix, char *color) {
  tft.setTextColor(color);
  tft.setTextSize(gruix);
  tft.setCursor(posx, posy);
  tft.print(var);
}

//********** Dibuixa un rectangle a la posició, el tamany, el gruix i el color indicat
void dibuRectag(int posx, int posy, int ancho, int alt, byte gruix, bool argu, char *color) {
  if (argu) { // Repetició per fora del rectangle
    for (int i = 0; i < gruix; i++) {
      tft.drawRect(posx - i, posy - i, ancho + (2 * i), alt + (2 * i), color);
    }
  } else { // Repetició per dins del rectangle
    for (int i = 0; i < gruix; i++) {
      tft.drawRect(posx + i, posy + i, ancho - (2 * i), alt - (2 * i), color);
    }
  }
}

//********** Dibuixa un rectangle a la posició, el tamany, el gruix, el color indicat i amb les cantonades rodones
void dibuRectagRudo(int posx, int posy, int ancho, int alt, byte radi, byte gruix, bool argu, char *color) {
  if (argu) { // Exterior
    for (int i = 0; i < gruix; i++) {
      tft.drawRoundRect(posx - i, posy - i, ancho + (2 * i), alt + (2 * i), radi, color);
    }
  } else { // Interior
    for (int i = 0; i < gruix; i++) {
      tft.drawRoundRect(posx + i, posy + i, ancho - (2 * i), alt - (2 * i), radi, color);
    }
  }
}

//********** Dibuixa un rectangle ple a la posició, el tamany, el gruix, el color indicat i amb les cantonades rodones
void FillRectagRudo(int posx, int posy, int ancho, int alt, byte radi, byte gruix, bool argu, char *color) {
  if (argu) { // Exterior
    for (int i = 0; i < gruix; i++) {
      tft.fillRoundRect(posx - i, posy - i, ancho + (2 * i), alt + (2 * i), radi, color);
    }
  } else { // Interior
    for (int i = 0; i < gruix; i++) {
      tft.fillRoundRect(posx + i, posy + i, ancho - (2 * i), alt - (2 * i), radi, color);
    }
  }
}

//********** Dibuixa un cercle a la posició, el radi, el gruix i el color indicat
void dibuCercle(int posx, int posy, int diam, byte gruix, bool argu, char *color) {
  if (argu) { // Repetició per fora del cercle
    for (int i = 0; i < gruix; i++) {
      tft.drawCircle(posx, posy, (diam / 2) + i, color);
    }
  } else { // Repetició per dins del cercle
    for (int i = 0; i < gruix; i++) {
      tft.drawCircle(posx, posy, (diam / 2) - i, color);
    }
  }
}

//********** Dibuixa línies verticals, horitzontals i inclinades a la posició, gruix, i color indicat
void dibuLinea(int posx, int posy, int fix, int fiy, byte gruix, bool argu, char *color) {
  if (posy == fiy && posx != fix) {   //línies horitzontals
    if (argu) { // per dalt
      for (int i = 0; i < gruix; i++) {
        tft.drawLine(posx, posy - i, fix, fiy - i, color);
      }
    } else { // per baix
      for (int i = 0; i < gruix; i++) {
        tft.drawLine(posx, posy + i, fix, fiy + i, color);
      }
    }
  } else if (posx == fix && posy != fiy) { // línies verticals
    if (argu) { // per davant
      for (int i = 0; i < gruix; i++) {
        tft.drawLine(posx - i, posy, fix - i, fiy, color);
      }
    } else { // per darrere
      for (int i = 0; i < gruix; i++) {
        tft.drawLine(posx + i, posy, fix + i, fiy, color);
      }
    }
  } else if (posx != fix && posy != fiy) { // línies inclinades
    if (argu) { // per sobre
      for (int i = 0; i < gruix; i++) {
        tft.drawLine(posx - i, posy - i, fix - i, fiy - i, color);
      }
    } else { // per baix
      for (int i = 0; i < gruix; i++) {
        tft.drawLine(posx + i, posy + i, fix + i, fiy + i, color);
      }
    }
  }

}

//********** Dibuixa un boto instantani rectangular, a la possició, amplada, gruix de línia, color de línia i color de fons indicats
bool botoInstanRectan(int posx, int posy, int ancho, int alt, byte gruix, char *color_linia, char *color_fons) {
  for (int i = 0; i < gruix; i++) {
    tft.drawRect(posx - i, posy - i, ancho + (2 * i), alt + (2 * i), color_linia);
  }

  //string.length(titol);
  //String msg1 = titol1;
  //String msg2 = titol2;

  if (xpos >= posx && xpos <= (posx + ancho) && ypos >= posy && ypos <= (posy + alt)) {
    tft.fillRect(posx + 1, posy + 1, ancho - 2, alt - 2, WHITE);
    //texto(titol1, posx + (ancho - (msg1.length() * 11))/2, posy + (alt/2) - 7, 2, color_linia);
    return true;
  } else {
    tft.fillRect(posx + 1, posy + 1, ancho - 2, alt - 2, color_fons);
    //texto(titol2, posx + (ancho - (msg2.length() * 11))/2, posy + (alt/2) - 7, 2, color_linia);
    return false;
  }
}

//********** Dibuixa un boto instantani rectangular amb cantunades rodanes, a la possició, amplada, gruix de línia, color de línia i color de fons indicats
bool botoInstanRectanCercle(int posx, int posy, int ancho, int alt, byte gruix, int radi, char *color_linia, char *color_fons) {
  for (int i = 0; i < gruix; i++) {
    tft.drawRoundRect(posx - i, posy - i, ancho + (2 * i), alt + (2 * i), radi, color_linia);
  }
  if (xpos >= posx && xpos <= (posx + ancho) && ypos >= posy && ypos <= (posy + alt) && zpos < 1000) {
    tft.fillRoundRect(posx + 1, posy + 1, ancho - 2, alt - 2, radi, WHITE);
    return true;
  } else {
    tft.fillRoundRect(posx + 1, posy + 1, ancho - 2, alt - 2, radi, color_fons);
    return false;
  }
}

//********** Dibuixa un boto instantani rodo a la possició, diàmetre, gruix de línia, color de línia i color de fons indicats
bool botoInstanCercle(int posx, int posy, byte gruix, int diam, char *color_linia, char *color_fons) {
  for (int i = 0; i < gruix; i++) {
    tft.drawCircle(posx, posy, (diam / 2) + i, color_linia);
  }
  if (xpos >= (posx - (diam / 2)) && xpos <= (posx + (diam / 2)) && ypos >= (posy - (diam / 2)) && ypos <= (posy + (diam / 2)) && zpos < 1000) {
    tft.fillCircle(posx, posy, (diam / 2) - 1, WHITE);
    return true;
  } else {
    tft.fillCircle(posx, posy, (diam / 2) - 1, color_fons);
    return false;
  }
}

//********** Dibuja una barra de dades horitzontal
byte cursorSliderH(int posx, int posy, int ancho, int alt, byte  gruix, int radi, char *color_linia, char *color_fons, char *color_cursor) {
  static byte sliderH;
  static int posicioHx;
  static int posicioHy;
  static bool marca_iniciH = false;

  dibuRectagRudo(posx, posy, ancho, alt, radi, gruix, true, color_linia);

  //&& zpos != 0 && zpos < 1000

  if (xpos >= (posx - 10) && xpos <= ((posx + ancho) - alt + 10) && ypos >= (posy - 5) && ypos <= (posy + alt + 5) || !marca_iniciH) {
    if (!marca_iniciH) xpos = posicioHx;
    tft.fillRoundRect(posx + 1, posy + 1, ancho - 2, alt - 2, radi, color_fons);
    if (xpos < posx) xpos = posx;
    if (xpos > (posx + ancho) - alt) xpos = (posx + ancho) - alt;
    tft.fillCircle(xpos + (alt / 2), posy + (alt / 2), (alt / 2) - 1, color_cursor);
    marca_iniciH = true;
    posicioHx = xpos;
    posicioHy = ypos;

    byte porcent = map(posicioHx, posx, (posx + ancho) - alt, 0, 100);
    tft.fillRoundRect((posx + ancho + 4), posy, 50, alt, radi, BLACK);
    variableB(porcent, (posx + ancho + 5), posy + (alt / 2) - 6, 2, WHITE);
    tft.print("%");
  }
  sliderH = map(posicioHx, posx, (posx + ancho) - alt, 0, 255);
  return sliderH;
}

//********** Dibuixa una barra de dades vertical
byte cursorSliderV(int posx, int posy, int ancho, int alt, byte  gruix, int radi, char *color_linia, char *color_fons, char *color_cursor) {
  static byte sliderV;
  static int posicioVx;
  static int posicioVy;
  static bool marca_iniciV = false;

  dibuRectagRudo(posx, posy, ancho, alt, radi, gruix, true, color_linia);

  if (ypos >= (posy - 10) && ypos <= ((posy + alt) - ancho + 10) && xpos >= (posx - 5) && xpos <= (posx + ancho + 5) && zpos != 0 && zpos < 1000 || !marca_iniciV) {
    if (!marca_iniciV) ypos = posicioVy;
    tft.fillRoundRect(posx + 1, posy + 1, ancho - 2, alt - 2, radi, color_fons);
    if (ypos < posy) ypos = posy;
    if (ypos > (posy + alt) - ancho) ypos = (posy + alt) - ancho;
    tft.fillCircle(posx + (ancho / 2), ypos + (ancho / 2), (ancho / 2) - 1, color_cursor);
    //tft.fillCircle(posx, posy, 15, color_cursor);
    marca_iniciV = true;
    posicioVx = xpos;
    posicioVy = ypos;

    byte porcent = map(posicioVy, posy, (posy + alt) - ancho, 100, 0);
    tft.fillRoundRect((posx - 4), posy - 32, 48, ancho, radi, BLACK);
    variableB(porcent, (posx - 3), posy - 25, 2, WHITE);
    tft.print("%");
  }
  sliderV = map(posicioVy, posy, (posy + alt) - ancho, 255, 0);
  return sliderV;
}
/*Serial.print(posiciox);
  Serial.print("\t");
  //Serial.print(posicioy);
  //Serial.print("\t");
  Serial.println(slider);*/

//********** Barra indicadora vertical per Omplir
void barraIndicaV_O(int valor, int posx, int posy, int ancho, int alt, byte radi, char *color_linia) {
  int z_roja, z_ambar, z_verde;
  int valor_max = 255;
  int adj, adj_v, adj_a, adj_r;
  int adj_fons;

  z_roja = ((alt * 10) / 100);
  z_ambar = ((alt * 40) / 100) - z_roja;
  z_verde = alt - z_roja - z_ambar;

  adj = map(valor, 0, valor_max, alt, 0);
  adj_v = adj; adj_a = adj; adj_r = adj; adj_fons = adj;

  dibuRectagRudo(posx, posy, ancho, alt, radi, 3, true, color_linia);
  if (adj == alt) adj_fons = adj - 2;
  if (adj == 0) adj_fons = adj;
  tft.fillRect(posx + 1, posy + 1, ancho - 2, (adj_fons), BLACK);

  if (adj_v <= alt - z_verde) adj_v = alt - z_verde + 2;
  tft.fillRect(posx + 1, posy + alt - 1, ancho - 2, adj_v - alt, GREEN);

  if (adj_a > alt - z_verde) adj_a = alt - z_verde;
  if (adj_a <= alt - (z_verde + z_ambar)) adj_a = alt - (z_verde + z_ambar);
  tft.fillRect(posx + 1, posy + z_roja + z_ambar + 2, ancho - 2, adj_a - (alt - z_verde), ORANGE);

  if (adj_r > alt - (z_verde + z_ambar)) adj_r = alt - (z_verde + z_ambar) + 2;
  tft.fillRect(posx + 1, posy + z_roja + 3, ancho - 2, adj_r - (alt - (z_verde + z_ambar)) - 2, RED);

  byte porcent = map(adj, alt, 0, 0, 100);
  tft.fillRoundRect(posx - 3, posy - 25, 25, ancho, radi, BLUE);
  variableB(porcent, (posx - 2), posy - 19, 1, WHITE);
  tft.print("%");
}

//********** Barra indicadora vertical per Buidar
void barraIndicaV_B(int valor, int posx, int posy, int ancho, int alt, byte radi, char *color_linia) {
  int z_roja, z_ambar, z_verde;
  int valor_max = 255;
  int adj, adj_v, adj_a, adj_r;
  int adj_fons;

  z_verde = ((alt * 10) / 100);
  z_ambar = ((alt * 40) / 100) - z_verde;
  z_roja = alt - z_verde - z_ambar;

  adj = map(valor, 0, valor_max, alt, 0);
  adj_v = adj; adj_a = adj; adj_r = adj; adj_fons = adj;

  dibuRectagRudo(posx, posy, ancho, alt, radi, 3, true, color_linia);
  if (adj == alt) adj_fons = adj - 2;
  if (adj == 0) adj_fons = adj;
  tft.fillRect(posx + 1, posy + 1, ancho - 2, (adj_fons), BLACK);

  if (adj_v <= alt - z_verde) adj_v = alt - z_verde + 2;
  tft.fillRect(posx + 1, posy + alt - 1, ancho - 2, adj_v - alt, RED);

  if (adj_a > alt - z_verde) adj_a = alt - z_verde;
  if (adj_a <= alt - (z_verde + z_ambar)) adj_a = alt - (z_verde + z_ambar);
  tft.fillRect(posx + 1, posy + z_roja + z_ambar + 2, ancho - 2, adj_a - (alt - z_verde), ORANGE);

  if (adj_r > alt - (z_verde + z_ambar)) adj_r = alt - (z_verde + z_ambar) + 2;
  tft.fillRect(posx + 1, posy + z_roja + 3, ancho - 2, adj_r - (alt - (z_verde + z_ambar)) - 2, GREEN);

  byte porcent = map(adj, alt, 0, 100, 0);
  tft.fillRoundRect(posx - 3, posy - 25, 25, ancho, radi, BLUE);
  variableB(porcent, (posx - 2), posy - 19, 1, WHITE);
  tft.print("%");
}

//********** Led Vermell petit
void ledVermellPetit(bool estat, int posx, int posy) {
  for (int i = 0; i < 2; i++) {
    tft.drawCircle(posx, posy, 8 + i, RED);
  }
  if (estat) {
    tft.fillCircle(posx, posy, 7, RED);
  } else {
    tft.fillCircle(posx, posy, 7, BLACK);
  }
}

//********** Led Verd petit
void ledVerdPetit(bool estat, int posx, int posy) {
  for (int i = 0; i < 2; i++) {
    tft.drawCircle(posx, posy, 8 + i, GREEN);
  }
  if (estat) {
    tft.fillCircle(posx, posy, 7, GREEN);
  } else {
    tft.fillCircle(posx, posy, 7, BLACK);
  }
}

//********** Led ambar petit
void ledTarongePetit(bool estat, int posx, int posy) {
  for (int i = 0; i < 2; i++) {
    tft.drawCircle(posx, posy, 8 + i, ORANGE);
  }
  if (estat) {
    tft.fillCircle(posx, posy, 7, ORANGE);
  } else {
    tft.fillCircle(posx, posy, 7, BLACK);
  }
}

//********** Led Blau petit
void ledBlauPetit(bool estat, int posx, int posy) {
  for (int i = 0; i < 2; i++) {
    tft.drawCircle(posx, posy, 8 + i, BLUE);
  }
  if (estat) {
    tft.fillCircle(posx, posy, 7, BLUE);
  } else {
    tft.fillCircle(posx, posy, 7, BLACK);
  }
}

//********** Led Vermell gran
void ledVermellGran(bool estat, int posx, int posy) {
  for (int i = 0; i < 2; i++) {
    tft.drawCircle(posx, posy, 12 + i, RED);
  }
  if (estat) {
    tft.fillCircle(posx, posy, 11, RED);
  } else {
    tft.fillCircle(posx, posy, 11, BLACK);
  }
}

//********** Led Verd gran
void ledVerdGran(bool estat, int posx, int posy) {
  for (int i = 0; i < 2; i++) {
    tft.drawCircle(posx, posy, 12 + i, GREEN);
  }
  if (estat) {
    tft.fillCircle(posx, posy, 11, GREEN);
  } else {
    tft.fillCircle(posx, posy, 11, BLACK);
  }
}

//********** Led ambar gran
void ledTarongeGran(bool estat, int posx, int posy) {
  for (int i = 0; i < 2; i++) {
    tft.drawCircle(posx, posy, 12 + i, ORANGE);
  }
  if (estat) {
    tft.fillCircle(posx, posy, 11, ORANGE);
  } else {
    tft.fillCircle(posx, posy, 11, BLACK);
  }
}

//********** Led Blau gran
void ledBlauGran(bool estat, int posx, int posy) {
  for (int i = 0; i < 2; i++) {
    tft.drawCircle(posx, posy, 12 + i, BLUE);
  }
  if (estat) {
    tft.fillCircle(posx, posy, 11, BLUE);
  } else {
    tft.fillCircle(posx, posy, 11, BLACK);
  }
}

//*********** Display 7 segments
void display7Seg(byte num, int posx, int posy, byte tamany, char *color_led, char *color_linia, bool dp) {

  int gruix;
  int llarg;

  switch (tamany) {
    case 0:
      gruix = 1;
      llarg = 7;
      break;
    case 1:
      gruix = 2;
      llarg = 15;
      break;
    case 2:
      gruix = 5;
      llarg = 30;
      break;
    default:
      gruix = 5;
      llarg = 30;
      break;
  }
  if (color_linia != "nulo") {
    tft.drawRoundRect(posx - 4, posy - 4, (3 * gruix) + llarg + 14, (7 * gruix) + (2 * llarg) + 8, 4, color_linia);
  }
  if (dp) {
    tft.fillCircle(posx + llarg + gruix + 8, posy + (5 * gruix) + (2 * llarg), gruix, color_led);
  } else {
    tft.fillCircle(posx + llarg + gruix + 8, posy + (5 * gruix) + (2 * llarg), gruix, BLACK);
  }

  switch (num) {
    case 0:
      tft.fillRect(posx + gruix, posy, llarg, gruix, color_led);//a
      tft.fillRect(posx + llarg + gruix, posy + (2 * gruix), gruix, llarg, color_led); //b
      tft.fillRect(posx + llarg + gruix, posy + (5 * gruix) + llarg, gruix, llarg, color_led); //c
      tft.fillRect(posx + gruix, posy + (6 * gruix) + (2 * llarg), llarg, gruix, color_led); //d
      tft.fillRect(posx, posy + (5 * gruix) + llarg, gruix, llarg, color_led); //e
      tft.fillRect(posx, posy + (2 * gruix), gruix, llarg, color_led); //f
      tft.fillRect(posx + gruix, posy + (3 * gruix) + llarg, llarg, gruix, BLACK); //g
      break;
    case 1:
      tft.fillRect(posx + gruix, posy, llarg, gruix, BLACK);//a
      tft.fillRect(posx + llarg + gruix, posy + (2 * gruix), gruix, llarg, color_led); //b
      tft.fillRect(posx + llarg + gruix, posy + (5 * gruix) + llarg, gruix, llarg, color_led); //c
      tft.fillRect(posx + gruix, posy + (6 * gruix) + (2 * llarg), llarg, gruix, BLACK); //d
      tft.fillRect(posx, posy + (5 * gruix) + llarg, gruix, llarg, BLACK); //e
      tft.fillRect(posx, posy + (2 * gruix), gruix, llarg, BLACK); //f
      tft.fillRect(posx + gruix, posy + (3 * gruix) + llarg, llarg, gruix, BLACK); //g
      break;
    case 2:
      tft.fillRect(posx + gruix, posy, llarg, gruix, color_led);//a
      tft.fillRect(posx + llarg + gruix, posy + (2 * gruix), gruix, llarg, color_led); //b
      tft.fillRect(posx + llarg + gruix, posy + (5 * gruix) + llarg, gruix, llarg, BLACK); //c
      tft.fillRect(posx + gruix, posy + (6 * gruix) + (2 * llarg), llarg, gruix, color_led); //d
      tft.fillRect(posx, posy + (5 * gruix) + llarg, gruix, llarg, color_led); //e
      tft.fillRect(posx, posy + (2 * gruix), gruix, llarg, BLACK); //f
      tft.fillRect(posx + gruix, posy + (3 * gruix) + llarg, llarg, gruix, color_led); //g
      break;
    case 3:
      tft.fillRect(posx + gruix, posy, llarg, gruix, color_led);//a
      tft.fillRect(posx + llarg + gruix, posy + (2 * gruix), gruix, llarg, color_led); //b
      tft.fillRect(posx + llarg + gruix, posy + (5 * gruix) + llarg, gruix, llarg, color_led); //c
      tft.fillRect(posx + gruix, posy + (6 * gruix) + (2 * llarg), llarg, gruix, color_led); //d
      tft.fillRect(posx, posy + (5 * gruix) + llarg, gruix, llarg, BLACK); //e
      tft.fillRect(posx, posy + (2 * gruix), gruix, llarg, BLACK); //f
      tft.fillRect(posx + gruix, posy + (3 * gruix) + llarg, llarg, gruix, color_led); //g
      break;
    case 4:
      tft.fillRect(posx + gruix, posy, llarg, gruix, BLACK);//a
      tft.fillRect(posx + llarg + gruix, posy + (2 * gruix), gruix, llarg, color_led); //b
      tft.fillRect(posx + llarg + gruix, posy + (5 * gruix) + llarg, gruix, llarg, color_led); //c
      tft.fillRect(posx + gruix, posy + (6 * gruix) + (2 * llarg), llarg, gruix, BLACK); //d
      tft.fillRect(posx, posy + (5 * gruix) + llarg, gruix, llarg, BLACK); //e
      tft.fillRect(posx, posy + (2 * gruix), gruix, llarg, color_led); //f
      tft.fillRect(posx + gruix, posy + (3 * gruix) + llarg, llarg, gruix, color_led); //g
      break;
    case 5:
      tft.fillRect(posx + gruix, posy, llarg, gruix, color_led);//a
      tft.fillRect(posx + llarg + gruix, posy + (2 * gruix), gruix, llarg, BLACK); //b
      tft.fillRect(posx + llarg + gruix, posy + (5 * gruix) + llarg, gruix, llarg, color_led); //c
      tft.fillRect(posx + gruix, posy + (6 * gruix) + (2 * llarg), llarg, gruix, color_led); //d
      tft.fillRect(posx, posy + (5 * gruix) + llarg, gruix, llarg, BLACK); //e
      tft.fillRect(posx, posy + (2 * gruix), gruix, llarg, color_led); //f
      tft.fillRect(posx + gruix, posy + (3 * gruix) + llarg, llarg, gruix, color_led); //g
      break;
    case 6:
      tft.fillRect(posx + gruix, posy, llarg, gruix, color_led);//a
      tft.fillRect(posx + llarg + gruix, posy + (2 * gruix), gruix, llarg, BLACK); //b
      tft.fillRect(posx + llarg + gruix, posy + (5 * gruix) + llarg, gruix, llarg, color_led); //c
      tft.fillRect(posx + gruix, posy + (6 * gruix) + (2 * llarg), llarg, gruix, color_led); //d
      tft.fillRect(posx, posy + (5 * gruix) + llarg, gruix, llarg, color_led); //e
      tft.fillRect(posx, posy + (2 * gruix), gruix, llarg, color_led); //f
      tft.fillRect(posx + gruix, posy + (3 * gruix) + llarg, llarg, gruix, color_led); //g
      break;
    case 7:
      tft.fillRect(posx + gruix, posy, llarg, gruix, color_led);//a
      tft.fillRect(posx + llarg + gruix, posy + (2 * gruix), gruix, llarg, color_led); //b
      tft.fillRect(posx + llarg + gruix, posy + (5 * gruix) + llarg, gruix, llarg, color_led); //c
      tft.fillRect(posx + gruix, posy + (6 * gruix) + (2 * llarg), llarg, gruix, BLACK); //d
      tft.fillRect(posx, posy + (5 * gruix) + llarg, gruix, llarg, BLACK); //e
      tft.fillRect(posx, posy + (2 * gruix), gruix, llarg, color_led); //f
      tft.fillRect(posx + gruix, posy + (3 * gruix) + llarg, llarg, gruix, BLACK); //g
      break;
    case 8:
      tft.fillRect(posx + gruix, posy, llarg, gruix, color_led);//a
      tft.fillRect(posx + llarg + gruix, posy + (2 * gruix), gruix, llarg, color_led); //b
      tft.fillRect(posx + llarg + gruix, posy + (5 * gruix) + llarg, gruix, llarg, color_led); //c
      tft.fillRect(posx + gruix, posy + (6 * gruix) + (2 * llarg), llarg, gruix, color_led); //d
      tft.fillRect(posx, posy + (5 * gruix) + llarg, gruix, llarg, color_led); //e
      tft.fillRect(posx, posy + (2 * gruix), gruix, llarg, color_led); //f
      tft.fillRect(posx + gruix, posy + (3 * gruix) + llarg, llarg, gruix, color_led); //g
      break;
    case 9:
      tft.fillRect(posx + gruix, posy, llarg, gruix, color_led);//a
      tft.fillRect(posx + llarg + gruix, posy + (2 * gruix), gruix, llarg, color_led); //b
      tft.fillRect(posx + llarg + gruix, posy + (5 * gruix) + llarg, gruix, llarg, color_led); //c
      tft.fillRect(posx + gruix, posy + (6 * gruix) + (2 * llarg), llarg, gruix, color_led); //d
      tft.fillRect(posx, posy + (5 * gruix) + llarg, gruix, llarg, BLACK); //e
      tft.fillRect(posx, posy + (2 * gruix), gruix, llarg, color_led); //f
      tft.fillRect(posx + gruix, posy + (3 * gruix) + llarg, llarg, gruix, color_led); //g
      break;
  }
}

//********** Interruptor horitzontal
bool interruptorH(int posx, int posy, int ancho, int alt, char *color_linia, char *color) {

  static bool act = true;
  static bool marca_inici = false;

  bool pulsacio = (ypos >= (posy - 10) && ypos <= (posy + alt - 15) && xpos >= (posx - 2) && xpos <= (posx + ancho));

  for (int i = 0; i < 4; i++) {
    tft.drawRoundRect(posx - i, posy - i, ancho + (2 * i), alt + (2 * i), 5, color_linia);
  }
  if (pulsacio && !act) {
    tft.fillRoundRect(posx + 1 + ((ancho / 2) - 1), posy + 1, (ancho / 2) - 1, alt - 2, 5, color);
    tft.fillRoundRect(posx + 1, posy + 1, ancho / 2 - 1, alt - 2, 5, BLACK);
    act = true;
    while (pulsacio) {
      lecturaPanel();
      pulsacio = (ypos >= (posy - 10) && ypos <= (posy + alt - 15) && xpos >= (posx - 2) && xpos <= (posx + ancho));
    }
  } else if (pulsacio && act || !marca_inici) {
    tft.fillRoundRect(posx + 1, posy + 1, ancho / 2 - 1, alt - 2, 5, color);
    tft.fillRoundRect(posx + 1 + ((ancho / 2) - 1), posy + 1, (ancho / 2) - 1, alt - 2, 5, BLACK);
    act = false;
    marca_inici = true;
    while (pulsacio) {
      lecturaPanel();
      pulsacio = (ypos >= (posy - 10) && ypos <= (posy + alt - 15) && xpos >= (posx - 2) && xpos <= (posx + ancho));
    }
  }
  return act;
}

//********** Interruptor vertical
bool interruptorV(int posx, int posy, int ancho, int alt, char *color_linia, char *color) {

  static bool act = true;
  static bool marca_inici = false;

  bool pulsacio = (ypos >= (posy - 10) && ypos <= (posy + alt - 15) && xpos >= (posx - 2) && xpos <= (posx + ancho));

  for (int i = 0; i < 4; i++) {
    tft.drawRoundRect(posx - i, posy - i, ancho + (2 * i), alt + (2 * i), 5, color_linia);
  }
  if (pulsacio && !act) {
    tft.fillRoundRect(posx + 1, posy + (alt / 2) + 1, ancho - 2, (alt / 2) - 2, 5, color);
    tft.fillRoundRect(posx + 1, posy + 1, ancho - 2, (alt / 2) - 2, 5, BLACK);
    act = true;
    while (pulsacio) {
      lecturaPanel();
      pulsacio = (ypos >= (posy - 10) && ypos <= (posy + alt - 15) && xpos >= (posx - 2) && xpos <= (posx + ancho));
    }
  } else if (pulsacio && act || !marca_inici) {
    tft.fillRoundRect(posx + 1, posy + 1, ancho - 2, (alt / 2) - 2, 5, color);
    tft.fillRoundRect(posx + 1, posy + (alt / 2) + 1, ancho - 2, (alt / 2) - 2, 5, BLACK);
    act = false;
    marca_inici = true;
    while (pulsacio) {
      lecturaPanel();
      pulsacio = (ypos >= (posy - 10) && ypos <= (posy + alt - 15) && xpos >= (posx - 2) && xpos <= (posx + ancho));
    }
  }
  return act;
}

//********** selecció de nombres float
float num_inputF(float num, int posx, int posy, byte gruix, char *color_text, char *color_linia, float lim_inf, float lim_sup, float pas) {

  //float  num = valor_inici;
  byte tmany_pul = 30;
  int x = posx + (6 * gruix * 5) + gruix;
  int y = posy + (8 * gruix / 2) - 29 - gruix;

  if (num < lim_inf) num = lim_sup;
  if (num > lim_sup) num = lim_inf;

  dibuRectag(posx - gruix, y - gruix, (6 * gruix * 5) + tmany_pul + (3 * gruix), (tmany_pul * 2) + (gruix * 2), 4, true, color_linia);

  if (botoInstanRectan(x, y, tmany_pul, tmany_pul, 2, YELLOW, BLUE)) {
    num = num + pas;
    if (num > lim_sup) num = lim_inf;
    FillRectagRudo(posx, posy, 6 * gruix * 5, (8 * gruix) - gruix, gruix * 2, gruix, true, BLACK);
  }
  if (botoInstanRectan(x, y + tmany_pul, tmany_pul, tmany_pul, 2, YELLOW, BLUE)) {
    num = num - pas;
    if (num < lim_inf) num = lim_sup;
    FillRectagRudo(posx, posy, 6 * gruix * 5, (8 * gruix) - gruix, gruix * 2, gruix, true, BLACK);
  }

  variableF(num, posx, posy, gruix, color_text);

  return num;
}

int num_inputI(int num, int posx, int posy, byte gruix, char *color_text, char *color_linia, int lim_inf, int lim_sup, int pas) {

  byte tmany_pul = 30;
  int x = posx + (6 * gruix * 5) + gruix;
  int y = posy + (8 * gruix / 2) - 29 - gruix;

  //if (num <= lim_inf) num = lim_sup;
  //if (num >= lim_sup) num = lim_inf;

  dibuRectag(posx - gruix, y - gruix, (6 * gruix * 5) + tmany_pul + (3 * gruix), (tmany_pul * 2) + (gruix * 2), 4, true, color_linia);

  if (botoInstanRectan(x, y, tmany_pul, tmany_pul, 2, YELLOW, BLUE)) {
    num = num + pas;
    if (num > lim_sup) num = lim_inf;
    FillRectagRudo(posx, posy, 6 * gruix * 5, (8 * gruix) - gruix, gruix * 2, gruix, true, BLACK);
  }
  if (botoInstanRectan(x, y + tmany_pul, tmany_pul, tmany_pul, 2, YELLOW, BLUE)) {
    num = num - pas;
    if (num < lim_inf) num = lim_sup;
    FillRectagRudo(posx, posy, 6 * gruix * 5, (8 * gruix) - gruix, gruix * 2, gruix, true, BLACK);
  }

  //FillRectagRudo(posx, posy, 6 * gruix * 5, (8 * gruix) - gruix, gruix * 2, gruix, true, BLACK);
  variableI(num, posx + 20, posy, gruix, color_text);

  return num;
}



















