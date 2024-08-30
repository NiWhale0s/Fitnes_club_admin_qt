#include "price.h"
#include "ui_price.h"

Price::Price(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Price)
{
    ui->setupUi(this);

    this->setMaximumSize(this->width(), this->height());
    this->setMinimumSize(this->width(), this->height());

    ui->protein->setSource(QUrl::fromLocalFile(":/html/price/protein.html"));
    ui->creatin->setSource(QUrl::fromLocalFile(":/html/price/creatin.html"));
    ui->abonement->setSource(QUrl::fromLocalFile(":/html/price/abonement.html"));
    ui->batonchic->setSource(QUrl::fromLocalFile(":/html/price/batonchic.html"));
    ui->baikal->setSource(QUrl::fromLocalFile(":/html/price/baikal.html"));
    connect(ui->exit_price, SIGNAL(clicked()), this, SLOT(close()));
}

Price::~Price()
{
    delete ui;
}
