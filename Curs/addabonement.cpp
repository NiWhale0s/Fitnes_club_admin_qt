#include "addabonement.h"
#include "ui_addabonement.h"

addabonement::addabonement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addabonement)
{
    ui->setupUi(this);
    this->setMaximumSize(this->width(),this->height());
    this->setMinimumSize(this->width(),this->height());

}

addabonement::~addabonement()
{
    delete ui;
}

void addabonement::on_Save_button_clicked()
{

    QString name = ui->Name->text();
    if (name == ""){
        QMessageBox::information(nullptr, "Уведомление", "Заполните поле \"Имя\"");
        return;
    }

    QString sname = ui->Surname->text();
    if (sname == ""){
        QMessageBox::information(nullptr, "Уведомление", "Заполните поле \"Название\"");
        return;
    }

    QString age = ui->age->text();
    if (age == ""){
        QMessageBox::information(nullptr, "Уведомление", "Заполните поле \"Возраст\"");
        return;
}   else if (age.toInt() > 100 || age.toInt() < 14){
        QMessageBox::information(nullptr, "Уведомление", "Заполните поле корректно \"Возраст\"");
        return;
    }
    QString abonement = ui->abonement->currentText();
    QString date = QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss");

    emit sendToWidget(name, sname, age, abonement, date);
    QMessageBox::information(nullptr, "Уведомление", "Запись успешно добавлена!");
    ui->Name->clear();
    ui->Surname->clear();
    ui->age->clear();
    close();

}

void addabonement::on_Cancel_button_clicked()
{
    ui->Name->clear();
    ui->Surname->clear();
    ui->age->clear();
    close();
}

