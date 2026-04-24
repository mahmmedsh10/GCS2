#pragma once

#include "core/communication/transport/ITransport.h"

#include <QObject>
#include <QSerialPort>

class SerialTransport : public QObject, public ITransport
{
    Q_OBJECT
public:
    explicit SerialTransport(QObject* parent = nullptr);

    bool open(const QString& endpoint, int baudRate) override;
    void close() override;
    bool write(const QByteArray& data) override;
    bool isOpen() const override;

signals:
    void bytesReceived(const QByteArray& data);
    void linkError(const QString& message);

private slots:
    void onReadyRead();

private:
    QSerialPort serial_;
};
