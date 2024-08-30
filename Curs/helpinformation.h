#ifndef HELPINFORMATION_H
#define HELPINFORMATION_H

#include <QWidget>
#include <QFile>

namespace Ui {
class helpinformation;
}

class helpinformation : public QWidget
{
    Q_OBJECT

public:
    explicit helpinformation(QWidget *parent = 0);
    ~helpinformation();

private:
    Ui::helpinformation *ui;
};

#endif // HELPINFORMATION_H
