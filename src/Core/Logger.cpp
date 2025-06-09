#include "Logger.hpp"


Core::Logger::Logger() : m_stream(&m_logFile) {}

Core::Logger::~Logger() {
    if (m_logFile.isOpen())
        m_logFile.close();
}

Core::Logger& Core::Logger::instance() {
    static Core::Logger instance;
    return instance;
}

void Core::Logger::setLogFile(const QString& filePath) {
    QDir().mkpath(QFileInfo(filePath).absolutePath());
    m_logFile.setFileName(filePath);
    if (!m_logFile.open(QIODevice::Append | QIODevice::Text)) {
        qWarning("Could not open log file: %s", qPrintable(filePath));
    }
}

void Core::Logger::enableConsoleOutput(bool enabled) {
    m_consoleOutputEnabled = enabled;
}

QString Core::Logger::levelToString(Level level) const {
    switch (level) {
    case Level::Debug:    return "DEBUG";
    case Level::Info:     return "INFO";
    case Level::Warning:  return "WARN";
    case Level::Error:    return "ERROR";
    case Level::Critical: return "CRITICAL";
    default:              return "UNKNOWN";
    }
}

void Core::Logger::log(const QString& message, Level level) {
    QMutexLocker locker(&m_mutex);

    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString output = QString("%1 [%2] %3").arg(timestamp, levelToString(level), message);

    if (m_logFile.isOpen()) {
        m_stream << output << "\n";
        m_stream.flush();
    }

    if (m_consoleOutputEnabled) {
        fprintf(stdout, "%s\n", output.toUtf8().constData());
        fflush(stdout);
    }
}
