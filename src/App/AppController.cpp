#include "AppController.h"

AppController::AppController(QObject* parent) : QObject(parent) {
    getInterface(); // auto-load on boot]
    connect(ThemeManager::instance(), &ThemeManager::themeChanged, this, &AppController::themeChanged);
    connect(&loginManager, &LoginManager::loginSuccessful, this, &AppController::loginSuccessful);
    connect(&loginManager, &LoginManager::rememberChanged, this, &AppController::rememberChanged);
}

QStringList AppController::interfaces() const {
    return m_interfaces;
}

void AppController::getInterface() {
    std::vector<std::string> raw = m_sniffer.getInterfaces();
    QStringList result;
    for (const auto& iface : raw)
        result << QString::fromStdString(iface);

    m_interfaces = result;
    emit interfacesChanged();
}

void AppController::login(const QString &email, const QString &password)
{
    loginManager.login(email, password);
}

void AppController::tryAutoLogin()
{
    loginManager.tryAutoLogin();
}

QVariantMap AppController::palette() const {
    return ThemeManager::instance()->flatPalette();
}

bool AppController::remember()
{
    return loginManager.remember();
}

void AppController::setRemember(bool value)
{
    return loginManager.setRemember(value);
}



// void AppController::startCapture(const QString& interfaceName) {
//     // convert to std::string and pass to PacketSniffer
//     m_sniffer.s({interfaceName.toStdString()});
// }
