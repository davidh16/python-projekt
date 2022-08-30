#include "SFE_BMP180.h"
#include "Wire.h"
 
SFE_BMP180 tlak;
 
double tlakZraka, tempZraka; 
 
void setup() {
  // zapocinjem serijsku komunikaciju
  Serial.begin(9600);
   
  // provjera je li sve uredu
  if(tlak.begin())  Serial.println("BMP180 uspjesno povezan.");
  else
  {
    Serial.print("Upss.. provjeri kako je modul spojen na Croduino...");
    while(1);
  }
}
 
void loop() {
   
  // ocitavam i zapisujem temp zraka
  tempZraka = ocitajTemperaturu();
  Serial.print("Temp zraka = " + String(tempZraka));
  Serial.println("C");
 
  // ispisuj podatke svakih 1000ms = 1sekundu
  delay(1000);
  Serial.println();
 
}

 
double ocitajTemperaturu()
{
  char status;
  double temp;
   
  // zapocinjemo mjerenje temperature
  // ako je mjerenje uspješno funkcija vraca delay u ms
  // u suprotnom nam vraća 0 (nulu)
   
  status = tlak.startTemperature();
  if(status != 0)
  {
    delay(status);
    // vraća 1 za uspjesno, odnosno 0 za neuspjesno mjerenje
    status = tlak.getTemperature(temp);
    if(status != 0)
    {
      return(temp);
    }
  }
}
