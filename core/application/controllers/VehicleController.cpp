#include "core/application/controllers/VehicleController.h"

#include "core/communication/session/LinkSession.h"
#include "core/services/TelemetryService.h"
#include "core/services/CommandService.h"

VehicleController::VehicleController(LinkSession* session,
                                     TelemetryService* telemetryService,
                                     CommandService* commandService,
                                     QObject* parent)
    : QObject(parent),
      session_(session),
      telemetryService_(telemetryService),
      commandService_(commandService)
{
    QObject::connect(session_, &LinkSession::telemetryReceived,
                     telemetryService_, &TelemetryService::updateSnapshot);
    QObject::connect(session_, &LinkSession::connectionChanged,
                     this, &VehicleController::connectionStateChanged);
}

bool VehicleController::connectVehicle(const QString& portName, int baudRate)
{
    return session_->connectToVehicle(portName, baudRate);
}

void VehicleController::disconnectVehicle()
{
    session_->disconnectFromVehicle();
}

bool VehicleController::sendHeartbeat()
{
    return commandService_->sendHeartbeat();
}

bool VehicleController::setAltitude(double altitudeM)
{
    return commandService_->setAltitude(altitudeM);
}

bool VehicleController::isConnected() const
{
    return session_->isConnected();
}
