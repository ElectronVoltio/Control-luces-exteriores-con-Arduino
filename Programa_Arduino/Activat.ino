void activat() {

  DateTime now = rtc.now();

  if (digitalRead(Sensor_D)) {
    sensor_retard_on();
    tempo2 = millis();
  } else {
    sensor_retard_off();
    tempo1 = millis();
  }

  if (mode == 2) {
    if (marca_Sensor) {

      segons_ara = (now.hour() * 3600L) + (now.minute() * 60L);

      // ********** Evento 1 i 2 (L1)**********
      segons_E1 = (hora_E1 * 3600L) + (minuts_E1 * 60L);
      segons_E2 = (hora_E2 * 3600L) + (minuts_E2 * 60L);

      if ((segons_ara >= segons_E1 && segons_ara < segons_E2) && !act_E1) {
        Evento1_l1_on();
        act_E1 = true;
      }

      if ((segons_ara == segons_E2) && !act_E2) {
        Evento2_l1_off();
        act_E2 = true;
      }
      // ********** Fi E1 i E2 **********

      // ********** Evento 3 i 4 (L1) **********
      segons_E3 = (hora_E3 * 3600L) + (minuts_E3 * 60L);
      segons_E4 = (hora_E4 * 3600L) + (minuts_E4 * 60L);

      if ((segons_ara >= segons_E3 && segons_ara < segons_E4) && !act_E3) {
        Evento3_l1_on();
        act_E3 = true;
      }

      if ((segons_ara == segons_E4) && !act_E4) {
        Evento4_l1_off();
        act_E4 = true;
      }
      // ********** Fi E3 i E4 **********

      // ********** Evento 5 i 6 (L2)**********

      segons_E5 = (hora_E5 * 3600L) + (minuts_E5 * 60L);
      segons_E6 = (hora_E6 * 3600L) + (minuts_E6 * 60L);

      if ((segons_ara >= segons_E5 && segons_ara < segons_E6) && !act_E5) {
        Evento1_l2_on();
        act_E5 = true;
      }

      if ((segons_ara == segons_E6) && !act_E6) {
        Evento2_l2_off();
        act_E6 = true;
      }
      // ********** Fi E5 i E6 **********

    } else {

      digitalWrite(Linea_1, HIGH);
      digitalWrite(Linea_2, HIGH);
      marca_l1 = true;
      marca_l2 = true;
      act_E1 = false;
      act_E2 = false;
      act_E3 = false;
      act_E4 = false;
      act_E5 = false;
      act_E6 = false;
    }
  } // fin mode==2
} // fi

void sensor_retard_on() {
  if (tempo1 > millis()) tempo1 = millis();
  if ((millis() - tempo1) >= 5000) {
    tempo1 = millis();
    marca_Sensor = true;
  }
}

void sensor_retard_off() {
  if (tempo2 > millis()) tempo2 = millis();
  if ((millis() - tempo2) >= 5000) {
    tempo2 = millis();
    marca_Sensor = false;
  }
}

