#include <assert.h>

const int spo2 = 90;
const int bpmLimits[] = {70, 150};
const int respRateLimits[] = {30, 95};

bool bpmCheck(float bpm) {
  return (bpm >= bpmLimits[0] && bpm < bpmLimits[1]);
}

bool spo2Check(float spo2) {
  return spo2 >= 90;
}

bool respRateCheck(float respRate) {
  return (respRate >= respRateLimits[0] && respRate < respRateLimits[1]);
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return bpmCheck(bpm) && spo2Check(spo2) && respRateCheck(respRate) ? true : false;
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
