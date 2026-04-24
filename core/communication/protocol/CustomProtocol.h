#pragma once

#include "core/communication/protocol/IProtocol.h"

class CustomProtocol : public IProtocol
{
public:
    QByteArray encodeHeartbeat() const override;
    QByteArray encodeSetAltitude(double altitudeM) const override;
    bool tryParseTelemetry(const QByteArray& raw, TelemetrySnapshot& snapshot) const override;
};
