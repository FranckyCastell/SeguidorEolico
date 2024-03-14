#include <Servo.h>
#define __DEBUG__
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// DECLARACIONES PARA LA PANTALLA OLED
#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 64
Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, -1);
// DECLARACIONES PARA LA PANTALLA OLED

// CREACION DE LOS SERVO MOTORES
Servo SViento; // SERVO PARA MOVER EL MOLINO HACIA EL VIENTO
Servo SPala1;  // SERVO PARA LA PALA 1
Servo SPala2;  // SERVO PARA LA PALA 2
Servo SPala3;  // SERVO PARA LA PALA 3
// CREACION DE LOS SERVO MOTORES

// VARIABLES DEL ANEMOMETRO
int ValorSensor = 0;                            // VALOR DEL SENSOR
float VoltajeSensor = 0;                        // VOLTAJE DEL SENSOR
float VelocidadViento = 0;                      // VELOCIDAD DEL VIENTO
float ConstanteConversionVoltaje = 0.004882814; // CONSTANTE DE CONVERSIÓN DE VOLTAJE
// VARIABLES PARA EL ANEMOMETRO

// VARIABLES DE LA VELETA
int PinVeleta = A1;  // ENTRADA DE PIN VELETA
int ValorVeleta = 0; // VALOR VELETA
int AnguloServoVeleta = 0;

int ValorNorte = 0;                          // VALOR NORTE
int ValorEste = 255;                         // VALOR ESTE
int ValorSur = 511;                          // VALOR SUR
int ValorOeste = 767;                        // VALOR OESTE
int ValorNE = (valorNorte + valorEste) / 2;  // VALOR NORESTE
int ValorSE = (valorSur + valorEste) / 2;    // VALOR SURESTE
int ValorSO = (valorSur + valorOeste) / 2;   // VALOR SUROESTE
int ValorNO = (valorNorte + valorOeste) / 2; // VALOR NOROESTE
// VARIABLES DE LA VELETA

void setup()
{
    SViento.attach(25); // DEFINIMOS SERVOMOTOR PIN 25 ( VIENTO )
    SPala1.attach(26);  // DEFINIMOS SERVOMOTOR PIN 26 ( PALA1 )
    SPala2.attach(27);  // DEFINIMOS SERVOMOTOR PIN 25 ( PALA2 )
    SPala3.attach(28);  // DEFINIMOS SERVOMOTOR PIN 26 ( PALA3 )

// INICIAMOS PANTALLA OLED
#ifdef __DEBUG__
    Serial.begin(9600);
    delay(100);
    Serial.println("~ INICIANDO PANTALLA OLED ~");
#endif

    // INICIAMOS PANTALLA OLED EN LA DIRECCIÓN 0x3C
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
#ifdef __DEBUG__
        Serial.println("NO SE A ENCONTRADO PANTALLA OLED");
#endif
        while (true)
            ;
    }
}

void loop()
{

    // OLED CONSTANTS
    display.clearDisplay();              // BORRAMOS CONTENIDO DE LA PANTALLA OLED
    display.setTextSize(1);              // DEFINIMOS TAMAÑO DEL TEXTO QUE SE VA A MOSTRAR EL 1 ES EL TAMAÑO MINIMO
    display.setTextColor(SSD1306_WHITE); // COLOR DEL TEXTO
    // OLED CONSTANTS

    // SECCION ANEMOMETRO
    ValorSensor = analogRead(A0); // VALOR PIN ANALOGICO
    VoltajeSensor = ValorSensor * ConstanteConversionVoltaje;
    VelocidadViento = VoltajeSensor; // EJEMPLO

    Serial.print("Velocidad del viento: "); // IMPRIMIMOS VELOCIDAD VIENTO
    Serial.print(VelocidadViento);
    Serial.println(" m/s");
    // SECCION ANEMOMETRO

    // SECCION VELETA
    ValorVeleta = analogRead(PinVeleta); // LEEMOS VALOR DE VELETA

    // LOGICA CONVERSION VALOR EN DIRECCION
    if (ValorVeleta >= ValorNO && ValorVeleta < ValorNE)
    {
        AnguloServoVeleta = 45; // NORESTE
    }
    else if (ValorVeleta >= ValorNE && ValorVeleta < ValorEste)
    {
        AnguloServoVeleta = 90; // ESTE
    }
    else if (ValorVeleta >= ValorEste && ValorVeleta < ValorSE)
    {
        AnguloServoVeleta = 135; // SURESTE
    }
    else if (ValorVeleta >= ValorSE && ValorVeleta < ValorSur)
    {
        AnguloServoVeleta = 180; // SUR
    }
    else if (ValorVeleta >= ValorSur && ValorVeleta < ValorSO)
    {
        AnguloServoVeleta = 225; // SUROESTE
    }
    else if (ValorVeleta >= ValorSO && ValorVeleta < ValorOeste)
    {
        AnguloServoVeleta = 270; // OESTE
    }
    else if (ValorVeleta >= ValorOeste && ValorVeleta < ValorNO)
    {
        AnguloServoVeleta = 315; // NOROESTE
    }
    else
    {
        AnguloServoVeleta = 0; // NORTE
    }

    miServo.write(AnguloServoVeleta); // MOVEMOS SERVO AL ANGULO DESEADO

    Serial.print("VALOR VELETA: ");
    Serial.print(ValorVeleta);
    Serial.print(", DIRECCION DEL VIENTO: ");
    if (AnguloServoVeleta == 45)
    {
        Serial.println("NORESTE");
    }
    else if (AnguloServoVeleta == 90)
    {
        Serial.println("ESTE");
    }
    else if (AnguloServoVeleta == 135)
    {
        Serial.println("SURESTE");
    }
    else if (AnguloServoVeleta == 180)
    {
        Serial.println("SUR");
    }
    else if (AnguloServoVeleta == 225)
    {
        Serial.println("SUROESTE");
    }
    else if (AnguloServoVeleta == 270)
    {
        Serial.println("OESTE");
    }
    else if (AnguloServoVeleta == 315)
    {
        Serial.println("NOROESTE");
    }
    else
    {
        Serial.println("NORTE");
    }
    // SECCION VELETA
}