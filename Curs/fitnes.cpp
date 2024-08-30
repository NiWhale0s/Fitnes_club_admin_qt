#include "fitnes.h"
#include "ui_fitnes.h"

Fitnes::Fitnes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fitnes)
{
    ui->setupUi(this);
    this->setMaximumSize(this->width(), this->height());
    this->setMinimumSize(this->width(), this->height());

    //ui->history->setSource(QUrl::fromLocalFile(":/helpInformation/index.html"));
    //ui->about_us->setSource(QUrl::fromLocalFile(":/helpInformation/index.html"));
    //ui->people_buy_abonement()
    connect(ui->history, SIGNAL(clicked()), this, SLOT(SlotHistory()));
    connect(ui->about_us, SIGNAL(clicked()), this, SLOT(SlotAbout()));
    connect(ui->people_buy_abonement, SIGNAL(clicked()), this, SLOT(SlotPrice()));
}

Fitnes::~Fitnes()
{
    delete ui;
}

void Fitnes::SlotAbout()
{
    about* form = new about();
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}

void Fitnes::SlotHistory()
{
    history* form = new history();
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}

void Fitnes::SlotPrice()
{
    Price* form = new Price();
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}





void Fitnes::on_exit_fitnes_clicked()
{
    this->close();      // Закрываем окно
    emit firstWindow(); // И вызываем сигнал на открытие главного окна
}
