#include <iostream>
#include <wiringPi.h>

#define SENSOR_PIN 0 // GPIO17 pin

int main() {
    if (wiringPiSetup() == -1) {
        std::cerr << "Failed to initialize WiringPi!" << std::endl;
        return 1;
    }

    pinMode(SENSOR_PIN, INPUT);

    while (true) {
        // Detect gas presence (LOW signal indicates gas)
        if (digitalRead(SENSOR_PIN) == LOW) {
            std::cout << "Gas detected!" << std::endl;
        } else {
            std::cout << "No gas detected." << std::endl;
        }

        // Delay between readings
        delay(1000); // 1 second delay
    }

    return 0;
}
