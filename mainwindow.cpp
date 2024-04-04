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
#include "QStackedWidget"
#include "QPushButton"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout* centerLay = new QVBoxLayout();

    ui->centralwidget->setLayout(centerLay);

    QWidget* navigation = new QWidget();

    QHBoxLayout* navLay = new QHBoxLayout();

    navigation->setLayout(navLay);

    QPushButton* bttpolicy = new QPushButton("Policy");
    QPushButton* bttrules = new QPushButton("Rules");
    QPushButton* bttstatus = new QPushButton("Status");
    QPushButton* btthelp = new QPushButton("Help");

    navLay->addWidget(bttpolicy);
    navLay->addWidget(bttrules);
    navLay->addWidget(bttstatus);
    navLay->addWidget(btthelp);

    QStackedWidget* block = new QStackedWidget();

    QVBoxLayout* blockLay = new QVBoxLayout();

    block->setLayout(blockLay);

    Policy * Wpolicy = new Policy();
    Rules* Wrules = new Rules();
    Status* Wstatus = new Status();

    block->addWidget(Wpolicy);
    block->addWidget(Wrules);
    block->addWidget(Wstatus);

    // block->setCurrentIndex(2);

    connect(bttpolicy,&QPushButton::clicked,this,[block](){
       block->setCurrentIndex(0);
    });

    connect(bttrules,&QPushButton::clicked,this,[block](){
        block->setCurrentIndex(1);
    });

    connect(bttstatus,&QPushButton::clicked,this,[block](){
        block->setCurrentIndex(2);
    });

    centerLay->addWidget(navigation);
    centerLay->addWidget(block);

    // Status* Wstatus = new Status();
    // Rules* Wrules = new Rules();

    // Wpolicy->show();
    // Wstatus->show();
    // Wrules->show();

    // connect(ui->pushButton,QPushButton::pressed(),&MainWindow,[=]()->void{
    //     qDebug() << "Mety";
    // });

}

MainWindow::~MainWindow()
{
    delete ui;
}


