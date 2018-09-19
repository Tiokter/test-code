#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Simulator)
{
    connect(&Server,SIGNAL(connected()),this,SLOT(SimPac()));
    connect(&Server,SIGNAL(packReady(QByteArray)),this,SLOT(fromCopPac(const QByteArray &)));

    Server.startServer();

    ui->setupUi(this);
    onLoad();
    setWindowTitle("Condi simulator");
}
MainWindow::~MainWindow()
{
    onSave();
    delete ui;
}
//метод реагирующий на изменение значения спинБокса температуры
void MainWindow::on_tempSpinBox_valueChanged(const QString &arg1)
{
    packet.setTemp(ui->tempSpinBox-> text());   //запись изменения в пакет
    Server.sockWrite(packet.toByteArray());     //запись в сокет изменения в виде массива байтов
}
//метод реагирующий на изменение значения спинБокса влажности
void MainWindow::on_humiSpinBox_valueChanged(const QString &arg1)
{
    packet.setHumi(ui->humiSpinBox-> text());
    Server.sockWrite(packet.toByteArray());
}
//метод реагирующий на изменение значения спинБокса градуса поворота
void MainWindow::on_gradSpinBox_valueChanged(const QString &arg1)
{
    packet.setGrad(ui->gradSpinBox-> text());
    Server.sockWrite(packet.toByteArray());
}
//метод реагирующий на изменение значения спинБокса давления
void MainWindow::on_pressSpinBox_valueChanged(const QString &arg1)
{
    packet.setPress(ui->pressSpinBox-> text());
    Server.sockWrite(packet.toByteArray());
}
//метод реагирующий на изменение значения нажатия кнопки Блок1
void MainWindow::on_pushButton_1_toggled(bool checked)
{
    packet.setButton1(ui->pushButton_1-> isChecked());
    Server.sockWrite(packet.toByteArray());
}
//метод реагирующий на изменение значения нажатия кнопки Блок2
void MainWindow::on_pushButton_2_toggled(bool checked)
{
    packet.setButton2(ui->pushButton_2-> isChecked());
    Server.sockWrite(packet.toByteArray());
}
//метод реагирующий на изменение значения нажатия кнопки Блок3
void MainWindow::on_pushButton_3_toggled(bool checked)
{
    packet.setButton3(ui->pushButton_3-> isChecked());
    Server.sockWrite(packet.toByteArray());
}
// ======================================================================
//Передача значений отображаемых параметров от клиента(панели управления)
void MainWindow::fromCopPac(const QByteArray &pack)
{
    packet.byByteArray(pack);

    ui->tempSpinBox->blockSignals(true);
    ui->tempSpinBox->setValue(packet.getTemp().toDouble());
    ui->tempSpinBox->blockSignals(false);

    ui->humiSpinBox->blockSignals(true);
    ui->humiSpinBox->setValue(packet.getHumi().toDouble());
    ui->humiSpinBox->blockSignals(false);

    ui->gradSpinBox->blockSignals(true);
    ui->gradSpinBox->setValue(packet.getGrad().toDouble());
    ui->gradSpinBox->blockSignals(false);

    ui->pressSpinBox->blockSignals(true);
    ui->pressSpinBox->setValue(packet.getPress().toDouble());
    ui->pressSpinBox->blockSignals(false);

    ui->pushButton_1->blockSignals(true);
    ui->pushButton_1->setChecked(packet.getbuttonOn1());
    ui->pushButton_1->blockSignals(false);

    ui->pushButton_2->blockSignals(true);
    ui->pushButton_2-> setChecked(packet.getbuttonOn2());
    ui->pushButton_2->blockSignals(false);

    ui->pushButton_3->blockSignals(true);
    ui->pushButton_3->setChecked(packet.getbuttonOn3());
    ui->pushButton_3->blockSignals(false);
}
// ======================================================================
//метод  сохранения всех данных в XML
void MainWindow::onSave()
{
    QFile file("D:/Condi/Sim/Sim/SimXML.xml");
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("Values");

    xmlWriter.writeStartElement("Temperature");
    xmlWriter.writeCharacters(ui->tempSpinBox-> text());
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("Humidity");
    xmlWriter.writeCharacters(ui->humiSpinBox-> text());
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("Pressure");
    xmlWriter.writeCharacters(ui->pressSpinBox-> text());
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("Grad");
    xmlWriter.writeCharacters(ui->gradSpinBox-> text());
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("Unit1");
    xmlWriter.writeAttribute("boolean", ui->pushButton_1-> isChecked() ? "true" : "false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("Unit2");
    xmlWriter.writeAttribute("boolean", ui->pushButton_2-> isChecked() ? "true" : "false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("Unit3");
    xmlWriter.writeAttribute("boolean", ui->pushButton_3-> isChecked() ? "true" : "false");
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
    //Завершаем запись в документ
    xmlWriter.writeEndDocument();

    file.close();
    qDebug() << "file save";

}
//метод  загрузки всех данных из XML
void MainWindow::onLoad()
{
    QFile file("D:/Condi/Sim/Sim/SimXML.xml");
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "file open error";
    }
    else
    {
        QXmlStreamReader xmlReader(&file);
        xmlReader.readNext();
        while(!xmlReader.atEnd())
        {
            if(xmlReader.isStartElement())
            {
                if(xmlReader.name() == "Temperature")
                {
                    ui->tempSpinBox->setValue((xmlReader.readElementText()).toDouble());
                }
                else if (xmlReader.name() == "Humidity")
                {
                    ui->humiSpinBox->setValue((xmlReader.readElementText()).toDouble());
                }
                else if (xmlReader.name() == "Pressure")
                {
                    ui->pressSpinBox->setValue((xmlReader.readElementText()).toDouble());
                }
                else if (xmlReader.name() == "Grad")
                {
                    ui->gradSpinBox->setValue((xmlReader.readElementText()).toDouble());
                }
                else if (xmlReader.name() == "Unit1")
                {
                    foreach(const QXmlStreamAttribute &attr, xmlReader.attributes())
                    {
                        if (attr.name().toString() == "boolean")
                        {
                            QString attribute_value = attr.value().toString();
                            ui->pushButton_1->setChecked((QString::compare(attribute_value , "true") == 0) ? true : false);
                        }
                    }
                }
                else if (xmlReader.name() == "Unit2")
                {
                    foreach(const QXmlStreamAttribute &attr, xmlReader.attributes())
                    {
                        if (attr.name().toString() == "boolean")
                        {
                            QString attribute_value = attr.value().toString();
                            ui->pushButton_2->setChecked((QString::compare(attribute_value , "true") == 0) ? true : false);
                        }
                    }
                }
                else if (xmlReader.name() == "Unit3")
                {
                    foreach(const QXmlStreamAttribute &attr, xmlReader.attributes())
                    {
                        if (attr.name().toString() == "boolean")
                        {
                            QString attribute_value = attr.value().toString();
                            ui->pushButton_3->setChecked((QString::compare(attribute_value , "true") == 0) ? true : false);
                        }
                    }
                }
            }
            xmlReader.readNext();
            //qDebug() << xmlReader.name()<< xmlReader.tokenString()<< xmlReader.text();
        }
        file.close();
    }
}
// ======================================================================
//метод  упаковщика всех данных из полей в пакет
void MainWindow::SimPac()
{
    packet.setTemp(ui->tempSpinBox-> text());
    packet.setHumi(ui->humiSpinBox-> text());
    packet.setGrad(ui->gradSpinBox-> text());
    packet.setPress(ui->pressSpinBox-> text());

    packet.setButton1(ui->pushButton_1-> isChecked());
    packet.setButton2(ui->pushButton_2-> isChecked());
    packet.setButton3(ui->pushButton_3-> isChecked());

    Server.sockWrite(packet.toByteArray());
}
