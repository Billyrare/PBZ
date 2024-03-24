#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/ASUS/Desktop/уроки/ПБЗ/lab2/zooland.db");
    if (db.open())
    {
        ui->statusbar->showMessage("Вы успешно подключились к базе данных: " + db.databaseName());



    }
    else
    {
        ui->statusbar->showMessage("При подключении к базе данных произошла ошибка: " +db.lastError().databaseText());
    }

}
MainWindow::~MainWindow()
{
    delete ui;
}

