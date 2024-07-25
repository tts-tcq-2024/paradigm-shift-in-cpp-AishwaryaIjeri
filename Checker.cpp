#include <iostream>
#include <cassert>

enum class BatteryStatus {
    OK,
    TEMPERATURE_OUT_OF_RANGE,
    STATE_OF_CHARGE_OUT_OF_RANGE,
    CHARGE_RATE_OUT_OF_RANGE
};

// Function to check temperature range
BatteryStatus checkTemperature(float temperature) {
    if (temperature < 0 || temperature > 45) {
        std::cout << "Temperature out of limit!\n";
        return BatteryStatus::TEMPERATURE_OUT_OF_RANGE;
    } 
    else {
    return BatteryStatus::OK;}
}

// Function to check state of charge range
BatteryStatus checkStateOfCharge(float soc) {
    if (soc < 20 || soc > 80) {
        std::cout << "State of Charge out of range!\n";
        return BatteryStatus::STATE_OF_CHARGE_OUT_OF_RANGE;
    } 
    else{
    return BatteryStatus::OK;}
}

// Function to check charge rate range
BatteryStatus checkChargeRate(float chargeRate) {
    if (chargeRate > 0.8) {
        std::cout << "Charge Rate above maximum limit!\n";
        return BatteryStatus::CHARGE_RATE_OUT_OF_RANGE_HIGH;
    }
    return BatteryStatus::OK;
}

// Function to integrate all checks and determine overall battery status
BatteryStatus checkBattery(float temperature, float soc, float chargeRate) {
    BatteryStatus tempStatus = checkTemperature(temperature);
    BatteryStatus socStatus = checkStateOfCharge(soc);
    BatteryStatus chargeRateStatus = checkChargeRate(chargeRate);

    if (tempStatus != BatteryStatus::OK) {
        return tempStatus;
    } else if (socStatus != BatteryStatus::OK) {
        return socStatus;
    } else if (chargeRateStatus != BatteryStatus::OK) {
        return chargeRateStatus;
    }

    return BatteryStatus::OK;
}

int main() {
    // Test cases using assertions
    assert(checkBattery(25, 70, 0.7) == BatteryStatus::OK);
    assert(checkBattery(-5, 70, 0.7) == BatteryStatus::TEMPERATURE_OUT_OF_RANGE);
    assert(checkBattery(50, 85, 0) == BatteryStatus::TEMPERATURE_OUT_OF_RANGE);
    assert(checkBattery(25, 10, 0.7) == BatteryStatus::STATE_OF_CHARGE_OUT_OF_RANGE);
    assert(checkBattery(25, 90, 0.7) == BatteryStatus::STATE_OF_CHARGE_OUT_OF_RANGE);
    assert(checkBattery(25, 70, 0.9) == BatteryStatus::CHARGE_RATE_OUT_OF_RANGE);
    return 0;
}
