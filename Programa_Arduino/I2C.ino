void transmi(){

  Wire.beginTransmission(0x68);       //Adreça del DS1307
  Wire.write((byte)0);                //Direcció de inici del registre DS1307
  Wire.write(bin2bcd(00));            //Segond
  Wire.write(bin2bcd(minuts));        //minuts
  Wire.write(bin2bcd(hores));         //hores
  Wire.write(bin2bcd(0));
  Wire.write(bin2bcd(dies));          //dies
  Wire.write(bin2bcd(mesos));         //mesos
  Wire.write(bin2bcd(anys));         //anys
  Wire.endTransmission();
}

static uint8_t bin2bcd (uint8_t val) {
  return val + 6 * (val / 10);
}
