#include "status.h"
#include "ui_status.h"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QGroupBox"
#include "QLabel"
#include "QtDebug"

Status::Status(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Status)
{
    ui->setupUi(this);
    this->statusInterface();
}

Status::~Status()
{
    delete ui;
}

void Status::statusInterface(){
    QVBoxLayout* centerLay = new QVBoxLayout();

    QGroupBox* input = new QGroupBox("Chain INPUT");
    QGroupBox* forward = new QGroupBox("Chain FORWARD");
    QGroupBox* output = new QGroupBox("Chain OUTPUT");

    centerLay->addWidget(input);
    centerLay->addWidget(forward);
    centerLay->addWidget(output);

    this->setLayout(centerLay);
}
