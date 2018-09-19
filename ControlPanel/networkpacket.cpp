#include "networkpacket.h"
#include <QString>
#include <QDebug>


//Приём данных
void NetworkPacket::byByteArray(QByteArray  arr)
{
    QDataStream in(&arr, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_4_2);
    in  >> tempSpinBox
        >> humiSpinBox
        >> gradSpinBox
        >> pressSpinBox
        >> Button1
        >> Button2
        >> Button3;
}
// ======================================================================
//методы взятия значений полей и кнопок из пакета
QString NetworkPacket::getTemp()
{
    return tempSpinBox;
}
QString NetworkPacket::getHumi()
{
    return humiSpinBox;
}
QString NetworkPacket::getGrad()
{
    return gradSpinBox;
}
QString NetworkPacket::getPress()
{
    return pressSpinBox;
}
bool NetworkPacket::getButton1()
{
   return Button1;
}
bool NetworkPacket::getButton2()
{
   return Button2;
}
bool NetworkPacket::getButton3()
{
   return Button3;
}

// ======================================================================
//метод  упаковщика данных в "массив байтов"
QByteArray NetworkPacket::toByteArray()
{
      QByteArray  arr;

      QDataStream out(&arr, QIODevice::WriteOnly);
      out.setVersion(QDataStream::Qt_4_2);
      out << tempLbl
          << humiLbl
          << gradLbl
          << pressLbl
          << buttonOn1
          << buttonOn2
          << buttonOn3;
      return arr;
}
//методы  взятия текста из лэйблов и значений с кнопок
void NetworkPacket::setTemp(QString txt)
{
    tempLbl = txt;
    qDebug()<< tempLbl;
    //emit PR(toByteArray());
}
void NetworkPacket::setHumi(QString txt)
{
    humiLbl = txt;
    qDebug()<< humiLbl;
}
void NetworkPacket::setGrad(QString txt)
{
    gradLbl = txt;
    qDebug()<< gradLbl;
}
void NetworkPacket::setPress(QString txt)
{
    pressLbl = txt;
    qDebug()<< pressLbl;
}
void NetworkPacket::setbuttonOn1(bool ar)
{
    buttonOn1 = ar;
    qDebug()<< buttonOn1;
}
void NetworkPacket::setbuttonOn2(bool ar)
{
    buttonOn2 = ar;
    qDebug()<< buttonOn2;
}
void NetworkPacket::setbuttonOn3(bool ar)
{
    buttonOn3 = ar;
    qDebug()<< buttonOn3;
}
