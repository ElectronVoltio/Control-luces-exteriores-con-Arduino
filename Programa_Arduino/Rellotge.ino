void pan_rellotge() {
  static int vell_hores = hora_inicial, vell_minuts = minuts_inicial;
  static int vell_dies = dies_inicial, vell_mesos = mesos_inicial, vell_anys = anys_inicial;

  texto(" Rellotge", 70, 5, 3, ORANGE);
  dibuLinea(0, 33, 350, 33, 3, true, VIOLETA);

  texto("Hora", 90, 130, 2, BLUE);
  hores = num_inputI(hora_inicial, 65, 175, 2, WHITE, BLUE, 0, 23, 1);
  hora_inicial = hores;

  if (vell_hores != hores) {
    canvi_rellotge = true;
    vell_hores = hores;
  }

  texto("Minuts", 185, 130, 2, BLUE);
  minuts = num_inputI(minuts_inicial, 175, 175, 2, WHITE, BLUE, 0, 59, 1);
  minuts_inicial = minuts;

  if (vell_minuts != minuts) {
    canvi_rellotge = true;
    vell_minuts = minuts;
  }

  texto("Dia", 35, 40, 2, RED);
  dies = num_inputI(dies_inicial, 5, 85, 2, WHITE, RED, 1, 31, 1);
  dies_inicial = dies;

  if (vell_dies != dies) {
    canvi_rellotge = true;
    vell_dies = dies;
  }

  texto("Mes", 145, 40, 2, RED);
  mesos = num_inputI(mesos_inicial, 115, 85, 2, WHITE, RED, 1, 12, 1);
  mesos_inicial = mesos;

  if (vell_mesos != mesos) {
    canvi_rellotge = true;
    vell_mesos = mesos;
  }

  texto("Any", 255, 40, 2, RED);
  anys = num_inputI(anys_inicial, 225, 85, 2, WHITE, RED, 17, 99, 1);
  anys_inicial = anys;

  if (vell_anys != anys) {
    canvi_rellotge = true;
    vell_anys = anys;
  }

}

