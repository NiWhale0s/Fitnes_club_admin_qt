#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QWidget>
#include <QDialog>
#include <QFile>
#include <QList>
#include <string>

namespace Ui {
class Schedule;
}

class Schedule : public QDialog
{
    Q_OBJECT

public:
    explicit Schedule(QWidget *parent = 0);
    ~Schedule();

public slots:
    void ShowFullSchedure();

signals:
    void firstWindow();

private:
    Ui::Schedule *ui;
    std::string line;

private slots:
    void ShowTime();
    void ShowSchedure();
    void on_pushButton_2_clicked();
};
#endif // SCHEDULE_H
