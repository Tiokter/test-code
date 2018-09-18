#ifndef NETWORKPACKET_H
#define NETWORKPACKET_H

#include <QByteArray>
#include <QString>

class NetworkPacket : public QByteArray
{
public:

    //ѕередача данных
    //метод упаковки в "массив байтов"
    QByteArray toByteArray();

    QString tempSpinBox;
    QString humiSpinBox;
    QString gradSpinBox;
    QString pressSpinBox;
    //методы вз€ти€ текста из полей
    void setTemp(QString txt);
    void setHumi(QString txt);
    void setGrad(QString txt);
    void setPress(QString txt);

    bool Button1;
    bool Button2;
    bool Button3;
    //методы вз€ти€ значени€ кнопок из полей
    void setButton1(bool ar);
    void setButton2(bool ar);
    void setButton3(bool ar);

    // ======================================================================

    //ѕриЄм данных
    void byByteArray(QByteArray  arr);

    QString tempLbl;
    QString humiLbl;
    QString gradLbl;
    QString pressLbl;

    QString getTemp();
    QString getHumi();
    QString getGrad();
    QString getPress();

    bool buttonOn1;
    bool buttonOn2;
    bool buttonOn3;

    bool getbuttonOn1();
    bool getbuttonOn2();
    bool getbuttonOn3();


};

#endif // NETWORKPACKET_H
