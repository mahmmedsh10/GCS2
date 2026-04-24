#pragma once

#include "core/domain/FlightMode.h"

struct AircraftState {
    double latitude_deg = 0.0;
    double longitude_deg = 0.0;
    double altitude_m = 0.0;
    double airspeed_mps = 0.0;
    double roll_deg = 0.0;
    double pitch_deg = 0.0;
    double yaw_deg = 0.0;
    bool connected = false;
    FlightMode flight_mode = FlightMode::Unknown;
};
