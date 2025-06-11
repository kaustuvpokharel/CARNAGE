#pragma once
#include <QFile>
#include <QObject>
#include <QVariantMap>

class ThemeManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(QVariantMap flatPalette READ flatPalette NOTIFY themeChanged)

public:
    explicit ThemeManager(QObject* parent = nullptr);
    static ThemeManager* instance();
    Q_INVOKABLE void setTheme(const QString& name);
    Q_INVOKABLE QString currentTheme() const;
    QVariantMap flatPalette() const;

signals:
    void themeChanged();

private:
    void loadTheme(const QString& name);
    QVariantMap flatten(const QVariantMap& input, const QString& prefix = "") const;

private:
    QVariantMap m_flatPalette;
    QString m_currentTheme;
};
