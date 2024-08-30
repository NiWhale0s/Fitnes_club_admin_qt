#include "history.h"
#include "ui_history.h"

history::history(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::history)
{
    ui->setupUi(this);

    this->setMaximumSize(this->width(), this->height());
    this->setMinimumSize(this->width(), this->height());

    ui->textBrowser->setSource(QUrl::fromLocalFile(":/html/history/history.html"));
}

history::~history()
{
    delete ui;
}

