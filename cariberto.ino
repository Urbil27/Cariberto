#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#define OLED_MOSI 9
#define OLED_CLK 10
#define OLED_DC 11
#define OLED_CS 12
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
int pestaneos = 0;
String data;
void setup(){
  Serial.begin(9600);
 display.begin(SSD1306_SWITCHCAPVCC); // Inicia el display OLED
 display.clearDisplay(); // Borrar imagen en el OLED
 display.setTextColor(WHITE); // Definir color del texto (WHITE-BLACK)
 
}
void loop() {
  if (Serial.available()>0){
    //read the sent option
    data=Serial.readString();
     display.setTextSize(2); // Tamaño del texto

    display.setCursor(30,0); // Definir posición Columna (0) Fila (0)
    display.clearDisplay(); // Borrar imagen en el OLED
    if(data.equals(String("comida"))){
          Serial.write("Recibido");
          display.println("^_^"); // Carga la información al buffer
          delay(1000);

    }
  }
  if(pestaneos<5){
    display.clearDisplay(); // Borrar imagen en el OLED
    display.setTextSize(5);
    display.setCursor(30,0); // Definir posición Columna (0) Fila (0)
    display.println("0_0"); // Carga la información al buffer
    display.display(); // Actualiza display con datos en Buffer
    delay(7000);
    display.clearDisplay(); // Borrar imagen en el OLED
    display.setCursor(30,0); // Definir posición Columna (0) Fila (0)
    display.println("-_-");
    display.display();
  }
  else{
    display.clearDisplay(); // Borrar imagen en el OLED
    display.setTextSize(5);
    display.setCursor(10,0); // Definir posición Columna (0) Fila (0)
    display.println("0_0"); // Carga la información al buffer
    display.display(); // Actualiza display con datos en Buffer
    delay(7000);
    display.clearDisplay(); // Borrar imagen en el OLED
    display.setCursor(10,0); // Definir posición Columna (0) Fila (0)
    display.println("-_-");
    display.display();
  }
  if(pestaneos == 10){
    pestaneos = 0;
  }
  // Actualiza display con datos en Buffer
  pestaneos++;
 delay(500); // Demora de 2 segundos.
}
