void dades_Lolin() {
  if (Serial1.available() > 0) {
    estat = Serial1.read();
    if (estat == 77) {               //Espera resposta del Lolin per passar a mode Manual amb la lletra "M"
      mode = 1;
      marca_inicial = false;
      digitalWrite(Linea_1, HIGH);
      digitalWrite(Linea_2, HIGH);
      marca_l1 = true;
      marca_l2 = true;
    }
    if (estat == 65) {                //Espera resposta del Lolin per passar a mode Activat amb la lletra "A"
      mode = 2;
      marca_inicial = true;
      digitalWrite(Linea_1, HIGH);
      digitalWrite(Linea_2, HIGH);
      marca_l1 = true;
      marca_l2 = true;
    }

    if (estat == 97) {                //Espera resposta del Lolin per encendre la línea 1 amb la lletra "a"
      digitalWrite(Linea_1, LOW);
      marca_l1 = false;
      //Evento1_l1_on();
    }

    if (estat == 98) {                //Espera resposta del Lolin per apagar la línea 1 amb la lletra "b"
      digitalWrite(Linea_1, HIGH);
      marca_l1 = true;
      //Evento2_l1_off();
    }

    if (estat == 99) {                //Espera resposta del Lolin per encendre la línea 2 amb la lletra "c"
      digitalWrite(Linea_2, LOW);
      marca_l2 = false;
    }

    if (estat == 100) {                //Espera resposta del Lolin per apagar la línea 2 amb la lletra "d"
      digitalWrite(Linea_2, HIGH);
      marca_l2 = true;
    }

    if (estat == 88) {                //Petició del Lolin per a saber la disposició de l'Arduino
      Serial1.println(mode);
      dadesPerLolin();
    }

    Serial.println(estat);
    //}
    //if (Serial1.available() > 4) {
    //val_inicial = Serial1.parseFloat();
    //if (val_inicial == 0) EEPROM.get(100, val_inicial);
    //consigna = val_inicial;
    //EEPROM.put(100, consigna);
    EEPROM.update(0, mode);
  } else {
    return;
  }
}

void dadesPerLolin() {
  //if (mode == 2) {
    Serial1.println((hora_E1 * 3600L) + (minuts_E1 * 60L));
    Serial1.println((hora_E2 * 3600L) + (minuts_E2 * 60L));
    Serial1.println((hora_E3 * 3600L) + (minuts_E3 * 60L));
    Serial1.println((hora_E4 * 3600L) + (minuts_E4 * 60L));
    Serial1.println((hora_E5 * 3600L) + (minuts_E5 * 60L));
    Serial1.println((hora_E6 * 3600L) + (minuts_E6 * 60L));
    //delay(100);
  //}
}

