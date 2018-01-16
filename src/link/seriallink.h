#pragma once

#include <QSerialPort>
#include <QSerialPortInfo>

#include "abstractlink.h"

class SerialLink : public AbstractLink, QSerialPort, QSerialPortInfo
{

public:
    SerialLink();
    ~SerialLink();

    bool isOpen() final { return isWritable() && isReadable(); };
    bool setConfiguration(const QString& arg) final;
    bool startConnection() final { return open(QIODevice::ReadWrite); };
    bool finishConnection() final;
    QStringList listAvailableConnections() final;
};