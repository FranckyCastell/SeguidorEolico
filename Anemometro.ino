#define __DEBUG__

int sensorValue = 0;
float sensorVoltage = 0;
float windSpeed = 0;
float voltageConversionConstant = 0.004882814;
int sensorDelay = 1000;
float voltageMin = .4;
float windSpeedMin = 0;
float voltageMax = 2.0;
float windSpeedMax = 32;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    sensorValue = analogRead(25);

    sensorVoltage = sensorValue * voltageConversionConstant;

    if (sensorVoltage <= voltageMin)
    {
        windSpeed = 0;
    }

    else
    {
        windSpeed = (sensorVoltage - voltageMin)

                    * windSpeedMax / (voltageMax - voltageMin);
    }

    Serial.print("Voltage: ");

    Serial.print(sensorVoltage);

    Serial.print("\t");

    Serial.print("Wind speed: ");

    Serial.println(windSpeed);

    delay(sensorDelay);
}