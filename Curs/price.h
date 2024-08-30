#ifndef PRICE_H
#define PRICE_H

#include <QWidget>

namespace Ui {
class Price;
}

class Price : public QWidget
{
    Q_OBJECT

public:
    explicit Price(QWidget *parent = 0);
    ~Price();

private:
    Ui::Price *ui;
};

#endif // PRICE_H
