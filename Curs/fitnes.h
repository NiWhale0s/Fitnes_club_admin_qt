#ifndef FITNES_H
#define FITNES_H

#include <QWidget>
#include "about.h"
#include "history.h"
#include "price.h"
namespace Ui {
class Fitnes;
}

class Fitnes : public QWidget
{
    Q_OBJECT

public:
    explicit Fitnes(QWidget *parent = 0);
    ~Fitnes();

signals:
    void firstWindow();

private slots:
    void on_exit_fitnes_clicked();

private:
    Ui::Fitnes *ui;

public slots:
    void SlotHistory();
    void SlotAbout();
    void SlotPrice();
};

#endif // FITNES_H
