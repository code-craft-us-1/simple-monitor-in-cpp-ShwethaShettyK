#pragma once

struct vitalSigns
{
	float temperature;
	float pulseRate;
	float spo2;
};

bool vitalsOk(vitalSigns vitalSign);


