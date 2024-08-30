#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include <QHeaderView>
#include <QTimer>
#include <QDateTime>
#include <QList>
#include <QSettings>
#include "database.h"
#include "addabonement.h"
#include "editabonement.h"
#include "schedule.h"
#include "helpinformation.h"
#include "fitnes.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, QString name = "Main");
    ~MainWindow();

    void SaveSettings();
    void LoadSettings();

public slots:
    void slotAdd();
    void slotEdit();
    void slotDel();
    void updateTable();
    void addRecordDataBase(const QString &fname, const QString &sname, const QString &age,const QString &abonement, const QString &time);
    void editRecordDataBase(const int &id,const QString &fname, const QString &sname, const QString &age,const QString &abonement, const QString &time);
    void ShowTime();
    void SlotInfo();


private slots:

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    addabonement *addForm;
    editabonement *editForm;
    Schedule *secondWindow;
    Fitnes  *thirdWindow;
    QSettings* settings;
    database *db;
    QSqlTableModel *model;
    int currRow = -1;
    int currID = -1;
signals:
    void sendForEdit(const int &ip, const QString &fname, const QString &sname,const QString &age, const QString &abonement, const QString &time);
};

#endif // MAINWINDOW_H
