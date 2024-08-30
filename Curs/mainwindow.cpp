#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent, QString name) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    secondWindow = new Schedule();
    connect(secondWindow, &Schedule::firstWindow, this, &MainWindow::show);\

    thirdWindow = new Fitnes();
    connect(thirdWindow, &Fitnes::firstWindow, this, &MainWindow::show);

    settings = new QSettings("geometry", "SettingsWindow", this);
    LoadSettings();


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(ShowTime()));
    timer->start();

    db = new database();
    db->connectToDataBase();

    model = new QSqlTableModel;
    model->setTable("abonement");
    model->setHeaderData(0, Qt::Horizontal, "id");


    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->edit_button->setEnabled(true);
    ui->delete_button->setEnabled(true);


    ui->tableView->horizontalHeader()->setSectionResizeMode( 1, QHeaderView::Stretch );
    ui->tableView->horizontalHeader()->setSectionResizeMode( 2, QHeaderView::Stretch );
    ui->tableView->horizontalHeader()->setSectionResizeMode( 3, QHeaderView::Stretch );
    ui->tableView->horizontalHeader()->setSectionResizeMode( 4, QHeaderView::Stretch );
    ui->tableView->horizontalHeader()->setSectionResizeMode( 5, QHeaderView::Stretch );
    updateTable();

    editForm = new editabonement();
    editForm->setWindowModality(Qt::ApplicationModal);
    addForm = new addabonement();
    addForm->setWindowModality(Qt::ApplicationModal);

    connect(addForm, SIGNAL(sendToWidget(QString, QString, QString, QString, QString)),
            this, SLOT(addRecordDataBase(QString, QString, QString, QString, QString)));
    connect(this, SIGNAL(sendForEdit(int, QString, QString,  QString, QString, QString)),
            editForm, SLOT(catchInfo(int, QString, QString, QString, QString, QString)));
    connect(editForm, SIGNAL(sendToWidgetUpdate(int, QString, QString, QString, QString, QString)),
            this, SLOT(editRecordDataBase(int, QString, QString, QString, QString, QString)));

    connect(ui->add_button, SIGNAL(clicked()), this, SLOT(slotAdd()));
    connect(ui->edit_button, SIGNAL(clicked()), this, SLOT(slotEdit()));
    connect(ui->delete_button, SIGNAL(clicked()), this, SLOT(slotDel()));
    connect(ui->action, SIGNAL(triggered()), this, SLOT(SlotInfo()));

}

MainWindow::~MainWindow()
{
    SaveSettings();
    delete ui;
}

void MainWindow::updateTable()
{
    currID = -1;
    model->select();
    model->setSort(5, Qt::AscendingOrder);


    if (currRow == -1) {
        ui->edit_button->setEnabled(false);
        ui->delete_button->setEnabled(false);
    } else {
        ui->edit_button->setEnabled(true);
        ui->delete_button->setEnabled(true);
    }




    ui->tableView->show();

}

void MainWindow::slotAdd()
{
    addForm->show();
}
void MainWindow::addRecordDataBase(const QString &fname, const QString &sname,const QString &age ,const QString &abonement, const QString &time)
{
    db->insertIntoTable(fname, sname, age, abonement, time);
    updateTable();
    currRow = -1;
    currID = -1;
}

void MainWindow::slotEdit()
{
    if (currRow != -1) {
        QString name = model->data(model->index(currRow, 1)).toString();
        QString sname = model->data(model->index(currRow, 2)).toString();
        QString age = model->data(model->index(currRow, 3)).toString();
        QString abonement = model->data(model->index(currRow, 4)).toString();
        QString time = model->data(model->index(currRow, 5)).toString();
        emit sendForEdit(currID, name, sname, age, abonement, time);
        editForm->show();
    }
}

void MainWindow::editRecordDataBase(const int &id,const QString &fname, const QString &sname, const QString &age, const QString &abonement, const QString &time)
{
    currRow = -1;
    currID = -1;
    db->editInTable(id, fname, sname, age, abonement, time);
    updateTable();
}

void MainWindow::slotDel()
{
    if (currID != -1){
        db->removeRecord(currID);
        updateTable();
        QMessageBox::information(nullptr, "Уведомление", "Запись успешно удалена");
        currRow = -1;
        currID = -1;
    }
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    {

        ui->edit_button->setEnabled(true);
        ui->delete_button->setEnabled(true);
        currID = model->data(model->index(index.row(), 0)).toInt();
        currRow = index.row();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    secondWindow->show();
    this->close();
}

void MainWindow::ShowTime()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString datetime_text = dateTime.toString();
    ui->label_5->setText(datetime_text);
}

void MainWindow::SlotInfo()
{
    helpinformation* form = new helpinformation();
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    thirdWindow->show();
    this->close();
}

void MainWindow::SaveSettings()
{
    settings->setValue("geometry", geometry());
}
void MainWindow::LoadSettings()
{
    setGeometry(settings->value("geometry", QRect(200, 200, 300, 300)).toRect());
}
