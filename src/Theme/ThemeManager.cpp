#include "ThemeManager.hpp"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

ThemeManager* ThemeManager::instance() {
    static ThemeManager inst;
    return &inst;
}

ThemeManager::ThemeManager(QObject* parent) : QObject(parent) {
    loadTheme("CarnageDark");
    qDebug() << "[ThemeManager] Loaded theme:" << m_currentTheme << m_flatPalette.keys();
}

QString ThemeManager::currentTheme() const {
    return m_currentTheme;
}

void ThemeManager::setTheme(const QString& name) {
    loadTheme(name);
    emit themeChanged();
}

QVariantMap ThemeManager::flatPalette() const {
    return m_flatPalette;
}

void ThemeManager::loadTheme(const QString& name) {
    QFile file(":/themes/themes/"+ name + ".json");

    if (!file.open(QIODevice::ReadOnly))
        return;

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QVariantMap theme = doc.object().toVariantMap()["theme"].toMap();

    m_flatPalette = flatten(theme);
    m_currentTheme = name;
}

QVariantMap ThemeManager::flatten(const QVariantMap& input, const QString& prefix) const {
    QVariantMap flat;
    for (auto it = input.begin(); it != input.end(); ++it) {
        QString key = prefix.isEmpty() ? it.key() : prefix + "." + it.key();
        if (it.value().typeId() == QMetaType::QVariantMap || it.value().type() == QVariant::Map) {
            QVariantMap nested = flatten(it.value().toMap(), key);
            for (auto nestedIt = nested.begin(); nestedIt != nested.end(); ++nestedIt) {
                flat.insert(nestedIt.key(), nestedIt.value());
            }
        } else {
            flat.insert(key, it.value());
        }
    }
    return flat;
}
