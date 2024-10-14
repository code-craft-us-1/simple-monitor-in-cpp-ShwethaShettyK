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

bool isNormalOxygenSaturation(float spo2) {
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

bool vitalsOk(vitalSigns vitalSign) {
  if (!isNormalTemparature(vitalSign.temperature)) {
      print("Temperature is critical!\n");
      return false;
  }
  if (!isNormalPulseRate(vitalSign.pulseRate)) {
      print("Pulse Rate is out of range!\n");
      return  false;
  }
  if (!isNormalOxygenSaturation(vitalSign.spo2)) {
      print("Oxygen Saturation out of range!\n");
      return false;
  }
  return true;
}
