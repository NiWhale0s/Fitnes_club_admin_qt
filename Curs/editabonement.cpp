#include "editabonement.h"
#include "ui_editabonement.h"

editabonement::editabonement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editabonement)
{
    ui->setupUi(this);
    this->setMaximumSize(this->width(),this->height());
    this->setMinimumSize(this->width(),this->height());
}

editabonement::~editabonement()
{
    delete ui;
}

void editabonement::catchInfo(const int &id, const QString &fname, const QString &sname, const QString &age,const QString &abonement, const QString &time)
{
    this->id = id;
    ui->name->setText(fname);
    ui->sname->setText(sname);
    ui->age->setText(age);
    ui->comboBox->setCurrentText(abonement);
}

void editabonement::on_Save_button_clicked()
{
    QString name = ui->name->text();
    if (name == ""){
        QMessageBox::information(nullptr, "Уведомление", "Заполните поле \"Имя\"");
        return;
    }

    QString sname = ui->sname->text();
    if (sname == ""){
        QMessageBox::information(nullptr, "Уведомление", "Заполните поле \"Название\"");
        return;
    }

    QString age = ui->age->text();
    if (age == ""){
        QMessageBox::information(nullptr, "Уведомление", "Заполните поле \"Возраст\"");
        return;
    } else if (age.toInt() > 100 || age.toInt() < 14){
        QMessageBox::information(nullptr, "Уведомление", "Заполните поле корректно \"Возраст\"");
        return;
    }

    QString abonement = ui->comboBox->currentText();
    QString date = QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss");
    emit sendToWidgetUpdate(this->id, name, sname, age, abonement, date);
    QMessageBox::information(nullptr, "Уведомление", "Запись успешно изменена!");
    close();
}

void editabonement::on_Cancel_button_clicked()
{
    this->close();
}
