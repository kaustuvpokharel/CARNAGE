#include "LoginManager.hpp"

LoginManager::LoginManager(QObject *parent)
{

}

void LoginManager::login(const QString& email, const QString& password)
{
    setLoading(true);
    QUrl url("http://127.0.0.1:8000/login");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject payload;
    payload["email"] = email;
    payload["password"] = password;

    QJsonDocument doc(payload);

    QNetworkReply* reply = manager.post(request, doc.toJson());

    connect(reply, &QNetworkReply::finished, this, [this, reply](){
        setLoading(false);
        if(reply->error() == QNetworkReply::NoError)
        {
            auto json = QJsonDocument::fromJson(reply->readAll()).object();
            currentToken = json["token"].toString();

            if(currentRemembermeStatus)
            {
                saveToken();
            }
            else
            {
                clearToken();
            }
            emit loginSuccessful();
        }
        else
        {
            clearToken();
            emit loginFailed();
        }
        reply->deleteLater();
    });
}

void LoginManager::fetchProfile()
{
    QUrl url("http://127.0.0.1:8000/profile");
    QNetworkRequest request(url);
    request.setRawHeader("Authorization", "Bearer " + currentToken.toUtf8());

    QNetworkReply* reply = manager.get(request);

    connect(reply, &QNetworkReply::finished, this, [this, reply](){
        setLoading(false);
        if(reply->error() == QNetworkReply::NoError)
        {
            auto json = QJsonDocument::fromJson(reply->readAll()).object();
            QString user = json["user"].toString();
            QString email = json["email"].toString();

            emit loginSuccessful();
            emit profileFetchSuccessful(user, email);
            clearToken();

        }
        else
        {
            emit profileFetchFailed();
        }
        reply->deleteLater();
    });
}

bool LoginManager::loading()
{
    return currentLoadingStatus;
}

void LoginManager::setLoading(bool value)
{
    if(currentLoadingStatus != value)
    {
        currentLoadingStatus = value;
        emit loadingChanged();
    }
}

bool LoginManager::remember()
{
    return currentRemembermeStatus;
}

void LoginManager::setRemember(bool value)
{
    if(currentRemembermeStatus != value)
    {
        currentRemembermeStatus = value;
        emit rememberChanged();
    }
}

void LoginManager::saveToken()
{
    QSettings setting;
    setting.setValue("auth/token", currentToken);
}

void LoginManager::loadToken()
{
    QSettings setting;
    currentToken = setting.value("auth/token", "").toString();
}

void LoginManager::clearToken()
{
    QSettings setting;
    setting.remove("auth/token");
}

void LoginManager::tryAutoLogin()
{
    loadToken();
    if(!currentToken.isEmpty())
    {
        fetchProfile();
    }
}





