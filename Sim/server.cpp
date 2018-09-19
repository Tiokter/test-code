#include "server.h"

server::server() : state(false)
{
    socket = NULL;
}
server::~server(){}

void server::startServer()
{
    if (this->listen(QHostAddress::Any, 33333))
    {
        qDebug() << "Listening";
    }
    else
    {
        qDebug() << "Not Listening";
    }
}
//новое соединение
void server::incomingConnection(int socketDescriptor)
{
    socket = new QTcpSocket(this);                                  //новый сокет
    socket->setSocketDescriptor(socketDescriptor);                  //задание инд.номера сокету

    state = true;
    connect(socket,SIGNAL(readyRead()),this,SLOT(sockReady()));     //сигнал о готовности чтения
    connect(socket,SIGNAL(disconnected()),this,SLOT(sockDisk()));   //сигнал отсоединения
    emit connected();                                               //сигнал о появлении соединения
/*проверка соединения
    qDebug()<< socket->isValid ();
    qDebug()<< socket->localAddress ();
    qDebug()<< socket->localPort ();
    qDebug()<< socket->peerAddress ();
    qDebug()<< socket->peerName ();
    qDebug()<< socket->peerPort ();
*/
    qDebug() << socketDescriptor << "Client connected";
}
void server::sockReady()
{
    socket-> waitForReadyRead(500);
    data = socket->readAll();
    emit packReady(data);
}
//метод записи в сокет "массива байтов"
void server::sockWrite(QByteArray xzc)
{

    if (!state) return;
    if (socket != NULL)
    {

        socket->write(xzc);
        socket->waitForBytesWritten(500);
    }
}
//метод отсоединения
void server::sockDisk()
{
    qDebug() << "Disconnect";
    state = false;
    socket->deleteLater();
}
