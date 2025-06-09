// #pragma once

#include <QObject>
#include <QQmlEngine>
#include <Logger.hpp>
#include <QStringList>
#include "PacketSniffer.hpp"

class AppController: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList interfaces READ interfaces NOTIFY interfacesChanged FINAL)
public:
    explicit AppController(QObject* parent = nullptr);
    ~AppController() = default;

    QStringList interfaces() const;

    Q_INVOKABLE void getInterface();
    //Q_INVOKABLE void startCapture(const QString& interfaceName);

signals:
    void interfacesChanged();

private:
    QStringList m_interfaces;
    Sniffer::PacketSniffer m_sniffer;
};
