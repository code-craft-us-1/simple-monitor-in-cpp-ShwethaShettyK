#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds, std::string;

bool isNormalTemparature(float temperature){
    return ((temperature > 102 || temperature < 95)) ? false : true;
}

bool isNormalPulseRate(float pulseRate){
    return (pulseRate < 60 || pulseRate > 100) ? false : true;
}

bool isNormalOxygenSaturation(float spo2){
    return (spo2 < 90) ? false : true;
}

void print(string message){
    cout << message;
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}

bool vitalsOk(vitalSigns vitalSign) {
    bool vitalOk = true;
  if (isNormalTemparature(vitalSign.temperature)) {
      print("Temperature is critical!\n");
      vitalOk = false;
  } else if (!isNormalPulseRate(vitalSign.pulseRate)) {
      print("Pulse Rate is out of range!\n");
      vitalOk = false;
  } else if (!isNormalOxygenSaturation(vitalSign.spo2)) {
      print("Oxygen Saturation out of range!\n");
      vitalOk = false;
  }
  return vitalOk;
}
