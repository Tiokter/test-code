#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QWidget>

#include <QtNetwork>
#include <QTcpSocket>
#include <QObject>
#include <QByteArray>
#include <QDebug>

#include "NetworkPacket.h"
#include "server.h"

#include <QtXml>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QFile>

namespace Ui
{
class Simulator;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    NetworkPacket packet;

    server Server;

    QXmlStreamWriter xmlWriter();
    QXmlStreamReader xmlReader();

private slots:
    //слот на изменение темепературы
    void on_tempSpinBox_valueChanged(const QString &arg1);
    //слот на изменение влажности
    void on_humiSpinBox_valueChanged(const QString &arg1);
    //слот на изменение градуса поврота
    void on_gradSpinBox_valueChanged(const QString &arg1);
    //слот на изменение давлени€
    void on_pressSpinBox_valueChanged(const QString &arg1);

    //слот на изменение положени€ кнопки включени€ Ѕлоков  1-3
    void on_pushButton_1_toggled(bool checked);
    void on_pushButton_2_toggled(bool checked);
    void on_pushButton_3_toggled(bool checked);


    //слот упаковщика всех данных из пакеа в пол€
    void fromCopPac(const QByteArray &pack);

    void onSave();

    void onLoad();

public slots:
    //слот упаковщика всех данных из полей в пакет
    void SimPac();

private:

    Ui::Simulator *ui;
    //слот на сохраненние в XML

signals:

};

#endif // MAINWINDOW_H
