#include <ESP8266WiFi.h>

// Connexió a xarxa privada
const char* ssid = "Senergy";
const char* password = "renova&energy";

// Servidor web escolta per port 80
WiFiServer server(1750);

IPAddress ip_xarxa;

int estado;                 // Variable de lectura dels valor enviat pel Arduino 1--> Manual 2--> Activat
int modo = 1;               // Variable que indica el mode del control 1--> Manual 2--> Activat
String getV;                // Variable que conte la resposta provenient de la pàgina web
bool led1 = false;
bool led2 = false;

long hm_E1, hm_E2, hm_E3, hm_E4, hm_E5, hm_E6;
long hora_E1, hora_E2, hora_E3, hora_E4, hora_E5, hora_E6;
long minuts_E1, minuts_E2, minuts_E3, minuts_E4, minuts_E5, minuts_E6;

// secuència d'arrancada
void setup() {
  // Inicialitzem port sèrie
  Serial.begin(115200);
  delay(10);
  //Serial1.begin(115200);

  // Connectant a la xarxa WiFi
  //Serial.println();
  //Serial.print("Connectant a ");
  //Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(50);
    //Serial.print(".");
  }
  //Serial.println("");
  //Serial.println("WiFi connectat");

  // Inicialitzant servidor WEB
  server.begin();
  //Serial.println("Servidor Web en marxa. Espereu per IP del ESP...");
  delay(10);

  // Visualitza adreça IP del ESP
  ip_xarxa = WiFi.localIP();
  //Serial.println(" ");
  //Serial.println(ip_xarxa);

  Serial.write("X");
}

void Dades_arduino() {

  /*if (Serial.available() > 0) {
    estat = Serial.read();
    //delay(10);
    if (estat == 77) {
      modo = 1;
      led1 = false;
      led2 = false;
    }
    if (estat == 65) {
      modo = 2;
      led1 = false;
      led2 = false;
    }

    if (estat == 97) {
      led1 = true;
    }
    if (estat == 98) {
      led1 = false;
    }

    if (estat == 99) {
      led2 = true;
    }
    if (estat == 100) {
      led2 = false;
    }
    } else {
    return;
    }*/

  if (Serial.available() > 4) {
    estado = Serial.parseInt();

    if (estado == 1) {
      modo = 1;
      led1 = false;
      led2 = false;
    }

    if (estado == 2) {
      modo = 2;
      led1 = false;
      led2 = false;
    }

    //if (modo == 2) {
    hm_E1 = Serial.parseInt();
    hm_E2 = Serial.parseInt();
    hm_E3 = Serial.parseInt();
    hm_E4 = Serial.parseInt();
    hm_E5 = Serial.parseInt();
    hm_E6 = Serial.parseInt();
    //}
  } else {
    return;
  }

  hora_E1 = hm_E1 / 3600;
  minuts_E1 = (hm_E1 % 3600) / 60;
  hora_E2 = hm_E2 / 3600;
  minuts_E2 = (hm_E2 % 3600) / 60;
  hora_E3 = hm_E3 / 3600;
  minuts_E3 = (hm_E3 % 3600) / 60;
  hora_E4 = hm_E4 / 3600;
  minuts_E4 = (hm_E4 % 3600) / 60;
  hora_E5 = hm_E5 / 3600;
  minuts_E5 = (hm_E5 % 3600) / 60;
  hora_E6 = hm_E6 / 3600;
  minuts_E6 = (hm_E6 % 3600) / 60;

  if (estado == 1) {
    modo = 1;
    led1 = false;
    led2 = false;
  }

  if (estado == 2) {
    modo = 2;
    led1 = false;
    led2 = false;
  }

  if (estado == 10) {
    led1 = true;
  }
  if (estado == 11) {
    led1 = false;
  }

  if (estado == 12) {
    led2 = true;
  }
  if (estado == 13) {
    led2 = false;
  }

  /*Serial.println(estado);
    Serial.println(hm_E1);
    Serial.println(hm_E2);
    Serial.println(hm_E3);
    Serial.println(hm_E4);
    Serial.println(hm_E5);
    Serial.println(hm_E6);*/

}

// Secuència principal
void loop() {

  Dades_arduino();

  // comprova nou client
  WiFiClient client = server.available();

  String req = client.readStringUntil('H');   //Lectura de la primera línia de la resposta de la web
  //if (req.indexOf("cons=") != -1) {
  //getV = req.substring(req.indexOf("=") + 1, req.length());
  //}
  //if (req.indexOf("incr=1") != -1) {
  //consigna = consigna + 0.5;
  //if (consigna > 30.0) {
  //consigna = 30.0;
  //}
  //Serial.println(" ");
  //Serial.println(consigna);
  //}
  //if (req.indexOf("incr=0") != -1) {
  //consigna = consigna - 0.5;
  //if (consigna < 16.0) {
  //consigna = 16.0;
  //}
  //Serial.println(" ");
  //Serial.println(consigna);
  //}

  if (req.indexOf("l1=1") != -1) {          //Encendre línea 1
    led1 = true;
    Serial.write("a");
  }

  if (req.indexOf("l1=0") != -1) {          //Apagar línea 1
    led1 = false;
    Serial.write("b");
  }

  if (req.indexOf("l2=1") != -1) {          //Encendre línea 2
    led2 = true;
    Serial.write("c");
  }

  if (req.indexOf("l2=0") != -1) {          //Apagar línea 2
    led2 = false;
    Serial.write("d");
  }

  /*if (req.indexOf("mato=2") != -1) {
    consigna = 21.0;
    Serial.println(" ");
    //Serial.println(consigna);
    }
    if (req.indexOf("mato=3") != -1) {
    //consigna = 22.0;
    Serial.println(" ");
    //Serial.println(consigna);
    }*/

  if (req.indexOf("mode=1") != -1) {           //Lectura pàgina web per passar a mode Manual
    modo = 1;
    Serial.write("M");
    led1 = false;
    led2 = false;
  }
  if (req.indexOf("mode=2") != -1) {         //lectura pàgina web per passar a mode Activat
    modo = 2;
    Serial.write("A");
    led1 = false;
    led2 = false;
  }

  client.flush();

  //PÀGINA WEB
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println();

  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head> <style type='text/css'>body{width:100%;height:100%}</style><meta http-equiv='refresh' ");
  client.println("content='30;URL=/' charset='utf-8'><title>Control de l'enllumenats exteriors casa</title>");
  client.println("</head><body bgcolor='black'><font color='white'><h1 align='center'>Control del enllumenat exterior</h1></font>");

  client.println("<table width='80%' align='center' border='2px'><tr>");
  client.println("<td width='50%' align='center' bgcolor='#F6F7BA'><a style='font-size:25pt' href='/?mode=1'>Mode<br>Manual</a></td>");
  client.println("<td>   </td>");
  client.println("<td width='50%' align='center' bgcolor='#F6F7BA'><a style='font-size:25pt' href='/?mode=2'>Mode<br>Activat</a></td>");
  client.println("</tr></table><br>");

  switch (modo) {
    case 1: // Manual
      client.println("<table width='80%' align='center' border='2px'><tr>");
      client.println("<td bgcolor='#255DE9' align='center' colspan='4'><font color='magenta'><h1>Manual</h1></td>");
      client.println("</tr><tr>");
      client.println("<td width='50%' align='center' colspan='2'><font color='magenta'><h2 style='font-size:25pt'>Línia 1</h2></td>");
      client.println("<td width='50%' align='center' colspan='2'><font color='magenta'><h2 style='font-size:25pt'>Línia 2</h2></td>");
      client.println("</tr><tr>");
      if (led1) {
        client.println("<td colspan='2' bgcolor='#00ff00' style='height: 10px'></td>");
      }
      else {
        client.println("<td colspan='2' bgcolor='red' style='height: 10px'></td>");
      }
      if (led2) {
        client.println("<td colspan='2' bgcolor='#00ff00' style='height: 10px'></td>");
      }
      else {
        client.println("<td colspan='2' bgcolor='red' style='height: 10px'></td>");
      }
      client.println("</tr><tr>");
      client.println("<td width='25%' align='center'><a style='font-size:25pt' href='/?l1=1'>Encendre</a></td>");
      client.println("<td width='25%' align='center'><a style='font-size:25pt' href='/?l1=0'>Apagar</a></td>");
      client.println("<td width='25%' align='center'><a style='font-size:25pt' href='/?l2=1'>Encendre</a></td>");
      client.println("<td width='25%' align='center'><a style='font-size:25pt' href='/?l2=0'>Apagar</a></td>");
      client.println("</tr></table><br><br>");
      break;
    case 2: // Activat
      client.println("<table width='80%' align='center' border='2px'><tr>");
      client.println("<td bgcolor='#255DE9' align='center' colspan='2'><font color='yellow'><h1>Activat</h1></td>");
      client.println("</tr><tr>");
      client.println("<td width='50%' align='center'><font color='yellow'><h2 style='font-size:25pt'>Línia 1</h2></td>");
      client.println("<td width='50%' align='center'><font color='yellow'><h2 style='font-size:25pt'>Línia 2</h2></td>");
      client.println("</tr><tr>");
      if (led1) {
        client.println("<td bgcolor='#00ff00' style='height: 10px'></td>");
      }
      else {
        client.println("<td bgcolor='red' style='height: 10px'></td>");
      }
      if (led2) {
        client.println("<td bgcolor='#00ff00' style='height: 10px'></td>");
      }
      else {
        client.println("<td bgcolor='red' style='height: 10px'></td>");
      }
      client.println("</tr><tr>");
      client.println("<td width='50%' align='center'><font color='white'><h2 style='font-size:25pt'><font color='blue'>1 ON:</font>");
      if (hora_E1 < 10) {
        client.println("0");
      }
      client.println(hora_E1);
      client.println(":");
      if (minuts_E1 < 10) {
        client.println("0");
      }
      client.println(minuts_E1);

      client.println("</h2><font color='white'><h2 style='font-size:25pt'><font color='aqua'>1 OFF:</font>");
      if (hora_E2 < 10) {
        client.println("0");
      }
      client.println(hora_E2);
      client.println(":");
      if (minuts_E2 < 10) {
        client.println("0");
      }
      client.println(minuts_E2);

      client.println("</h2><font color='white'><h2 style='font-size:25pt'><font color='olive'>2 ON:</font>");
      if (hora_E3 < 10) {
        client.println("0");
      }
      client.println(hora_E3);
      client.println(":");
      if (minuts_E3 < 10) {
        client.println("0");
      }
      client.println(minuts_E3);

      client.println("</h2><font color='white'><h2 style='font-size:25pt'><font color='lime'>1 OFF:</font>");
      if (hora_E4 < 10) {
        client.println("0");
      }
      client.println(hora_E4);
      client.println(":");
      if (minuts_E4 < 10) {
        client.println("0");
      }
      client.println(minuts_E4);

      client.println("</h2></td>");
      client.println("<td width='50%' align='center'><font color='white'><h2 style='font-size:25pt'><font color='purple'>1 ON:</font>");
      if (hora_E5 < 10) {
        client.println("0");
      }
      client.println(hora_E5);
      client.println(":");
      if (minuts_E5 < 10) {
        client.println("0");
      }
      client.println(minuts_E5);

      client.println("</h2><font color='white'><h2 style='font-size:25pt'><font color='fuchsia'>1 OFF:</font>");
      if (hora_E6 < 10) {
        client.println("0");
      }
      client.println(hora_E6);
      client.println(":");
      if (minuts_E6 < 10) {
        client.println("0");
      }
      client.println(minuts_E6);
      client.println("</h2></td>");
      client.println("</tr><tr>");
      client.println("</tr></table><br><br>");
      break;
  }

  /*client.println("<form action = '/'>");
  client.println("<font color='fuchsia'>Select a time:</font>");
  client.println("<input type = 'time' name = 'usr_time'>");
  client.println("<input type = 'submit'>");
  client.println("< / form >");*/

  client.stop();
}
