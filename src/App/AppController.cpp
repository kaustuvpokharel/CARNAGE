#include "AppController.h"

AppController::AppController(QObject* parent) : QObject(parent) {
    getInterface(); // auto-load on boot]
    connect(ThemeManager::instance(), &ThemeManager::themeChanged, this, &AppController::themeChanged);
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

QVariantMap AppController::palette() const {
    return ThemeManager::instance()->flatPalette();
}


// void AppController::startCapture(const QString& interfaceName) {
//     // convert to std::string and pass to PacketSniffer
//     m_sniffer.s({interfaceName.toStdString()});
// }
