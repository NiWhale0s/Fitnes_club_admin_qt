#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);

    this->setMaximumSize(this->width(), this->height());
    this->setMinimumSize(this->width(), this->height());

    ui->label_2->setText("<a color=orange href=https://vk.com/ni_whale_os>Мы в ВК </a>");
    ui->label_2->setTextFormat(Qt::RichText);
    ui->label_2->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->label_2->setOpenExternalLinks(true);

    ui->label_3->setText("<a href=https://www.instagram.com/ni_whale_0s>Мы в Инстаграмм</a>");
    ui->label_3->setTextFormat(Qt::RichText);
    ui->label_3->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->label_3->setOpenExternalLinks(true);

    ui->label_4->setText("<a href=\"https://t.me/Ni_Whale_Os\">Мы в Телеграмм</a>");
    ui->label_4->setTextFormat(Qt::RichText);
    ui->label_4->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->label_4->setOpenExternalLinks(true);

    ui->label_5->setText("<a href=\"https://yandex.ru/maps/geo/3302819215/?ll=142.591467%2C11.370951&z=15.51\">Мы на карте</a>");
    ui->label_5->setTextFormat(Qt::RichText);
    ui->label_5->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->label_5->setOpenExternalLinks(true);

}

about::~about()
{
    delete ui;
}
