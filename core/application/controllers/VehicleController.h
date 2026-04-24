#pragma once

#include <QObject>

class LinkSession;
class TelemetryService;
class CommandService;

class VehicleController : public QObject
{
    Q_OBJECT
public:
    VehicleController(LinkSession* session,
                      TelemetryService* telemetryService,
                      CommandService* commandService,
                      QObject* parent = nullptr);

    bool connectVehicle(const QString& portName, int baudRate);
    void disconnectVehicle();
    bool sendHeartbeat();
    bool setAltitude(double altitudeM);
    bool isConnected() const;

signals:
    void connectionStateChanged(bool connected);

private:
    LinkSession* session_;
    TelemetryService* telemetryService_;
    CommandService* commandService_;
};
