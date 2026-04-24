#pragma once

#include <QByteArray>
#include <QString>

class ITransport
{
public:
    virtual ~ITransport() = default;
    virtual bool open(const QString& endpoint, int baudRate) = 0;
    virtual void close() = 0;
    virtual bool write(const QByteArray& data) = 0;
    virtual bool isOpen() const = 0;
};
