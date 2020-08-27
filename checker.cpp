#include <assert.h>
#include <climits>

bool vitalIsOkay(float value, int lower_bound, int upper_bound) {
  return value >= lower_bound && value < upper_bound;
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return vitalIsOkay(bpm, 70, 150) && 
          vitalIsOkay(spo2, 90, INT_MAX) &&
          vitalIsOkay(respRate, 30, 95);
}

int main() {
  assert(vitalIsOkay(96, 70, 150) == true);
  assert(vitalIsOkay(50, 30, 95) == true);
  assert(vitalIsOkay(152, 70, 150) == false);
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
