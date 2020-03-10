/* 
The Sound Machine - based on Roald Dahl short story
Roni Bandini
March 2020
Buenos Aires, Argentina
Twitter/Instagram @RoniBandini
*/

#include "SoftwareSerial.h"
#include <TM1637Display.h>

// Mp3 player rx and tx
SoftwareSerial mySerial(10, 11); 

# define Start_Byte 0x7E
# define Version_Byte 0xFF
# define Command_Length 0x06
# define End_Byte 0xEF
# define Acknowledge 0x00 
# define ACTIVATED LOW

#define sensor A7
#define buttonPin 2
#define CLK 4
#define DIO 5

// Creates display object  
TM1637Display display(CLK, DIO);

// All - in display
const uint8_t SEG_START[] = {
          SEG_G,            // -
           SEG_G, // -
          SEG_G,   // -
          SEG_G  // -
          };

int buttonValue=0;
int humidValue=0;
long randNumber;

void setup(){
        
        Serial.begin(9600);        

        //uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
        display.setBrightness(0x0f);
             
        display.setSegments(SEG_START); 

        // humidity sensor
        pinMode(sensor, INPUT);
        // button
        pinMode(buttonPin,INPUT_PULLUP);       
        
        // mp3 player 
        mySerial.begin(9600);        

        // nothing being played, just init        
        playFirst();      

        Serial.println("The Sound Machine by Roni Bandini");
        Serial.println("Based on Roald Dahl short story");
        
        delay (2000);

        Serial.println("Ready...");

}



void loop(){

  // read button
  buttonValue = digitalRead(buttonPin);
  
   // for random sounds in each moisture category
   randomSeed(analogRead(4));   
               
  if (buttonValue == LOW) {

          // button has been pressed, map humidty sensor
          humidValue = map(analogRead(sensor), 0, 1023, 100, 0);
         
          
          Serial.print("Humidity: ");
          Serial.print(humidValue);
          Serial.println("%");

          // send to display
          display.showNumberDec(humidValue, false,4);
          
          if (humidValue<40){
                randNumber = random(1, 9);
                Serial.println("Dry");
                switch (randNumber) {
                  case 1:
                     execute_CMD(0x0F,0x01,0x01);  
                    break;
                  case 2:
                     execute_CMD(0x0F,0x01,0x02);  
                    break;   
                    case 3:
                     execute_CMD(0x0F,0x01,0x03);  
                    break;
                    case 4:
                     execute_CMD(0x0F,0x01,0x04);  
                    break;
                    case 5:
                     execute_CMD(0x0F,0x01,0x05);  
                    break;
                    case 6:
                     execute_CMD(0x0F,0x01,0x06);  
                    break;
                    case 7:
                     execute_CMD(0x0F,0x01,0x07);  
                    break;
                     case 8:
                     execute_CMD(0x0F,0x01,0x08);  
                    break;
                    case 9:
                     execute_CMD(0x0F,0x01,0x09);  
                    break;   
                }
               
                
            }
        
          if (humidValue>39 and humidValue<60){
                randNumber = random(10, 11);
                Serial.println("Medium");
                Serial.println(randNumber);
                switch (randNumber) {                 
                    case 10:
                     execute_CMD(0x0F,0x01,0x10);  
                    break;
                    case 11:
                     execute_CMD(0x0F,0x01,0x11);  
                    break;              
                }       
            }  
        
           if (humidValue>61){
                randNumber = random(12, 18);
                Serial.println("Lot of water");
                Serial.println(randNumber);
                switch (randNumber) {
                  case 12:
                     execute_CMD(0x0F,0x01,0x12);  
                    break;
                  case 13:
                     execute_CMD(0x0F,0x01,0x13);  
                    break;   
                    case 14:
                     execute_CMD(0x0F,0x01,0x14);  
                    break;
                    case 15:
                     execute_CMD(0x0F,0x01,0x15);  
                    break;  
                    case 16:
                     execute_CMD(0x0F,0x01,0x16);  
                    break;  
                    case 17:
                     execute_CMD(0x0F,0x01,0x17);  
                    break;  
                    case 18:
                     execute_CMD(0x0F,0x01,0x18);  
                    break;              
                }           
            }  

 delay(1000);
 display.setSegments(SEG_START); 
 } // button pressed
  
}


void playFirst()
{
  execute_CMD(0x3F, 0, 0); // query device
  delay(500);
  setVolume(25);
  delay(500);
  //execute_CMD(0x11,0,1); // repeat playback
  //delay(500);
}

void pause()
{
  execute_CMD(0x0E,0,0);
  delay(500);
}

void play()
{
  execute_CMD(0x0D,0,1); 
  delay(500);
}

void playNext()
{
  execute_CMD(0x01,0,1);
  delay(500);
}

void playPrevious()
{
  execute_CMD(0x02,0,1);
  delay(500);
}

void setVolume(int volume)
{
  execute_CMD(0x06, 0, volume); // Set the volume (0x00~0x30)
  delay(2000);
}

void execute_CMD(byte CMD, byte Par1, byte Par2)
// Excecute the command and parameters
{
// Calculate the checksum (2 bytes)
word checksum = -(Version_Byte + Command_Length + CMD + Acknowledge + Par1 + Par2);
// Build the command line
byte Command_line[10] = { Start_Byte, Version_Byte, Command_Length, CMD, Acknowledge,
Par1, Par2, highByte(checksum), lowByte(checksum), End_Byte};
//Send the command line to the module
for (byte k=0; k<10; k++)
{
mySerial.write( Command_line[k]);
}
}
