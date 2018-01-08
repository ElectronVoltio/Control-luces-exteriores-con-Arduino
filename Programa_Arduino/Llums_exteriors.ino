#include "Adafruit_GFX.h"
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>
#include <EEPROM.h>
#include <Wire.h>
#include "RTClib.h"

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

int YP = A1;
int XM = A2;
int YM = 7;
int XP = 6;

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

#define TS_LEFT 115
#define TS_BOT 140
#define TS_RT 900
#define TS_TOP 900

// Assignació de colors legibles
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
//#define ORANGE 0xC360
#define ORANGE  tft.color565(255, 147, 0)
#define VERD    tft.color565(22, 82, 0)
#define VIOLETA tft.color565(120,0,120)
#define ROSA    tft.color565(238, 0, 216)
#define BLAU    tft.color565(0, 230, 238)
#define VIOLET  tft.color565(93, 0, 100)

RTC_DS1307 rtc;
MCUFRIEND_kbv tft;

int xpos, ypos, zpos;

int minuts, hores, dies, mesos, anys;
int minuts_inicial, hora_inicial, dies_inicial, mesos_inicial, anys_inicial;
bool canvi_rellotge = false;

int pagina = 1, mode = 1, parametres = 1;
int mode_vell;
bool marca_inicial = false;
bool primera_vegada = true;

long segons_ara;
int hora_E1, minuts_E1, hora_E2, minuts_E2, hora_E3, minuts_E3, hora_E4, minuts_E4, hora_E5, minuts_E5, hora_E6, minuts_E6;
int hora_E1_inicial, minuts_E1_inicial, hora_E2_inicial, minuts_E2_inicial;
int hora_E3_inicial, minuts_E3_inicial, hora_E4_inicial, minuts_E4_inicial;
int hora_E5_inicial, minuts_E5_inicial, hora_E6_inicial, minuts_E6_inicial;
long segons_E1, segons_E2, segons_E3, segons_E4, segons_E5, segons_E6;
bool act_E1 = false, act_E2 = false;
bool act_E3 = false, act_E4 = false;
bool act_E5 = false, act_E6 = false;

unsigned long tempo1 = millis();
unsigned long tempo2 = millis();
bool marca_Sensor;

const int Linea_1 = 22;
const int Linea_2 = 24;
const int Sensor_D = 53;

bool marca_l1 = true;
bool marca_l2 = true;

char estat;
int estado;

void setup(void) {

  Serial.begin(115200);
  Serial1.begin(115200);

  uint16_t ID = tft.readID();
  //Serial.print("ID = 0x");
  //Serial.println(ID, HEX);

  if (! rtc.begin()) {
    Serial.println("No trobo el DS1307");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("El DS1307 NO funciona!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    //rtc.adjust(DateTime(2017, 12, 22, 3, 0, 0));
  }

  tft.begin(ID);
  tft.setRotation(1);
  //tft.fillScreen(BLACK);
  pan_inici();

  pinMode(Linea_1, OUTPUT);
  pinMode(Linea_2, OUTPUT);
  pinMode(Sensor_D, INPUT);
  digitalWrite(Linea_1, HIGH);
  digitalWrite(Linea_2, HIGH);

  /*EEPROM.put(0, 1);
    EEPROM.put(10, 1);
    EEPROM.put(12, 1);
    EEPROM.put(14, 1);
    EEPROM.put(16, 1);
    EEPROM.put(18, 1);
    EEPROM.put(20, 1);
    EEPROM.put(22, 1);
    EEPROM.put(24, 1);
    EEPROM.put(26, 1);
    EEPROM.put(28, 1);
    EEPROM.put(30, 1);
    EEPROM.put(32, 1);*/
  EEPROM.get(0, mode);
  EEPROM.get(10, hora_E1);
  EEPROM.get(12, minuts_E1);
  EEPROM.get(14, hora_E2);
  EEPROM.get(16, minuts_E2);
  EEPROM.get(18, hora_E3);
  EEPROM.get(20, minuts_E3);
  EEPROM.get(22, hora_E4);
  EEPROM.get(24, minuts_E4);
  EEPROM.get(26, hora_E5);
  EEPROM.get(28, minuts_E5);
  EEPROM.get(30, hora_E6);
  EEPROM.get(32, minuts_E6);
  delay(5);

  if (mode == 1) {
    marca_inicial = false;
    Serial1.println(1);
  } else {
    marca_inicial = true;
    Serial1.println(2);
  }
  dadesPerLolin();
  mode_vell = mode;
}

void pan_inici() {
  tft.fillScreen(BLUE);
  tft.fillScreen(MAGENTA);
  tft.fillScreen(YELLOW);
  tft.fillScreen(RED);
  tft.fillScreen(BLACK);
  texto("BENVINGUTS!!!", 50, 110, 3, GREEN);
  delay(2000);
  tft.fillScreen(BLACK);
}

void lecturaPanel() {

  TSPoint tp = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  pinMode(XP, OUTPUT);
  pinMode(YM, OUTPUT);

  xpos = map(tp.y, TS_LEFT, TS_RT, 0, tft.width());
  ypos = map(tp.x, TS_TOP, TS_BOT, 0, tft.height());
  zpos = tp.z;

  //Serial.print(xpos);
  //Serial.print("\t");
  //Serial.println(ypos);
  //Serial.print("\t");
  //Serial.println(zpos);
  //Serial.print("\t");
  //Serial.println(tp.y);

}

void loop(void) {

  DateTime now = rtc.now();
  lecturaPanel();
  RTC_DS ();
  dades_Lolin();

  switch (pagina) {
    case 1: // Pantalla principal
      texto("Llums Exteriors", 25, 5, 3, YELLOW);
      dibuLinea(0, 33, 350, 33, 3, true, VIOLETA);


      if (botoInstanRectanCercle(80, 50, 60, 25, 3, 5, BLUE, YELLOW) && !marca_inicial) { // Mode Activat
        mode = 2; // Activat
        marca_inicial = true;
        digitalWrite(Linea_1, HIGH);
        digitalWrite(Linea_2, HIGH);
        marca_l1 = true;
        marca_l2 = true;
        Serial1.println(2);
        dadesPerLolin();
        while ((xpos > 80 && xpos < 140) && (ypos > 70 && ypos < 95)) {
          lecturaPanel();// Anti-repetició
        }
      } else if (botoInstanRectanCercle(80, 50, 60, 25, 3, 5, BLUE, YELLOW) && marca_inicial) { // Mode Manual
        mode = 1; // Manual
        marca_inicial = false;
        digitalWrite(Linea_1, HIGH);
        digitalWrite(Linea_2, HIGH);
        marca_l1 = true;
        marca_l2 = true;
        Serial1.println(1);
        dadesPerLolin();
        while ((xpos > 80 && xpos < 140) && (ypos > 70 && ypos < 95)) {
          lecturaPanel();// Anti-repetició
        }
      }

      if (mode == 2) {
        if (mode_vell != mode || primera_vegada) {

          int m_E1 = 0, h_E1 = 0, m_E2 = 0, h_E2 = 0;
          int m_E3 = 0, h_E3 = 0, m_E4 = 0, h_E4 = 0;
          int m_E5 = 0, h_E5 = 0, m_E6 = 0, h_E6 = 0;

          FillRectagRudo(179, 50, 85, 25, 5,  2, true, BLUE);
          FillRectagRudo(65, 158, 90, 47, 5,  2, true, BLACK);
          FillRectagRudo(175, 158, 90, 47, 5,  2, true, BLACK);

          texto("L1_1 ON", 70, 160, 1, BLUE);
          if (hora_E1 < 10) {
            texto("0", 120, 160, 1, WHITE);
            h_E1 = 6;
          }
          variableI(hora_E1, 120 + h_E1, 160, 1, WHITE);
          texto(":", 130, 160, 1, WHITE);
          if (minuts_E1 < 10) {
            texto("0", 135, 160, 1, WHITE);
            m_E1 = 6;
          }
          variableI(minuts_E1, 135 + m_E1, 160, 1, WHITE);

          texto("L1_1 OFF", 70, 170, 1, BLAU);
          if (hora_E2 < 10) {
            texto("0", 120, 170, 1, WHITE);
            h_E2 = 6;
          }
          variableI(hora_E2, 120 + h_E2, 170, 1, WHITE);
          texto(":", 130, 170, 1, WHITE);
          if (minuts_E2 < 10) {
            texto("0", 135, 170, 1, WHITE);
            m_E2 = 6;
          }
          variableI(minuts_E2, 135 + m_E2, 170, 1, WHITE);

          texto("L1_2 ON", 70, 185, 1, VERD);
          if (hora_E3 < 10) {
            texto("0", 120, 185, 1, WHITE);
            h_E3 = 6;
          }
          variableI(hora_E3, 120 + h_E3, 185, 1, WHITE);
          texto(":", 130, 185, 1, WHITE);
          if (minuts_E3 < 10) {
            texto("0", 135, 185, 1, WHITE);
            m_E3 = 6;
          }
          variableI(minuts_E3, 135 + m_E3, 185, 1, WHITE);

          texto("L1_2 OFF", 70, 195, 1, GREEN);
          if (hora_E4 < 10) {
            texto("0", 120, 195, 1, WHITE);
            h_E4 = 6;
          }
          variableI(hora_E4, 120 + h_E4, 195, 1, WHITE);
          texto(":", 130, 195, 1, WHITE);
          if (minuts_E4 < 10) {
            texto("0", 135, 195, 1, WHITE);
            m_E4 = 6;
          }
          variableI(minuts_E4, 135 + m_E4, 195, 1, WHITE);

          texto("L2 ON", 180, 160, 1, VIOLET);
          if (hora_E5 < 10) {
            texto("0", 230, 160, 1, WHITE);
            h_E5 = 6;
          }
          variableI(hora_E5, 230 + h_E5, 160, 1, WHITE);
          texto(":", 240, 160, 1, WHITE);
          if (minuts_E5 < 10) {
            texto("0", 245, 160, 1, WHITE);
            m_E5 = 6;
          }
          variableI(minuts_E5, 245 + m_E5, 160, 1, WHITE);

          texto("L2 OFF", 180, 190, 1, ROSA);
          if (hora_E6 < 10) {
            texto("0", 230, 190, 1, WHITE);
            h_E6 = 6;
          }
          variableI(hora_E6, 230 + h_E6, 190, 1, WHITE);
          texto(":", 240, 190, 1, WHITE);
          if (minuts_E6 < 10) {
            texto("0", 245, 190, 1, WHITE);
            m_E6 = 6;
          }
          variableI(minuts_E6, 245 + m_E6, 190, 1, WHITE);

          mode_vell = mode;
          primera_vegada = false;
        }
        texto("Activat", 180, 54, 2, YELLOW);
        dibuRectagRudo(60, 85, 100, 125, 10, 3, true, WHITE);
        texto("Linia 1", 70, 90, 2, YELLOW);
        dibuRectagRudo(170, 85, 100, 125, 10, 3, true, WHITE);
        texto("Linia 2", 180, 90, 2, YELLOW);
      } else {
        if (mode_vell != mode || primera_vegada) {
          FillRectagRudo(179, 50, 85, 25, 5,  2, true, BLUE);
          FillRectagRudo(65, 158, 90, 47, 5,  2, true, BLACK);
          FillRectagRudo(175, 158, 90, 47, 5,  2, true, BLACK);
          mode_vell = mode;
          primera_vegada = false;
        }
        texto("Manual", 180 + 7, 54, 2, MAGENTA);

        if (botoInstanRectanCercle(90, 160, 40, 40, 3, 5, BLUE, VIOLETA) && !marca_l1) {            // Apagar el Led 1 en manual
          Evento2_l1_off();
          while ((xpos > 90 && xpos < 130) && (ypos > 160 && ypos < 200)) {
            lecturaPanel();// Anti-repetició
          }
        } else if (botoInstanRectanCercle(90, 160, 40, 40, 3, 5, BLUE, VIOLETA) && marca_l1) {      // Encendre el Led 1 en manual
          Evento1_l1_on();
          while ((xpos > 90 && xpos < 130) && (ypos > 160 && ypos < 200)) {
            lecturaPanel();// Anti-repetició
          }
        }

        if (botoInstanRectanCercle(200, 160, 40, 40, 3, 5, BLUE, VIOLETA) && !marca_l2) {           // Apagar el Led 2 en manual
          Evento2_l2_off();
          while ((xpos > 200 && xpos < 240) && (ypos > 160 && ypos < 200)) {
            lecturaPanel();// Anti-repetició
          }
        } else if (botoInstanRectanCercle(200, 160, 40, 40, 3, 5, BLUE, VIOLETA) && marca_l2) {     // Encendre el Led 2 en manual
          Evento1_l2_on();
          while ((xpos > 200 && xpos < 240) && (ypos > 160 && ypos < 200)) {
            lecturaPanel();// Anti-repetició
          }
        }
        dibuRectagRudo(60, 85, 100, 125, 10, 3, true, WHITE);
        texto("Linia 1", 70, 90, 2, VIOLETA);
        dibuRectagRudo(170, 85, 100, 125, 10, 3, true, WHITE);
        texto("Linia 2", 180, 90, 2, VIOLETA);
      }

      ledVerdGran(!marca_l1, 108, 130);
      ledVerdGran(!marca_l2, 218, 130);

      if (mode == 1) {
        if ((xpos > 330 && xpos < 348) && (ypos > 150 && ypos < 183)) {
          tft.fillScreen(BLACK);
          pagina = 2;
          //DateTime now = rtc.now();
          minuts_inicial = now.minute();
          hora_inicial = now.hour();
          dies_inicial = now.day();
          mesos_inicial = now.month();
          anys_inicial = now.year() - 2000;
          break;
        }

        if ((xpos > 330 && xpos < 348) && (ypos > 0 && ypos < 33)) {
          tft.fillScreen(BLACK);
          pagina = 3;
          parametres = 1;
          minuts_E1_inicial = minuts_E1;
          hora_E1_inicial = hora_E1;
          minuts_E2_inicial = minuts_E2;
          hora_E2_inicial = hora_E2;
          minuts_E3_inicial = minuts_E3;
          hora_E3_inicial = hora_E3;
          minuts_E4_inicial = minuts_E4;
          hora_E4_inicial = hora_E4;
          minuts_E5_inicial = minuts_E5;
          hora_E5_inicial = hora_E5;
          minuts_E6_inicial = minuts_E6;
          hora_E6_inicial = hora_E6;
        }
      }
      break;
    case 2: // Rellotge

      pan_rellotge();

      if ((xpos > 330 && xpos < 348) && (ypos > 203 && ypos < 233)) {
        tft.fillScreen(BLACK);
        pagina = 1;
        if (canvi_rellotge) {
          canvi_rellotge = false;
          transmi();
        }
      }

      break;
    case 3: // Parametres
      switch (parametres) {
        case 1:

          pan_param_E12_L1();

          if ((xpos > 330 && xpos < 348) && (ypos > 0 && ypos < 33)) {
            tft.fillScreen(BLACK);
            parametres = 2;
            break;
          }

          if ((xpos > 330 && xpos < 348) && (ypos > 203 && ypos < 233)) {
            tft.fillScreen(BLACK);
            pagina = 1;
          }
          break;
        case 2:

          pan_param_E34_L1();

          if ((xpos > 330 && xpos < 348) && (ypos > 0 && ypos < 33)) {
            tft.fillScreen(BLACK);
            parametres = 3;
            break;
          }

          if ((xpos > 330 && xpos < 348) && (ypos > 50 && ypos < 83)) {
            tft.fillScreen(BLACK);
            parametres = 1;
            break;
          }

          if ((xpos > 330 && xpos < 348) && (ypos > 203 && ypos < 233)) {
            tft.fillScreen(BLACK);
            pagina = 1;
          }
          break;
        case 3:

          pan_param_E56_L2();

          if ((xpos > 330 && xpos < 348) && (ypos > 50 && ypos < 83)) {
            tft.fillScreen(BLACK);
            parametres = 2;
            break;
          }

          if ((xpos > 330 && xpos < 348) && (ypos > 203 && ypos < 233)) {
            tft.fillScreen(BLACK);
            pagina = 1;
          }
          break;
      }

      if ((xpos > 330 && xpos < 348) && (ypos > 203 && ypos < 233)) {
        tft.fillScreen(BLACK);
        pagina = 1;
      }

      break;
  } // fi switch
  EEPROM.update(0, mode);
  activat();

} // fi Loop

void Evento1_l1_on() {                // Encendre el Led 1 primer event
  digitalWrite(Linea_1, LOW);
  marca_l1 = false;
  Serial1.println(10);
  dadesPerLolin();
}

void Evento2_l1_off() {               // Apagar en Led 1 primer event
  digitalWrite(Linea_1, HIGH);
  marca_l1 = true;
  Serial1.println(11);
  dadesPerLolin();
}

void Evento3_l1_on() {                // Encencdre el Led 1 segon event
  digitalWrite(Linea_1, LOW);
  marca_l1 = false;
  Serial1.println(10);
  dadesPerLolin();
}

void Evento4_l1_off() {               // Apagar el Led 1 segon event
  digitalWrite(Linea_1, HIGH);
  marca_l1 = true;
  Serial1.println(11);
  dadesPerLolin();
}

void Evento1_l2_on() {                // Encendre el Led 2
  digitalWrite(Linea_2, LOW);
  marca_l2 = false;
  Serial1.println(12);
  dadesPerLolin();
}

void Evento2_l2_off() {               // Apagar el Led 2
  digitalWrite(Linea_2, HIGH);
  marca_l2 = true;
  Serial1.println(13);
  dadesPerLolin();
}








