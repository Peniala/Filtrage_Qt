#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "policy.h"
#include "status.h"
#include "rules.h"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QGroupBox"
#include "QLabel"
#include "QtDebug"
#include "QComboBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    if (ui->centralwidget->layout()) {
//        delete ui->centralwidget->layout();  // Optional if clearing
//    }

    Policy * Wpolicy = new Policy();
    Status* Wstatus = new Status();
    Rules* Wrules = new Rules();

    Wpolicy->show();
    Wstatus->show();
    Wrules->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

