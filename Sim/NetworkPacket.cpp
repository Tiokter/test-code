#include "NetworkPacket.h"
#include <QString>
#include <QDebug>

//Передача данных
//метод  упаковщика данных в "массив байтов"
QByteArray NetworkPacket::toByteArray()
{
      QByteArray  arr;

      QDataStream out(&arr, QIODevice::WriteOnly);
      out.setVersion(QDataStream::Qt_4_2);
      out << tempSpinBox
          << humiSpinBox
          << gradSpinBox
          << pressSpinBox
          << Button1
          << Button2
          << Button3;
      return arr;
}
//методы  взятия текста из спинБоксов и значений с кнопок
void NetworkPacket::setTemp(QString txt)
{
    tempSpinBox = txt;
    qDebug()<< tempSpinBox;
}
void NetworkPacket::setHumi(QString txt)
{
    humiSpinBox = txt;
    qDebug()<< humiSpinBox;
}
void NetworkPacket::setGrad(QString txt)
{
    gradSpinBox = txt;
    qDebug()<< gradSpinBox;
}
void NetworkPacket::setPress(QString txt)
{
    pressSpinBox = txt;
    qDebug()<< pressSpinBox;
}
void NetworkPacket::setButton1(bool ar)
{
    Button1 = ar;
    qDebug()<< Button1;
}
void NetworkPacket::setButton2(bool ar)
{
    Button2 = ar;
    qDebug()<< Button2;
}
void NetworkPacket::setButton3(bool ar)
{
    Button3 = ar;
    qDebug()<< Button3;
}

// ======================================================================
void NetworkPacket::byByteArray(QByteArray  ar)
{
    QDataStream in(&ar, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_4_2);
    in  >> tempLbl
        >> humiLbl
        >> gradLbl
        >> pressLbl
        >> buttonOn1
        >> buttonOn2
        >> buttonOn3;
}
// ======================================================================
//методы взятия значений полей и кнопок
QString NetworkPacket::getTemp()
{
    return tempLbl;
}
QString NetworkPacket::getHumi()
{
    return humiLbl;
}
QString NetworkPacket::getGrad()
{
    return gradLbl;
}
QString NetworkPacket::getPress()
{
    return pressLbl;
}
bool NetworkPacket::getbuttonOn1()
{
   return buttonOn1;
}
bool NetworkPacket::getbuttonOn2()
{
   return buttonOn2;
}
bool NetworkPacket::getbuttonOn3()
{
   return buttonOn3;
}
