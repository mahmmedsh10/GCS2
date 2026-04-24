#include "core/communication/session/LinkSession.h"

#include "core/communication/transport/ITransport.h"
#include "core/communication/transport/SerialTransport.h"
#include "core/communication/protocol/IProtocol.h"

LinkSession::LinkSession(ITransport* transport, IProtocol* protocol, QObject* parent)
    : QObject(parent), transport_(transport), protocol_(protocol)
{
    if (auto* serial = dynamic_cast<SerialTransport*>(transport_)) {
        QObject::connect(serial, &SerialTransport::bytesReceived, this, &LinkSession::handleBytes);
    }
}

bool LinkSession::connectToVehicle(const QString& portName, int baudRate)
{
    const bool ok = transport_->open(portName, baudRate);
    emit connectionChanged(ok);
    return ok;
}

void LinkSession::disconnectFromVehicle()
{
    transport_->close();
    emit connectionChanged(false);
}

bool LinkSession::sendHeartbeat()
{
    return transport_->write(protocol_->encodeHeartbeat());
}

bool LinkSession::sendSetAltitude(double altitudeM)
{
    return transport_->write(protocol_->encodeSetAltitude(altitudeM));
}

bool LinkSession::isConnected() const
{
    return transport_->isOpen();
}

void LinkSession::handleBytes(const QByteArray& data)
{
    TelemetrySnapshot snapshot;
    if (protocol_->tryParseTelemetry(data, snapshot)) {
        emit telemetryReceived(snapshot);
    }
}
