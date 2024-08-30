#ifndef ADDABONEMENT_H
#define ADDABONEMENT_H

#include <QWidget>
#include <QFileDialog>
#include <QBuffer>
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>
#include "database.h"

namespace Ui {
class addabonement;
}

class addabonement : public QWidget
{
    Q_OBJECT

public:
    explicit addabonement(QWidget *parent = 0);
    ~addabonement();

    private slots:
        void on_Save_button_clicked();

    void on_Cancel_button_clicked();

private:
    Ui::addabonement *ui;
    database *db;

signals:
    void sendToWidget(const QString &fname, const QString &sname, const QString &age,const QString &abonement, const QString &time);
};

#endif // ADDABONEMENT_H
