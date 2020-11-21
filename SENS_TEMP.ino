#include <SimpleDHT.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;     //Inizializzo le variabili con i valori dei rispettivi PIN di Arduino
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// for DHT11,
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2

#define DHTPIN 7      //Definisco il PIN di Arduino che riceve dati dal sensore
SimpleDHT11 dht11;    //Oggetto della classe SimpleDTH11

void setup() {
  lcd.begin(16,2);              //Comunico le dimensioni del display LCD
  lcd.print("Temp di oggi");    
  delay(1500);
  lcd.clear();
}

void loop() {
  byte temp = 0;
  byte umid = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(DHTPIN, &temp, &umid, NULL)) != SimpleDHTErrSuccess) {    //Lettura dei parametri rilevati dal sensore
    lcd.clear();
    lcd.print("Errore lettura");
    lcd.setCursor(0,1);
    lcd.print("Temperatura");
    delay(1000);
    lcd.clear();
    return;
  }

  lcd.setCursor(0,0);   //Cursore nel primo carattere della prima riga
  lcd.print("TEMP: ");
  lcd.print((int)temp); //Stampa del valore di temperatura misurato
  lcd.setCursor(0,1);
  lcd.print("UMID: ");
  lcd.print((int)umid); //Stampa del valore di umidità misurato


  delay(3500);          // Delay di 3,5 secondi
}
