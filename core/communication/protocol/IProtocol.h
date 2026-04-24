#pragma once

#include <QByteArray>

#include "core/domain/TelemetrySnapshot.h"

class IProtocol
{
public:
    virtual ~IProtocol() = default;
    virtual QByteArray encodeHeartbeat() const = 0;
    virtual QByteArray encodeSetAltitude(double altitudeM) const = 0;
    virtual bool tryParseTelemetry(const QByteArray& raw, TelemetrySnapshot& snapshot) const = 0;
};
