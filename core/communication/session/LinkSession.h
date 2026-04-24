#pragma once

#include <QObject>

#include "core/domain/TelemetrySnapshot.h"

class ITransport;
class IProtocol;
class SerialTransport;

class LinkSession : public QObject
{
    Q_OBJECT
public:
    explicit LinkSession(ITransport* transport, IProtocol* protocol, QObject* parent = nullptr);

    bool connectToVehicle(const QString& portName, int baudRate);
    void disconnectFromVehicle();
    bool sendHeartbeat();
    bool sendSetAltitude(double altitudeM);
    bool isConnected() const;

signals:
    void telemetryReceived(const TelemetrySnapshot& snapshot);
    void connectionChanged(bool connected);

private slots:
    void handleBytes(const QByteArray& data);

private:
    ITransport* transport_;
    IProtocol* protocol_;
};
