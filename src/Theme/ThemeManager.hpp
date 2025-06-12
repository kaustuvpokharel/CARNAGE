#pragma once

#include <QObject>
#include <QVariantMap>
#include <QSet>

class ThemeManager : public QObject {
    Q_OBJECT

public:
    static ThemeManager* instance();

    QString currentTheme() const;
    QVariantMap flatPalette() const;

    void setTheme(const QString& name);

    QString fontForWeight(const QString& family, int weight) const;

signals:
    void themeChanged();

private:
    explicit ThemeManager(QObject* parent = nullptr);

    void loadTheme(const QString& name);
    QVariantMap flatten(const QVariantMap& input, const QString& prefix = QString()) const;
    void loadFontsFromSet(const QSet<QString>& families);

    QString m_currentTheme;
    QVariantMap m_flatPalette;
};
