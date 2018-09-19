#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "NetworkPacket.h"
#include "MyClient.h"
#include <QtXml>
#include <QStyleFactory>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    void scene_update();

private slots:

    //слот упаковщика всех данных из пакета в поля
    void fromSimPac(const QByteArray &pack);

    //слот упаковщика всех данных из полей в пакет
    void CopPac();

    //Повышение температуры
    void on_buttonTempUp_clicked();

    //Понижение температуры
    void on_buttonTempDown_clicked();

    //Повышение угла подачи воздуха
    void on_buttonGradUp_clicked();

    //Понижение угла подачи воздуха
    void on_buttonGradDown_clicked();

    //изменение отображения статуса работы кондиционера (цвета блока 1-3)
    void on_buttonOn1_toggled(bool checked);
    void on_buttonOn2_toggled(bool checked);
    void on_buttonOn3_toggled(bool checked);

    //метод  сохранения всех данных в XML
    void onSave();

    //метод  загрузки всех данных из XML
    void onLoad();

    //перевод в градусы Фаренгейта
    void on_action_toFaren_triggered();

    //перевод в градусы Цельсия
    void on_action_toCelsi_triggered();

    //перевод в Кельвины
    void on_action_toKelv_triggered();

    //перевод в мм.рт.ст.
    void on_action_toMm_triggered();

    //перевод в Паскали
    void on_action_toPascal_triggered();

    // Слот обработчик клика кнопки для установки тёмного или светлого оформления
    void on_darkPushButton_toggled(bool checked);

private:
    Ui::MainWindow *ui;

    //Имена сцены и 3х прямоугольников
    QGraphicsScene *scene;
    QGraphicsRectItem *rect;
    QGraphicsRectItem *rect2;
    QGraphicsRectItem *rect3;

    MyClient client;

    //Пакет для упаковки данных в сокет
    NetworkPacket packet;
};
#endif // MAINWINDOW_H
