#include <iostream>
#include <cassert>

using namespace std;

enum BatteryStatus {
    OK,
    TEMPERATURE_OUT_OF_RANGE,
    STATE_OF_CHARGE_OUT_OF_RANGE,
    CHARGE_RATE_OUT_OF_RANGE
};

BatteryStatus checkBattery(float temperature, float soc, float chargeRate) {
    if (temperature < 0 || temperature > 45) {
        cout << "Temperature out of range!\n";
        return TEMPERATURE_OUT_OF_RANGE;
    } else if (soc < 20 || soc > 80) {
        cout << "State of Charge out of range!\n";
        return STATE_OF_CHARGE_OUT_OF_RANGE;
    } else if (chargeRate > 0.8) {
        cout << "Charge Rate out of range!\n";
        return CHARGE_RATE_OUT_OF_RANGE;
    }

    return OK;
}

int main() {
    assert(checkBattery(25, 70, 0.7) == OK);
    assert(checkBattery(50, 85, 0) == TEMPERATURE_OUT_OF_RANGE);
}
