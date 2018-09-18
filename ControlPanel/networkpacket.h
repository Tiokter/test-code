#ifndef NETWORKPACKET_H
#define NETWORKPACKET_H

#include <QByteArray>
#include <QString>

class NetworkPacket : public QByteArray
{
public:

    //Приём данных
    void byByteArray(QByteArray  arr);

    QString tempSpinBox;
    QString humiSpinBox;
    QString gradSpinBox;
    QString pressSpinBox;

    QString getTemp();
    QString getHumi();
    QString getGrad();
    QString getPress();

    bool Button1;
    bool Button2;
    bool Button3;

    bool getButton1();
    bool getButton2();
    bool getButton3();
// ======================================================================
    //Передача данных
    QByteArray toByteArray();

    QString tempLbl;
    QString humiLbl;
    QString gradLbl;
    QString pressLbl;

    void setTemp(QString txt);
    void setHumi(QString txt);
    void setGrad(QString txt);
    void setPress(QString txt);

    bool buttonOn1;
    bool buttonOn2;
    bool buttonOn3;

    void setbuttonOn1(bool ar);
    void setbuttonOn2(bool ar);
    void setbuttonOn3(bool ar);
};

#endif // NETWORKPACKET_H
