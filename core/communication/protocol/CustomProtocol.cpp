#include "core/communication/protocol/CustomProtocol.h"

#include <QtEndian>

QByteArray CustomProtocol::encodeHeartbeat() const
{
    return QByteArray::fromHex("7396C80000000000");
}

QByteArray CustomProtocol::encodeSetAltitude(double altitudeM) const
{
    QByteArray bytes(8, '\0');
    bytes[0] = static_cast<char>(0x73);
    bytes[1] = static_cast<char>(0x96);
    bytes[2] = static_cast<char>(0x10);

    const quint16 scaled = static_cast<quint16>(altitudeM);
    bytes[3] = static_cast<char>((scaled >> 8) & 0xFF);
    bytes[4] = static_cast<char>(scaled & 0xFF);

    quint8 checksum = 0;
    for (int i = 0; i < 7; ++i) {
        checksum += static_cast<quint8>(bytes[i]);
    }
    bytes[7] = static_cast<char>(checksum);
    return bytes;
}

bool CustomProtocol::tryParseTelemetry(const QByteArray& raw, TelemetrySnapshot& snapshot) const
{
    if (raw.size() < 8) {
        return false;
    }

    if (static_cast<quint8>(raw[0]) != 0x73 || static_cast<quint8>(raw[1]) != 0x96) {
        return false;
    }

    snapshot.aircraft.connected = true;
    snapshot.aircraft.altitude_m = static_cast<quint8>(raw[3]);
    snapshot.aircraft.airspeed_mps = static_cast<quint8>(raw[4]) / 10.0;
    snapshot.aircraft.roll_deg = static_cast<qint8>(raw[5]);
    snapshot.aircraft.pitch_deg = static_cast<qint8>(raw[6]);
    return true;
}
