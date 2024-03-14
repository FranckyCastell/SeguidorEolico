#define __DEBUG__

// VARIABLES DE LA VELETA
int PinVeleta = 20;        // ENTRADA DE PIN VELETA
int ValorVeleta = 0;       // VALOR VELETA
int AnguloServoVeleta = 0; // ANGULO DEL SERVO DE LA VELETA

int ValorNorte = 0;                          // VALOR NORTE
int ValorEste = 255;                         // VALOR ESTE
int ValorSur = 511;                          // VALOR SUR
int ValorOeste = 767;                        // VALOR OESTE
int ValorNE = (ValorNorte + ValorEste) / 2;  // VALOR NORESTE
int ValorSE = (ValorSur + ValorEste) / 2;    // VALOR SURESTE
int ValorSO = (ValorSur + ValorOeste) / 2;   // VALOR SUROESTE
int ValorNO = (ValorNorte + ValorOeste) / 2; // VALOR NOROESTE
// VARIABLES DE LA VELETA

void setup()
{
    Serial.begin(9600);
    
}

void loop() {
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

    SViento.write(AnguloServoVeleta); // MOVEMOS SERVO AL ANGULO DESEADO

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