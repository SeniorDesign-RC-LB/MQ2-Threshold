#include <iostream>
#include <wiringPi.h>

#define MQ2_PIN 0

int main() {
    if (wiringPiSetup() == -1) {
        std::cerr << "Failed to initialize WiringPi!" << std::endl;
        return 1;
    }

    std::cout << "MQ2 warming up!" << std::endl;
    delay(20000); // Allow the MQ2 to warm up

    float sensorValue;

    while (true) {
        sensorValue = analogRead(MQ2_PIN); // Read analog input pin

        std::cout << "Sensor Value: " << sensorValue << std::endl;

        delay(2000); // Wait 2s for next reading
    }

    return 0;
}
