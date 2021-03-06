#ifndef FACEMASH2_MYCLIENT_H
#define FACEMASH2_MYCLIENT_H

#include <QtNetwork/QtNetwork>
#include <QtWidgets>

namespace clientnetwork
{
struct Photo;

struct Group;

struct User;

class MyClient : public QObject
{
Q_OBJECT

private:
    QTcpSocket *_readwritesocket;
    qint64 totalBytes;//总字节数
    qint64 BytesReceived;//已接收字节数

    QString KeepPath;//保存根目录
    //QFile *file;

    //User *_user;
    QByteArray inArray;

    QString UserName;
    //QString _password;

    QString HostIP;

    QMap<QString,double> _map;

    void SavePhotos(User *user);

    //void SaveBigPhoto(User *user);
    void SaveLog(User *user);

    void UpdatePoints(User *user);

private slots:

    void DealWithMessage(User *user);

    void ReceiveMessage();

signals:
	void connected();

    void Received(User*);

    void PhotosSaved(QStringList);

    void LogSaved();

    void PointsUpdated();

public:
    explicit MyClient(QObject *parent = 0);

    ~MyClient();

    void SetPath(const QString &path);

    void SetIP(const QString &hostip);

    void ScorePhoto(const QString &date, const QString &title, double points);

    void LogIn(const QString &username);

    void LogOut();

    void AskforLog();

    void UploadSinglePhoto(const QString &photopath);

    void AskforBigPhoto(const QString &date, const QString &title);

    QSize AskforOneSize(const QString& date, const QString& title);
    
    int AskforOnePoints(const QString& date, const QString& title);

public slots:
    void SetupConnection();

};
}
#endif // FACEMASH2_MYCLIENT_H
