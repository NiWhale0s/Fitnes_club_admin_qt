#ifndef EDITABONEMENT_H
#define EDITABONEMENT_H

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QBuffer>
#include <QDebug>
#include <QDateTime>

namespace Ui {
class editabonement;
}

class editabonement : public QWidget
{
    Q_OBJECT

public:
    explicit editabonement(QWidget *parent = 0);
    ~editabonement();

public slots:
    void catchInfo(const int &id, const QString &fname, const QString &sname, const QString &age,const QString &abonement, const QString &time);

private slots:
    void on_Save_button_clicked();

    void on_Cancel_button_clicked();

private:
    Ui::editabonement *ui;
    int id;

signals:
    sendToWidgetUpdate(const int &id, const QString &fname, const QString &sname, const QString &age,const QString &abonement, const QString &time);
};

#endif // EDITABONEMENT_H
