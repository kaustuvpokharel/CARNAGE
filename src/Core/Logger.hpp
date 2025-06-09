#pragma once

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QMutex>
#include <QDir>

#define LOG_INFO(msg)      Core::Logger::instance().log(QString("[%1:%2] ").arg(__FILE__).arg(__LINE__) + msg, Core::Logger::Level::Info)
#define LOG_DEBUG(msg)     Core::Logger::instance().log(QString("[%1:%2] ").arg(__FILE__).arg(__LINE__) + msg, Core::Logger::Level::Debug)
#define LOG_WARN(msg)      Core::Logger::instance().log(QString("[%1:%2] ").arg(__FILE__).arg(__LINE__) + msg, Core::Logger::Level::Warning)
#define LOG_ERROR(msg)     Core::Logger::instance().log(QString("[%1:%2] ").arg(__FILE__).arg(__LINE__) + msg, Core::Logger::Level::Error)
#define LOG_CRITICAL(msg)  Core::Logger::instance().log(QString("[%1:%2] ").arg(__FILE__).arg(__LINE__) + msg, Core::Logger::Level::Critical)

namespace Core {

class Logger
{
public:

    enum class Level
    {
        Debug,
        Info,
        Warning,
        Error,
        Critical
    };

    static Logger& instance();

    void setLogFile(const QString& filePath);
    void enableConsoleOutput(bool enabled);
    void log(const QString& message, Level level = Level::Info);

    private:
    Logger();
    ~Logger();

    QFile m_logFile;
    QTextStream m_stream;
    QMutex m_mutex;
    bool m_consoleOutputEnabled = true;

    QString levelToString(Level level) const;

};

}
