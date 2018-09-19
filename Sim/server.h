#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork>
#include <QTcpSocket>
#include <QTcpServer>
#include <QByteArray>

class server : public QTcpServer
{
    Q_OBJECT

public:
    server();
    ~server();

    QTcpSocket *socket;
    QByteArray data;

private:

    bool state;

public slots:

    void startServer();                             //старт сертвера
    void incomingConnection(int socketDescriptor);  //новое соединение
    void sockReady();                               //готовность к чтения сокета
    void sockWrite(QByteArray);                     //запись сокета
    void sockDisk();                                //отсоединение сокета

signals:

    void packReady(QByteArray);

    void connected();                               //сигнал о новом подсоединении клиента
};

#endif // SERVER_H
