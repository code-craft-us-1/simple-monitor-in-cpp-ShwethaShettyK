#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds, std::string;

bool isNormalTemparature(float temperature) {
    return ((temperature <= 102 && temperature >= 95));
}

bool isNormalPulseRate(float pulseRate) {
    return (pulseRate >= 60 && pulseRate <= 100);
}

bool isNormalO2Saturation(float spo2) {
    return (spo2 >= 90);
}

void print(string message) {
    cout << message;
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}

bool checkVital(bool (*checkFunction)(float), float value, const char* warning) {
    if (!checkFunction(value)) {
        print(warning);
        return false;
    }
    return true;
}

bool vitalsOk(vitalSigns vitalSign) {
    return checkVital(isNormalTemparature, vitalSign.temperature, "Temperature is critical!\n") &&
           checkVital(isNormalPulseRate, vitalSign.pulseRate, "Pulse Rate is out of range!\n") &&
           checkVital(isNormalO2Saturation, vitalSign.spo2, "Oxygen Saturation out of range!\n");
}
