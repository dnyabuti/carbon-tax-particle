#include "EmonLib/EmonLib.h"

EnergyMonitor emon1;                   // Create an instance
double accpower=0;
int count = 0;
unsigned long lastmillis;

void setup()
{
    emon1.current(1, 83);             // Current: input pin, calibration.
    lastmillis=millis();
}

void loop()
{
    if (count<10) {
        double Irms = (((emon1.calcIrms(1480)/sqrt(2))*120)/3600)/1000;  // Calculate Irms only
        accpower += Irms;
        count++;
    }

    else {
        String data = String(accpower);
        Particle.publish("kwh", data, PRIVATE);
        accpower = 0;
        count = 0;
    }
    delay(1000-(millis()-lastmillis));
    lastmillis = millis();
}
