#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QJsonObject>
#include <QJsonDocument>
#include <QSettings>

class LoginManager: public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool loading READ loading WRITE setLoading NOTIFY loadingChanged)
    Q_PROPERTY(bool remember READ remember WRITE setRemember NOTIFY rememberChanged FINAL)

public:
    LoginManager(QObject* parent = nullptr);
    Q_INVOKABLE void login(const QString& email, const QString& password);
    Q_INVOKABLE void fetchProfile();

    bool loading();
    void setLoading(bool value);
    bool remember();
    void setRemember(bool value);
    void tryAutoLogin();

private:
    bool currentLoadingStatus = false;
    bool currentRemembermeStatus = false;
    QNetworkAccessManager manager;
    QString currentToken;
    void saveToken();
    void loadToken();
    void clearToken();

signals:
    void loadingChanged();
    void loginSuccessful();
    void loginFailed();
    void rememberChanged();
    void profileFetchSuccessful(QString user, QString email);
    void profileFetchFailed();
};
