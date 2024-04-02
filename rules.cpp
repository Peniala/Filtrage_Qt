#include "rules.h"
#include "ui_rules.h"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QGroupBox"
#include "QComboBox"
#include "QRadioButton"
#include "QLabel"
#include "QtDebug"

Rules::Rules(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rules)
{
    ui->setupUi(this);

    this->rulesInterface();
}

Rules::~Rules()
{
    delete ui;
}

void Rules::rulesInterface(){
    QVBoxLayout* centerLayout = new QVBoxLayout();

    QGroupBox* label = new QGroupBox("Add rules");

    QVBoxLayout* field = new QVBoxLayout();

    QWidget* firstblock = new QWidget();

    QHBoxLayout* firstLay = new QHBoxLayout();

    QComboBox* chain = new QComboBox();

    chain->addItem("INPUT");
    chain->addItem("FORWARD");
    chain->addItem("OUTPUT");

    QGroupBox* Wtarget = new QGroupBox("Target");

    QHBoxLayout* targetLay = new QHBoxLayout();
    QRadioButton* accept = new QRadioButton("ACCEPT");
    QRadioButton* drop = new QRadioButton("DROP");

    targetLay->addWidget(accept);
    targetLay->addWidget(drop);

    Wtarget->setLayout(targetLay);

    QComboBox* interface = new QComboBox();

    interface->addItem("Interface");

    firstLay->addWidget(chain);
    firstLay->addWidget(Wtarget);
    firstLay->addWidget(interface);

    firstblock->setLayout(firstLay);

    field->addWidget(firstblock);

    label->setLayout(field);

    centerLayout->addWidget(label);

    this->setLayout(centerLayout);

}
