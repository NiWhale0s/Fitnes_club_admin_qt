#include "schedule.h"
#include "ui_schedule.h"

#include <QTimer>
#include <QDateTime>
#include <QList>
#include <fstream>
#include <iostream>
#include <QTextStream>

Schedule::Schedule(QWidget *parent) : QDialog(parent),
    ui(new Ui::Schedule)
{
    ui->setupUi(this);

    this->setMaximumSize(this->width(), this->height());
    this->setMinimumSize(this->width(), this->height());

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(ShowTime()));
    timer->start();
    ShowSchedure();
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(ShowFullSchedure()));
}

Schedule::~Schedule()
{
    delete ui;
}

void Schedule::ShowTime()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString datetime_text = dateTime.toString();
    ui->label_5->setText(datetime_text);
}

void Schedule::ShowSchedure()
{
    QTime Time = QTime::currentTime();
    QFile file ("./textfile/1.txt");
    QList<QString> list_fitnes_couch;

    QFile inputFile(QString("D:/Curs/textfile/1.txt"));
    inputFile.open(QIODevice::ReadOnly);
    QTextStream stream(&inputFile);
    for (QString line = stream.readLine();
         !line.isNull();
         line = stream.readLine()) {

        list_fitnes_couch.append(line);
        /* process information */
    };


    QList<QString> list_tranning = {"Тренировка на Выносливость", "Медитация", "Мотивация", "Силовая тренировка", "Растяжка"};
    QList<QString> list_time = {"08 : 00", "09 : 30", "11 : 00", "12 : 30", "14 : 00", "15 : 30", "17 : 00", "18 : 30", "20 : 00", "21 : 30"};
    QList<int> time_traning_hour={8, 9, 11, 12, 14, 15, 17, 18, 20, 21};
    QList<int> time_traning_minute={0, 30, 0, 30, 0, 30, 0, 30, 0, 30};


    for (qsizetype i = 0; i < time_traning_hour.size(); ++i){
        if (Time.hour() < time_traning_hour[i]){
            ui->textBrowser->append("Тренер: ");
            ui->textBrowser->insertPlainText(list_fitnes_couch[i%5]);
            ui->textBrowser->append("Тренировка: ");
            ui->textBrowser->insertPlainText(list_tranning[i%5]);
            ui->textBrowser->append("Время начала тренировки: ");
            ui->textBrowser->insertPlainText(list_time[i]);
            ui->textBrowser->append("");
        }
        else if (Time.hour() == time_traning_hour[i] && Time.minute() < time_traning_minute[i] ){
            ui->textBrowser->append("Тренер: ");
            ui->textBrowser->insertPlainText(list_fitnes_couch[i%5]);
            ui->textBrowser->append("Тренировка: ");
            ui->textBrowser->insertPlainText(list_tranning[i%5]);
            ui->textBrowser->append("Время начала тренировки: ");
            ui->textBrowser->insertPlainText(list_time[i]);
            ui->textBrowser->append("");
        }
    }

}

void Schedule::ShowFullSchedure(){
    QList<QString> list_fitnes_couch = {"Тихонов Никита", "Притула Алексей", "Мотиватор Антон", "Дядя Вася", "Бомж Валера"};
    QList<QString> list_tranning = {"Тренировка на Выносливость", "Медитация", "Мотивация", "Силовая тренировка", "Растяжка"};
    QList<QString> list_time = {"08 : 00", "09 : 30", "11 : 00", "12 : 30", "14 : 00", "15 : 30", "17 : 00", "18 : 30", "20 : 00", "21 : 30"};
    ui->textBrowser_2->clear();
    for (qsizetype i = 0; i < list_time.size(); ++i){
            ui->textBrowser_2->append("Тренер: ");
            ui->textBrowser_2->insertPlainText(list_fitnes_couch[i%5]);
            ui->textBrowser_2->append("Тренировка: ");
            ui->textBrowser_2->insertPlainText(list_tranning[i%5]);
            ui->textBrowser_2->append("Время начала тренировки: ");
            ui->textBrowser_2->insertPlainText(list_time[i]);
            ui->textBrowser_2->append("");
        }
}


void Schedule::on_pushButton_2_clicked()
{


        this->close();      // Закрываем окно
        emit firstWindow(); // И вызываем сигнал на открытие главного окна

}
