#include "helpinformation.h"
#include "ui_helpinformation.h"

helpinformation::helpinformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::helpinformation)
{
    ui->setupUi(this);
    this->setMaximumSize(this->width(), this->height());
    this->setMinimumSize(this->width(), this->height());


    // Установка соединений (сигналов и слотов) для кнопок и текстового браузера
    connect(ui->textBrowser, SIGNAL(anchorClicked(QUrl)), this, SLOT(on_textBrowser_anchorClicked(QUrl)));
    connect(ui->homeButton, SIGNAL(clicked()), ui->textBrowser, SLOT(home()));

    // Установка источника для текстового браузера (открывается HTML-страница из ресурсов)
    ui->textBrowser->setSource(QUrl::fromLocalFile(":/html/helpInformation/index.html"));
}

helpinformation::~helpinformation()
{
    delete ui;
}
