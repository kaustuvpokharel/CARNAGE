#include "ThemeManager.hpp"
#include <QFile>
#include <QJsonDocument>
#include <QFontDatabase>
#include <QJsonObject>
#include <QDebug>

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
    QFile file(":/themes/themes/" + name + ".json");
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open theme JSON:" << name;
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QVariantMap theme = doc.object().toVariantMap()["theme"].toMap();

    m_flatPalette = flatten(theme);
    m_currentTheme = name;

    // Parse and load required fonts
    QVariantMap typographyMap = theme["typography"].toMap();
    QVariantMap fontFamilyMap = typographyMap["fontFamily"].toMap();

    QSet<QString> requiredFonts;
    for (const QVariant& fontList : std::as_const(fontFamilyMap)) {
        for (const QString& fontName : fontList.toStringList()) {
            requiredFonts.insert(fontName);
        }
    }

    loadFontsFromSet(requiredFonts);
}

QVariantMap ThemeManager::flatten(const QVariantMap& input, const QString& prefix) const {
    QVariantMap flat;
    for (auto it = input.begin(); it != input.end(); ++it) {
        QString key = prefix.isEmpty() ? it.key() : prefix + "." + it.key();
        if (it.value().typeId() == QMetaType::QVariantMap || it.value().typeId() == QMetaType::Type()) {
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

void ThemeManager::loadFontsFromSet(const QSet<QString>& families) {
    QMap<QString, QStringList> fontFiles = {
        {"Inter 28pt", {
                      ":/fonts/fonts/Inter_28pt-Regular.ttf",
                      ":/fonts/fonts/Inter_28pt-Medium.ttf",
                      ":/fonts/fonts/Inter_28pt-SemiBold.ttf",
                      ":/fonts/fonts/Inter_28pt-Bold.ttf"
                  }},
        {"Ubuntu", {
                               ":/fonts/fonts/Ubuntu-Light.ttf",
                               ":/fonts/fonts/Ubuntu-Regular.ttf",
                               ":/fonts/fonts/Ubuntu-Medium.ttf",
                               ":/fonts/fonts/Ubuntu-Bold.ttf"
                           }}
    };

    for (const QString& family : families) {
        if (!fontFiles.contains(family))
            continue;

        for (const QString& path : std::as_const(fontFiles[family])) {
            int id = QFontDatabase::addApplicationFont(path);
            if (id != -1) {
                QStringList loadedFamilies = QFontDatabase::applicationFontFamilies(id);
                qDebug() << "Loaded font:" << loadedFamilies.join(", ") << "from" << path;
            } else {
                qWarning() << "Failed to load font from:" << path;
            }
        }
    }
}
