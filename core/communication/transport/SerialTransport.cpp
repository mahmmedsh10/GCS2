#include "core/communication/transport/SerialTransport.h"

SerialTransport::SerialTransport(QObject* parent)
    : QObject(parent)
{
    QObject::connect(&serial_, &QSerialPort::readyRead, this, &SerialTransport::onReadyRead);
}

bool SerialTransport::open(const QString& endpoint, int baudRate)
{
    if (serial_.isOpen()) {
        serial_.close();
    }

    serial_.setPortName(endpoint);
    serial_.setBaudRate(baudRate);
    return serial_.open(QIODevice::ReadWrite);
}

void SerialTransport::close()
{
    serial_.close();
}

bool SerialTransport::write(const QByteArray& data)
{
    return serial_.write(data) == data.size();
}

bool SerialTransport::isOpen() const
{
    return serial_.isOpen();
}

void SerialTransport::onReadyRead()
{
    emit bytesReceived(serial_.readAll());
}
