// #pragma once

#include <QObject>
#include <QQmlEngine>
#include <Logger.hpp>
#include <QStringList>
#include <map>
#include "PacketSniffer.hpp"
#include "ThemeManager.hpp"
#include "LoginManager.hpp"

class AppController: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantMap interfaces READ interfaces NOTIFY interfacesChanged FINAL)
    Q_PROPERTY(QVariantMap palette READ palette NOTIFY themeChanged FINAL)
    Q_PROPERTY(bool remember READ remember WRITE setRemember NOTIFY rememberChanged FINAL)

public:
    explicit AppController(QObject* parent = nullptr);
    ~AppController() = default;

    QVariantMap interfaces() const;
    QVariantMap palette() const;
    bool remember();
    Q_INVOKABLE void setRemember(bool value);

    Q_INVOKABLE void getInterface();
    Q_INVOKABLE void login(const QString& email, const QString& password);
    Q_INVOKABLE void tryAutoLogin();
    //Q_INVOKABLE void startCapture(const QString& interfaceName);


signals:
    void interfacesChanged();
    void themeChanged();
    void loginSuccessful();
    void rememberChanged();


private:
    QVariantMap m_interfaces;
    Sniffer::PacketSniffer m_sniffer;
    LoginManager loginManager;
};
