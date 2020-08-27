#include <assert.h>
#include <climits>

const int bpmLimits[] = {70, 150};
const int spo2Limits[] = {90, INT_MAX}; //has only lower bound so treated the the upper bound as INT_MAX
const int respRateLimits[] = {30, 95};

bool vitalIsOkay(float value, int lower_bound, int upper_bound) {
  return value >= lower_bound && value < upper_bound;
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return vitalIsOkay(bpm, bpmLimits[0], bpmLimits[1]) && 
          vitalIsOkay(spo2, spo2Limits[0], spo2Limits[1]) &&
          vitalIsOkay(respRate, respRateLimits[0], respRateLimits[1]);
}

int main() {
  assert(vitalIsOkay(96, 70, 150) == true);
  assert(vitalIsOkay(50, 30, 95) == true);
  assert(vitalIsOkay(152, 70, 150) == false);
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
