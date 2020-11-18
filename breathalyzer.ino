#include <LiquidCrystal.h>
//#include <dht11.h>


// initialize the library with the numbers of the interface pins
//    LiquidCrystal lcd(RS, enable, d4, d5, d6, d7); //
//
// The parameters to this initialisation function are the pins on 
// the Arduino board that are connected to the pins on the LCD Module, 
// i.e., the pins on the right column in the table above.
//
// The first parameter is the “RS” — which, literally, means 
//      “Register Select”, and which is used to tell the
//       module if “that which comes over the bus (the set of data pins)
//       corresponds to “data to print” or “control instructions”
//
// The second parameter is “Enable Signal"
//       the remaining parameters are the 4 digital pins forming the bus.
//
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
char text;
int value;
//int temp;
const int AOUTpin=0; //the AOUT pin of the alcohol sensor goes into analog pin A0 of the arduino
//const int TOUTpin=1; //Temperature Sensor
int max_value;
bool need_to_clear;




//#define DHT11PIN 4

//dht11 DHT11;


void setup() {
      // set up the LCD's number of columns and rows:
      lcd.begin(16, 2);
      need_to_clear = 0;
      //Serial.begin(9600);
}

void loop() {
  value= analogRead(AOUTpin);//reads the analaog value from the alcohol sensor's AOUT pin
  if(value >= 1020) {value = 0;}
  if(value > max_value) { max_value = value; } // Keep max value updated
  if(value >= 1000) {need_to_clear = 1; }      // If value reaches 4 digits, will need to refresh


  
  if (need_to_clear & value < 1000){ // Reset screen if necessary
    //lcd.clear();
    need_to_clear = 0;
  }

  lcd.setCursor(0, 0);
  lcd.print("Live:");
  lcd.setCursor(6, 0);
  lcd.print(value);
  lcd.setCursor(0,1);
  lcd.print(" Max:");
  lcd.setCursor(6,1);
  lcd.print(max_value);
  //Serial.println(value);
  

  //Serial.println();

  //int chk = DHT11.read(DHT11PIN);

  //lcd.setCursor(10,1);
  //lcd.print(chk);  

  //Serial.print("Humidity (%): ");
  //Serial.println((float)DHT11.humidity, 2);

  ///lcd.setCursor(0,0);
  //lcd.print("test");

  //Serial.print("Temperature (C): ");
  //Serial.println((float)DHT11.temperature, 2);
  //Serial.println(DHT11.temperature);

  //(2000);
  
}
